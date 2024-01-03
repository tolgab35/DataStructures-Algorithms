#include <stdio.h>
#include <stdlib.h>

// Creating Node Structure
struct node {
	int data;
	struct node *next;
};

// Function Prototypes
struct node *createNewNode();
struct node *insertBegin(struct node *root);
void printList(struct node *root);

int main(int argc, char *argv[]) {
	// Initialize the root of the circular linked list
    struct node *root = NULL;
    
	// Insert elements at the begin of the list
	root = insertBegin(root);
	root = insertBegin(root);
	root = insertBegin(root);
	root = insertBegin(root);
	
	// Display the circular linked list
	printList(root);
	return 0;
}

// Function to create a new node and return it to insert function
struct node *createNewNode() {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if(newNode == NULL) {
	    perror("Memory allocation failed");
	    exit(EXIT_FAILURE);
	}
    newNode->next = newNode;
    return newNode;
}

// Function to create a new node at the begin of the circular linked list
struct node *insertBegin(struct node *root) {
	struct node *newNode = createNewNode();
	printf("Enter data: ");
    scanf("%d", &(newNode->data));
    
	if(root == NULL) {
		// If the list is empty
		root = newNode;
	} else {
		newNode->next = root->next;
        root->next = newNode;
        root = newNode;
	}
	printf("%d inserted at the beginning of the circular linked list.\n\n", root->data);
	
	// Return updated root
	return root;
}

// Function to display the circular linked list
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
