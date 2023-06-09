#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "social_network.h"
#include "color.h"

// Function to create a new user with user's input
User* create_user() {
    // Allocate memory for a new user and initialize user's data
    User *user = (User *) malloc(sizeof(User));

    // Request user input for user's details
    set_color(MAGENTA);
    printf("Enter user name: ");
    scanf("%s", user->name);
    printf("Enter age: ");
    scanf("%d", &user->age);
    printf("Enter email: ");
    scanf("%s", user->email);
    printf("Enter location: ");
    scanf("%s", user->location);

    // Request user input for user's preferences
    printf("Enter 5 preferences:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%s", user->preferences[i]);
    }
    set_color(WHITE);

    // Initialize user's lists to NULL
    user->posts = NULL;
    user->friends = NULL;
    user->received_requests = NULL;
    user->next = NULL;

    return user;
}

// Function to insert a new user into a sorted linked list of users
void insert_user(User **head, User *new_user) {
    // Insert the new user at the head or in the middle of the list
    if (*head == NULL || strcmp(new_user->name, (*head)->name) < 0) {
        new_user->next = *head;
        *head = new_user;
    } else {
        User *current = *head;
        while (current->next != NULL && strcmp(new_user->name, current->next->name) > 0) {
            current = current->next;
        }
        new_user->next = current->next;
        current->next = new_user;
    }
}

// Function to display all registered users
void display_users(User *head) {
    set_color(CYAN);
    printf("\nRegistered Users:\n");
    set_color(MAGENTA);
    while (head != NULL) {
        printf("%s\n", head->name);
        head = head->next;
    }
    set_color(WHITE);
}

// Function to search for a user by username
User* search_user(User *head, const char *username) {
    while (head != NULL && strcmp(head->name, username) != 0) {
        head = head->next;
    }
    return head;
}

// Function to send a friend request from sender to receiver
void friend_request(User *sender, User *receiver) {
    FriendRequest *request = (FriendRequest *) malloc(sizeof(FriendRequest));
    request->user = sender;
    request->next = receiver->received_requests;
    receiver->received_requests = request;
}

// Function to manage friend requests for a user
void manage_requests(User *user) {
    FriendRequest *current = user->received_requests;
    while (current != NULL) {
        printf("\nFriend request from %s. Accept?(y/n): ", current->user->name);
        char response;
        scanf(" %c", &response);
        if (response == 'y' || response == 'Y') {
            User *friend = current->user;
            friend->next = user->friends;
            user->friends = friend;
            set_color(GREEN);
            printf("\nFriend request accepted!");
            set_color(WHITE);
        }
        if (response == 'n' || response == 'N') {
            set_color(RED);
            printf("\nFriend request rejected");
            set_color(WHITE);
        }

        FriendRequest *temp = current;
        current = current->next;
        free(temp);
    }
    user->received_requests = NULL;
}

// Function to create a new post for a user
void make_post(User *user, const char *text) {
    Post *new_post = (Post *) malloc(sizeof(Post));
    strncpy(new_post->text, text, 120);
    new_post->text[120] = '\0';
    new_post->next = user->posts;
    user->posts = new_post;
}

// Function to list all posts by a user
void list_posts(User *user) {
    printf("\nPosts by %s:\n", user->name);
    Post *post = user->posts;
    while (post != NULL) {
        printf("%s\n", post->text);
        post = post->next;
    }
}

// Function to count the occurrence of a word in a WordNode list
void count_word(WordNode **word_list, const char *word) {
    WordNode *current = *word_list;
    while (current != NULL && strcmp(current->word_count.word, word) != 0) {
        current = current->next;
    }
    if (current == NULL) {
        WordNode *new_node = (WordNode *) malloc(sizeof(WordNode));
        strncpy(new_node->word_count.word, word, 49);
        new_node->word_count.word[49] = '\0';
        new_node->word_count.count = 1;
        new_node->next = *word_list;
        *word_list = new_node;
    } else {
        current->word_count.count++;
    }
}

// Function to get the top most frequently used words from a WordNode linked list
WordNode* get_top_words(WordNode *word_list, int top) {
    WordNode *top_words = NULL; // Initialize an empty list for the top words

    // Iterate 'top' times or until the word_list is empty
    for (int i = 0; i < top && word_list != NULL; i++) {
        WordNode *max_node = NULL; // To store the node with the maximum count
        WordNode *current = word_list; // Pointer to traverse the word_list
        WordNode *prev = NULL; // To store the previous node while traversing
        WordNode *prev_max = NULL; // To store the previous node of the max_node

        // Traverse the word_list to find the max_node
        while (current != NULL) {
            if (max_node == NULL || current->word_count.count > max_node->word_count.count) {
                max_node = current;
                prev_max = prev;
            }
            prev = current;
            current = current->next;
        }

        // Remove the max_node from the word_list
        if (prev_max != NULL) {
            prev_max->next = max_node->next;
        } else {
            word_list = max_node->next;
        }

        // Add the max_node to the top_words list
        max_node->next = top_words;
        top_words = max_node;
    }

    return top_words;
}

// Function to display the top words along with their counts
void display_top_words(WordNode *top_words, int top) {
    printf("\nTop %d most frequently used words:\n", top);
    while (top_words != NULL) {
        printf("%s: %d times\n", top_words->word_count.word, top_words->word_count.count);
        top_words = top_words->next;
    }
}

// Function to free the memory allocated for a WordNode linked list
void free_word_list(WordNode *word_list) {
    while (word_list != NULL) {
        WordNode *temp = word_list;
        word_list = word_list->next;
        free(temp);
    }
}

// Function to free the memory allocated for a Post linked list
void free_posts(Post *head) {
    while (head != NULL) {
        Post *temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to free the memory allocated for a FriendRequest linked list
void free_friend_requests(FriendRequest *head) {
    while (head != NULL) {
        FriendRequest *temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to free the memory allocated for a User linked list
void free_users(User *head) {
    while (head != NULL) {
        User *temp = head;
        head = head->next;
        free_posts(temp->posts); // Free the posts linked list associated with the user
        free_friend_requests(temp->received_requests); // Free the friend requests linked list associated with the user
        free(temp);
    }
}