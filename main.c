#include <stdio.h>
#include <adoctint.h>
#include "main.h"

typedef struct user {
    char username[50];
    int age;
    char email[50];
    char location[50];
    char preferences[5][50];
} user;

int main() {
    user user;

    printf("Enter your username: ");
    scanf("%s", user.username);

    printf("Enter your age or year of birth: ");
    scanf("%d", &user.age);

    printf("Enter your email address: ");
    scanf("%s", user.email);

    printf("Enter your current location (city): ");
    scanf("%s", user.location);

    printf("Enter your 5 preferences, one per line:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%s", user.preferences[i]);
    }
}

void list_user_posts();

void make_post();

void manage_friend_requests();

void send_friend_request();

void insert_user();

void list_users();

void operate_user();

int menu() {

    int choice = 0;

    while (choice != 7) {
        printf("Select an option:\n");
        printf("1. Insert a new user\n");
        printf("2. List all existing users\n");
        printf("3. Operate as a specific user\n");
        printf("4. Send friend requests\n");
        printf("5. Manage pending requests\n");
        printf("6. Make a post\n");
        printf("7. List the posts of the selected user\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
                send_friend_request();
                break;
            case 5:
                manage_friend_requests();
                break;
            case 6:
                make_post();
                break;
            case 7:
                list_user_posts();
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

        printf("\n");
    }

    return 0;
}

void operate_user() {

}

void list_users() {

}

void insert_user() {

}

void send_friend_request() {

}

void manage_friend_requests() {

}

void make_post() {

}

void list_user_posts() {

}

typedef struct Node {
    user user;
    struct Node* next;
} Node;

void print_user(User user);

void add_user(Node** head, user user) {
    Node* new_node = malloc(sizeof(Node));
    new_node->user = user;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        Node* current_node = *head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

void list_users(Node* head) {
    Node* current_node = head;
    while (current_node != NULL) {
        print_user(current_node->user);
        printf("\n");
        current_node = current_node->next;
    }
}







