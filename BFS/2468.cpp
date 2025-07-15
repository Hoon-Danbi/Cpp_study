//https://www.acmicpc.net/problem/2468
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N;
struct node{
    int x,y;
};
vector<vector<int>> map;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};

int BFS_ans(int set){
    queue<node> q;
    vector<vector<bool>> visited(N,vector<bool>(N,false));
    int dist=0;
    for (int i=0; i<N; i++) {
        for(int j=0;j<N;j++){
            if(map[j][i]<=set||visited[j][i]) continue;
            dist++;
            q.push({i,j});
            visited[j][i]=true;
            
            while(!q.empty())
            {
                node cur=q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int nx=cur.x + dx[k];
                    int ny=cur.y + dy[k];
                    if(nx<0 || nx>=N || ny<0||ny>=N) continue;
                    if(visited[ny][nx]) continue;
                    if(map[ny][nx] <= set) continue;
                    q.push({nx,ny});
                    visited[ny][nx]=true;
                }                
            }
        }
    }
    return dist;
}

int main() {
    cin>>N;
    map.resize(N,vector<int>(N));
    int tmp;
    int max_high=0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin>>tmp;
            max_high=max(max_high,tmp);
            map[i][j]=tmp;
        }
    }
    int max_ans=1;
    int temp=0;
    for(int i=1;i<=max_high;i++){
        temp = BFS_ans(i);
        max_ans = max(max_ans,temp);
        //cout<<"BFS: "<<temp<<"  Max_ans: "<<max_ans<<'\n';
    }
    cout<<max_ans;
    return 0;
}