#include <stdbool.h>

// Define the Post structure, which represents a single post in the social network
typedef struct Post {
    char text[121];                // Text content of the post, limited to 120 characters
    struct Post *next;             // Pointer to the next post in a linked list of posts
} Post;

// Define the FriendRequest structure, which represents a friend request between users
typedef struct FriendRequest {
    struct User *user;             // Pointer to the sender of the friend request
    struct FriendRequest *next;    // Pointer to the next friend request in a linked list of requests
} FriendRequest;

// Define the User structure, which represents a user in the social network
typedef struct User {
    char name[50];                 // Name of the user, limited to 49 characters
    int age;                       // Age of the user
    char email[100];               // Email address of the user, limited to 99 characters
    char location[50];             // Location of the user, limited to 49 characters
    char preferences[5][50];       // Array of 5 preferences, each limited to 49 characters
    Post *posts;                   // Pointer to the head of a linked list of posts by the user
    struct User *friends;          // Pointer to the head of a linked list of the user's friends
    FriendRequest *received_requests; // Pointer to the head of a linked list of friend requests received by the user
    struct User *next;             // Pointer to the next user in a linked list of users
} User;

// Define the WordCount structure, which represents a word and its occurrence count
typedef struct {
    char word[50];                 // The word itself, limited to 49 characters
    int count;                     // The number of occurrences of the word
} WordCount;

// Define the WordNode structure, which represents a node in a linked list of WordCount objects
typedef struct WordNode {
    WordCount word_count;          // The WordCount object containing the word and its count
    struct WordNode *next;         // Pointer to the next WordNode in a linked list
} WordNode;

// Function prototypes for the social network

User* create_user();
void insert_user(User **head, User *new_user);
void display_users(User *head);
User* search_user(User *head, const char *username);
void friend_request(User *sender, User *receiver);
void manage_requests(User *user);
void make_post(User *user, const char *text);
void list_posts(User *user);
void count_word(WordNode **word_list, const char *word);
WordNode* get_top_words(WordNode *word_list, int top);
void display_top_words(WordNode *top_words, int top);
void free_word_list(WordNode *word_list);
void free_users(User *head);


