#include <stdio.h>
#include <stdbool.h>

int owner[11];
int neighbors[11];
int count = 0;

int binarySearch(int arr[], int low, int high, int target){
	while(low <= high){
		int mid = low + (high - low) / 2;
		
		if(arr[mid] == target){
			return mid;
		}
		if(arr[mid] < target){
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return -1;
}
void swap(int* xp, int* yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void bubbleSort(int arr[], int n){
	int i, j;
	bool swapped;
	
	for(int i = 0; i < n - 1; i++){
		swapped = false;
		for(j = 0; j < n - 1; j++){
			if(arr[j] > arr[j+1] && (( arr[j] != 0) && (arr[j+1] != 0))){
				swap(&arr[j], &arr[j+1]);
				swapped = true;
			}
		}
		
		if(swapped == false){
			break;
		}
	}
}
void primeOwner(int n){
	
	int c = 0;
	
	while (n % 2 == 0){
		owner[c] = 2; 
		n = n / 2;
		c++;
	}
	
	for(int i = 3; i * i <= n; i = i + 2){
		while(n % i == 0){
			owner[c] = i;
			c++;
			n = n / i;
		}
	}
	
	if(n > 2){
		owner[c] = n;
	}
}
void primeNeighbors(int n){
	
	int c = 0;
	
	while (n % 2 == 0){
		owner[c] = 2; 
		n = n / 2;
		c++;
	}
	
	for(int i = 3; i * i <= n; i = i + 2){
		while(n % i == 0){
			owner[c] = i;
			c++;
			n = n / i;
		}
	}
	
	if(n > 2){
		owner[c] = n;
	}
}
int main(){
	
	int n;
	scanf("%d", &n);
	primeOwner(n);
	bubbleSort(owner, 11);
	
//	int k = 0;
//	while(owner[k] != '\0'){
//		printf("%d ", owner[k]);
//		k++;
//	}
	
	for(int i = 0; i < 11; i++){
		for(int j = n - 1; j > 0; j--){
			primeNeighbors(j);
			bubbleSort(neighbors, 11);
			int k = 0;
			while(neighbors[k] != '\0'){
				printf("%d ", neighbors[k]);
				k++;
			}
		}
		
		
		
		int c = 0;
		while(neighbors[c] != '\0'){
			 int result = binarySearch(owner, 0, n, neighbors[c]);
			 if(result == -1){
			 	c++;
			 	printf("%d\n", c);
			 } else {
			 	count++;
			 	c++;
			 	printf("c = %d\n", c);
			 	printf("count = %d\n", count);
			 }
		}
	}
//	printf("%d\n", count);
	
//	int l = 0;
//	while(owner[l] != '\0'){
//		printf("%d\n", owner[l]);
//		l++;
//	}
//	int k = 0;
//	while(neighbors[k] != '\0'){
//		printf("%d\n", neighbors[k]);
//		k++;
//	}
	
		
	
	
	return 0;
}
