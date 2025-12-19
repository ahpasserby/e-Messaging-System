#include "common.h"
#include "menu_interface.h"
#include "user_management.h"
#include "friend_management.h"
#include "message_management.h"
#include "file_operations.h"
#include <stdio.h>

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
