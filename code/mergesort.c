#include <stdio.h>
#define SIZE_OF_ARRAY 10

void merge(int data[], int start, int middle, int end);
void mergeSort(int data[], int start, int end);


int main(){
    int arr[SIZE_OF_ARRAY] = {31,24,5,1,37,4,12,36,42,16};
    printf("정렬 전 : ");
    for(int i= 0; i < SIZE_OF_ARRAY; i++)
        printf("%d ", arr[i]);
    mergeSort(arr, 0, SIZE_OF_ARRAY - 1);
    printf("\n정렬 후 : ");
    for(int i= 0; i < SIZE_OF_ARRAY; i++)
        printf("%d ", arr[i]);
    
    return 0;
}

void merge(int data[], int start, int middle, int end){
    int i, j, k;
    int temp[1000];
    i = start;
    j = middle + 1;
    k = start;

    while(i <= middle && j <= end){
        if(data[i] <= data[j]){
            temp[k] = data[i];
            i++;
        }
        else{
            temp[k] = data[j];
            j++;
        }
        k++;
    }
    if(i > middle){
        for(int t = j; t <= end; t++){
            temp[k] = data[t];
            k++;
        }
    }
    else{
        for(int t = i; t <= middle; t++){
            temp[k] = data[t];
            k++;
        }
    }
    for(int t = start; t <= end; t++)
        data[t] = temp[t];
}

void mergeSort(int data[], int start, int end){
    if(start < end){
        int middle;
        middle = (start + end) / 2;
        mergeSort(data, start, middle);
        mergeSort(data, middle + 1, end);
        merge(data, start, middle, end);
    }
}