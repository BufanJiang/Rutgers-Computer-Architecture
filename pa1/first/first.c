#include <stdio.h>
#include <stdlib.h>
void swap(int* ptr1, int* ptr2);

void evenOdd(int arr[], int size);

void ascSort(int arr[], int size);

void desSort(int arr[], int size);

void swap(int *ptr1, int* ptr2){
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

void evenOdd(int arr[], int size){
	int left = 0;
	int right = size - 1;
	while(left<right){
		while((arr[left]%2==0) && (left<right)){
			left++;
		}
		while((arr[right]%2!=0) && (left<right)){
			right--;
		}
		if(left<right){
			swap(&arr[left],&arr[right]);
			left++;
			right--;
		}
	}
}

void ascSort(int arr[], int size){
	int i;
	int j;
	for(i=0; i<size-1; i++){
		for(j=0; j<size-i-1; j++){
			if(arr[j]>arr[j+1]){
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}

void desSort(int arr[], int size){
	int i;
	int j;
	for(i=0; i<size-1; i++){
		for(j=size-1; j>i; j--){
			if(arr[j]>arr[j-1]){
				swap(&arr[j], &arr[j-1]);
			}
		}
	}
}

int main(int argc, char** argv){
	FILE *fp;
	fp = fopen(argv[1], "r");
	if(fp==NULL){
		printf("Could not open test.txt\n");
		return 1;
	}

	int num;
	fscanf(fp, "%d\n", &num);

	int arr[num];
	int i;
	for(i=0; i<num; i++){
		fscanf(fp, "%d\t", &arr[i]);
	}
	evenOdd(arr,num);

	int left;
	int right;
	int f;
	for(f=0; f<num; f++){
		if(arr[f]%2==1 || arr[f]%2==-1){
			left = f-1;
			right = f;
			break;
		}
	}
	ascSort(arr, left+1);
	desSort(&arr[right], num-right);
	int j;
	for(j=0; j<num; j++){
		printf("%d\t", arr[j]);
	}

	fclose(fp);
	return 0;
}	
