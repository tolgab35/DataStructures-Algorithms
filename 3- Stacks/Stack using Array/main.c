#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

int stack[MAX_SIZE];
int top = -1;

// Function Prototypes
void push();        // Function to push an element onto the stack
void pop();         // Function to pop an element from the stack
void peek();        // Function to retrieve the top element of the stack
void traverse();    // Function to traverse and display elements of the stack
int isEmpty();      // Function to check if the stack is empty
int isFull();       // Function to check if the stack is full
void getMenu();     // Function to display the menu
int getChoice();    // Function to get user's menu choice

int main() {
	getMenu();
	while(1) {
		switch(getChoice()) {
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				peek();
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

void push() {
	if(!isFull()) {
		printf("Enter the value that you want to push: ");
		int value;
		scanf("%d", &value);
		stack[++top] = value;
		printf("%d pushed into the stack.\n", value);
	}
}

void pop() {
	if(!isEmpty()) {
		int temp = stack[top--];
		printf("%d just popped out of the stack.\n", temp);
	}
}

void peek() {
	if(!isEmpty()) {
		printf("%d is the top element of the stack.\n", stack[top]);
	}
}

void traverse() {
	if(!isEmpty()) {
		int i = top;
		while(i != -1) {
			printf("%d ", stack[i--]);
		}
		printf("\n");
	}
}

int isEmpty() {
	if(top == -1) {
		printf("Stack Underflow!\n");
		return 1;
	}
	return 0;
}

int isFull() {
	if(top == MAX_SIZE - 1) {
		printf("Stack Overflow!\n");
		return 1;
	}
	return 0;
}

void getMenu() {
	printf("- MENU-------------------------------------\n");
	printf("- Enter 1 to push elements into the stack\n");
	printf("- Enter 2 to pop element from the stack\n");
	printf("- Enter 3 to show peek element of the stack\n");
	printf("- Enter 4 to display elements of the stack\n");
	printf("- Enter 5 to quit program\n");
	printf("- -----------------------------------------\n");
}

int getChoice() {
	int choice;
	printf("\n- Your Choice: ");
	scanf("%d", &choice);
	return choice;
}
