#include "user_management.h"
#include "menu_interface.h"
#include "file_operations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

User users[MAX_USERS];
int user_count = 0;
char current_user[MAX_USERNAME_LEN] = "";// Currently logged-in user

/**
 * Finds the array index of a user by username.
 * 
 * @param username The username to search for
 * @return Index in the users array if found, -1 if not found
 */
int find_user_index(const char* username) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return i;
        }
    }
    return -1;// User not found
}

/**
 * Registers a new user account.
 * 
 * Process:
 * 1. Prompts for desired username
 * 2. Checks if username already exists
 * 3. Prompts for password (entered twice for confirmation)
 * 4. Adds new user to the system if all validations pass
 * 
 * The new user is initialized with empty friend and pending request lists.
 */
void register_user() {
    char username[MAX_USERNAME_LEN];
    char password1[MAX_PASSWORD_LEN];
    char password2[MAX_PASSWORD_LEN];

    // Get desired username
    printf("Enter account name: ");
    if (fgets(username, sizeof(username), stdin) == NULL) {
        return;
    }
    username[strcspn(username, "\n")] = 0;

    // Check if username already exists
    if (find_user_index(username) != -1) {
        printf("Account name already exists.\n");
        return;
    }

    // Get password (entered twice for verification)
    printf("Enter password: ");
    if (fgets(password1, sizeof(password1), stdin) == NULL) {
        return;
    }
    password1[strcspn(password1, "\n")] = 0;
    
    printf("Confirm password: ");
    if (fgets(password2, sizeof(password2), stdin) == NULL) {
        return;
    }
    password2[strcspn(password2, "\n")] = 0;

    // Verify password match
    if (strcmp(password1, password2) != 0) {
        printf("Passwords do not match. Registration failed.\n");
        return;
    }

    // Add new user if capacity allows
    if (user_count < MAX_USERS) {
        strcpy(users[user_count].username, username);
        strcpy(users[user_count].password, password1);
        users[user_count].friend_count = 0;// Initialize empty friend list
        users[user_count].pending_count = 0;// Initialize empty pending requests
        user_count++;
        
        printf("Registration successful! You can now login.\n");
        save_users();// Persist to file
    } else {
        printf("Maximum user limit reached.\n");
    }
}

/**
 * Authenticates a user and logs them into the system.
 * 
 * Process:
 * 1. Prompts for username and password
 * 2. Validates credentials against stored user data
 * 3. Sets current_user global variable on success
 * 4. Sets global login flag is_logged_in to true
 * 
 * @return 1 if login successful, 0 if failed
 */
int login_user() {
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];

    // Get credentials
    printf("Please input your account name: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;
    
    printf("and password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;

    // Check if system has any users
    if (user_count == 0) {
        printf("No user in this system, please register one.\n");
        return 0;
    }

    // Find user by username
    int user_idx = find_user_index(username);
    if (user_idx == -1) {
        printf("Warning! Account name not found.\n");
        return 0;
    }

    // Verify password
    if (strcmp(users[user_idx].password, password) != 0) {
        printf("Warning! Incorrect password.\n");
        return 0;
    }

    // Successful login - update global state
    strcpy(current_user, username);
    printf("Login successful. Welcome %s!\n", username);

    // Update global login flag (defined in menu_interface.c)
    extern int is_logged_in;
    is_logged_in = 1;
    
    return 1;// Login successful
}

/**
 * Wrapper function to load user data from file.
 * Calls the file operation function that reads from "users.txt".
 */
void load_users() {
    load_users_from_file();
}

/**
 * Wrapper function to save user data to file.
 * Calls the file operation function that writes to "users.txt".
 */
void save_users() {
    save_users_to_file();
}
