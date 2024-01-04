#include <stdio.h>
#include <stdlib.h>

// Creating Node Structure
struct node {
	int data;
	struct node *next;
};

// Function Prototypes
struct node *insertBegin(struct node *root, struct node **tail);
struct node *deleteBegin(struct node *root, struct node **tail);
struct node *deleteEnd(struct node *root, struct node **tail);
struct node *deleteSpecific(struct node *root, struct node **tail);
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

// Function to delete a node from the beginning of the circular linked list
struct node *deleteBegin(struct node *root, struct node **tail) {
	if(root == NULL) {
		printf("List is empty!\n");
		return NULL;
	}
	struct node *deletedNode = root;
	
	// Check if the node to be deleted is the last node
	if (root->next == root) {
		root = NULL;
		*tail = NULL;
	} else {
		root = root->next;
		(*tail)->next = root;
	}
	printf("%d deleted from the beginning of the circular linked list.\n", deletedNode->data);
	free(deletedNode);

	// Return updated root
	return root;
}

// Function to delete a node from the end of the circular linked list
struct node *deleteEnd(struct node *root, struct node **tail) {
	if(root == NULL) {
		printf("List is empty!\n");
		return NULL;
	}
	struct node *deletedNode = *tail;
	
	// Check if the node to be deleted is the last node
	if ((*tail)->next == *tail) {
		root = NULL;
		*tail = NULL;
	} else {
		struct node *iter = root;
		
		// Find the position before last node
		while(iter->next != *tail) {
			iter = iter->next;
		}
		iter->next = root;
		*tail = iter;
	}
	printf("%d deleted from the end of the circular linked list.\n", deletedNode->data);
	free(deletedNode);
	
	// Return updated root
	return root;
}

// Function to delete a node from a specific position in the circular linked list
struct node *deleteSpecific(struct node *root, struct node **tail) {
	// If the list is empty
	if(root == NULL) {
		printf("List is empty!\n");
		return NULL;
	}
	struct node *deletedNode;
	int position;
	
	printf("Enter the position of the node to delete: ");
	scanf("%d", &position);
	
	if(position == 1) {
		deletedNode = root;
		
		// Check if the node to be deleted is the last node
		if(root->next == root) {
			root = NULL;
			*tail = NULL;
		} else {
			root = root->next;
			(*tail)->next = root;
		}
	} else {
		struct node *iter = root;
		int count = 1;
		
		// Traverse to the node before the specified position
		while(count < position - 1 && iter->next != root) {
			iter = iter->next;
			count++;
		}
		
		// Check for invalid position
		if(iter == root || iter->next == root) {
			printf("Invalid position!\n");
			return root;
		}
		
		// Delete the node at the specified position
		deletedNode = iter->next;
		iter->next = iter->next->next;
		
		if(deletedNode == *tail) {
			*tail = iter;
		}
	}
	printf("%d deleted from the linked list.\n", deletedNode->data);
	free(deletedNode);
	
	// Return the updated root of the circular linked list
	return root;
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
	printf("1- Insert a new node at the BEGIN of the linked list\n");
	printf("2- Delete a node from the BEGINNING of the linked list\n");
	printf("3- Delete a node from the END of the linked list\n");
	printf("4- Delete a new node from a specify position of the linked list\n");
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
