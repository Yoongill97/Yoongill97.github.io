#include <iostream>
 
using namespace std;
 
#define MIN(A, B) ((A)>(B)?(B):(A)) //#include <algorithm> 도 가능
#define INF 9999999
#define MAX_SIZE 101
 
int M[MAX_SIZE][MAX_SIZE];
int d[MAX_SIZE];
 
int main()
{
    int size = 4;

    d[0] = 20, d[1] = 1, d[2] = 30, d[3] = 10, d[4] = 10;

    //(20*1), (1*30), (30*10), (10*10) 4개의 행렬이지만 요소가 5개인 것 헷갈리지 x
    /*
    size = 6이라면?
    1: 10 20
    2: 20 50
    3: 50 2
    4: 2 10
    5: 10 4
    6: 4 13
    행렬은 6개지만 d[] = {10, 20, 50, 2, 10, 4, 13} 가 채워진다.
    */
 
    for (int diagonal = 0; diagonal < size; diagonal++)
    //구하려는 행렬 사이즈만큼 반복한다.
    {
        for (int i = 1; i <= size - diagonal; i++)
        // 상단부터 시작해서, 반복횟수가 1씩 감소하게 되고
        {
            int j = i + diagonal;
            //반복할때마다 우측으로 이동시킨다.
            if (j == i)
            {
                M[i][j] = 0;
                //행렬의 대각선 부분
                continue;
            }
            M[i][j] = INF;
            for (int k = i; k <= j - 1; k++)
                M[i][j] = MIN(M[i][j], M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j]);
                //행렬을 완성하는 단계 -> 곱의 최소값을 채워나간다.
        }
    }
 
    /*결과 출력*/
    cout << M[1][size] << endl;
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}