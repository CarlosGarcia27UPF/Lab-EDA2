#include "utilities.h"
#include <stdio.h>
#include <string.h>

// Function to insert a new user by taking input from the user
void insert_new_user() {
    char name[50];
    int age;
    char email[50];
    char location[50];
    char preferences[5][50];

    // Prompt user for input and read the input values
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

    // Add the new user and display the result
    if (add_user(new_user)) {
        printf("New user added successfully!\n");
    } else {
        printf("Failed to add new user. User limit reached.\n");
    }
}

// Function to display the list of users
void list_users() {
    display_users();
}

// Function to display a menu for a specific user and perform the selected actions
void user_menu(User *user) {
    int choice;

    // Display user menu and prompt for input until the user chooses to exit
    do {
        printf("\n--- %s's Menu ---\n", user->name);
        printf("1. Send friend request\n");
        printf("2. Accept friend request\n");
        printf("3. Add post\n");
        printf("4. View posts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the selected action based on the user's input
        switch (choice) {
            case 1: {
                char name[50];
                printf("Enter the name of the user to send a friend request to: ");
                getchar(); // To consume the newline character from the input buffer
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character from the input
                User *to_user = get_user_by_name(name);

                // Send a friend request and display the result
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

                // Accept a friend request and display the result
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

                // Add a post and display the result
                if (add_post(user, content)) {
                    printf("Post added successfully!\n");
                } else {
                    printf("Failed to add post.\n");
                }
                break;
            }
            case 4:
                // Display the user's posts
                display_posts(user);
                break;
            case 5:
                // Exit the user menu
                printf("Returning to main menu...\n");
                break;
            default:
                // Handle invalid input
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}