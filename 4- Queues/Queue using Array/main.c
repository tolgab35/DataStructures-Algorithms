#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

// Global variables
int queue[MAX_SIZE];
int rear = -1;

// Function Prototypes
void enqueue();		// Function to insert an element onto the queue
void dequeue();		// Function to delete an element from the queue
void front();		// Function to retrieve the front element of the queue
void traverse();	// Function to traverse and display elements of the queue
int isEmpty();		// Function to check if the queue is empty
int isFull();     	// Function to check if the queue is full
void getMenu();    	// Function to display the menu
int getChoice();   	// Function to get user's menu choice

int main() {
	getMenu();	// Display the initial menu
	while(1) {
		switch(getChoice()) {	// Get the user's choice and perform the corresponding operation
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				front();
				break;
			case 4:
				traverse();
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

void enqueue() {
	if(!isFull()) {
		printf("Enter the value to insert into the queue: ");
		int value;
		scanf("%d", &value);
		queue[++rear] = value;
		printf("%d inserted into the queue.\n", value);
	} else {
		printf("Queue is full!\n");
	}
}

void dequeue() {
	if(!isEmpty()) {
		int temp = queue[0];
		
		int i;
		for (i = 0; i < rear; i++) {
            queue[i] = queue[i + 1];
        }
        rear--;
		
		printf("%d deleted from the front of the queue.\n", temp);
	} else {
		printf("Queue is empty!\n");
	}
}

void front() {
	if(!isEmpty()) {
		printf("Front element of the queue: %d\n", queue[0]);
	} else {
		printf("Queue is empty!\n");
	}
}

void traverse() {
    if (!isEmpty()) {
    	printf("Elements in the queue: ");
    	int i;
        for (i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    } else {
    	printf("Queue is empty!\n");
	}
}

int isEmpty() {
	return rear == -1;
}

int isFull() {
	return rear == MAX_SIZE - 1;
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
