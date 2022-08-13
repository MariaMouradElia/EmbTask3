#pragma warning(disable : 4996)
#include <stdlib.h>
#include <stdio.h>
int numbers[30];

int arr_is_sorted(int *arr,int n);
void bubble_sort(int* arr, int n);
void swap(int* arr, int a, int b);
int binarySearch(int value, int a, int z);

int main() {
	int size;
	int key = 0;
	int i;
	int index;

	
	printf("please enter  numbers that you want to sort:\n");
	
	for (i = 0; i<5; i++)
		scanf("%d", &numbers[i]);

	size = i;

	if (arr_is_sorted(&numbers, size) == 0) {
		bubble_sort(&numbers, size);
		printf("\nyour array after being sorted is:\n");
		for (i = 0; i < 5; i++) {
			printf("%d", numbers[i]);
		}
		printf("\n");
	}
	else
		printf("\nyour array is already sorted !");


	printf("\nwhich number do you want to search for?\n");
	scanf("%d", &key);

	index = binarySearch(key, 0 , size);
	if (index == -1)
		printf("your number does not exist in the entered array !");
	else
		printf("your number is at index %d in the array", index);

	return 0;
}

int arr_is_sorted(int *arr, int n) {
	for (int i = 0; i < n-1; i++) {
		if (arr[i] > arr[i + 1]) {
			return 0;
		}
	}
	return 1;
}

void bubble_sort(int* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr, j, j + 1);
			}
		}
	}
}

void swap(int* arr, int a, int b) {
	int temp = 0;
	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}


int binarySearch(int value, int a, int z) {
	while (a <= z) {
		int mid = a + (z - a) / 2;

		if (numbers[mid] == value)
			return mid;

		else if (numbers[mid] > value)
			z = mid - 1;

		else
			a =  mid + 1; 
	}
	return -1;
}

