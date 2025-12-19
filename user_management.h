#ifndef USER_MANAGEMENT_H
#define USER_MANAGEMENT_H

#include "common.h"

// Function declarations
void register_user();
int login_user();
void load_users();
void save_users();
int find_user_index(const char* username);

#endif
