#include <stdio.h>
#include <stdlib.h>

// Define a structure for a linked list node
struct node {
	int data;
	struct node *next;
};

// Function Declarations
struct node * insertBegin(struct node *root, struct node **tail);
struct node * deleteBegin(struct node *root, struct node **tail);
struct node * deleteEnd(struct node *root, struct node **tail);
struct node * deleteSpecific(struct node *root, struct node **tail);
void printList(struct node *root);

int main(int argc, char *argv[]) {
	// Initialize the root and tail of the linked list
	struct node *root = NULL;
	struct node *tail = NULL;
	int choice;
	
	printf("Choose an operation\n");
	printf("1- Insert a new node at the begin of the linked list\n");
	printf("2- Delete a node from the BEGIN of the linked list\n");
	printf("3- Delete a node from the END of the linked list\n");
	printf("4- Delete a node from the SPECIFIC position of the linked list\n");
	printf("5- Print all the elements of the linked list\n");
	printf("6- Exit\n");
	
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
					root = deleteBegin(root, &tail);
				}
				break;
			case 3:
				if(root == NULL) {
					printf("Insert some nodes first!\n");
				} else {
					root = deleteEnd(root, &tail);
				}
				break;
			case 4:
				if(root == NULL) {
					printf("Insert some nodes first!\n");
				} else {
					root = deleteSpecific(root, &tail);
				}
				break;
			case 5:
				if(root == NULL) {
					printf("Insert some nodes first!\n");
				} else {
					printList(root);
				}
				break;
			case 6:
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

// Function to delete a node from the BEGIN of the linked list
struct node * deleteBegin(struct node *root, struct node **tail) {
	struct node *deletedNode = root;
	
	root = root->next;
	if(root == NULL) {
		*tail = NULL;
	}
	printf("%d deleted from the linked list.\n", deletedNode->data);
	free(deletedNode);
	
	// Return the updated root of the linked list
	return root;
}

// Function to delete a node from the END of the linked list
struct node * deleteEnd(struct node *root, struct node **tail) {
	struct node *deletedNode = *tail;
	
	if(root->next == NULL) {
		root = NULL;
		*tail = NULL;
	} else {
		struct node *iter = root;
		
		while(iter->next->next != NULL) {
			iter = iter->next;
		}
		iter->next = NULL;
		*tail = iter;
	}
	printf("%d deleted from the linked list.\n", deletedNode->data);
	free(deletedNode);
	
	// Return the updated root of the linked list
	return root;
}

// Function to delete a node from the SPECIFIC position in the linked list
struct node * deleteSpecific(struct node *root, struct node **tail) {
	struct node *deletedNode;
	int position;
	
	printf("Enter a node position that you want to delete: ");
	scanf("%d", &position);
	
	// Deletion from the beginning
	if(position == 1) {
		deletedNode = root;
		root = root->next;
		
		// If the only node in the linked list is deleted, update tail with NULL
		if(root == NULL) {
			*tail = NULL;
		}
	} else {
		struct node *iter = root;
		int count = 1;
		
		// Traverse to the node before the specified position
		while(count < position - 1 && iter != NULL) {
			iter = iter->next;
			count++;
		}
		
		// Check for invalid position
		if(iter == NULL || iter->next == NULL) {
			printf("Invalid position!\n");
			return root;
		}
		// Delete the node at the specified position
		deletedNode = iter->next;
		iter->next = iter->next->next;
		
		// If the last node is deleted, update tail
		if(iter->next == NULL) {
			*tail = iter->next;
		}
	}
	printf("%d deleted from the linked list.\n", deletedNode->data);
	free(deletedNode);
	
	// Return the updated root of the linked list
	return root;
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
