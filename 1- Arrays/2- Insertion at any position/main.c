#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 5

// Function & Variable declaration
void insertSpesific(int arr[], int size);
void insertBegin(int arr[], int size);
void insertEnd(int arr[], int size);
void shiftElementsRight(int arr[], int pos, int size);
int isValidPosition(int pos, int size);
void printArray(const int arr[], int size);

int i; // Declared to be used in for loops

int main(int argc, char *argv[]) {
	int arr[ARRAY_SIZE] = {1, 2, 3, 4, 5};	
	int choice;
	
	printf("Choose an operation:\n");
    printf("1- Insertion at specific position\n");
    printf("2- Insertion at the beginning\n");
    printf("3- Insertion at the end\n");
    printf("4- Print the elements of the array\n");
    printf("5- Exit\n");

	while(1) {
		printf("Your choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				insertSpesific(arr, ARRAY_SIZE);
				break;
			case 2:
				insertBegin(arr, ARRAY_SIZE);
				break;
			case 3:
				insertEnd(arr, ARRAY_SIZE);
				break;
			case 4:
				printArray(arr, ARRAY_SIZE);
				break;
			case 5:
				printf("Bye bye!\n");
				return 0; // Exit situation hehheh
			default:
				printf("Not a valid choice!\n");
				break;
		}
	}
	return 0;
}

void insertSpesific(int arr[], int size) {
	int pos, data;
	
	printf("Enter a position you'd like to insert at in array: ");
	scanf("%d", &pos);
	
	if(isValidPosition(pos, size)) {
		printf("Enter a value that you want to insert: ");
		scanf("%d", &data);
		
		shiftElementsRight(arr, pos, size);
		
		arr[pos - 1] = data;
		printf("%d inserted to %dth element in the array.", data, pos);
	}
	printf("\n");
}
void insertBegin(int arr[], int size) {
	int data;
	
	printf("Enter a value that you want to insert to begin: ");
	scanf("%d", &data);
	
	shiftElementsRight(arr, 0, size);
	
	arr[0] = data;
	printf("%d inserted to begin of the array.\n", data);
}
void insertEnd(int arr[], int size) {
	int data;
	
	printf("Enter a value that you want to insert to end: ");
	scanf("%d", &data);

	arr[size - 1] = data;
	printf("%d inserted to end of the array.\n", data);
}

void shiftElementsRight(int arr[], int pos, int size) {
	for(i = size - 1; i >= pos - 1; i--) arr[i] = arr[i - 1];
}
int isValidPosition(int pos, int size) {
	if(!(pos <= size && pos > 0)) {
		printf("Invalid position!\n");
        return 0;
	}
	else return 1;
}

void printArray(const int arr[], int size) {
	printf("Elements of the array are:\n");
	for(i = 0; i < size; i++) printf("%d ", arr[i]);
	printf("\n");
}
