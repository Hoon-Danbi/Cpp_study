//https://www.acmicpc.net/problem/17136

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int M[10][10];
int S[6]={0,5,5,5,5,5};
int result = INT_MAX;


void Dfs(int xy,int usecnt);
bool check(int x,int y,int size);
void fill(int x,int y,int size,int num);

int main(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin>>M[i][j];
        }
    }

    Dfs(0,0);

    if(result == INT_MAX){
        cout<<-1<<"\n";
    }else{
        cout<<result<<"\n";
    }

}

void Dfs(int xy,int usecnt){
    if(xy ==100){
        result = min(result,usecnt);
        return;
    }
    int x = xy %10;
    int y = xy /10;
    if (result <= usecnt)
    {
        return;
    }

    if(M[y][x]==1){
        for(int i=5;i>=1;i--){
            if(S[i]>0 && check(x,y,i)){
                S[i]--;
                fill(x,y,i,0);
                Dfs(xy+1,usecnt+1);
                S[i]++;
                fill(x,y,i,1);
            }
        }
    }else{
        Dfs(xy+1,usecnt);
    }
    
}

bool check(int x,int y,int size){
    if(x+size>10 ||y+size>10) return false;
    for(int i=y;i<y+size;i++){
        for(int j=x;j<x+size;j++){
            if(M[i][j] != 1) return false;
        }
    }
    return true;
}

void fill(int x,int y,int size,int num){
    for(int i=y;i<y+size;i++){
        for(int j=x;j<x+size;j++){
            M[i][j] = num;
        }
    }
}