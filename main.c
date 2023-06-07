#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the user struct
typedef struct {
    char name[50];
    int age;
    char email[50];
    char location[50];
    char preferences[5][50];
    char posts[100][120];
    int num_posts;
} User;

// Declare global variables
User *users;
int num_users = 0;

// Declare function prototypes
void insert_user();
void list_users();
void operate_user();

int main() {
    int choice;
    users = malloc(sizeof(User));

    do {
        // Display menu options
        printf("\n\nSocial Network Menu\n");
        printf("1. Insert a new user\n");
        printf("2. List all existing users\n");
        printf("3. Operate as a specific user\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Call the appropriate function based on user choice
        switch(choice) {
            case 1:
                insert_user();
                break;
            case 2:
                list_users();
                break;
            case 3:
                operate_user();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    free(users);
    return 0;
}

void insert_user() {
    // Prompt user to enter user details
    printf("\nInsert a new user\n");
    printf("Enter name: ");
    scanf("%s", users[num_users].name);
    printf("Enter age: ");
    scanf("%d", &users[num_users].age);
    printf("Enter email: ");
    scanf("%s", users[num_users].email);
    printf("Enter location: ");
    scanf("%s", users[num_users].location);
    printf("Enter 5 preferences (separated by spaces): ");
    for (int i = 0; i < 5; i++) {
        scanf("%s", users[num_users].preferences[i]);
    }

    // Initialize the number of posts to 0
    users[num_users].num_posts = 0;

    // Increment the number of users and allocate memory for the new user
    num_users++;
    users = realloc(users, (num_users + 1) * sizeof(User));

    printf("User added successfully!\n");
}

void list_users() {
    printf("\nList of all registered users:\n");
    for (int i = 0; i < num_users; i++) {
        printf("User %d:\n", i+1);
        printf("Name: %s\n", users[i].name);
        printf("Age: %d\n", users[i].age);
        printf("Email: %s\n", users[i].email);
        printf("Location: %s\n", users[i].location);
        printf("Preferences: ");
        for (int j = 0; j < 5; j++) {
            printf("%s ", users[i].preferences[j]);
        }
        printf("\n");
    }
}

void operate_user() {
    int user_choice;
    printf("\nList of all registered users:\n");
    for (int i = 0; i < num_users; i++) {
        printf("%d. %s\n", i+1, users[i].name);
    }
    printf("Enter the user number you want to operate as: ");
    scanf("%d", &user_choice);

    // Check if user choice is valid
    if (user_choice < 1 || user_choice > num_users) {
        printf("Invalid choice. Please try again.\n");
        return;
    }

    // Display submenu options
    int sub_choice;
    do {
        printf("\n\nOperating as %s\n", users[user_choice-1].name);
        printf("1. Send friend request\n");
        printf("2. Manage pending requests\n");
        printf("3. Make a post\n");
        printf("4. List the posts of the selected user\n");
        printf("5. Return to the main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &sub_choice);

        // Call the appropriate function based on user choice
        switch(sub_choice) {
            case 1:
                printf("Friend request sent!\n");
                break;
            case 2:
                printf("Pending requests managed!\n");
                break;
            case 3:
                // Prompt user to enter post
                printf("Enter your post (limited to 120 characters): ");
                scanf("%s", users[user_choice-1].posts[users[user_choice-1].num_posts]);
                users[user_choice-1].num_posts++;

                printf("Post made successfully!\n");
                break;
            case 4:
                printf("List of posts:\n");
                for (int i = 0; i < users[user_choice-1].num_posts; i++) {
                    printf("%d. %s\n", i+1, users[user_choice-1].posts[i]);
                }
                break;
            case 5:
                printf("Returning to main menu...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (sub_choice != 5);
}

int partition(User arr[], int low, int high) {
    char pivot[50];
    strcpy(pivot, arr[high].name);
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (strcmp(arr[j].name, pivot) < 0) {
            i++;
            User temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    User temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(User arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}



void search_user() {
    char username[50];
    printf("Enter the username you want to search for: ");
    scanf("%s", username);
    quickSort(users, 0, num_users - 1);
    int low = 0;
    int high = num_users - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (strcmp(users[mid].name, username) == 0) {
            operate_user(mid);
            return;
        } else if (strcmp(users[mid].name, username) < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("User not found.\n");
}

void operate_user(int user_choice) {
    // Display submenu options
    int sub_choice;
    do {
        printf("\n\nOperating as %s\n", users[user_choice].name);
        printf("1. Send friend request\n");
        printf("2. Manage pending requests\n");
        printf("3. Make a post\n");
        printf("4. List the posts of the selected user\n");
        printf("5. Return to the main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &sub_choice);

        // Call the appropriate function based on user choice
        switch(sub_choice) {
            case 1:
                printf("Friend request sent!\n");
                break;
            case 2:
                printf("Pending requests managed!\n");
                break;
            case 3:
                // Prompt user to enter post
                printf("Enter your post (limited to 120 characters): ");
                scanf("%s", users[user_choice].posts[users[user_choice].num_posts]);
                users[user_choice].num_posts++;

                printf("Post made successfully!\n");
                break;
            case 4:
                printf("List of posts:\n");
                for (int i = 0; i < users[user_choice].num_posts; i++) {
                    printf("%d. %s\n", i+1, users[user_choice].posts[i]);
                }
                break;
            case 5:
                printf("Returning to main menu...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (sub_choice != 5);
}









