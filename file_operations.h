#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include "common.h"

// User data operations
void load_users_from_file();
void save_users_to_file();

// Friend relationship operations
void load_friends_from_file();
void save_friends_to_file();

// Message data operations
void load_messages_from_file(const char* username);
void save_messages_to_file(const char* username);
void save_single_message(Message* msg);

#endif
