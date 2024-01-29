#include <stdio.h>
#include <stdlib.h>

// Creating Node Structure
struct node {
	int data;
	struct node *prev;
	struct node *next;
};

// Function Declarations
struct node *createNewNode(struct node *root, struct node **tail);
void printList(struct node *root);

int main(int argc, char *argv[]) {
	// Initialize the root and tail of the circular doubly linked list
    struct node* root = NULL;
	struct node* tail = NULL;
	
	// Insert elements at the end of the list	
	root = createNewNode(root, &tail);
	root = createNewNode(root, &tail);
	root = createNewNode(root, &tail);
	root = createNewNode(root, &tail);
	
	// Display the circular doubly linked list
	printList(root);
	return 0;
}

// Function to create a new node end of the circular doubly linked list
struct node *createNewNode(struct node *root, struct node **tail) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->prev = newNode;
	newNode->next = newNode;
	
	printf("Enter a value: ");
	scanf("%d", &(newNode->data));
	
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
