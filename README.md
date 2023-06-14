Report

TABLE OF CONTENTS:
Introduction
Objectives
Mandatory objectives met
Desirable objectives met
Exploratory objectives met
System architecture
Error handling
Data model design
Dataset processing
Improvements
References

INTRODUCTION
This project implements the basic functionality of a text-based social network where users can register, send friend requests, make posts, and see the most commonly used words in posts. The main objectives are to effectively manage user accounts, handle friend requests between users, create and store user posts in a memory efficient way, and analyze word popularity in posts. The chosen data structures for storing data are linked lists for users, posts, friend requests, and word frequency counts.

OBJECTIVES

Manage User Accounts
Overview: Each user has a name, age, email address, location, and 5 preferences stored as strings. Users are stored in a sorted linked list with their name as the sorting key. A binary search-like approach is used when inserting a new user to achieve O(n) time complexity.
Variables: name, age, email, location, preferences arrays
Data Structures: User linked list
Algorithm: Binary search insertion
Performance: O(n) time
Limitations: Search is linear
Improvements: Use a self-balancing binary search tree

Time Taken: 30 minutes
Location: insert_user() in social_network.c

Handle Friend Requests
Overview: Friend requests are stored in linked lists attached to each user. When a user makes a request, a FriendRequest node is added to the recipient's linked list. From the recipient's menu, requests can be accepted, in which case the sender is added as a friend, or rejected and the request node is freed.
Variables: sender, recipient
Data Structures: FriendRequest linked list per user
Algorithm: Linear search and add/remove nodes
Performance: O(n) time
Limitations: Linear time search
Improvements: Use hash table

Time Taken: 1 hour
Location: friend_request() and manage_requests() in social_network.c

Store and List User Posts
Overview: Each post has up to 120 characters of text. Posts are stored in linked lists, with one list per user. When a user makes a new post, a Post node is added to the front of their linked list. All posts by a user can be listed by traversing their post linked list.
Variables: post text
Data Structures: Post linked list per user
Algorithm: Add node to front, linear traversal
Performance: O(1) and O(n)
Limitations: Wastes space at front of list
Improvements: Add to end, search from end

Time Taken: 1 hour
Location: make_post() and list_posts() in social_network.c

Analyze Popular Words
Overview: Each unique word and its count are stored in a WordNode. To find the most common words, the WordNode list is traversed and the node with the highest count identified. The count for that node is then reset to 0 and the process repeated for the next highest words, up to the requested number of words.
Variables: word, count
Data Structures: WordNode linked list
Algorithm: Find max, reset count
Performance: O(n2) time
Limitations: Inefficient finding max
Improvements: Use heap

Time Taken: 2 hours
Location: count_word(), most_common_words() in social_network.c

Mandatory objectives met:
We have implemented a dynamic list to save our registered users.
We have implemented a linear search algorithm to search for a specific user to operate with when the person types that user.
We have implemented a Insertion Sort algorithm in the list of registered users to sort the users by alphabetical order so that when all registered users are displayed they are ordered.
We have implemented a dictionary so that all the posts that users post go through the dictionary and in that way we can display the top 3 most used words in all posts.
We have commented on all important parts of the code so it's easy to understand.
We have used github to share the code between the members of the group.


Desirable objectives met:
We have measured the time it takes for multiple functions to be executed these functions are: display_users(), seach_users and the display_top_words.

Exploratory objectives met:
We have made the menu more aesthetically pleasing buy adding lines and colors to the text of the menu, this way the different options are easier to distinguish and feel more natural like the fact that the exit option, the reject friend request  and errors are displayed in a red color meanwhile messages like the friend request was accepted are displayed in green.

Solution:

System Architecture
The system has 3 main modules:

User Manager - Handles all operations related to users. It stores users in a sorted linked list using names as keys. It can search, insert, display, and send/receive friend requests for users. It notifies the Post Manager when a new post is made.
The user data structure stores the user's name, age, email, location, preferences, and linked lists for posts, friends, and received friend requests. The linked lists allow easy insertion/deletion and traversal of data.

Post Manager - Handles all operations related to user posts. It can create new posts, store them in per-user linked lists, and list all posts for a given user.
When a new post is made, a Post node is created and added to the front of the user's post linked list. This allows the latest posts to be accessed faster but wastes space at the front of the list.

The Post Manager notifies the Word Analyzer when a new post is made so word counts can be updated.

Word Analyzer - Counts the frequency of words from all user posts. It stores each unique word and its count in a WordNode linked list.
To find the most frequent words, it traverses the WordNode list and identifies the node with the highest count. The count for that node is then reset to 0 and the process repeats to find the next highest words, up to the requested number of words.

This algorithm has O(n^2) time complexity due to the inefficient method of finding the max node on each iteration. A heap data structure could improve this to O(nlogn).

Error Handling

Error codes are returned for operations like searching for a non-existent user. These codes are checked in the caller and an appropriate error message is displayed in red text to alert the user. This separates the error handling from the main logic.




Data Model Design

A data flow diagram shows data from the User Manager flows to the Post Manager when a new post is created. The Post Manager then notifies the Word Analyzer so word counts can be updated. This isolates dependencies between modules.

The Word Analyzer maintains a separate WordNode list to count word frequencies across all posts. This allows it to operate independently from the Post Manager.

Dataset Processing

No external datasets were used in the project. Sample user data and posts are generated for demonstration purposes.

Strings from user input and post text are tokenized using " " and ".,!-?" as delimiters. Each token is then passed to the count_word() function to be added or have its count incremented in the WordNode list.

The Word Analyzer traverses this WordNode list to identify the most frequent words and display the top results.

Improvements

Several improvements were identified to enhance the project:

Use a self-balancing search tree for O(log n) user search
Add new posts to the end of post linked lists for better space usage
Use a heap to find the max WordNode in O(log n) time instead of O(n)
Implement unit tests to thoroughly test individual functions
Add more functions to manage friend lists, block users, like posts, and comment on posts
Hope this expanded solutions section provides a more detailed overview of the project implementation! Let me know if you have any other questions.


REFERENCES 
youtube.com
(we also used material available in the aula global)

