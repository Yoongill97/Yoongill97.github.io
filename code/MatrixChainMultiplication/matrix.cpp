#include <iostream>
 
using namespace std;
 
#define MIN(A, B) ((A)>(B)?(B):(A)) //#include <algorithm> �� ����
#define INF 9999999
#define MAX_SIZE 101
 
int M[MAX_SIZE][MAX_SIZE];
int d[MAX_SIZE];
 
int main()
{
    int size = 4;

    d[0] = 20, d[1] = 1, d[2] = 30, d[3] = 10, d[4] = 10;

    //(20*1), (1*30), (30*10), (10*10) 4���� ��������� ��Ұ� 5���� �� �򰥸��� x
    /*
    size = 6�̶��?
    1: 10 20
    2: 20 50
    3: 50 2
    4: 2 10
    5: 10 4
    6: 4 13
    ����� 6������ d[] = {10, 20, 50, 2, 10, 4, 13} �� ä������.
    */
 
    for (int diagonal = 0; diagonal < size; diagonal++)
    //���Ϸ��� ��� �����ŭ �ݺ��Ѵ�.
    {
        for (int i = 1; i <= size - diagonal; i++)
        // ��ܺ��� �����ؼ�, �ݺ�Ƚ���� 1�� �����ϰ� �ǰ�
        {
            int j = i + diagonal;
            //�ݺ��Ҷ����� �������� �̵���Ų��.
            if (j == i)
            {
                M[i][j] = 0;
                //����� �밢�� �κ�
                continue;
            }
            M[i][j] = INF;
            for (int k = i; k <= j - 1; k++)
                M[i][j] = MIN(M[i][j], M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j]);
                //����� �ϼ��ϴ� �ܰ� -> ���� �ּҰ��� ä��������.
        }
    }
 
    /*��� ���*/
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