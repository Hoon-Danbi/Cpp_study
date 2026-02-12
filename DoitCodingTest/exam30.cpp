//https://www.acmicpc.net/problem/2178

// N x M 크기 배열 미로 1: 이동 가능 0: 이동 불가 
// 1,1 -> N,M  위치로 이동시 지나야할 최소 칸수 갯수 

#include <iostream>
#include <queue>
#include <string>
using namespace std;

int arr[102][102] = {0}; //0  맴의 가에 0으로 패딩 해서 못 나가게 처리 
int visited[102][102] = {0};
int N,M;
int del_row[4] ={-1,1,0,0}; //상하좌우
int del_col[4] ={0,0,-1,1};

struct node{
    int row,col;
};

int main(){
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        string str; cin>>str;
        for(int j=1;j<=M;j++){
            arr[i][j] = str[j-1] - '0';
        }
    }

    queue<node> q;
    q.push({1,1});
    visited[1][1]=1;

    while(!q.empty()){
        node xy = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int n_row = xy.row + del_row[i];
            int n_col = xy.col + del_col[i];
            if(!arr[n_row][n_col] || visited[n_row][n_col]) continue;
            q.push({n_row,n_col});
            visited[n_row][n_col]=1;

            arr[n_row][n_col] += arr[xy.row][xy.col]; 
        } 
    }
    cout<<arr[N][M];

    return 0;
}

