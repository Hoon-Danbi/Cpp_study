//https://jungol.co.kr/problem/1681?cursor=OCw1LDI%3D
#include <iostream>
#include <vector>
using namespace std;
int N;
vector<vector<int>> map;
vector<bool> visited;
int min_res=0x7fffffff;
void DFS(int total,int depth,int cur){
    cout<<"cur: "<<cur<<" depth: "<<depth<<" total: "<<total<<'\n';
    if(total > min_res) return;
    if(depth==N){ // 모든 곳을 경유하고 나서 1로 추가 도달을 해주고난 결과값 total 과 min값을 비교해 갱신 한다. 
        total += map[cur][1];
        cout<<"min_res: "<<min_res<<" total: "<<total<<'\n';
        if(min_res >total){
            min_res=total;
        }    
    
        return;
    }
    
    //1부터 시작해서 끝점이 1이니까 절대 1에 들어가면 안되니까 2~N까지 찾아 간다. 
    for(int i=2;i<=N;i++){
        if(visited[i] || map[cur][i]==0) continue;
        visited[i]=true; // 방문 처리를 꼭 해줘야 한다. DFS, 재귀 호출 하기 전에
        DFS(total+map[cur][i],depth + 1,i);
        visited[i]=false; //백 트래킹을 하면서 return 하는 동작중에 방문 해제를 해서 나중에 다른 케이스에서 참조 할수 있도록 한다.
    }
}
int main() {
    cin>>N;
    map.resize(N+1,vector<int>(N+1));
    visited.resize(N+1,false);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>map[i][j];
        }
    }
    
    DFS(0,1,1);
    cout<<min_res;
    return 0;
}