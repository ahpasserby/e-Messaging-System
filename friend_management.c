#include "friend_manager.h"

void show_friend_management_menu() {
    int choice;

    while (is_logged_in) {
        printf("\n ==================== Manage Friends ====================\n");
        printf("1. Add friends\n");
        printf("2. Accept friends\n");
        printf("3. Delete friends\n");
        printf("4. Show current friends\n");
        printf("5. Back\n");
        printf("========================================================\n");
        printf("Choose an option (1-5): ");
        
        scanf("%d", &choice);

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
            printf("Invalid choice! Please enter 1-5.\n");
        }
    }
}

void add_friend_function(User* user) {
    char input[MAX_FRIENDS * MAX_ACCOUNT_LENGTH];
    char* account_name;
    printf("Enter account names separated by space: ");
    fgets(input, sizeof(input), stdin);

    account_name = strtok(input, " ");
    while (account_name != NULL) {
        // check if the account exist 
        if (strcmp(account_name, user->friends.accounts[0]) == 0) {
            printf("Account name already exists in friends list.\n");
        }
        else {
            // add to the waiting list
            if (user->waiting_to_confirm.count < MAX_FRIENDS) {
                strcpy(user->waiting_to_confirm.accounts[user->waiting_to_confirm.count], account_name);
                user->waiting_to_confirm.count++;
                printf("Added %s to waiting to confirm list.\n", account_name);
            }
            else {
                printf("Waiting to confirm list is full.\n");
            }
        }
        account_name = strtok(NULL, " ");
    }
}

void accept_friend_request_function(User* user) {
    int i, choice;
    if (user->waiting_to_confirm.count == 0) {//if no friends addition
        printf("No friends to accept.\n");
        return;
    }

    printf("Waiting to confirm friends:\n");
    for (i = 0; i < user->waiting_to_confirm.count; i++) {
        printf("%d. %s\n", i + 1, user->waiting_to_confirm.accounts[i]);
    }
    printf("Enter index to accept (0 to cancel): ");
    scanf("%d", &choice);

    if (choice > 0 && choice <= user->waiting_to_confirm.count) {
        if (user->friends.count < MAX_FRIENDS) {
            strcpy(user->friends.accounts[user->friends.count], user->waiting_to_confirm.accounts[choice - 1]);
            user->friends.count++;
            printf("Accepted %s as friend.\n", user->waiting_to_confirm.accounts[choice - 1]);
        }
        else {
            printf("Friends list is full.\n");
        }
        for (i = choice - 1; i < user->waiting_to_confirm.count - 1; i++) {
            strcpy(user->waiting_to_confirm.accounts[i], user->waiting_to_confirm.accounts[i + 1]);
        }
        user->waiting_to_confirm.count--;
    }
}


void delete_friend_function(User* user) {
    int i, choice;
    if (user->friends.count == 0) {
        printf("No friends to delete.\n");
        return;
    }

    printf("Friends list:\n");
    for (i = 0; i < user->friends.count; i++) {
        printf("%d. %s\n", i + 1, user->friends.accounts[i]);
    }
    printf("Enter index to delete (0 to cancel): ");
    scanf("%d", &choice);

    if (choice > 0 && choice <= user->friends.count) {
        // remove from the list
        for (i = choice - 1; i < user->friends.count - 1; i++) {
            strcpy(user->friends.accounts[i], user->friends.accounts[i + 1]);
        }
        user->friends.count--;
        printf("Deleted friend.\n");
    }
}


void show_friends_function(const User* user) {
    int i;
    if (user->friends.count == 0) {
        printf("No friends.\n");
        return;
    }

    printf("Friends list:\n");
    for (i = 0; i < user->friends.count; i++) {
        printf("%d. %s\n", i + 1, user->friends.accounts[i]);
    }
}


void save_user_to_file(const User* user, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(file, "%d\n", user->friends.count);
    for (int i = 0; i < user->friends.count; i++) {
        fprintf(file, "%s\n", user->friends.accounts[i]);
    }

    fprintf(file, "%d\n", user->waiting_to_confirm.count);
    for (int i = 0; i < user->waiting_to_confirm.count; i++) {
        fprintf(file, "%s\n", user->waiting_to_confirm.accounts[i]);
    }

    fclose(file);
}

void load_user_from_file(User* user, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fscanf(file, "%d\n", &user->friends.count);
    for (int i = 0; i < user->friends.count; i++) {
        fscanf(file, "%s\n", user->friends.accounts[i]);
    }

    fscanf(file, "%d\n", &user->waiting_to_confirm.count);
    for (int i = 0; i < user->waiting_to_confirm.count; i++) {
        fscanf(file, "%s\n", user->waiting_to_confirm.accounts[i]);
    }

    fclose(file);
}
