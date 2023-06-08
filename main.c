#include "menu.h"
#include "utilities.h"
#include <stdio.h>
#include <string.h>

int main() {
    // Declare an integer variable "choice" to store the user's choice
    int choice;

    // Start a do-while loop to display the main menu and accept user input
    do {
        // Call the main menu function to display the menu
        main_menu();

        // Prompt the user to enter their choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Use a switch statement to handle the user's choice
        switch (choice) {
            // Case 1: Call the "insert_new_user" function
            case 1:
                insert_new_user();
                break;

                // Case 2: Call the "list_users" function
            case 2:
                list_users();
                break;

                // Case 3: Handle user searching
            case 3: {
                char name[50]; // Declare a character array "name" with a size of 50
                printf("Enter your name: ");
                getchar(); // Consume the newline character from the input buffer
                fgets(name, sizeof(name), stdin); // Read user input into the "name" array
                name[strcspn(name, "\n")] = 0; // Remove newline character from the input

                // Call "get_user_by_name" function and store its result in a User pointer
                User *user = get_user_by_name(name);

                // Check if the user was found
                if (user != NULL) {
                    // Call the "user_menu" function if the user was found
                    user_menu(user);
                } else {
                    // Print an error message if the user was not found
                    printf("User not found.\n");
                }
                break;
            }

                // Case 4: Exit the program
            case 4:
                printf("Goodbye!\n");
                break;

                // Default case: Handle invalid input
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4); // Continue looping until the user chooses to exit (choice = 4)

    return 0; // Return 0 to indicate successful program execution
}