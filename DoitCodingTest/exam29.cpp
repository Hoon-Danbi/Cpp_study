//https://www.acmicpc.net/problem/1260

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

//v:시작할 번호
int N,M,V;
vector<vector<int>> arr;
int visited[1001]={0};

void Dfs(int num,int depth);

int main(){
    cin>>N>>M>>V;
    
    arr.resize(N+1,vector<int>());

    for(int i=0;i<M;i++){
        int u,v; cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    for(int i=1;i<=N;i++){
        sort(arr[i].begin(),arr[i].end());
    }

    //DFS일떄 출력 
    visited[V]=1;
    cout<<V<<" ";
    Dfs(V,1);
    cout<<"\n";
    //visited[V]=0;

    fill(visited,visited+1001,0);

    //BFS 일때 출력 
    queue<int> q;
    
    q.push(V);
    visited[V]=1;

    while(!q.empty()){
        int num = q.front();
        q.pop();
        cout<<num<<" ";
        
        for(auto ch:arr[num]){
            if(!visited[ch]){
                visited[ch]=1;
                q.push(ch);
            }
        }
    }


    return 0;
}


void Dfs(int num,int depth){
    // 작은 숫자부터 접근
    for(auto num:arr[num]){
        if(!visited[num]){
            visited[num]=1;
            cout<<num<<" ";
            Dfs(num,depth+1);
            //visited[num]=0; -> 이게 들어가면 완전 탐색이 되어 버린다. 
        }
    }
    
}