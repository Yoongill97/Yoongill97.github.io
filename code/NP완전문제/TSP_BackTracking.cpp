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
    //i에서 출발해서 가장 짧은걸 찾는다.
    //상태공간에 저장

    //도착한 점에서 다시 짧은걸 찾는다.
    //상태공간에 저장

    //탐색이 끝났으면 Best값에 업데이트.

    //뒤로 돌아가서 상태공간 값이 작으면 탐색한 후 Best값 업데이트.
}