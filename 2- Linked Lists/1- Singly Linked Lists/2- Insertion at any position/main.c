#include <stdio.h>
#include <stdlib.h>

// Define a structure for a linked list node
struct node {
	int data;
	struct node *next;
};

// Function Declarations
struct node * createNewNode();
struct node * insertBegin(struct node *root, struct node **tail);
struct node * insertEnd(struct node *root, struct node **tail);
struct node * insertSpecific(struct node *root, struct node **tail);
void printList(struct node *root);

int main(int argc, char *argv[]) {
	// Initialize the root and tail of the linked list
	struct node *root = NULL;
	struct node *tail = NULL;
	int choice;
	
	printf("Choose an operation\n");
	printf("1- Insert a new node at the BEGIN of the linked list\n");
	printf("2- Insert a new node at the END of the linked list\n");
	printf("3- Insert a new node at the specify position of the linked list\n");
	printf("4- Print all the elements of the linked list\n");
	printf("5- Exit\n");
	
	while(1) {
		printf("\nYour choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				root = insertBegin(root, &tail);
				break;
			case 2:
				root = insertEnd(root, &tail);
				break;
			case 3:
				root = insertSpecific(root, &tail);
				break;
			case 4:
				if(root == NULL) {
					printf("Insert some nodes first!\n");
				} else {
					printList(root);
				}
				break;
			case 5:
				printf("\nBye!");
				return 0; // Exit
		}
	}
}
// Function to create a new node and return it to insertion
struct node * createNewNode() {
	// Allocate memory for a new node
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	
	// Prompt the user to enter data for the new node
	printf("Enter data: ");
	scanf("%d", &newNode->data);
	newNode->next = NULL;
	
	return newNode;
}
// Function to insertion a new node at the BEGIN of the linked list
struct node * insertBegin(struct node *root, struct node **tail) {
	struct node *newNode = createNewNode();
	
	// If the linked list is empty, make the new node the root
	if(root == NULL) {
		root = newNode;
		*tail = root;
	}
	// Otherwise, make the new node comes before root
	else {
		newNode->next = root;
		root = newNode;
	}
	printf("%d inserted to the begin of the linked list.\n", root->data);
	
	// Return the updated root of the linked list
	return root;
}
// Function to insertion a new node at the END of the linked list
struct node * insertEnd(struct node *root, struct node **tail) {
	struct node *newNode = createNewNode();
	
	// If the linked list is empty, make the new node the root
	if(root == NULL) {
		root = newNode;
		*tail = root;
	}
	// Otherwise, add the new node after tail and update tail
	else {
		(*tail)->next = newNode;
		*tail = newNode;
	}
	printf("%d inserted to the end of the linked list.\n", newNode->data);
	
	// Return the updated root of the linked list
	return root;
}
// Function to insertion a new node at the SPESIFIED position of the linked list
struct node * insertSpecific(struct node *root, struct node **tail) {
	struct node *newNode = createNewNode();

	// If the linked list is empty, make the new node the root
	if(root == NULL) {
		root = newNode;
		*tail = root;
	} else {
		int position;
		
		printf("Enter the position you want to insert data: ");
		scanf("%d", &position);
		
		// Insert at the beginning
		if (position == 1) {
            newNode->next = root;
            root = newNode;
        } else {
			// Traverse the linked list to find the specified position
			struct node *iter = root;
			int count = 1;
			
			while(count < position - 1 && iter->next != NULL) {
				iter = iter->next;
				count++;
			}
			// Check if the specified position is valid
			if(count < position - 1 && iter->next == NULL) {
				printf("%d not a valid position!\n", position);
				return root;
			}
			
			// Insert the new node at the specified position
			newNode->next = iter->next;
			iter->next = newNode;
			
			// If the newNode is at the end, update the tail
			if(newNode == (*tail)->next) {
				*tail = newNode;
			}
		}
		printf("%d inserted to %d position of the linked list.\n", newNode->data, position);
	}
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
