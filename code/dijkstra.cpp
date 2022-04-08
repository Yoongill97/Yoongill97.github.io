#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <algorithm>

int graph[100][100];
int INF = INT_MAX/2;

int find(int x){
    bool visited[sizeof(graph)];

    int min = INF;
    int idx = 0;
    for(int i=0; i<sizeof(graph); i++){
        if(graph[x][i] < min || visited[i] == false){
            min = graph[x][i];
            idx = i;
        }
    }

    //


    //  경유지 선택
        //  업데이트 (경유, 직행)

    

    return NULL;
}

int main(){
    
}