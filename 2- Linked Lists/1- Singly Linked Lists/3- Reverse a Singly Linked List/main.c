#include <stdio.h>
#include <stdlib.h>

// Define a structure for a linked list node
struct node {
	int data;
	struct node *next;
};

// Function Declarations
struct node * insertBegin(struct node *root, struct node **tail);
struct node * reverseList(struct node *root, struct node **tail);
void printList(struct node *root);

int main(int argc, char *argv[]) {
	// Initialize the root and tail of the linked list
	struct node *root = NULL;
	struct node *tail = NULL;
	int choice;
	
	printf("Choose an operation\n");
	printf("1- Insert a new node at the begin of the linked list\n");
	printf("2- Reverse the linked list\n");
	printf("3- Print all the elements of the linked list\n");
	printf("4- Exit\n");
	
	while(1) {
		printf("\nYour choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				root = insertBegin(root, &tail);
				break;
			case 2:
				if(root == NULL) {
					printf("Insert some nodes first!\n");
				} else {
					root = reverseList(root, &tail);
				}
				break;
			case 3:
				if(root == NULL) {
					printf("Insert some nodes first!\n");
				} else {
					printList(root);
				}
				break;
			case 4:
				printf("\nBye!");
				return 0; // Exit
		}
	}
}

// Function to insertion a new node at the begin of the linked list
struct node * insertBegin(struct node *root, struct node **tail) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	
	// Prompt the user to enter data for the new node
	printf("Enter data: ");
	scanf("%d", &newNode->data);
	newNode->next = NULL;
	
	// If the linked list is empty, make the new node the root
	if(root == NULL) {
		root = newNode;
		*tail = root;
	}
	// Otherwise, make the new node come before the root
	else {
		newNode->next = root;
		root = newNode;
	}
	printf("%d inserted to the begin of the linked list.\n", root->data);
	
	// Return the updated root of the linked list
	return root;
}

// Function to reverse the linked list
struct node * reverseList(struct node *root, struct node **tail) {
	struct node *prevNode = NULL, *currentNode = root, *nextNode;
	
	while(currentNode != NULL) {
		nextNode = currentNode->next; // Save the next node
		currentNode->next = prevNode; // Reverse the link
		
		// Move one step forward in the list
		prevNode = currentNode;
		currentNode = nextNode;
	}
	// prevNode now points to the new head of the reversed list
	
	// Update the tail pointer
	if(*tail != NULL) {
		*tail = root;
	}
	printf("Linked List is reversed.\n");
	
	// Return the updated root of the linked list
	return prevNode;
}

// Function to print the elements of the linked list
void printList(struct node *root) {
	// Traverse the linked list and print each element
	struct node *iter = root;
	
	while(iter != NULL) {
		printf("%d ", iter->data);
		iter = iter->next;
	}
	printf("\n");
}
