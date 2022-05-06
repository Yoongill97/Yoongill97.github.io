#include <iostream>
#include <vector>
#include <time.h>
#include <math.h>

using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(vector<int>& arr, int l, int r) {
	int pivot = arr[r];
	int i = l - 1;

	for (int j = l; j < r; j++) {
		if (pivot > arr[j]) {
			i++;
			swap(arr[i], arr[j]);
		}
	}

	swap(&arr[i + 1], &arr[r]);
	return (i + 1);
}
void QuickSort2(vector<int>& arr, int l, int r) {
	int st[1000];
	int top = -1;
	st[++top] = l;
	st[++top] = r;

	while (top >= 0) {		
		int tr = st[top--];
		int tl = st[top--];
		
		int p = partition(arr, tl, tr);
		if (p - 1 > tl) {
			st[++top] = tl;
			st[++top] = p - 1;
		}

		if (p + 1 < tr) {
			st[++top] = p + 1;
			st[++top] = tr;
		}
	}
}

int main(){
    clock_t start_quick, end_quick;   //시간측정하기
    srand(time(0));

    int LENGTH_OF_ARRAY;
    

    for(int i=5; i<=20; i++){
        LENGTH_OF_ARRAY = int(pow(2,i));
        vector<int> a(LENGTH_OF_ARRAY);

        printf("입력 데이터 수 : %d\t", LENGTH_OF_ARRAY);
        for(int j=0; j<LENGTH_OF_ARRAY; j++){
          a[j] = rand() % 1000;
        }

        start_quick = clock();
        QuickSort2(a,0,LENGTH_OF_ARRAY-1);
        end_quick = clock();
        printf("실행시간 : %f\n",(float)(end_quick-start_quick)/CLOCKS_PER_SEC);
    }
    return 0;
}