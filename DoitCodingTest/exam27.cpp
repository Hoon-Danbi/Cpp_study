//https://www.acmicpc.net/problem/9663

#include <iostream>
#include <cmath>
using namespace std;


int A[15];;
int N;
int cnt=0;

void Dfs(int row);
bool check(int row);

int main(){
    cin>>N;
    Dfs(0);
    cout<<cnt;
    return 0;
}

void Dfs(int row){
    if(row ==N){
        cnt++;
        return;
    }
    for(int i=0;i<N;i++){
        A[row]=i;
        if(check(row)) Dfs(row+1);
    }
}

bool check(int row){
    for(int i=0;i<row;i++){
        if(A[i] ==A[row]) return false;
        if(abs(row-i) == abs(A[i]-A[row])) return false;
    }
    return true;
}