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
void printList(struct node *root);

int main(int argc, char *argv[]) {
	// Initialize the root of the doubly linked list
    struct node* root = NULL;
    struct node* tail = NULL;
	int choice;
	
	printf("Choose an operation\n");
	printf("1- Insert a new node at the begin of the doubly linked list\n");
	printf("2- Delete a node from the BEGIN of the doubly linked list\n");
	printf("3- Delete a node from the END of the doubly linked list\n");
	printf("4- Delete a node from the SPECIFIC position of the doubly linked list\n");
	printf("5- Print all the elements of the doubly linked list\n");
	printf("6- Exit\n");
	
	while(1) {
		printf("\nYour choice(1-6): ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				root = insertBegin(root, &tail);
				break;
			case 2:
				if(root == NULL) {
					printf("List is empty! Insert some nodes first.\n");
				} else {
					root = deleteBegin(root, &tail);
				}
				break;
			case 3:
				if(root == NULL) {
					printf("List is empty! Insert some nodes first.\n");
				} else {
					root = deleteEnd(root, &tail);
				}
				break;
			case 4:
				if(root == NULL) {
					printf("List is empty! Insert some nodes first.\n");
				} else {
					root = deleteSpecific(root, &tail);
				}
				break;
			case 5:
				if(root == NULL) {
					printf("List is empty! Insert some nodes first.\n");
				} else {
					printList(root);
				}
				break;
			case 6:
				printf("Bye!\n");
				return 0;
			default:
				printf("Enter a valid option!");
				break;
		}
	}
}

// Function to insertion a new node at the BEGIN
struct node *insertBegin(struct node *root, struct node **tail) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	
	// Prompt the user to enter data for the new node
	printf("Enter data: ");
	scanf("%d", &newNode->data);
	
	newNode->prev = NULL;
	newNode->next = NULL;
	
	// If the doubly linked list is empty, make the new node the root
	if(root == NULL) {
		root = newNode;
		*tail = root;
	} else {
		newNode->next = root;
		root->prev = newNode;
		root = newNode;
	}
	printf("%d inserted to the begin of the doubly linked list.\n", root->data);
	
	// Return the updated root of the list
	return root;
}

// Function to delete a node from the BEGIN
struct node *deleteBegin(struct node *root, struct node **tail) {
	struct node *deletedNode = root;
	
	root = root->next;
	
	if(root == NULL) {
		*tail = NULL;
	}
	printf("%d deleted from the doubly linked list.\n", deletedNode->data);
	free(deletedNode);
	
	// Return the updated root of the doubly linked list
	return root;
}

// Function to delete a node from the END
struct node *deleteEnd(struct node *root, struct node **tail) {
	struct node *deletedNode = *tail;
	
	*tail = (*tail)->prev;

	if(root->next == NULL) {
		root = NULL;
	} else {
		(*tail)->next = NULL; 
	}
	printf("%d deleted from the doubly linked list.\n", deletedNode->data);
	free(deletedNode);
	
	// Return the updated root of the doubly linked list
	return root;
}

// Function to delete a node from the SPECIFIC position
struct node *deleteSpecific(struct node *root, struct node **tail) {
	struct node *deletedNode;
	int position;
	
	printf("Enter the position of the node to delete: ");
	scanf("%d", &position);
	
	if(position == 1) {
		deletedNode = root;
		root = root->next;
		if(root != NULL) {
			root->prev = NULL;
		}
		// If the only node in the doubly linked list is deleted, update tail with NULL
		if(root == NULL) {
			*tail = NULL;
		}
	} else {
		struct node *iter = root;
		int count = 1;
		
		// Traverse to the node before the specified position
		while(count < position - 1 && iter->next != NULL) {
			iter = iter->next;
			count++;
		}
		
		// Check for invalid position
		if(iter == NULL || iter->next == NULL) {
			printf("Invalid position!");
			return root;
		}
		
		// Delete the node at the specified position
		deletedNode = iter->next;
		iter->next = iter->next->next;
		if(iter->next != NULL){
			iter->next->prev = iter;
		} else {
			// If the last node is deleted, update tail
			*tail = iter;
		}
	}
	printf("%d deleted from the linked list.\n", deletedNode->data);
	free(deletedNode);
	
	// Return the updated root of the doubly linked list
	return root;
}

// Function to print the elements
void printList(struct node *root) {
	// Check if the list is empty
	if(root == NULL) {
		printf("List is empty!\n");
	} else {
		while(root != NULL) {
			printf("%d ", root->data);
			root = root->next;
		}
		printf("\n");
	}
}
