#include "file_operations.h"
#include "user_management.h"
#include "friend_management.h"
#include "message_management.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern User users[MAX_USERS];
extern int user_count;
extern char current_user[MAX_USERNAME_LEN];
extern Message messages[MAX_MESSAGES];
extern int message_count;

void load_users_from_file() {
    FILE* file = fopen("users.txt", "r");
    if (file == NULL) {
        user_count = 0;
        return;
    }
    
    user_count = 0;
    char line[256];
    
    while (fgets(line, sizeof(line), file) != NULL && user_count < MAX_USERS) {
        line[strcspn(line, "\n")] = 0;
        
        char* username = strtok(line, " ");
        char* password = strtok(NULL, " ");
        
        if (username != NULL && password != NULL) {
            strcpy(users[user_count].username, username);
            strcpy(users[user_count].password, password);
            users[user_count].friend_count = 0;
            users[user_count].pending_count = 0;
            user_count++;
        }
    }
    
    fclose(file);
}

void save_users_to_file() {
    FILE* file = fopen("users.txt", "w");
    if (file == NULL) {
        return;
    }
    
    for (int i = 0; i < user_count; i++) {
        fprintf(file, "%s %s\n", users[i].username, users[i].password);
    }
    
    fclose(file);
}

void load_friends_from_file() {
    FILE* file = fopen("friends.txt", "r");
    if (file == NULL) {
        return;
    }
    
    char line[1024];
    char current_username[MAX_USERNAME_LEN] = "";
    int current_user_idx = -1;
    
    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = 0;
        
        if (strstr(line, "FRIENDS:") != NULL) {
            if (current_user_idx != -1) {
                char* token = strtok(line + 9, " ");
                users[current_user_idx].friend_count = 0;
                
                while (token != NULL && users[current_user_idx].friend_count < MAX_FRIENDS) {
                    strcpy(users[current_user_idx].friends[users[current_user_idx].friend_count], token);
                    users[current_user_idx].friend_count++;
                    token = strtok(NULL, " ");
                }
            }
        } else if (strstr(line, "PENDING:") != NULL) {
            if (current_user_idx != -1) {
                char* token = strtok(line + 9, " ");
                users[current_user_idx].pending_count = 0;
                
                while (token != NULL && users[current_user_idx].pending_count < MAX_FRIENDS) {
                    strcpy(users[current_user_idx].pending_requests[users[current_user_idx].pending_count], token);
                    users[current_user_idx].pending_count++;
                    token = strtok(NULL, " ");
                }
            }
        } else {
            strcpy(current_username, line);
            current_user_idx = -1;
            
            for (int i = 0; i < user_count; i++) {
                if (strcmp(users[i].username, current_username) == 0) {
                    current_user_idx = i;
                    break;
                }
            }
        }
    }
    
    fclose(file);
}

void save_friends_to_file() {
    FILE* file = fopen("friends.txt", "w");
    if (file == NULL) {
        return;
    }
    
    for (int i = 0; i < user_count; i++) {
        fprintf(file, "%s\n", users[i].username);
        
        fprintf(file, "FRIENDS:");
        for (int j = 0; j < users[i].friend_count; j++) {
            fprintf(file, " %s", users[i].friends[j]);
        }
        fprintf(file, "\n");
        
        fprintf(file, "PENDING:");
        for (int j = 0; j < users[i].pending_count; j++) {
            fprintf(file, " %s", users[i].pending_requests[j]);
        }
        fprintf(file, "\n");
    }
    
    fclose(file);
}

void load_messages_from_file(const char* username) {
    char filename[MAX_FILENAME_LEN];
    snprintf(filename, sizeof(filename), "%s.txt", username);
    
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        message_count = 0;
        return;
    }
    
    message_count = 0;
    char line[512];
    Message current_msg;
    int reading_content = 0;
    
    while (fgets(line, sizeof(line), file) != NULL && message_count < MAX_MESSAGES) {
        line[strcspn(line, "\n")] = 0;
        
        if (line[0] == '[' && strstr(line, "] From: ") != NULL) {
            if (reading_content && message_count < MAX_MESSAGES) {
                // Set receiver and save message
                strcpy(current_msg.receiver, username);
                messages[message_count++] = current_msg;
            }
            
            // Find timestamp end position
            char* timestamp_end = strstr(line, "]");
            if (timestamp_end != NULL) {
                // Extract timestamp (without modifying original line)
                int timestamp_len = timestamp_end - (line + 1);
                strncpy(current_msg.timestamp, line + 1, timestamp_len);
                current_msg.timestamp[timestamp_len] = '\0';
                
                // Extract sender
                char* from_start = strstr(timestamp_end, "From: ");
                if (from_start != NULL) {
                    // Extract sender name (to space or end of line)
                    char* sender_end = strchr(from_start + 6, ' ');
                    if (sender_end != NULL) {
                        int sender_len = sender_end - (from_start + 6);
                        strncpy(current_msg.sender, from_start + 6, sender_len);
                        current_msg.sender[sender_len] = '\0';
                        
                        // Find "Read: " marker after sender
                        char* read_start = strstr(sender_end, "Read: ");
                        if (read_start != NULL) {
                            current_msg.is_read = atoi(read_start + 6);
                        } else {
                            current_msg.is_read = 0; // Default unread
                        }
                    } else {
                        // No space, entire remaining part is sender
                        strcpy(current_msg.sender, from_start + 6);
                        current_msg.is_read = 0; // Default unread
                    }
                }
            }
            
            reading_content = 1;
            current_msg.content[0] = '\0';
        } else if (reading_content) {
            if (current_msg.content[0] != '\0') {
                strcat(current_msg.content, "\n");
            }
            strcat(current_msg.content, line);
        }
    }
    
    if (reading_content && message_count < MAX_MESSAGES) {
        // Set receiver and save the last message
        strcpy(current_msg.receiver, username);
        messages[message_count++] = current_msg;
    }
    
    fclose(file);
}

void save_messages_to_file(const char* username) {
    char filename[MAX_FILENAME_LEN];
    snprintf(filename, sizeof(filename), "%s.txt", username);
    
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        return;
    }
    
    for (int i = 0; i < message_count; i++) {
        if (strcmp(messages[i].receiver, username) == 0) {
            fprintf(file, "[%s] From: %s Read: %d\n", messages[i].timestamp, messages[i].sender, messages[i].is_read);
            fprintf(file, "%s\n", messages[i].content);
        }
    }
    
    fclose(file);
}

void save_single_message(Message* msg) {
    char filename[MAX_FILENAME_LEN];
    snprintf(filename, sizeof(filename), "%s.txt", msg->receiver);
    
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        return;
    }
    
    fprintf(file, "[%s] From: %s Read: %d\n", msg->timestamp, msg->sender, msg->is_read);
    fprintf(file, "%s\n", msg->content);
    
    fclose(file);
}
