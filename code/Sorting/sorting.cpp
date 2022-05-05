#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

void BubbleSort(int* arr,int cnt){
    int temp;
    for(int i=0; i<cnt; i++){
        for(int j=0; j<cnt-1; j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void SelectionSort(int* arr, int cnt){
    int min = 10000, minIdx, temp;
    for(int i=0; i<cnt; i++){
        for(int j=i; j<cnt; j++){
            if(arr[j] < min){
                min = arr[j];
                minIdx = j;
            }
        }
        temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}
void InsertionSort(int* arr, int cnt){
    int temp;
    for(int i=1; i<cnt; i++){
        int j=i-1;
        while((arr[j]>arr[j+1]) && (j>=0)){
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            j--;
        }
    }
}
void ShellSort(int* arr, int cnt){
    int gap=cnt/2;
    int j,key;

    while(1){
        if(gap%2 == 0) gap++;
        for(int i=gap; i<cnt; i++){
            key=arr[i];
            for(j=i-gap; j>=0; j=j-gap){
                if(key < arr[j]) arr[j+gap] = arr[j];
                else break;
            }
            arr[j+gap] = key;
        }
        if(gap == 1) break;
        gap /= 2;
    }
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int here, int size) {
    int left = here * 2 + 1;
    int right = here * 2 + 2;
    int max=here;
    if (left < size&&arr[left]>arr[max])
        max = left;
    if (right < size&&arr[right]>arr[max])
        max = right;
 
    if (max != here) {
        swap(&arr[here], &arr[max]);
        heapify(arr, max, size);
    }
}
 
void buildHeap(int arr[], int size) {
    int i,j;
    for (i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, i, size);
        /*for (j = 0; j < size; j++)
            printf("%d ", arr[j]);
        printf("\n\n");*/
    }
}
 
void HeapSort(int arr[],int size) {
    int treeSize;
    buildHeap(arr, size);
    for (treeSize = size - 1; treeSize >= 0; treeSize--) {
        swap(&arr[0], &arr[treeSize]);
        heapify(arr, 0,treeSize);
    }
}
/*void Heap(int* arr, int cnt){
    for(int i=1; i<cnt; i++){
        int child = i;
        while(child>0){
            int root = (child-1)/2;
            if(arr[root] < arr[child]){
                int temp = arr[root];
                arr[root] = arr[child];
                arr[child] = temp;
            }
            child = root;
        }
    }
}
void HeapSort(int* arr, int cnt){
    Heap(arr, cnt);

    for(int i=cnt-1; i>=0; i--){
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;

        Heap(arr, i);
    }
}*/
void QuickSort(int* arr, int start, int end){
	if(start>=end){
		return;
	}
	
	int pivot = start;
	int i = pivot+1;
	int j = end;
	int temp;
	
	while(i<=j){
		while(i<=end && arr[i]<=arr[pivot]){
			++i;
		}
		while(j>start && arr[j]>=arr[pivot]){
			--j;
		}
		if(i>=j) break;

		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	temp = arr[j];
	arr[j] = arr[pivot];
	arr[pivot] = temp;
	
	QuickSort(arr, start, j-1);
	QuickSort(arr, j+1, end);
}
void Copy(int* arr1, int* arr2, int cnt){
    for(int i=0; i<cnt; i++) arr1[i] = arr2[i];
}

int main(){
    clock_t start_bubble, start_selection, start_insertion, start_shell, start_heap, start_quick,
            end_bubble, end_selection, end_insertion, end_shell, end_heap, end_quick;   //시간측정하기
    srand(time(0));

    int LENGTH_OF_ARRAY;

    for(int i=5; i<=20; i++){
        LENGTH_OF_ARRAY = int(pow(2,i));

        printf("입력 데이터 수 : %d\n\n", LENGTH_OF_ARRAY);

    int *random=(int*)malloc(sizeof(int)*LENGTH_OF_ARRAY);
    int *arr=(int*)malloc(sizeof(int)*LENGTH_OF_ARRAY);
    for(int i=0; i<LENGTH_OF_ARRAY; i++){
        random[i] = rand() % 1000;
    }

    //printf("정렬전\n");
    //for(int i=0; i<LENGTH_OF_ARRAY; i++)printf("%d\n", random[i]);

    Copy(arr, random, LENGTH_OF_ARRAY);
    start_bubble = clock();
    BubbleSort(arr,LENGTH_OF_ARRAY);
    end_bubble = clock();
    printf("<Bubble> 실행시간 : %f\n",(float)(end_bubble-start_bubble)/CLOCKS_PER_SEC);
    //for(int i=0; i<LENGTH_OF_ARRAY; i++)printf("%d\n", arr[i]);

    Copy(arr, random, LENGTH_OF_ARRAY);
    start_selection = clock();
    SelectionSort(arr, LENGTH_OF_ARRAY);
    end_selection = clock();
    printf("<Selection> 실행시간 : %f\n",(float)(end_selection-start_selection)/CLOCKS_PER_SEC);
    //for(int i=0; i<LENGTH_OF_ARRAY; i++)printf("%d\n", arr[i]);


    Copy(arr, random, LENGTH_OF_ARRAY);
    start_insertion = clock();
    InsertionSort(arr,LENGTH_OF_ARRAY);
    end_insertion = clock();
    printf("<Insertion> 실행시간 : %f\n",(float)(end_insertion-start_insertion)/CLOCKS_PER_SEC);
    //for(int i=0; i<LENGTH_OF_ARRAY; i++)printf("%d\n", arr[i]);


    Copy(arr, random, LENGTH_OF_ARRAY);
    start_shell = clock();
    ShellSort(arr,LENGTH_OF_ARRAY);
    end_shell = clock();
    printf("<Shell> 실행시간 : %f\n",(float)(end_shell-start_shell)/CLOCKS_PER_SEC);
    //for(int i=0; i<LENGTH_OF_ARRAY; i++)printf("%d\n", arr[i]);

    Copy(arr, random, LENGTH_OF_ARRAY);
    start_heap = clock();
    HeapSort(arr,LENGTH_OF_ARRAY);
    end_heap = clock();
    printf("<Heap> 실행시간 : %f\n",(float)(end_heap-start_heap)/CLOCKS_PER_SEC);
    //for(int i=0; i<LENGTH_OF_ARRAY; i++)printf("%d\n", arr[i]);

    Copy(arr, random, LENGTH_OF_ARRAY);
    start_quick = clock();
    QuickSort(arr,0,LENGTH_OF_ARRAY-1);
    end_quick = clock();
    printf("<Quick> 실행시간 : %f\n",(float)(end_quick-start_quick)/CLOCKS_PER_SEC);
    //for(int i=0; i<LENGTH_OF_ARRAY; i++)printf("%d\n", arr[i]);

    printf("\n");
    }

    return 0;
}