#include <stdio.h>
#define N 10

// 	WORST CASE O(n^2)
//	AVARAGE CASE O)(nlogn)

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int pivot(int *arr, int low, int high){
	int mid = (low+high)/2;
	if(arr[mid]<arr[low])
		swap(&arr[mid],&arr[low]);
	if(arr[high]<arr[low])
		swap(&arr[high],&arr[low]);
	if(arr[high]<arr[mid])
		swap(&arr[high],&arr[mid]);

	return arr[mid];
}

int partition(int *arr, int low, int high){
	int middle = pivot(arr,low,high);
	int i=low+1;
	int j=high-1;
	for(;;){
			
		while(arr[i]<middle)
			i++;
		
		while (arr[j]>middle)
			j--;

		if(i>=j)
			return j;
		swap(&arr[i],&arr[j]);
	}
}

void quickSort(int *arr, int low, int high){
	if (low >= high) return; 
	int p = partition(arr,low,high);
	quickSort(arr,low,p);
	quickSort(arr,p+1,high);
}

int main(){
	int arr[N] = {6,7,9,1,8,3,0,4,5,2};
	quickSort(arr,0,N-1);
	for (int i = 0; i < N; ++i)
	{
		printf("%d ",arr[i] );
	}
}
