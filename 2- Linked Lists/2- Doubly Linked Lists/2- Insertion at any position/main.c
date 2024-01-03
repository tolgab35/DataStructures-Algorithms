#include <stdio.h>
#include <stdlib.h>

// Creating Node Structure
struct node {
	int data;
	struct node *prev;
	struct node *next;
};

// Function Prototypes
struct node *createNewNode();
struct node *insertBegin(struct node *root, struct node **tail);
struct node *insertEnd(struct node *root, struct node **tail);
struct node *insertSpecific(struct node *root, struct node **tail);
void printList(struct node *root);

int main(int argc, char *argv[]) {
	// Initialize the root of the doubly linked list
    struct node* root = NULL;
    struct node* tail = NULL;
	int choice;
	
	printf("Choose an operation\n");
	printf("1- Insert a new node at the BEGIN of the linked list\n");
	printf("2- Insert a new node at the END of the linked list\n");
	printf("3- Insert a new node at the specify position of the linked list\n");
	printf("4- Print all the elements of the linked list\n");
	printf("5- Exit\n");
	
	while(1) {
		printf("\nYour choice(1-5): ");
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
				printList(root);
				break;
			case 5:
				printf("Bye!\n");
				return 0;
			default:
				printf("Enter a valid option!");
				break;
		}
	}
}

// Function to create a new node and return it to insertion
struct node *createNewNode() {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	
	// Prompt the user to enter data for the new node
	printf("Enter data: ");
	scanf("%d", &newNode->data);
	
	newNode->prev = NULL;
	newNode->next = NULL;
	
	return newNode;
}

// Function to insertion a new node at the BEGIN
struct node *insertBegin(struct node *root, struct node **tail) {
	struct node *newNode = createNewNode();
	
	// If the linked list is empty, make the new node the root
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

// Function to insertion a new node at the END
struct node *insertEnd(struct node *root, struct node **tail) {
	struct node *newNode = createNewNode();
	
	// If the linked list is empty, make the new node the root
	if(root == NULL) {
		root = newNode;
		*tail = root;
	} else {
		(*tail)->next = newNode;
		newNode->prev = *tail;
		*tail = newNode;
	}
	printf("%d inserted to the end of the doubly linked list.\n", (*tail)->data);
	
	// Return the updated root of the list
	return root;
}

// Function to insertion a new node at the SPESIFIED position
struct node *insertSpecific(struct node *root, struct node **tail) {
	struct node *newNode = createNewNode();
	
	// If the linked list is empty, make the new node the root
	if(root == NULL) {
		root = newNode;
		*tail = root;
		printf("%d inserted at the beginning of the doubly linked list.\n", newNode->data);
	} else {
		int position;
		
		printf("Enter the position you want to insert data: ");
		scanf("%d", &position);
		
		if(position == 1) {
			newNode->next = root;
			root->prev = newNode;
			root = newNode;
		} else {
			// Traverse the doubly linked list to find the specified position
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
			newNode->prev = iter;
			
			// If the newNode is at the end, update the tail
			if(newNode == (*tail)->next) {
				*tail = newNode;
			}
		}
		printf("%d inserted to %d position of the doubly linked list.\n", newNode->data, position);
	}
	
	// Return the updated root of the list
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
