//https://www.acmicpc.net/problem/11724

#include <iostream>
#include <vector>

using namespace std;


vector<vector<int>> arr;
vector<int> visited;

void dfs(int u){
    //혹시나 이미 접근한 노드에 다시 접근 방지 기능 
    if(visited[u]) return;

    //접근 했으니 방문 처리 
    visited[u] = 1;
    //인접 노드 접근 후 방문 하기 
    for(int i=0;i<arr[u].size();i++){
        int next_num = arr[u][i];
        //방문 하지 않은 노드만 접근 
        if(!visited[next_num]){
            //cout<<"input: "<<next_num<<"\n";
            dfs(next_num);
            //cout<<"output: "<<next_num<<"\n";
        }
    }
}


int main(){
    int N,M; cin>>N>>M;
    //arr.assign(N,vector<int>());
    arr.resize(N+1);
    visited.assign(N+1,0);
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    int res=0;
    for(int i=1;i<=N;i++){
        //방문 하지 않은 노드 접근 할때 DFS , res++
        if(!visited[i]){
            res++;
            dfs(i);
        }
    }
    cout<<res;
    return 0;
}