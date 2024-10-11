#include <stdio.h>
#include <string.h>

// syntax sorting:
// 		- quickSort (adv)

void swap(int *a, int *b);
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void merge(int arr[], int left, int right);
void mergeSort(int arr[], int left, int right);
int linearSearch(int arr[], int n, int target);
int binarySearch(int arr[], int left, int right, int target);
int leftMostBinarySearch(int arr[], int left, int right, int target);
int rightMostBinarySearch(int arr[], int left, int right, int target);
int interpolationSearch(int arr[], int left, int right, int target);
int main(){
	
	int arr[10] = {4, 5, 8, 6, 9, 7, 1, 2, 3, 10};
	int length = sizeof(arr) / sizeof(arr[0]);
	printf("Length = %d\n", length);
	printf("\n");
	
	//Sorting
	printf("Before sorted: ");
	for(int i = 0; i < length; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	
//	bubbleSort(arr,length);
//	mergeSort(arr,0,length-1);
//	selectionSort(arr,length);
//	insertionSort(arr,length);
//	
//	
//	printf("After sorted: ");
//	for(int i = 0; i < length; i++){
//		printf("%d ", arr[i]);
//	}
//	printf("\n");

//	Searching
//	printf("\nMasukan angka yang ingin dicari: ");
//	int target;
//	scanf("%d", &target);
//	getchar();
//	
//	int hasil = linearSearch(arr,length,target);
//	int hasil = binarySearch(arr, 0, length - 1, target);
//	int hasil = interpolationSearch(arr, 0, length - 1, target);
//	
//	if(hasil == -1){
//		printf("Angka tidak ditemukan!\n");
//	} else {
//		printf("Angka yang dicari berada di index ke-%d\n", hasil);
//	}
	
	return 0;
}
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void bubbleSort(int arr[], int n){
	
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(arr[j] > arr[j+1]){
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
	
}
void selectionSort(int arr[], int n){
	
	for(int i = 0; i < n - 1; i++){
		int minIdx = i;
		
		for(int j = (i+1); j < n; j++){
			if(arr[j] < arr[minIdx]){
				minIdx = j;
			}
		}
		
		swap(&arr[i], &arr[minIdx]);
		
	}
	
	
}
void insertionSort(int arr[], int n){
	
	for(int i = 1; i < n; i++){
		int temp = arr[i];
		int j = i - 1;
		
		for(j; j >= 0; j--){
			if(arr[j] > temp){
				arr[j+1] = arr[j];
			}
			else {
				break;
			}
		}
		
		arr[j+1] = temp;
		
	}
	
}
void merge(int arr[], int left, int right){
	int mid = (left + right) / 2;
	int sortedArr[right - left + 1];
	int curr = 0;
	int leftIdx = left;
	int rightIdx = mid + 1;
	
	//Compare value
	while(leftIdx <= mid && rightIdx <= right){
		if(arr[leftIdx] < arr[rightIdx]){
			sortedArr[curr] = arr[leftIdx];
			curr++;
			leftIdx++;
		} else if (arr[leftIdx] > arr[rightIdx]){
			sortedArr[curr] = arr[rightIdx];
			curr++;
			rightIdx++;
		} else if(arr[leftIdx] == arr[rightIdx]){
			sortedArr[curr] = arr[rightIdx];
			curr++;
			rightIdx++;
		}
	}
	
	//The rest value
	while(leftIdx <= mid){
		sortedArr[curr] = arr[leftIdx];
		curr++;
		leftIdx++;
	}
	
	//The rest value
	while(rightIdx <= right){
		sortedArr[curr] = arr[rightIdx];
		curr++;
		rightIdx++;
	}
	
	//Insert sorted value to real variable
	for(int i = 0; i < curr; i++){
		arr[i + left] = sortedArr[i];
	}
	
}
void mergeSort(int arr[], int left, int right){
	
	if(left < right){
		int mid = (left + right) / 2;
		// Divide data
		mergeSort(arr, left, mid);
		mergeSort(arr,mid + 1, right);
		// Merge and Sort Data
		merge(arr,left,right);
	}
	
}
int linearSearch(int arr[], int n, int target){
	for(int i = 0; i < n; i++){
		if(arr[i] == target){
			return i;
		} 
	}
	return -1; // not found
}
int binarySearch(int arr[], int left, int right, int target){
	
	while(left <= right){
		int mid = (left + right) / 2;
		
		if(arr[mid] == target){
			return mid;
		} else if(arr[mid] > target){
			right = mid - 1;
		} else if(arr[mid] < target){
			left = mid + 1;
		}
	}
	
	return -1;
}
int leftMostBinarySearch(int arr[], int left, int right, int target){
	
	while(left <= right){
		int mid = (left + right) / 2;
		//Kondisi 1: kalau array di index tengah itu udah sama dengan target
		if(arr[mid] == target){ // Kita harus mencari keberedaan target di sisi kiri mid
			//Cara andrew (faster)
			int cek_kiri = leftMostBinarySearch(arr, left, mid - 1, target);
			if(cek_kiri == -1){ // Artinya gaada data yang sama dengan target di sisi kiri mid
				return mid;
			}
			else {
				return cek_kiri;
			}
			//Cara iqbal
//			for(int i = 0; i < mid; i++){
//					if(arr[i] == target){
//						return i;
//					}
//			}
			
		}
		//Kondisi 2: kalau array di index tengah > target
		else if(arr[mid] > target){
			right = mid - 1;
		}
		//Kondisi 3: kalau array di index tengah < target
		else if(arr[mid] < target){
			left = mid + 1;
		}
	}
	
	return -1;
}
int rightMostBinarySearch(int arr[], int left, int right, int target){
	
	while(left <= right){
		int mid = (left + right) / 2;
		//Kondisi 1: kalau array di index tengah itu udah sama dengan target
		if(arr[mid] == target){
			//Cara andrew (faster)
			int cek_kanan = rightMostBinarySearch(arr, mid + 1, right, target);
			if(cek_kanan == -1){
				return mid;
			}
			else {
				return cek_kanan;
			}
			
//			Cara iqbal
//			for(int i = right; i > mid; i--){
//				if(arr[i] == target){
//					return i;
//				}
//			}
			
		}
		//Kondisi 2: kalau array di index tengah > target
		else if(arr[mid] > target){
			right = mid - 1;
		}
		//Kondisi 3: kalau array di index tengah < target
		else if(arr[mid] < target){
			left = mid + 1;
		}
	}
	
	return -1;
}
int interpolationSearch(int arr[], int left, int right, int target){

	
	while(left <= right){
		if((arr[left] <= target) && (arr[right] >= target)){
			int mid = (left + right) / 2;
			
			if(arr[mid] == target){
				return mid;
			}
			else if(arr[mid] > target){
				right = mid - 1;
			} 
			else if(arr[mid] < target){
				left = mid + 1;
			}
		} 
		else {
			return -1;
		}
	}
	
	return -1; // not found
}