#include <stdio.h>
#include <stdlib.h>

// Define a structure for a linked list node
struct node {
	int data;
	struct node *next;
};
// Function to create a new node and add it to the end of the linked list
struct node * createNewNode(struct node *root);
// Function to print the elements of the linked list
void printList(struct node *root);

int main(int argc, char *argv[]) {
	// Initialize the root of the linked list
	struct node *root = NULL;
	
	// Create new nodes and add them to the linked list
	root = createNewNode(root);
	root = createNewNode(root);
	root = createNewNode(root);
	root = createNewNode(root);
	
	// Print the elements of the linked list
	printList(root);
	return 0;
}

struct node * createNewNode(struct node *root) {
	// Allocate memory for a new node
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	
	// Prompt the user to enter data for the new node
	printf("Enter data: ");
	scanf("%d", &newNode->data);
	newNode->next = NULL;
	
	// If the linked list is empty, make the new node the root
	if(root == NULL) {
		root = newNode;
	}
	// Otherwise, traverse the list to find the last node and add the new node to the end
	else {
		struct node *iter = root;
		while(iter->next != NULL) {
			iter = iter->next;
		}
		iter->next = newNode;
	}
	// Return the updated root of the linked list
	return root;
}

void printList(struct node *root) {
	// Traverse the linked list and print each element
	struct node *iter = root;
	while(iter != NULL) {
		printf("%d ", iter->data);
		iter = iter->next;
	}
}
