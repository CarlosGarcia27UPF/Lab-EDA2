#ifndef USER_H
#define USER_H

#include <stdbool.h>

#define MAX_FRIENDS 100
#define MAX_POSTS 100
#define MAX_USERS 100

typedef struct Post {
    char content[200];
} Post;

typedef struct User {
    char name[50];
    int age;
    char email[50];
    char location[50];
    char preferences[5][50];
    int friend_requests[MAX_USERS];
    int num_friend_requests;
    int friends[MAX_FRIENDS];
    int num_friends;
    Post posts[MAX_POSTS];
    int num_posts;
} User;

User create_user(const char *name, int age, const char *email, const char *location, const char *preferences[5]);
bool add_user(User user);
void display_users();
User *get_user_by_name(const char *name);
bool send_friend_request(User *from_user, User *to_user);
bool accept_friend_request(User *from_user, User *to_user);
bool add_post(User *user, const char *content);
void display_posts(const User *user);

#endif // USER_H