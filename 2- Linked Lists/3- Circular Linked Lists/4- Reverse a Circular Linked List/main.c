#include <stdio.h>
#include <stdlib.h>

// Creating Node Structure
struct node {
	int data;
	struct node *next;
};

// Function Prototypes
struct node *insertBegin(struct node *root, struct node **tail);
struct node *reverseList(struct node *root, struct node **tail);
void printList(struct node *root);
void printMenu();
int getUserChoice();
int getUserData();

int main() {
	// Initialize the root and tail of the circular linked list
    struct node *root = NULL;
	struct node *tail = NULL;
	
	// Display menu and get user choice
	printMenu();
	int choice;
	while(1) {
		choice = getUserChoice();
		switch(choice) {
			case 1:
				root = insertBegin(root, &tail);
				break;
			case 2:
				root = reverseList(root, &tail);
				break;
			case 3:
				printList(root);
				break;
			case 4:
				printf("Bye!\n");
				return 0; // Exit
			default:
				printf("Enter a valid option!");
				break;
		}
	}
}

// Function to create a new node and return it to insertion
struct node *createNewNode() {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	if(newNode == NULL) {
	    perror("Memory allocation failed");
	    exit(EXIT_FAILURE);
	}
	newNode->data = getUserData();
	newNode->next = newNode;
	return newNode;
}

// Function to insert a node at the beginning of the circular linked list
struct node *insertBegin(struct node *root, struct node **tail) {
	struct node *newNode = createNewNode();
	
	if(root == NULL) {
		// If the list is empty, set the new node as the root and tail
		root = newNode;
		*tail = root;
	} else {
		// Insert at the beginning and update tail
		newNode->next = root;
		root = newNode;
		(*tail)->next = root;
	}
	printf("%d inserted at the beginning of the circular linked list.\n", root->data);
	
	// Return updated root
	return root;
}

// Function to reverse the circular linked list
struct node *reverseList(struct node *root, struct node **tail) {
	if(root == NULL) {
		printf("List is empty!\n");
		return NULL;
	}
	struct node *prevNode = NULL, *currentNode = root, *nextNode;
	
	do {
		nextNode = currentNode->next;
		currentNode->next = prevNode;
		prevNode = currentNode;
		currentNode = nextNode;
	} while(currentNode != root);
	
	// Update the tail pointer
	if(*tail != NULL) {
		*tail = prevNode;
	}
	printf("List is reversed.\n");
	
	// Return updated root
	return prevNode;
}

// Function to print all elements of the circular linked list
void printList(struct node *root) {
	if(root == NULL) {
		// Check if the list is empty
		printf("List is empty!\n");
	} else {
		struct node *iter = root;
		do {
			printf("%d ", iter->data);
			iter = iter->next;
		} while(iter != root);
		printf("\n");
	}
}

// Function to display the menu
void printMenu() {
	printf("Choose an operation\n");
	printf("1- Insert a new node at the BEGIN of the circular linked list\n");
	printf("2- Reverse the circular linked list\n");
	printf("3- Print all the elements of the circular linked list\n");
	printf("4- Exit\n");
}

// Function to get user choice from the menu
int getUserChoice() {
	int choice;
	printf("\nYour choice(1-4): ");
	scanf("%d", &choice);
	return choice;
}

// Function to get user input for the new node data
int getUserData() {
    int data;
    printf("Enter the data you want to insert: ");
    scanf("%d", &data);
    return data;
}
