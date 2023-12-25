#include <stdio.h>
#include <stdlib.h>

// Function declaration
void insertArray(int arr[], int size);
void printArray(int arr[], int size);

int main(int argc, char *argv[]) {
	int arr[10], size, i; // I selected 10 as upper bound of the array
	
	printf("Enter size of the array(1 - 10): ");
	scanf("%d", &size);
	
	if(!(size <= 10 && size > 0)) {
		printf("Invalid array size. Exiting...\n");
        return 1; // Exit with an error code
	}
	printf("\n");
	
	insertArray(arr, size);
	printArray(arr, size);
	
	return 0;

}

int i;
void insertArray(int arr[], int size){
	printf("Enter elements of the array: \n");
	for(i = 0; i < size; i++) {
		printf("Enter %d. element: ", (i + 1));
		scanf("%d", &arr[i]);
	}
	printf("\n");
}
void printArray(int arr[], int size){
	printf("Elements of the array are:\n");
	for(i = 0; i < size; i++) printf("%d ", arr[i]);
	printf("\n");
}

