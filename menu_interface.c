#include "menu_interface.h"
#include "user_management.h"
#include "friend_management.h"
#include "message_management.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_logged_in = 0;

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
        
        if (fgets(input, sizeof(input), stdin) == NULL) {
            continue;
        }
        
        if (sscanf(input, "%d", &choice) != 1) {
            printf("Invalid input!\n");
            continue;
        }
        
        switch (choice) {
            case 1:
                if (login_user()) {
                    show_main_service_menu();
                }
                break;
            case 2:
                register_user();
                break;
            case 3:
                printf("Byebye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1 and 3.\n");
        }
    }
}

void show_main_service_menu() {
    int choice;
    
    while (is_logged_in) {
        printf("==================== Main Service ====================\n");
        printf("1. Manage friends\n");
        printf("2. Manage messages\n");
        printf("3. Back\n");
        printf("======================================================\n");
        printf("Choose an option (1-3): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        
        // Clear input buffer
        while (getchar() != '\n');
        
        switch (choice) {
            case 1:
                show_friend_management_menu();
                break;
            case 2:
                show_message_management_menu();
                break;
            case 3:
                logout_user();
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
