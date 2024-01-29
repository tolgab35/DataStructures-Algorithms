#include <stdio.h>
#include <stdlib.h>

// Creating Node Structure
struct node {
	int data;
	struct node *prev;
	struct node *next;
};

// Function Prototypes
struct node *insertBegin(struct node *root, struct node **tail);
struct node *insertEnd(struct node *root, struct node **tail);
struct node *insertSpecific(struct node *root, struct node **tail);
void printList(struct node *root);
void printMenu();
int getUserChoice();
int getUserData();

int main(int argc, char *argv[]) {
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
				root = insertEnd(root, &tail);
				break;
			case 3:
				root = insertSpecific(root, &tail);
				break;
			case 4:
				printList(root);
				break;
			case 5:
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
	newNode->prev = newNode;
	newNode->next = newNode;
	return newNode;
}

// Function to insert a new node at the beginning of the circular doubly linked list
struct node *insertBegin(struct node *root, struct node **tail) {
	struct node *newNode = createNewNode();

	// If the list is empty, set the new node as the root
	if(root == NULL) {
		root = newNode;
		*tail = root;
	} else {
		newNode->next = root;
		root->prev = newNode;
		root = newNode;
		(*tail)->next = root;
		root->prev = *tail;
	}
	// Return updated root
	printf("%d inserted at the beginning of the circular doubly linked list.\n", newNode->data);
	return root;
}

// Function to insert a new node at the end of the circular doubly linked list
struct node *insertEnd(struct node *root, struct node **tail) {
	struct node *newNode = createNewNode();

	// If the list is empty, set the new node as the root
	if(root == NULL) {
		root = newNode;
		*tail = root;
	} else {
		(*tail)->next = newNode;
		newNode->prev = *tail;
		*tail = newNode;
		(*tail)->next = root;
		root->prev = *tail;
	}
	
	// Return updated root
	printf("%d inserted at the end of the circular doubly linked list.\n", newNode->data);
	return root;
}

// Function to insert a new node at a specific position in the circular doubly linked list
struct node *insertSpecific(struct node *root, struct node **tail) {	
	int position;
	printf("Enter the position you want to insert data: ");
	scanf("%d", &position);
	
	// Insertion at the beginning
	if(position == 1) {
		root = insertBegin(root, tail);
		return root;
	}
	
	// Find the position before the given position by user
	int count = 1;
	struct node *iter = root;
	while(count < position - 1 && iter->next != root) {
		iter = iter->next;
		count++;
	}
	
	// Check if the given position is valid
	if(count < position - 1 && iter->next == root) {
		printf("Invalid position!\n");
		return root;
	}
	
	struct node *newNode = createNewNode();
	
	newNode->next = iter->next;
	newNode->prev = iter;
	iter->next->prev = newNode;
	iter->next = newNode;
	
	
	// Update tail if newNode inserted at the end
    if (newNode->next == root) {
        *tail = newNode;
    }
	
	// Return updated root
	printf("%d inserted at the %d position in the circular doubly linked list.\n", newNode->data, position);
	return root;
}

// Function to display the circular doubly linked list
void printList(struct node *root) {
	// Check if the linked list is empty
	if(root == NULL) {
		printf("List is empty!\n");
	} else {
		struct node* iter = root;
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
	printf("1- Insert a new node at the BEGIN of the linked list\n");
	printf("2- Insert a new node at the END of the linked list\n");
	printf("3- Insert a new node at the specify position of the linked list\n");
	printf("4- Print all the elements of the linked list\n");
	printf("5- Exit\n");
}

// Function to get user choice from the menu
int getUserChoice() {
	int choice;
	printf("\nYour choice(1-5): ");
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
