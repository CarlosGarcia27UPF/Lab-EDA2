#include "utilities.h"
#include <stdio.h>
#include <string.h>

void insert_new_user() {
    char name[50];
    int age;
    char email[50];
    char location[50];
    char preferences[5][50];

    printf("Enter name: ");
    getchar(); // To consume the newline character from the input buffer
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline character from the input

    printf("Enter age: ");
    scanf("%d", &age);

    printf("Enter email: ");
    getchar(); // To consume the newline character from the input buffer
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = 0; // Remove newline character from the input

    printf("Enter location: ");
    fgets(location, sizeof(location), stdin);
    location[strcspn(location, "\n")] = 0; // Remove newline character from the input

    printf("Enter 5 preferences:\n");
    for (int i = 0; i < 5; i++) {
        fgets(preferences[i], sizeof(preferences[i]), stdin);
        preferences[i][strcspn(preferences[i], "\n")] = 0; // Remove newline character from the input
    }
    const char *prefs[5] = {preferences[0], preferences[1], preferences[2], preferences[3], preferences[4]};
    User new_user = create_user(name, age, email, location, prefs);

    if (add_user(new_user)) {
        printf("New user added successfully!\n");
    } else {
        printf("Failed to add new user. User limit reached.\n");
    }
}

void list_users() {
    display_users();
}

void user_menu(User *user) {
    int choice;

    do {
        printf("\n--- %s's Menu ---\n", user->name);
        printf("1. Send friend request\n");
        printf("2. Accept friend request\n");
        printf("3. Add post\n");
        printf("4. View posts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[50];
                printf("Enter the name of the user to send a friend request to: ");
                getchar(); // To consume the newline character from the input buffer
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character from the input
                User *to_user = get_user_by_name(name);

                if (send_friend_request(user, to_user)) {
                    printf("Friend request sent successfully!\n");
                } else {
                    printf("Failed to send friend request.\n");
                }
                break;
            }
            case 2: {
                char name[50];
                printf("Enter the name of the user to accept a friend request from: ");
                getchar(); // To consume the newline character from the input buffer
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character from the input
                User *from_user = get_user_by_name(name);

                if (accept_friend_request(from_user, user)) {
                    printf("Friend request accepted!\n");
                } else {
                    printf("Failed to accept friend request.\n");
                }
                break;
            }
            case 3: {
                char content[200];
                printf("Enter post content: ");
                getchar(); // To consume the newline character from the input buffer
                fgets(content, sizeof(content), stdin);
                content[strcspn(content, "\n")] = 0; // Remove newline character from the input

                if (add_post(user, content)) {
                    printf("Post added successfully!\n");
                } else {
                    printf("Failed to add post.\n");
                }
                break;
            }
            case 4:
                display_posts(user);
                break;
            case 5:
                printf("Returning to main menu...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}

