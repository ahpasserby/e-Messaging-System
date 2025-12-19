#include "friend_management.h"
#include "menu_interface.h"
#include "file_operations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variable declarations
extern User users[MAX_USERS];
extern int user_count;
extern char current_user[MAX_USERNAME_LEN];

// Find user index (declared as extern, defined in user_management.c)
extern int find_user_index(const char* username);

// Find current user index
static int find_current_user_index() {
    return find_user_index(current_user);
}

// Display friend management menu
void show_friend_management_menu() {
    int choice;

    while (1) {
        printf("==================== Manage Friends ====================\n");
        printf("1. Add friends\n");
        printf("2. Accept friends\n");
        printf("3. Delete friends\n");
        printf("4. Show current friends\n");
        printf("5. Back\n");
        printf("========================================================\n");
        printf("Choose an option (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                add_friend_function();
                break;
            case 2:
                accept_friend_request_function();
                break;
            case 3:
                delete_friend_function();
                break;
            case 4:
                show_friends_function();
                break;
            case 5:
                return;
            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    }
}

// Add friend function
void add_friend_function() {
    int current_idx = find_current_user_index();
    if (current_idx == -1) {
        printf("Error: Current user not found!\n");
        return;
    }

    char input[1000];
    printf("Enter usernames to add (in one line separated by space): ");
    getchar(); // Consume newline character
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    char* token = strtok(input, " ");
    while (token != NULL) {
        // Check if it's self
        if (strcmp(token, current_user) == 0) {
            printf("You cannot send a friend request to yourself.\n");
        }
        // Check if user exists
        else if (find_user_index(token) == -1) {
            printf("Account %s does not exist.\n", token);
        }
        // Check if already friends
        else {
            int is_friend = 0;
            for (int i = 0; i < users[current_idx].friend_count; i++) {
                if (strcmp(users[current_idx].friends[i], token) == 0) {
                    is_friend = 1;
                    break;
                }
            }

            if (is_friend) {
                printf("%s is already your friend.\n", token);
            }
            // Check if there is already a pending request
            else {
                // Find target user's index
                int target_idx = find_user_index(token);
                if (target_idx == -1) {
                    printf("Error: Target user %s not found.\n", token);
                    continue;
                }
                
                // First check if the other user has already sent a request to current user
                int has_received_request = 0;
                for (int i = 0; i < users[current_idx].pending_count; i++) {
                    if (strcmp(users[current_idx].pending_requests[i], token) == 0) {
                        has_received_request = 1;
                        break;
                    }
                }
                
                if (has_received_request) {
                    printf("%s has sent friend request to you.\n", token);
                        // According to README design, friend relationship should not be automatically established here
                        // User should go to "Accept friend requests" menu to handle it
                }
                // Check if current user's request is already in target user's pending list
                else {
                    int has_pending = 0;
                    for (int i = 0; i < users[target_idx].pending_count; i++) {
                        if (strcmp(users[target_idx].pending_requests[i], current_user) == 0) {
                            has_pending = 1;
                            break;
                        }
                    }

                    if (has_pending) {
                        printf("Friend request to %s is already pending.\n", token);
                    } else {
                        // Add to target user's pending list (not current user's list!)
                        if (users[target_idx].pending_count < MAX_FRIENDS) {
                            strcpy(users[target_idx].pending_requests[users[target_idx].pending_count], current_user);
                            users[target_idx].pending_count++;
                            printf("Friend request sent to %s.\n", token);
                        } else {
                            printf("Pending requests list is full for %s.\n", token);
                        }
                    }
                }
            }
        }

        token = strtok(NULL, " ");
    }

    save_friends();
}

// Accept friend request function
void accept_friend_request_function() {
    int current_idx = find_current_user_index();
    if (current_idx == -1) {
        printf("Error: Current user not found!\n");
        return;
    }

    if (users[current_idx].pending_count == 0) {
        printf("No pending friend requests for %s.\n", current_user);
        return;
    }

    printf("Pending friend requests for %s:\n", current_user);
    for (int i = 0; i < users[current_idx].pending_count; i++) {
        printf("%d. %s\n", i + 1, users[current_idx].pending_requests[i]);
    }
    printf("%d. All\n", users[current_idx].pending_count + 1);
    printf("%d. Back\n", users[current_idx].pending_count + 2);

    printf("Enter indices (space separated), press Enter to finish: ");

    char input[100];
    getchar(); // Consume newline character
    fgets(input, sizeof(input), stdin);

    // First collect all choices to accept (using original display numbers)
    int choices[MAX_FRIENDS];
    int choice_count = 0;
    
    char* token = strtok(input, " ");
    while (token != NULL && choice_count < MAX_FRIENDS) {
        int choice = atoi(token);
        choices[choice_count++] = choice;
        token = strtok(NULL, " ");
    }
    
    // Check if there is "All" option
    for (int c = 0; c < choice_count; c++) {
        if (choices[c] == users[current_idx].pending_count + 1) { // All
            // Accept all requests
            for (int i = 0; i < users[current_idx].pending_count; i++) {
                char* friend_name = users[current_idx].pending_requests[i];
                int friend_idx = find_user_index(friend_name);

                if (friend_idx != -1) {
                    // Add to current user's friend list
                    if (users[current_idx].friend_count < MAX_FRIENDS) {
                        strcpy(users[current_idx].friends[users[current_idx].friend_count], friend_name);
                        users[current_idx].friend_count++;
                    }

                    // Add to other user's friend list
                    if (users[friend_idx].friend_count < MAX_FRIENDS) {
                        strcpy(users[friend_idx].friends[users[friend_idx].friend_count], current_user);
                        users[friend_idx].friend_count++;
                    }
                }
            }
            users[current_idx].pending_count = 0;
            printf("Friend requests updated for all.\n");
            save_friends();
            return;
        } else if (choices[c] == users[current_idx].pending_count + 2) { // Back
            return;
        }
    }
    
    // Mark items to accept (using original display numbers)
    int accepted_count = 0;
    char accepted_names[MAX_FRIENDS][MAX_USERNAME_LEN];
    
    for (int c = 0; c < choice_count; c++) {
        int choice = choices[c];
        
        if (choice > 0 && choice <= users[current_idx].pending_count) {
            // Record friend name to accept
            strcpy(accepted_names[accepted_count], users[current_idx].pending_requests[choice - 1]);
            accepted_count++;
        }
    }
    
    // Process accepted friend requests in input order
    for (int a = 0; a < accepted_count; a++) {
        char* friend_name = accepted_names[a];
        int friend_idx = find_user_index(friend_name);

        if (friend_idx != -1) {
            // Add to current user's friend list
            if (users[current_idx].friend_count < MAX_FRIENDS) {
                strcpy(users[current_idx].friends[users[current_idx].friend_count], friend_name);
                users[current_idx].friend_count++;
            }

            // Add to other user's friend list
            if (users[friend_idx].friend_count < MAX_FRIENDS) {
                strcpy(users[friend_idx].friends[users[friend_idx].friend_count], current_user);
                users[friend_idx].friend_count++;
            }

            // Remove from pending list (need to find current position in the list)
            int found_index = -1;
            for (int i = 0; i < users[current_idx].pending_count; i++) {
                if (strcmp(users[current_idx].pending_requests[i], friend_name) == 0) {
                    found_index = i;
                    break;
                }
            }
            
            if (found_index != -1) {
                // Remove from pending list
                for (int i = found_index; i < users[current_idx].pending_count - 1; i++) {
                    strcpy(users[current_idx].pending_requests[i], users[current_idx].pending_requests[i + 1]);
                }
                users[current_idx].pending_count--;
            }

            printf("Friend requests updated for %s.\n", friend_name);
        }
    }

    save_friends();
}

// Delete friend function
void delete_friend_function() {
    int current_idx = find_current_user_index();
    if (current_idx == -1) {
        printf("Error: Current user not found!\n");
        return;
    }

    if (users[current_idx].friend_count == 0) {
        printf("You have no friends.\n");
        return;
    }

    // Create temporary array for sorting and display
    char sorted_friends[MAX_FRIENDS][MAX_USERNAME_LEN];
    int original_indices[MAX_FRIENDS]; // Store indices of sorted friends in original array
    
    for (int i = 0; i < users[current_idx].friend_count; i++) {
        strcpy(sorted_friends[i], users[current_idx].friends[i]);
        original_indices[i] = i; // Initial index
    }
    
    // Sort alphabetically while maintaining index correspondence
    for (int i = 0; i < users[current_idx].friend_count - 1; i++) {
        for (int j = i + 1; j < users[current_idx].friend_count; j++) {
            if (strcmp(sorted_friends[i], sorted_friends[j]) > 0) {
                // Swap names
                char temp_name[MAX_USERNAME_LEN];
                strcpy(temp_name, sorted_friends[i]);
                strcpy(sorted_friends[i], sorted_friends[j]);
                strcpy(sorted_friends[j], temp_name);
                
                // Swap indices
                int temp_idx = original_indices[i];
                original_indices[i] = original_indices[j];
                original_indices[j] = temp_idx;
            }
        }
    }

    printf("Your friends:\n");
    for (int i = 0; i < users[current_idx].friend_count; i++) {
        printf("%d. %s\n", i + 1, sorted_friends[i]);
    }
    printf("%d. All\n", users[current_idx].friend_count + 1);
    printf("%d. Back\n", users[current_idx].friend_count + 2);

    printf("Enter friend numbers (separated by space), press Enter to finish: ");

    char input[100];
    getchar(); // Consume newline character
    fgets(input, sizeof(input), stdin);

    // First collect all choices to delete
    int choices[MAX_FRIENDS];
    int choice_count = 0;
    int delete_all = 0;
    
    char* token = strtok(input, " ");
    while (token != NULL && choice_count < MAX_FRIENDS) {
        int choice = atoi(token);
        choices[choice_count++] = choice;
        token = strtok(NULL, " ");
    }
    
    // Check if there is "All" option
    for (int c = 0; c < choice_count; c++) {
        if (choices[c] == users[current_idx].friend_count + 1) { // All
            delete_all = 1;
            break;
        } else if (choices[c] == users[current_idx].friend_count + 2) { // Back
            return;
        }
    }
    
    if (delete_all) {
        // Delete all friends
        printf("Deleting all...\n");
        for (int i = 0; i < users[current_idx].friend_count; i++) {
            char* friend_name = users[current_idx].friends[i];
            int friend_idx = find_user_index(friend_name);

            if (friend_idx != -1) {
                // Remove current user from other user's friend list
                for (int j = 0; j < users[friend_idx].friend_count; j++) {
                    if (strcmp(users[friend_idx].friends[j], current_user) == 0) {
                        for (int k = j; k < users[friend_idx].friend_count - 1; k++) {
                            strcpy(users[friend_idx].friends[k], users[friend_idx].friends[k + 1]);
                        }
                        users[friend_idx].friend_count--;
                        break;
                    }
                }
            }
        }
        users[current_idx].friend_count = 0;
        printf("Friend list updated.\n");
    } else {
        // Mark items to delete (using sorted numbers)
        int deleted_count = 0;
        char deleted_names[MAX_FRIENDS][MAX_USERNAME_LEN];
        
        for (int c = 0; c < choice_count; c++) {
            int choice = choices[c];
            
            if (choice > 0 && choice <= users[current_idx].friend_count) {
                // Record friend name to delete (using sorted array)
                strcpy(deleted_names[deleted_count], sorted_friends[choice - 1]);
                deleted_count++;
            }
        }
        
        // Process deleted friends in input order
        for (int d = 0; d < deleted_count; d++) {
            char* friend_name = deleted_names[d];
            printf("Deleting %s...\n", friend_name);
            
            int friend_idx = find_user_index(friend_name);

            if (friend_idx != -1) {
                // Remove current user from other user's friend list
                for (int j = 0; j < users[friend_idx].friend_count; j++) {
                    if (strcmp(users[friend_idx].friends[j], current_user) == 0) {
                        for (int k = j; k < users[friend_idx].friend_count - 1; k++) {
                            strcpy(users[friend_idx].friends[k], users[friend_idx].friends[k + 1]);
                        }
                        users[friend_idx].friend_count--;
                        break;
                    }
                }
            }

            // Remove from current user's friend list (need to find current position in the list)
            int found_index = -1;
            for (int i = 0; i < users[current_idx].friend_count; i++) {
                if (strcmp(users[current_idx].friends[i], friend_name) == 0) {
                    found_index = i;
                    break;
                }
            }
            
            if (found_index != -1) {
                // Remove from friend list
                for (int i = found_index; i < users[current_idx].friend_count - 1; i++) {
                    strcpy(users[current_idx].friends[i], users[current_idx].friends[i + 1]);
                }
                users[current_idx].friend_count--;
            }
        }
        
        if (deleted_count > 0) {
            printf("Friend list updated.\n");
        }
    }

    save_friends();
}

// Comparison function for qsort sorting
static int compare_strings(const void* a, const void* b) {
    return strcmp((const char*)a, (const char*)b);
}

// Display friends function
void show_friends_function() {
    int current_idx = find_current_user_index();
    if (current_idx == -1) {
        printf("Error: Current user not found!\n");
        return;
    }

    if (users[current_idx].friend_count == 0) {
        printf("You have no friends.\n");
        return;
    }

    // Create temporary array for sorting
    char sorted_friends[MAX_FRIENDS][MAX_USERNAME_LEN];
    for (int i = 0; i < users[current_idx].friend_count; i++) {
        strcpy(sorted_friends[i], users[current_idx].friends[i]);
    }
    
    // Sort alphabetically
    qsort(sorted_friends, users[current_idx].friend_count, MAX_USERNAME_LEN, compare_strings);

    printf("Your friends:\n");
    for (int i = 0; i < users[current_idx].friend_count; i++) {
        printf("%d. %s\n", i + 1, sorted_friends[i]);
    }
}

// Load friends
void load_friends() {
    load_friends_from_file();
}

// Save friends
void save_friends() {
    save_friends_to_file();
}
