#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the user struct
typedef struct User {
    char name[50];
    int age;
    char email[50];
    char location[50];
    char preferences[5][50];
    struct User* friends[100];
    int num_friends;
    struct User* pending_requests[100];
    int num_pending_requests;
} User;

// Declare global variables
User users[100];
int num_users = 0;

// Declare function to load users from CSV file
void load_users() {
    FILE* fp = fopen("users.csv", "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        char* name = strtok(line, ",");
        int age = atoi(strtok(NULL, ","));
        char* email = strtok(NULL, ",");
        char* location = strtok(NULL, ",");
        char* preferences_str = strtok(NULL, ",");
        char* preference = strtok(preferences_str, "|");
        char preferences[5][50];
        int i = 0;
        while (preference != NULL) {
            strcpy(preferences[i], preference);
            preference = strtok(NULL, "|");
            i++;
        }
        User user = {0};
        strcpy(user.name, name);
        user.age = age;
        strcpy(user.email, email);
        strcpy(user.location, location);
        memcpy(user.preferences, preferences, sizeof(preferences));
        users[num_users] = user;
        num_users++;
    }
    fclose(fp);
}

// Declare function to search for a user by name
User* search_user(char* name) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].name, name) == 0) {
            return &users[i];
        }
    }
    return NULL;
}

// Declare function to add a friend
void add_friend(User* user) {
    char friend_name[50];
    printf("Enter the name of the person you want to add as a friend: ");
    scanf("%s", friend_name);
    User* friend = search_user(friend_name);
    if (friend == NULL) {
        printf("User not found.\n");
        return;
    }
    user->pending_requests[user->num_pending_requests] = friend;
    user->num_pending_requests++;
    printf("Friend request sent to %s\n", friend->name);
}

// Declare function to connect with strangers
void connect_with_strangers(User* user) {
    User* strangers[3];
    for (int i = 0; i < 3; i++) {
        int index = rand() % num_users;
        User* stranger = &users[index];
        while (stranger == user || strstr(stranger->preferences[0], user->preferences[0]) == NULL) {
            index = rand() % num_users;
            stranger = &users[index];
        }
        strangers[i] = stranger;
    }
    for (int i = 0; i < 3; i++) {
        user->pending_requests[user->num_pending_requests] = strangers[i];
        user->num_pending_requests++;
        printf("Friend request sent to %s\n", strangers[i]->name);
    }
}

// Declare function to list friends
void list_friends(User* user) {
    printf("List of friends:\n");
    for (int i = 0; i < user->num_friends; i++) {
        printf("%s\n", user->friends[i]->name);
    }
}

// Declare function to list posts
void list_posts(User* user) {
    // TODO: implement function to list posts
}

// Declare function to operate as a specific user
void operate_user() {
    printf("\nList of all registered users:\n");
    for (int i = 0; i < num_users; i++) {
        printf("%d %s\n", i+1, users[i].name);
    }
    int user_choice;
    printf("Enter the user number you want to operate as: ");
    scanf("%d", &user_choice);

    // Check if user choice is valid
    if (user_choice < 1 || user_choice > num_users) {
        printf("Invalid choice. Please try again.\n");
        return;
    }

    // Display submenu options
    User* user = &users[user_choice-1];
    int sub_choice = 0;
    while (sub_choice != 5) {
        printf("\n\nOperating as %s\n", user->name);
        printf("1. List friends\n");
        printf("2. Add new friend\n");
        printf("3. Connect with strangers\n");
        printf("4. List posts\n");
        printf("5. Return to the main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &sub_choice);

        // Call the appropriate function based on user choice
        switch (sub_choice) {
            case 1:
                list_friends(user);
                break;
            case 2:
                add_friend(user);
                break;
            case 3:
                connect_with_strangers(user);
                break;
            case 4:
                list_posts(user);
                break;
            case 5:
                printf("Returning to main menu...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}

int main() {
    srand(time(NULL));

    // Load users from CSV file
    load_users();

    // Display menu options
    int choice = 0;
    while (choice != 4) {
        printf("\n\nSocial Network Menu\n");
        printf("1. Insert a new user\n");
        printf("2. List all existing users\n");
        printf("3. Operate as a specific user\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Call the appropriate function based on user choice
        switch (choice) {
            case 1: {
                // Prompt user to enter user details
                printf("\nInsert a new user\n");
                User user = {0};
                printf("Enter name: ");
                scanf("%s", user.name);
                printf("Enter age: ");
                scanf("%d", &user.age);
                printf("Enter email: ");
                scanf("%s", user.email);
                printf("Enter location: ");
                scanf("%s", user.location);
                printf("Enter 5 preferences (separated by commas): ");
                for (int i = 0; i < 5; i++) {
                    scanf("%s", user.preferences[i]);
                }
                users[num_users] = user;
                num_users++;
                printf("User added successfully!\n");
                break;

            }
            case 2:
                printf("\nList of all registered users:\n");
                for (int i = 0; i < num_users; i++) {
                    printf("%d %s\n", i+1, users[i].name);
                }
                break;
            case 3:
                operate_user();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}







