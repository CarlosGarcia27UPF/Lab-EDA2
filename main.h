//
// Created by Oleh on 18.05.2023.
//

#ifndef UNTITLED1_MAIN_H
#define UNTITLED1_MAIN_H

#endif //UNTITLED1_MAIN_H

#include <stdio.h>

typedef struct user {
    char username[50];
    int age;
    char email[50];
    char location[50];
    char preferences[5][50];
} User;

int main();

__attribute__((unused)) int menu();
int insert_user();
int list_users();
int operate_user();
int send_friend_request();
int manage_friend_requests();
int make_post();
int list_user_posts();
