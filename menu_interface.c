#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define MAX_USERNAME 50
#define MAX_PASSWORD 50
#define MAX_FRIENDS 50
#define MAX_MESSAGES 100
#define MAX_CONTENT 255
#define MAX_TIMESTAMP 20

// 用户结构体
typedef struct {
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
    char friends[MAX_FRIENDS][MAX_USERNAME];
    char pending_requests[MAX_FRIENDS][MAX_USERNAME];
    int friend_count;
    int pending_count;
} User;

// 消息结构体
typedef struct {
    char sender[MAX_USERNAME];
    char receiver[MAX_USERNAME];
    char content[MAX_CONTENT];
    char timestamp[MAX_TIMESTAMP];
    int is_read;
} Message;

// 当前登录用户
User current_user;
int is_logged_in = 0;

// 函数声明
void show_login_menu();
void show_main_service_menu();
void show_friend_management_menu();
void show_message_management_menu();
void register_user();
int login_user();
void logout_user();

// 主函数
int main() {
    show_login_menu();
    return 0;
}

// 显示登录菜单
void show_login_menu() {
    int choice;

    while (1) {
        printf("\n==================== Login ====================\n");
        printf("1. Login\n");
        printf("2. Register (If you do not have an account)\n");
        printf("3. Exit\n");
        printf("===============================================\n");
        printf("Choose an option (1-3): ");
        scanf("%d", &choice);
        getchar(); // 清除输入缓冲区

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
            printf("Exiting system. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice! Please enter 1-3.\n");
        }
    }
}

// 显示主服务菜单
void show_main_service_menu() {
    int choice;

    while (is_logged_in) {
        printf("\n==================== Main Service ====================\n");
        printf("1. Manage friends\n");
        printf("2. Manage messages\n");
        printf("3. Back \n");
        printf("======================================================\n");
        printf("Choose an option (1-3): ");
        scanf("%d", &choice);
        getchar(); // 清除输入缓冲区

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
            printf("Invalid choice! Please enter 1-3.\n");
        }
    }
}

// 显示好友管理菜单
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
        getchar(); // 清除输入缓冲区

        switch (choice) {
        case 1:
            // add_friend_function();
            printf("Add friend function will be implemented here.\n");
            break;
        case 2:
            // accept_friend_request_function();
            printf("Accept friend request function will be implemented here.\n");
            break;
        case 3:
            // delete_friend_function();
            printf("Delete friend function will be implemented here.\n");
            break;
        case 4:
            // show_friends_function();
            printf("Show friends function will be implemented here.\n");
            break;
        case 5:
            return;
        default:
            printf("Invalid choice! Please enter 1-5.\n");
        }
    }
}

// 显示消息管理菜单
void show_message_management_menu() {
    int choice;

    while (is_logged_in) {
        printf("\n  ==================== Manage Messages ====================\n");
        printf("1. Send a message\n");
        printf("2. Read messages\n");
        printf("1. Send a message\n");
        printf("4. Back\n");
        printf(" =========================================================\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);
        getchar(); // 清除输入缓冲区

        switch (choice) {
        case 1:
            // send_message_function();
            printf("Send message function will be implemented here.\n");
            break;
        case 2:
            // read_messages_function();
            printf("Read messages function will be implemented here.\n");
            break;
        case 3:
            // delete_message_function();
            printf("Delete message function will be implemented here.\n");
            break;
        case 4:
            return;
        default:
            printf("Invalid choice! Please enter 1-4.\n");
        }
    }
}

// 用户注册函数
void register_user() {
    char username[MAX_USERNAME];
    char password1[MAX_PASSWORD];
    char password2[MAX_PASSWORD];

    printf("\n===================Registration ===================\n");

    // 输入用户名
    printf("Enter username (no spaces): ");
    fgets(username, MAX_USERNAME, stdin);
    username[strcspn(username, "\n")] = 0; // 移除换行符

    // 这里应该检查用户名是否已存在
    // check_username_exists(username);

    // 输入密码
    printf("Enter password: ");
    fgets(password1, MAX_PASSWORD, stdin);
    password1[strcspn(password1, "\n")] = 0;

    printf("Confirm password: ");
    fgets(password2, MAX_PASSWORD, stdin);
    password2[strcspn(password2, "\n")] = 0;

    // 检查两次密码是否相同
    if (strcmp(password1, password2) == 0) {
        // 这里应该保存用户信息到文件
        // save_user_to_file(username, password1);
        printf("Registration successful! You can now login.\n");
    }
    else {
        printf("Error: Passwords do not match! Registration failed.\n");
    }
}

// 用户登录函数
int login_user() {
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];

    printf("\n==================== Login ====================\n");
    printf("Username: ");
    fgets(username, MAX_USERNAME, stdin);
    username[strcspn(username, "\n")] = 0;

    printf("Password: ");
    fgets(password, MAX_PASSWORD, stdin);
    password[strcspn(password, "\n")] = 0;

    // 这里应该验证用户名和密码
    // int result = verify_credentials(username, password);

    // 临时模拟登录成功
    int result = 1; // 假设验证成功

    if (result) {
        strcpy(current_user.username, username);
        strcpy(current_user.password, password);
        current_user.friend_count = 0;
        current_user.pending_count = 0;
        is_logged_in = 1;
        printf("Login successful! Welcome %s!\n", username);
        return 1;
    }
    else {
        printf("Login failed! Invalid username or password.\n");
        return 0;
    }
}

// 用户登出函数
void logout_user() {
    is_logged_in = 0;
    memset(&current_user, 0, sizeof(User));
    printf("You have been logged out.\n");
}
