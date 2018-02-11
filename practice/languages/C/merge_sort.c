#include <stdio.h>

void merge_array(int arr[], int start, int end, int middle) {
	int leftPartIndex = middle - start + 1;
	int rightPartIndex = end - middle;
	int left[leftPartIndex];
	int right[rightPartIndex];
	//int left[50];
	//int right[50];

	for (int i = 0 ; i < leftPartIndex ; i++) left[i] = arr[start+i];
        for (int j = 0 ; j < rightPartIndex; j++) right[j] = arr[middle+1+j];
	
	int k,l,m;
	k=l=m=0;
	m = start;
	while (k < leftPartIndex && l < rightPartIndex) {
		if (left[k] <= right[l]) {arr[m] = left[k]; k++;}
		else {arr[m] = right[l]; l++;}
		m++;
	}

	while (k < leftPartIndex) {arr[m] = left[k]; k++;m++;}
	while (l < rightPartIndex) {arr[m] = right[l]; l++;m++;}
}

void merge_sort(int arr[], int start, int end) {
	if (start < end) {
		int middle = (start + end)/2;
		merge_sort(arr,start,middle);
		merge_sort(arr,middle+1,end);
		merge_array(arr, start, end, middle);
	}
}

int main() {
	int arr[5] = {4,3,2,5,2};
	for (int i = 0 ; i < 5; i++) {
	printf("%d ",arr[i]);}
	merge_sort(arr,0,5);
	printf("\n");
	for (int i = 0 ; i < 5; i++) {
	printf("%d ",arr[i]);}
}
