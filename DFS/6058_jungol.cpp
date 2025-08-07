#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<bool>> map;
vector<bool> visited;
int ans =0;
void DFS(int cnt){
    //cout<<"cnt: "<<cnt<<'\n';
    if(cnt==N){
        ans++;
        return;
    }
    for(int c=0;c<N;c++){
        //cout<<"cnt: "<<cnt<<" c: "<<c<<'\n';
        if(visited[c]) continue;
        if(!map[cnt][c]) continue;
        //cout<<"OK cnt: "<<cnt<<" c: "<<c<<'\n';
        visited[c] = true;
        DFS(cnt+1);
        visited[c] = false;
    }
}


int main(){
    cin>>N;
    visited.resize(N,false);
    map.resize(N,vector<bool>(N,true));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            char tmp;
            cin>>tmp;
            if(tmp == '#') map[i][j] = false;
        }
    }
//    for(int i=0;i<N;i++){
//         for(int j=0;j<N;j++){
//             cout<<map[i][j]<<" ";
//         }
//         cout<<'\n';
//     }
    DFS(0);
    cout<<ans;
}
