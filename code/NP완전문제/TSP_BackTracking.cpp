#include <stdio.h>

#define NUMBER_OF_POINT 5
#define I 9999

int TSPbacktrack(int graph[NUMBER_OF_POINT][NUMBER_OF_POINT]);
int MinArr(int arr[NUMBER_OF_POINT]);

int main(){
    int graph[NUMBER_OF_POINT][NUMBER_OF_POINT] 
    =   {
        {I, 2, 7, 3, 10},
        {2, I, 3, 5, 4},
        {7, 3, I, 6, 1},
        {3, 5, 6, I, 9},
        {10, 4, 1, 9, I}
        };

    printf("%d", TSPbacktrack(graph));

    return 0;
}



int TSPbacktrack(int graph[NUMBER_OF_POINT][NUMBER_OF_POINT]){
    //i���� ����ؼ� ���� ª���� ã�´�.
    //���°����� ����

    //������ ������ �ٽ� ª���� ã�´�.
    //���°����� ����

    //Ž���� �������� Best���� ������Ʈ.

    //�ڷ� ���ư��� ���°��� ���� ������ Ž���� �� Best�� ������Ʈ.
}