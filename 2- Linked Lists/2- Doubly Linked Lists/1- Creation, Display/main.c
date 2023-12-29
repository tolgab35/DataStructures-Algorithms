#include <stdio.h>
#include <stdlib.h>

// Creating Node Structure
struct node {
	int data;
	struct node *prev;
	struct node *next;
};

// Function Declarations
struct node *createNewNode(struct node *root);
void printList(struct node *root);

int main(int argc, char *argv[]) {
	// Initialize the root of the doubly linked list
    struct node* root = NULL;

	// Insert elements at the end of the list	
	root = createNewNode(root);
	root = createNewNode(root);
	root = createNewNode(root);
	root = createNewNode(root);
	
	// Display the doubly linked list
	printList(root);
	return 0;
}

// Function to create a new node end of the doubly linked list
struct node *createNewNode(struct node *root) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->prev = NULL;
	newNode->next = NULL;
	
	printf("Enter a value: ");
	scanf("%d", &(newNode->data));
	
	// If the list is empty, set the new node as the root
	if(root == NULL) {
		root = newNode;
	}
	else {
		struct node *iter = root;
		
		// Find the last node of the list
		while(iter->next != NULL) {
			iter = iter -> next;
		}
		newNode->prev = iter;
		iter->next = newNode;
	}
	
	// Return updated root
	return root;
}

// Function to display the doubly linked list
void printList(struct node *root) {
	// Check if the linked list is empty
	if(root == NULL) {
		printf("List is empty!\n");
	}
	else {
		while(root != NULL) {
			printf("%d ", root->data);
			root = root->next;
		}
		printf("\n");
	}
}
