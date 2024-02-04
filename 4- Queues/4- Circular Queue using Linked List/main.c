#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

// Function Prototypes
void enqueue(struct Node **root, struct Node **rear);	// Function to insert an element onto the queue
void dequeue(struct Node **root, struct Node **rear);	// Function to delete an element from the queue
void front(struct Node *root);		// Function to retrieve the front element of the queue
void traverse(struct Node *root);	// Function to traverse and display elements of the queue
int isEmpty(struct Node *root);		// Function to check if the queue is empty
void getMenu();    	// Function to display the menu
int getChoice();   	// Function to get user's menu choice

int main() {
	struct Node *root = NULL;
	struct Node *rear = NULL;
	
	getMenu();	// Display the initial menu
	while(1) {
		switch(getChoice()) {	// Get the user's choice and perform the corresponding operation
			case 1:
				enqueue(&root, &rear);
				break;
			case 2:
				dequeue(&root, &rear);
				break;
			case 3:
				front(root);
				break;
			case 4:
				traverse(root);
				break;
			case 5:
				printf("Bye!\n");
				return 0;
			default: 
				printf("Not a valid choice!\n");
				break;
		}
	}	
}

void enqueue(struct Node **root, struct Node **rear) {
	printf("Enter the value to insert into the queue: ");
	int value;
	scanf("%d", &value);
	
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = newNode;
	
	if(isEmpty(*root)) {
		*root = newNode;
		*rear = *root;
	} else {
		(*rear)->next = newNode;
		newNode->next = *root;
		*rear = newNode;
	}
	
	printf("%d inserted into the queue.\n", value);
}

void dequeue(struct Node **root, struct Node **rear) {
	if(isEmpty(*root)) {
		printf("Queue is empty!\n");
	} else {
		struct Node *deletedNode = *root;
		*root = (*root)->next;
		
		printf("%d deleted from the front of the queue.\n", deletedNode->data);
		
		if(*root == deletedNode) {
			*root = NULL;
			*rear = NULL;
		} else {
			(*rear)->next = *root;
		}
		free(deletedNode);
	}
}

void front(struct Node *root) {
	if(isEmpty(root)) {
		printf("Queue is empty!\n");
	} else {
		printf("Front element of the queue: %d\n", root->data);
	}
}

void traverse(struct Node *root) {
    if (isEmpty(root)) {
    	printf("Queue is empty!\n");
    } else {
    	printf("Elements in the queue: ");
    	struct Node *iter = root;
        do {
            printf("%d ", iter->data);
            iter = iter->next;
        } while(iter != root);
        printf("\n");
	}
}

int isEmpty(struct Node *root) {
	return root == NULL;
}

void getMenu() {
	printf("\n-- QUEUE MENU --\n");
    printf("1. Enqueue (Insert)\n");
    printf("2. Dequeue (Delete)\n");
    printf("3. Front (Peek)\n");
    printf("4. Traverse (Display)\n");
    printf("5. Quit\n");
    printf("-----------------\n");
}

int getChoice() {
	int choice;
	printf("\nEnter your choice (1-5): ");
	scanf("%d", &choice);
	return choice;
}
