#include <stdio.h>
#include <stdlib.h>

// Function & Variable declaration
void insertBegin(int arr[], int *size);
void deleteSpesific(int arr[], int *size);
void printArray(const int arr[], int size);

int i; // Declared to be used in for loops

int main(int argc, char *argv[]) {
	const int ARRAY_SIZE = 5;
	int arr[ARRAY_SIZE];
	int size = 0;
	int choice;
	
	printf("Choose an operation:\n");
    printf("1- Insertion at the beginning\n");
    printf("2- Deletion from the spesific position\n");
    printf("3- Print the elements of the array\n");
    printf("4- Exit\n");

	while(1) {
		printf("Your choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				if (size == ARRAY_SIZE) {
                    printf("Array is full! Delete some elements before insertion.\n");
                } else {
                    insertBegin(arr, &size);
                }
				break;
			case 2:
				if(size == 0) {
					printf("Array is empty! Add elements first.\n");
				} else {
					deleteSpesific(arr, &size);
				}
				break;
			case 3:
				if(size == 0) {
					printf("Array is empty! Add elements first.\n");
				} else {
					printArray(arr, size);
				}
				break;
			case 4:
				printf("Bye bye!");
				return 0; // Exit
			default:
				printf("Invalid choice! Please enter a valid option.\n");
				break;
		}
	}
	return 0;
}

void insertBegin(int arr[], int *size) {
	int data;
	(*size)++;
	
	// shift elements to the right
	for(i = *size; i >= 0; i--) {
		arr[i + 1] = arr[i];
	}
	
	printf("Enter the value you want to insert: ");
	scanf("%d", &data);
	arr[0] = data;
	printf("%d inserted to begin of the array.\n", data);
}

void deleteSpesific(int arr[], int *size) {
	int pos;
	
	printf("Enter the position you want to delete(1-5): ");
	scanf("%d", &pos);
	
	// check if position is valid
	if (pos < 1 || pos > *size) {
        printf("Invalid position! Please enter a valid position.\n");
    }
	else{
		int deletedValue = arr[pos - 1];
		
		for(i = pos - 1; i < *size - 1; i++) {
			arr[i] = arr[i + 1];
		}
		
		(*size)--;
		printf("%d deleted from the array.\n", deletedValue);
	}
}

void printArray(const int arr[], int size) {
	for(i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
