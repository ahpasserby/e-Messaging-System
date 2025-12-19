#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

// Maximum constant definitions
#define MAX_USERS 100
#define MAX_FRIENDS 50
#define MAX_MESSAGES 1000
#define MAX_USERNAME_LEN 50
#define MAX_PASSWORD_LEN 50
#define MAX_MESSAGE_LEN 255
#define MAX_FILENAME_LEN 100

// User structure
typedef struct {
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
    char friends[MAX_FRIENDS][MAX_USERNAME_LEN];
    char pending_requests[MAX_FRIENDS][MAX_USERNAME_LEN];
    int friend_count;
    int pending_count;
} User;

// Message structure
typedef struct {
    char sender[MAX_USERNAME_LEN];
    char receiver[MAX_USERNAME_LEN];
    char content[MAX_MESSAGE_LEN];
    char timestamp[20];
    int is_read;
} Message;

// Global variable declarations
extern User users[MAX_USERS];
extern int user_count;
extern char current_user[MAX_USERNAME_LEN];

#endif // COMMON_H
