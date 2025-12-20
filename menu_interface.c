#include "menu_interface.h"
#include "user_management.h"
#include "friend_management.h"
#include "message_management.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global login state flag
int is_logged_in = 0;

/**
 * Displays the login menu and handles user authentication.
 * 
 * This is the main entry point after system initialization. Users can:
 * 1. Login with existing credentials
 * 2. Register a new account
 * 3. Exit the program
 * 
 * After successful login, control is passed to the main service menu.
 */
void show_login_menu() {
    char input[10];
    int choice;
    
    while (1) {
        printf("==================== Login ====================\n");
        printf("1. Login\n");
        printf("2. Register (If you do not have an account)\n");
        printf("3. Exit\n");
        printf("===============================================\n");
        printf("Choose an option (1-3): ");

        // Read user input with fgets for safety
        if (fgets(input, sizeof(input), stdin) == NULL) {
            continue;
        }

        // Parse integer choice from input
        if (sscanf(input, "%d", &choice) != 1) {
            printf("Invalid input!\n");
            continue;
        }

        // Handle menu selection
        switch (choice) {
            case 1:
                // Attempt to log in
                if (login_user()) {
                    show_main_service_menu();// Success -> show main menu
                }
                break;
            case 2:
                register_user();// Create new account
                break;
            case 3:
                printf("Byebye!\n");
                exit(0);// Terminate program
            default:
                printf("Invalid choice! Please enter a number between 1 and 3.\n");
        }
    }
}

/**
 * Displays the main service menu for authenticated users.
 * 
 * After login, users can access:
 * 1. Friend management (add/accept/delete/view friends)
 * 2. Message management (send/view messages)
 * 3. Logout (return to login menu)
 * 
 * Continues showing the menu until the user logs out.
 */
void show_main_service_menu() {
    int choice;

    // Only show menu while user is logged in
    while (is_logged_in) {
        printf("==================== Main Service ====================\n");
        printf("1. Manage friends\n");
        printf("2. Manage messages\n");
        printf("3. Back\n");
        printf("======================================================\n");
        printf("Choose an option (1-3): ");

        // Read user choice
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        
        // Clear input buffer
        while (getchar() != '\n');
        
        switch (choice) {
            case 1:
                show_friend_management_menu();// Access friend operations
                break;
            case 2:
                show_message_management_menu();// Access message operations
                break;
            case 3:
                logout_user();// Return to login menu
                return;
            default:
                printf("Invalid choice! Please enter a number between 1 and 3.\n");
        }
    }
}

void logout_user() {
    is_logged_in = 0;
    // According to README design, logout success message should not be printed when choosing Back
    // Simply return to Login menu
}

