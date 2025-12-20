#include "common.h"
#include "menu_interface.h"
#include "user_management.h"
#include "friend_management.h"
#include "message_management.h"
#include "file_operations.h"
#include <stdio.h>

/**
 * Initializes the system by loading persistent data from files.
 * This function is called once at program startup.
 * 
 * Loads:
 * 1. User credentials from "users.txt"
 * 2. Friend relationships from "friends.txt"
 * 
 * Note: Messages are NOT loaded here because they are user-specific.
 * Messages are loaded only after a user successfully logs in.
 */
void initialize_system() {
    load_users();
    load_friends();
    // load_messages() should not be called here because it requires current user
    // Messages will be loaded after user logs in
}

int main() {
    initialize_system();
    show_login_menu();
    return 0;
}
