#include <stdio.h>
#include <stdlib.h>

int getSumNegativeArrayElements(int*, int);
int getSumOfPositiveArrayElements(int*, int);

int main() {
	int size;
	int *array = NULL;

	printf("Input the array size: ");
	scanf("%d", &size);

	array = malloc(size * sizeof(int));

	printf("Input array elements: ");
	int i = 0;
	for (; i < size; i++)
	{
		scanf("%d", (array + i));
	}

	int positiveSum = getSumOfPositiveArrayElements(array, size);
	int negativeSum = getSumNegativeArrayElements(array, size);

	printf("\nResult:");
	printf("\n\tsum of positive elements = %d", positiveSum);
	printf("\n\tsum of negative elements = %d\n\n", negativeSum);

	return 0;

}

int getSumOfPositiveArrayElements(int* array, int size) {
	int sum = 0;
	int i = 0;

	for (; i < size; i++)
	{
		if (array[i] > 0) {
			sum += array[i];
		}
	}

	return sum;
}

int getSumNegativeArrayElements(int* array, int size) {
	int sum = 0;
	int i = 0;

	for (; i < size; i++) {
		if (array[i] < 0) {
			sum += array[i];
		}
	}
	return sum;
}
