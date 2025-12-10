#ifndef FRIEND_MANAGER_H
#define FRIEND_MANAGER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNT_LENGTH 50
#define MAX_FRIENDS 100

typedef struct {
    char accounts[MAX_FRIENDS][MAX_ACCOUNT_LENGTH];
    int count;
} FriendList;

typedef struct {
    FriendList friends;
    FriendList waiting_to_confirm;
} User;

void manage_friends(User* user);
void add_friend_function(User* user);
void accept_friend_request_function(User* user);
void delete_friend_function(User* user);
void show_friends_function(const User* user);
void save_user_to_file(const User* user, const char* filename);
void load_user_from_file(User* user, const char* filename);

#endif
