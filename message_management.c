#include "message_management.h"
#include "friend_management.h"
#include "menu_interface.h"
#include "file_operations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Global variable declarations
extern User users[MAX_USERS];
extern int user_count;
extern char current_user[MAX_USERNAME_LEN];

// Message array
Message messages[MAX_MESSAGES];
int message_count = 0;

// Find user index (declared as extern, defined in user_management.c)
extern int find_user_index(const char* username);

// Find current user index
static int find_current_user_index() {
    return find_user_index(current_user);
}

// Get current timestamp
void get_current_timestamp(char* timestamp) {
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    strftime(timestamp, 20, "%Y-%m-%d %H:%M:%S", t);
}

// Display message management menu
void show_message_management_menu() {
    int choice;
    
    while (1) {
        printf("==================== Manage Messages ====================\n");
        printf("1. Send a message\n");
        printf("2. Read messages\n");
        printf("3. Delete messages\n");
        printf("4. Back\n");
        printf("=========================================================\n");
        printf("Choose an option (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        
        switch (choice) {
            case 1:
                send_message_function();
                break;
            case 2:
                read_messages_function();
                break;
            case 3:
                delete_messages_function();
                break;
            case 4:
                return;
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    }
}

// Send message function
void send_message_function() {
    int current_idx = find_current_user_index();
    if (current_idx == -1) {
        printf("Error: Current user not found!\n");
        return;
    }
    
    if (users[current_idx].friend_count == 0) {
        printf("You have no friends to send messages to.\n");
        return;
    }
    
    // Input message content
    char content[MAX_MESSAGE_LEN];
    printf("Enter message (max 255 chars), press Enter to finish: ");
    getchar(); // Consume newline character
    fgets(content, sizeof(content), stdin);
    content[strcspn(content, "\n")] = 0; // Remove newline character
    
    // Display friend list
    printf("Your friends:\n");
    for (int i = 0; i < users[current_idx].friend_count; i++) {
        printf("%d. %s\n", i + 1, users[current_idx].friends[i]);
    }
    printf("%d. All\n", users[current_idx].friend_count + 1);
    printf("%d. Back\n", users[current_idx].friend_count + 2);
    
    printf("Enter friend numbers (separated by space), press Enter to finish: ");
    
    char input[100];
    fgets(input, sizeof(input), stdin);
    
    // Process input
    char* token = strtok(input, " ");
    while (token != NULL) {
        int choice = atoi(token);
        
        if (choice == users[current_idx].friend_count + 1) { // All
            // Send to all friends
            for (int i = 0; i < users[current_idx].friend_count; i++) {
                if (message_count < MAX_MESSAGES) {
                    strcpy(messages[message_count].sender, current_user);
                    strcpy(messages[message_count].receiver, users[current_idx].friends[i]);
                    strcpy(messages[message_count].content, content);
                    get_current_timestamp(messages[message_count].timestamp);
                    messages[message_count].is_read = 0;
                    
                    // Immediately save to receiver's file
                    save_single_message(&messages[message_count]);
                    
                    message_count++;
                }
            }
            printf("Message sent to All\n");
            break;
        } else if (choice == users[current_idx].friend_count + 2) { // Back
            return;
        } else if (choice > 0 && choice <= users[current_idx].friend_count) {
            // Send to specified friend
            if (message_count < MAX_MESSAGES) {
                strcpy(messages[message_count].sender, current_user);
                strcpy(messages[message_count].receiver, users[current_idx].friends[choice - 1]);
                strcpy(messages[message_count].content, content);
                get_current_timestamp(messages[message_count].timestamp);
                messages[message_count].is_read = 0;
                
                // Immediately save to receiver's file
                save_single_message(&messages[message_count]);
                
                message_count++;
                printf("Message sent to %s\n", users[current_idx].friends[choice - 1]);
            } else {
                printf("Message storage is full.\n");
            }
        }
        
        token = strtok(NULL, " ");
    }
    
    // No need to call save_messages() anymore, as messages have been saved individually
}

// Read messages function
void read_messages_function() {
    // Load messages
    load_messages();
    
    // First check if current user has messages
    int has_messages = 0;
    for (int i = 0; i < message_count; i++) {
        if (strcmp(messages[i].receiver, current_user) == 0) {
            has_messages = 1;
            break;
        }
    }
    
    if (!has_messages) {
        printf("No messages found.\n");
        return;
    }
    
    int choice;
    printf("1. Read all messages\n");
    printf("2. Read unread messages only\n");
    printf("3. Back\n");
    printf("Choose an option: ");
    
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input!\n");
        while (getchar() != '\n');
        return;
    }
    
    // Clear newline character from input buffer
    while (getchar() != '\n');
    
    if (choice == 3) {
        return;
    }
    
    int found = 0;
    if (choice == 1) {
        // Read all messages
        for (int i = 0; i < message_count; i++) {
            if (strcmp(messages[i].receiver, current_user) == 0) {
                printf("[%s] From: %s\n", messages[i].timestamp, messages[i].sender);
                printf("%s\n", messages[i].content);
                messages[i].is_read = 1;
                found = 1;
            }
        }
        if (!found) {
            printf("No messages found.\n");
        }
    } else if (choice == 2) {
        // Read only unread messages
        for (int i = 0; i < message_count; i++) {
            if (strcmp(messages[i].receiver, current_user) == 0 && messages[i].is_read == 0) {
                printf("[%s] From: %s\n", messages[i].timestamp, messages[i].sender);
                printf("%s\n", messages[i].content);
                messages[i].is_read = 1;
                found = 1;
            }
        }
        if (!found) {
            printf("Found no messages.\n");
        }
    } else {
        printf("Invalid choice!\n");
    }
    
    save_messages();
}

// Helper function: convert dd/mm/yyyy to yyyy-mm-dd format for comparison
int convert_date_format(const char* input_date, char* output_date) {
    int day, month, year;
    if (sscanf(input_date, "%d/%d/%d", &day, &month, &year) != 3) {
        return 0; // Parsing failed
    }
    sprintf(output_date, "%04d-%02d-%02d", year, month, day);
    return 1;
}

// Delete messages function
void delete_messages_function() {
    // Load messages
    load_messages();
    
    // Check if current user has messages
    int has_messages = 0;
    for (int i = 0; i < message_count; i++) {
        if (strcmp(messages[i].receiver, current_user) == 0) {
            has_messages = 1;
            break;
        }
    }
    
    if (!has_messages) {
        printf("No messages found.\n");
        // Clear input buffer
        while (getchar() != '\n');
        return;
    }
    
    char start_date[11], end_date[11], account[MAX_USERNAME_LEN];
    
    printf("Enter start date (dd/mm/yyyy): ");
    scanf("%s", start_date);
    
    printf("Enter end date (dd/mm/yyyy): ");
    scanf("%s", end_date);
    
    printf("Enter account name (or 'all'): ");
    scanf("%s", account);
    
    // Clear input buffer
    while (getchar() != '\n');
    
    // Convert date format
    char start_date_conv[11], end_date_conv[11];
    if (!convert_date_format(start_date, start_date_conv) || !convert_date_format(end_date, end_date_conv)) {
        printf("Invalid date format!\n");
        return;
    }
    
    int removed_count = 0;
    for (int i = 0; i < message_count; i++) {
        if (strcmp(messages[i].receiver, current_user) == 0) {
            // Check account match
            int account_match = (strcmp(account, "all") == 0) || (strcmp(messages[i].sender, account) == 0);
            
            // Check date match
            int date_match = 0;
            // Extract message date part (first 10 characters: YYYY-MM-DD)
            char message_date[11];
            strncpy(message_date, messages[i].timestamp, 10);
            message_date[10] = '\0';
            
            // Compare dates
            if (strcmp(message_date, start_date_conv) >= 0 && strcmp(message_date, end_date_conv) <= 0) {
                date_match = 1;
            }
            
            if (account_match && date_match) {
                // Delete message
                for (int j = i; j < message_count - 1; j++) {
                    messages[j] = messages[j + 1];
                }
                message_count--;
                i--;
                removed_count++;
            }
        }
    }
    
    printf("Removed %d message(s) from %s in period %s - %s.\n", 
           removed_count, account, start_date, end_date);
    
    save_messages();
}

// Load messages
void load_messages() {
    load_messages_from_file(current_user);
}

// Save messages
void save_messages() {
    save_messages_to_file(current_user);
}
