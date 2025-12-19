#include "common.h"

// Current logged-in user status
extern int is_logged_in;

// Function declarations
void show_login_menu();
void show_main_service_menu();
void show_friend_management_menu();
void show_message_management_menu();
void register_user();
int login_user();
void logout_user();
