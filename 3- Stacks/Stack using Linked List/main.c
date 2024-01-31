#include <stdio.h>
#include <stdlib.h>

struct Stack {
	int data;
	struct Stack *next;
};

// Function Prototypes
void push(struct Stack **root);        // Function to push an element onto the stack
void pop(struct Stack **root);         // Function to pop an element from the stack
void peek(struct Stack **root);        // Function to retrieve the top element of the stack
void traverse(struct Stack **root);    // Function to traverse and display elements of the stack
int isEmpty(struct Stack *root);      // Function to check if the stack is empty
void getMenu();     // Function to display the menu
int getChoice();    // Function to get user's menu choice

int main() {
	struct Stack *root = NULL;
	
	getMenu();
	while(1) {
		switch(getChoice()) {
			case 1:
				push(&root);
				break;
			case 2:
				pop(&root);
				break;
			case 3:
				peek(&root);
				break;
			case 4:
				traverse(&root);
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

void push(struct Stack **root) {
	struct Stack *newNode = (struct Stack *)malloc(sizeof(struct Stack));
	
	printf("Enter the value that you want to push: ");
	scanf("%d", &(newNode->data));
	newNode->next = NULL;
	
	if(*root == NULL) {
		*root = newNode;
	} else {
		newNode->next = *root;
		*root = newNode;
	}
	
	printf("%d pushed into the stack.\n", newNode->data);
}

void pop(struct Stack **root) {
	if(!isEmpty(*root)) {
		printf("%d just popped out of the stack.\n", (*root)->data);
		*root = (*root)->next;
	} else {
        printf("Stack is empty, cannot pop!\n");
    }
}

void peek(struct Stack **root) {
	if(!isEmpty(*root)) {
		printf("%d is the top element of the stack.\n", (*root)->data);
	} else {
        printf("Stack is empty, cannot peek!\n");
    }
}

void traverse(struct Stack **root) {
	if(!isEmpty(*root)) {
		struct Stack *iter = *root;
		while(iter != NULL) {
			printf("%d ", iter->data);
			iter = iter->next;
		}
		printf("\n");
	} else {
        printf("Stack is empty, cannot display!\n");
    }
}

int isEmpty(struct Stack *root) {
	if(root == NULL) {
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
