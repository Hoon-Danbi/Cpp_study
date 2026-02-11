//https://www.acmicpc.net/problem/13023


// 깊이 탐색해서 4가 되면 1   불가능 하면 0

#include <vector>
#include <iostream>
using namespace std;
vector<vector<int>> friends;
vector<bool> visited;

bool is_friends = false;

void Dfs(int i,int depth){
    //깊이가 4가 되면 true 출력 
    if(depth ==4){
        is_friends=true;
        return;
    }
    //방문 하지 않은 인접 노트 접근 들어 갈때 방문 처리 , 백트래킹으로 false 지정 까지 
    for(auto num:friends[i]){
        if(!visited[num]){
            //방문 하지 않았을때: 접근 
            visited[num]=true;
            Dfs(num,depth+1);
            visited[num]=false;
        }
    }


}


int main(){
    int N,M; cin>>N>>M;
    friends.resize(N);
    visited.assign(N,false);

    for(int i=0;i<M;i++){
        int u,v; cin>>u>>v;
        friends[u].push_back(v);
        friends[v].push_back(u);
    }

    for(int i=0;i<N;i++){
        visited[i]=true;
        Dfs(i,0);
        if(is_friends){
            cout<<1;
            return 0;
        }
        visited[i]=false;
    }

    cout<<0;
    return 0;
}