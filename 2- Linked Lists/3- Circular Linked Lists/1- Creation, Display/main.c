#include <stdio.h>
#include <stdlib.h>

// Creating Node Structure
struct node {
	int data;
	struct node *next;
};

// Function Prototypes
struct node *createNewNode(struct node *root);
void printList(struct node *root);

int main(int argc, char *argv[]) {
	// Initialize the root of the circular linked list
    struct node* root = NULL;

	// Insert elements at the end of the list	
	root = createNewNode(root);
	root = createNewNode(root);
	root = createNewNode(root);
	root = createNewNode(root);
	
	// Display the circular linked list
	printList(root);
	return 0;
}

// Function to create a new node at the end of the circular linked list
struct node *createNewNode(struct node *root) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->next = newNode;
	
	printf("Enter a value: ");
	scanf("%d", &(newNode->data));
	
	// If the list is empty, set the new node as the root
	if(root == NULL) {
		root = newNode;
	} else {
		struct node *iter = root;
		
		// Find the last node of the list
		do {
			iter = iter->next;
		} while(iter->next != root);
		
		iter->next = newNode;
		newNode->next = root;
	}
	// Return updated root
	return root;
}

// Function to display the circular linked list
void printList(struct node *root) {
	// Check if the list is empty
	if(root == NULL) {
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
