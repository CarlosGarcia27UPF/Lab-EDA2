#include "user.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Declare an array of User structs and an integer to keep track of the user count
User users[MAX_USERS];
int user_count = 0;

// Function to create a new user with given details
User create_user(const char *name, int age, const char *email, const char *location, const char *preferences[5]) {
    User user;
    strcpy(user.name, name);
    user.age = age;
    strcpy(user.email, email);
    strcpy(user.location, location);

    // Copy the preferences into the user struct
    for (int i = 0; i < 5; i++) {
        strcpy(user.preferences[i], preferences[i]);
    }

    // Initialize other user properties
    user.num_friend_requests = 0;
    user.num_friends = 0;
    user.num_posts = 0;

    return user;
}

// Function to add a user to the users array, returns true if successful
bool add_user(User user) {
    if (user_count < MAX_USERS) {
        users[user_count++] = user;
        return true;
    }
    return false;
}

// Function to display all users in the users array
void display_users() {
    for (int i = 0; i < user_count; i++) {
        printf("User %d:\n", i + 1);
        printf("Name: %s\n", users[i].name);
        printf("Age: %d\n", users[i].age);
        printf("Email: %s\n", users[i].email);
        printf("Location: %s\n", users[i].location);
        printf("Preferences:\n");
        for (int j = 0; j < 5; j++) {
            printf("\t%s\n", users[i].preferences[j]);
        }
        printf("\n");
    }
}

// Function to get a user by name, returns a pointer to the user if found
User *get_user_by_name(const char *name) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].name, name) == 0) {
            return &users[i];
        }
    }
    return NULL;
}

// Function to send a friend request from one user to another, returns true if successful
bool send_friend_request(User *from_user, User *to_user) {
    // Check for invalid inputs
    if (from_user == NULL || to_user == NULL || from_user == to_user) {
        return false;
    }

    // Add the friend request if possible
    if (to_user->num_friend_requests < MAX_USERS) {
        to_user->friend_requests[to_user->num_friend_requests++] = from_user - users;
        return true;
    }

    return false;
}

// Function to accept a friend request between two users, returns true if successful
bool accept_friend_request(User *from_user, User *to_user) {
    // Check for invalid inputs
    if (from_user == NULL || to_user == NULL || from_user == to_user) {
        return false;
    }

    int from_user_index = from_user - users;
    int to_user_index = to_user - users;

    // Check if there is a friend request from from_user to to_user
    bool request_found = false;
    for (int i = 0; i < to_user->num_friend_requests; i++) {
        if (to_user->friend_requests[i] == from_user_index) {
            request_found = true;
            // Remove friend request
            for (int j = i; j < to_user->num_friend_requests - 1; j++) {
                to_user->friend_requests[j] = to_user->friend_requests[j + 1];
            }
            to_user->num_friend_requests--;
            break;
        }
    }

    // Return false if no friend request found
    if (!request_found) {
        return false;
    }

    // Add each other as friends if possible
    if (from_user->num_friends < MAX_FRIENDS && to_user->num_friends < MAX_FRIENDS) {
        from_user->friends[from_user->num_friends++] = to_user_index;
        to_user->friends[to_user->num_friends++] = from_user_index;
        return true;
    }

    return false;
}

// Function to add a post for a user, returns true if successful
bool add_post(User *user, const char *content) {
    if (user == NULL || user->num_posts >= MAX_POSTS) {
        return false;
    }

    Post new_post;
    strncpy(new_post.content, content, sizeof(new_post.content) - 1);
    new_post.content[sizeof(new_post.content) - 1] = '\0';

    user->posts[user->num_posts++] = new_post;
    return true;
}

// Function to display the posts of a user
void display_posts(const User *user) {
    if (user == NULL) {
        return;
    }

    printf("%s's posts:\n", user->name);
    for (int i = 0; i < user->num_posts; i++) {
        printf("%d. %s\n", i + 1, user->posts[i].content);
    }
    printf("\n");
}