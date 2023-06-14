#include <stdio.h>
#include <string.h>
#include <time.h>
#include "social_network.h"
#include "color.h"

int main() {
    // Initialize user and word lists
    User *users = NULL;
    WordNode *word_list = NULL;

    // Variables for measuring execution time
    clock_t start, end;
    double cpu_time_used;

    int choice;
    // Main loop for menu-driven program
    do {
        // Display main menu
        set_color(CYAN);
        printf("\n-----------Menu-----------\n");
        set_color(YELLOW);
        printf("1. Insert a new user\n");
        printf("2. List all existing users\n");
        printf("3. Operate as a specific user\n");
        printf("4. Top 3 most frequently used words\n");
        set_color(RED);
        printf("5. Exit\n");
        set_color(WHITE);
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handle main menu choices
        switch (choice) {
            case 1: {
                // Create and insert a new user
                User *new_user = create_user();
                insert_user(&users, new_user);
                break;
            }
            case 2:
                // Measure and display execution time for displaying users
                start = clock();
                display_users(users);
                end = clock();
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                set_color(BLUE);
                printf("\nIt took %f seconds to display all the registered users\n", cpu_time_used);
                set_color(WHITE);
                break;
            case 3: {
                // Search for a specific user
                char username[50];
                printf("Enter the username: ");
                scanf("%s", username);
                User *user = search_user(users, username);
                // Measure and display execution time for searching users
                start = clock();
                search_user(users, username);
                end = clock();
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                set_color(BLUE);
                printf("\nIt took %f seconds to find the user\n", cpu_time_used);
                set_color(WHITE);
                // If the user is not found, display an error message and break
                if (user == NULL) {
                    set_color(RED);
                    printf("User not found.\n");
                    set_color(WHITE);
                    break;
                }

                int sub_choice;
                // Submenu loop for operating as a specific user
                do {
                    // Display user-specific submenu
                    set_color(CYAN);
                    printf("\n-----------%s's submenu-----------\n", user->name);
                    set_color(YELLOW);
                    printf("1. Send friend request\n");
                    printf("2. Manage pending requests\n");
                    printf("3. Make a post\n");
                    printf("4. List the posts of the selected user\n");
                    set_color(RED);
                    printf("5. Return to the main menu\n");
                    set_color(WHITE);
                    printf("Enter your choice: ");
                    scanf("%d", &sub_choice);

                    // Handle user-specific submenu choices
                    switch (sub_choice) {
                        case 1: {
                            // Send a friend request to another user
                            char friend_username[50];
                            printf("Enter the friend's username: ");
                            scanf("%s", friend_username);

                            User *friend_user = search_user(users, friend_username);
                            if (friend_user == NULL) {
                                set_color(RED);
                                printf("Friend user not found.\n");
                                set_color(WHITE);
                            } else {
                                friend_request(user, friend_user);
                                set_color(GREEN);
                                printf("Friend request has been sent!\n");
                                set_color(WHITE);
                            }
                            break;
                        }
                        case 2:
                            // Manage pending friend requests for the user
                            printf("Pending requests:\n");
                            manage_requests(user);
                            break;
                        case 3: {
                            // Make a post as the user
                            char text[121];
                            printf("Enter the post text: ");
                            scanf(" %[^\n]s", text);
                            make_post(user, text);
                            set_color(GREEN);
                            printf("Post made successfully!!\n");
                            set_color(WHITE);

                            // Update the global word list with words from the post
                            char *word = strtok(text, " ");
                            while (word != NULL) {
                                count_word(&word_list, word);
                                word = strtok(NULL, " ");
                            }
                            break;
                        }
                        case 4:
                            // List the user's posts
                            printf("Posts:\n");
                            list_posts(user);
                            break;
                        case 5:
                            // Return to the main menu
                            set_color(RED);
                            printf("Returning...");
                            set_color(WHITE);

                            break;
                        default:
                            set_color(RED);
                            printf("Invalid choice.\n");
                            set_color(WHITE);
                    }
                } while (sub_choice != 5);

                break;
            }
            case 4: {
                // Display the top 3 most frequently used words
                WordNode *top_words = get_top_words(word_list, 3);
                // Measure and display execution time for displaying top words
                start = clock();
                display_top_words(top_words, 3);
                end = clock();
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                set_color(BLUE);
                printf("\nIt took %f seconds to display the most used words\n", cpu_time_used);
                set_color(WHITE);
                break;
            }
            case 5:
                // Exit the program
                set_color(RED);
                printf("Exiting...\n");
                set_color(WHITE);
                break;
            default:
                // Display an error message for invalid input
                set_color(RED);
                printf("Invalid choice.\n");
                set_color(WHITE);
        }
    } while (choice != 5);

    // Free memory for the word_list and users lists
    free_word_list(word_list);
    free_users(users);

    return 0;
}
