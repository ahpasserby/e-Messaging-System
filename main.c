#include "common.h"
#include "file_operations.h"
#include "menu_interface.h"

// 初始化系统
void initialize_system() {
    // 加载用户数据
    load_users();
    // 加载好友关系
    load_friends();
}

// 主函数
int main() {
    // 初始化系统
    initialize_system();
    
    printf("欢迎使用电子消息系统！\n");
    
    // 主循环
    while (1) {
        display_login_menu();
    }
    
    return 0;
}
