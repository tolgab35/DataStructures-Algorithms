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
struct node *deleteBegin(struct node *root, struct node **tail);
struct node *deleteEnd(struct node *root, struct node **tail);
struct node *deleteSpecific(struct node *root, struct node **tail);
int isEmpty(struct node *root);
void printList(struct node *root);
void printMenu();
int getUserChoice();
int getUserData();

int main(int argc, char *argv[]) {
	// Initialize the root and tail of the circular doubly linked list
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
				root = deleteBegin(root, &tail);
				break;
			case 3:
				root = deleteEnd(root, &tail);
				break;
			case 4:
				root = deleteSpecific(root, &tail);
				break;
			case 5:
				printList(root);
				break;
			case 6:
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

struct node *deleteBegin(struct node *root, struct node **tail) {
	// If the list is empty
	if(isEmpty(root)) {
		return root;
	}
	struct node *deletedNode = root;
	
	// If there is only node in the circular doubly linked list
	if(root->next == root) {
		root = NULL;
		*tail = NULL;
	} else {
		root = root->next;
		root->prev = *tail;
		(*tail)->next = root;
	}
	printf("%d deleted from the beginning of the circular doubly linked list.\n", deletedNode->data);
	free(deletedNode);
	return root;
}

struct node *deleteEnd(struct node *root, struct node **tail) {
	// If the list is empty
	if(isEmpty(root)) {
		return root;
	}
	struct node *deletedNode = *tail;
	
	// If there is only node in the circular doubly linked list
	if(root->next == root) {
		root = NULL;
		*tail = NULL;
	} else {
		*tail = (*tail)->prev;
		(*tail)->next = root;
		root->prev = *tail;
	}
	printf("%d deleted from the end of the circular doubly linked list.\n", deletedNode->data);
	free(deletedNode);
	return root;
}

struct node *deleteSpecific(struct node *root, struct node **tail) {
	// If the list is empty
	if(isEmpty(root)) {
		return root;
	}
	int position;
	printf("Enter the position of the node you want to delete: ");
	scanf("%d", &position);
	
	// If the given position is at the begin
	if(position == 1) {
		return deleteBegin(root, tail);
	}
	
	// Traverse to the node before the given position
	int count = 1;
	struct node *iter = root;
	while(count < position - 1 && iter->next != root) {
		iter = iter->next;
		count++;
	}

	// Check for invalid position
	if(iter->next == root) {
		printf("Invalid position!\n");
		return root;
	}
	
	struct node *deletedNode = iter->next;
	
	// If the given position is at the end
	if(deletedNode == *tail) {
		return deleteEnd(root, tail);
	}
	iter->next = iter->next->next;
	iter->next->prev = iter;
	
	printf("%d deleted from the end of the circular doubly linked list.\n", deletedNode->data);
	free(deletedNode);
	return root;
}

int isEmpty(struct node *root) {
	if(root == NULL) {
		printf("List is empty!\n");
		return 1;
	}
	return 0;
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
	printf("2- Delete a node from the BEGIN of the linked list\n");
	printf("3- Delete a node from the END of the linked list\n");
	printf("4- Delete a node from the specify position of the linked list\n");
	printf("5- Print all the elements of the linked list\n");
	printf("6- Exit\n");
}

// Function to get user choice from the menu
int getUserChoice() {
	int choice;
	printf("\nYour choice(1-6): ");
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
