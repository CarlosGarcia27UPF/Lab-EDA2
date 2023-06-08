#include "menu.h"
#include "utilities.h"
#include <stdio.h>
#include <string.h>

int main() {
    int choice;

    do {
        main_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_new_user();
                break;
            case 2:
                list_users();
                break;
            case 3: {
                char name[50];
                printf("Enter your name: ");
                getchar(); // To consume the newline character from the input buffer
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character from the input

                User *user = get_user_by_name(name);
                if (user != NULL) {
                    user_menu(user);
                } else {
                    printf("User not found.\n");
                }
                break;
            }
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}