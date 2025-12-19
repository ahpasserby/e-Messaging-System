#include "user_management.h"
#include "menu_interface.h"
#include "file_operations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

User users[MAX_USERS];
int user_count = 0;
char current_user[MAX_USERNAME_LEN] = "";

int find_user_index(const char* username) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return i;
        }
    }
    return -1;
}

void register_user() {
    char username[MAX_USERNAME_LEN];
    char password1[MAX_PASSWORD_LEN];
    char password2[MAX_PASSWORD_LEN];
    
    printf("Enter account name: ");
    if (fgets(username, sizeof(username), stdin) == NULL) {
        return;
    }
    username[strcspn(username, "\n")] = 0;
    
    if (find_user_index(username) != -1) {
        printf("Account name already exists.\n");
        return;
    }
    
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
    
    if (strcmp(password1, password2) != 0) {
        printf("Passwords do not match. Registration failed.\n");
        return;
    }
    
    if (user_count < MAX_USERS) {
        strcpy(users[user_count].username, username);
        strcpy(users[user_count].password, password1);
        users[user_count].friend_count = 0;
        users[user_count].pending_count = 0;
        user_count++;
        
        printf("Registration successful! You can now login.\n");
        save_users();
    } else {
        printf("Maximum user limit reached.\n");
    }
}

int login_user() {
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
    
    printf("Please input your account name: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;
    
    printf("and password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;
    
    if (user_count == 0) {
        printf("No user in this system, please register one.\n");
        return 0;
    }
    
    int user_idx = find_user_index(username);
    if (user_idx == -1) {
        printf("Warning! Account name not found.\n");
        return 0;
    }
    
    if (strcmp(users[user_idx].password, password) != 0) {
        printf("Warning! Incorrect password.\n");
        return 0;
    }
    
    strcpy(current_user, username);
    printf("Login successful. Welcome %s!\n", username);
    
    extern int is_logged_in;
    is_logged_in = 1;
    
    return 1;
}

void load_users() {
    load_users_from_file();
}

void save_users() {
    save_users_to_file();
}
