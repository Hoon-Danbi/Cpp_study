//https://www.acmicpc.net/problem/1926
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Point{
    int x,y;
};
vector<vector<int>> map;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
int max_res;
void BFS(int x,int y){
    queue<Point> q;
    q.push({x,y});
    map[y][x] =0;
    max_res=1;
    while(!q.empty()){
        Point cur=q.front(); q.pop();
        for(int i=0;i<4;i++){
            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];
            if(map[ny][nx]==0) continue;
            q.push({nx,ny});
            max_res +=1;
            map[ny][nx]=0;
        }
    }
    
}


int main(){
    int N,M;
    cin>>N>>M;
    map.resize(N+2,vector<int>(M+2));
    int tmp;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>tmp;
            map[i][j]=tmp;
        }
    }
    int count=0;
    int max_ele=0;
    vector<int>ans;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(map[i][j]==0) continue;
            BFS(j,i);
            count +=1;
            max_ele=max(max_ele,max_res);          
            max_res=0;
        }
    }
    
    cout<<count<<'\n';
    cout<<max_ele<<'\n';
    return 0;
}