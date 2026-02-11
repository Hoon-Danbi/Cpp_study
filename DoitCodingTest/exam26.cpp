//https://www.acmicpc.net/problem/15649

#include <iostream>
#include <vector>
using namespace std;

vector<bool> visited;
vector<int> number;
int N,M;

void Dfs(int num , int depth){
    if(depth == M){
        for(auto num:number){
            cout<<num<<" ";
        }
        cout<<"\n";
        
        return;
    }
    for(int i=1;i<=N;i++){
        if(!visited[i]){
            visited[i]=true;
            number.push_back(i);
            Dfs(i,depth+1);
            visited[i]=false;
            number.pop_back();
        }
    }
}

int main(){
    cin>>N>>M;
    visited.assign(N+1,false);
    
    for(int i=1;i<=N;i++){
        visited[i]=true;
        number.push_back(i);
        Dfs(i,1);
        visited[i]=false;
        number.pop_back();
    }
    return 0;
}