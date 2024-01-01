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
struct node *reverseList(struct node *root, struct node **tail);
void printList(struct node *root);
void printMenu();
int getUserChoice();
int getUserData();

int main() {
	// Initialize the root and tail of the doubly linked list
    struct node* root = NULL;
    struct node* tail = NULL;
    
    // Display menu and get user choice
    printMenu();
	int choice;
	while(1) {
		choice = getUserChoice();
		
		// Process user choice
		switch(choice) {
			case 1:
				root = insertBegin(root, &tail);
				break;
			case 2:
				if(root == NULL) {
					printf("List is empty! Insert some nodes first.\n");
				} else {
					root = reverseList(root, &tail);
				}
				break;
			case 3:
				if(root == NULL) {
					printf("List is empty! Insert some nodes first.\n");
				} else {
					printList(root);
				}
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

// Function to insert a new node at the beginning
struct node *insertBegin(struct node *root, struct node **tail) {
	// Allocate memory for a new node
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
	
	// Get user data for the new node
	newNode->data = getUserData();
	newNode->prev = NULL;
	newNode->next = NULL;
	
	// Update the linked list pointers
	if(root == NULL) {
		root = newNode;
		*tail = root;
	} else {
		newNode->next = root;
		root->prev = newNode;
		root = newNode;
	}
	printf("%d inserted at the beginning of the doubly linked list.\n", root->data);
	
	// Return the updated root of the list
	return root;
}

// Function to reverse the linked list
struct node * reverseList(struct node *root, struct node **tail) {
	// Initialize pointers for reversing the list
	struct node *currentNode = root, *temp = NULL;
	
	// Traverse the list and reverse the pointers
	while(currentNode != NULL) {
		temp = currentNode->prev;
		currentNode->prev = currentNode->next;
		currentNode->next = temp;
		currentNode = currentNode->prev;
	}
	
	// Update the root pointer
    if (temp != NULL) {
        root = temp->prev;
    }

    // Update the tail pointer
    *tail = root;
    printf("Linked list reversed.\n");
    
    // Return the updated root of the list
    return root;
}

// Function to print the elements of the doubly linked list
void printList(struct node *root) {
	// Check if the list is empty
	if(root == NULL) {
		printf("List is empty!\n");
	} else {
		while(root != NULL) {
			// Traverse the list and print elements
			printf("%d ", root->data);
			root = root->next;
		}
		printf("\n");
	}
}

// Function to display the menu
void printMenu() {
	printf("Choose an operation\n");
	printf("1- Insert a new node at the begin of the linked list\n");
	printf("2- Reverse the linked list\n");
	printf("3- Print all the elements of the linked list\n");
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
    printf("Enter data: ");
    scanf("%d", &data);
    return data;
}

