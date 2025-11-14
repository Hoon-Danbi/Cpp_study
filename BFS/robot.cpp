//https://jungol.co.kr/problem/1006?cursor=OCw1LDg%3D
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//동 서 남 북
int dir_drow[5]={0,0,0,1,-1};
int dir_dcol[5]={0,1,-1,0,0};

int turn_left(int i){
    if(i==1) return 4;
    if(i==2) return 3;
    if(i==3) return 1;
    if(i==4) return 2;
    return -1;
}
int turn_right(int i){
    if(i==1) return 3;
    if(i==2) return 4;
    if(i==3) return 2;
    if(i==4) return 1; 
    return -1;
}
struct point{
  int row,col,dir,count;  
};
int main(){
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>> map(n+2,vector<int>(m+2,1));
    vector<vector<vector<int>>> visited(n+1,vector<vector<int>>(m+1,vector<int>(5,0)));
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            cin>>map[i][j];
        }
    }
    int start_row,start_col,start_dir;
    cin>>start_row>>start_col>>start_dir;
    int end_row,end_col,end_dir;
    cin>>end_row>>end_col>>end_dir;

    queue<point> q;
    q.push({start_row,start_col,start_dir,1});
    visited[start_row][start_col][start_dir]=1;
    
    while(!q.empty()){
        point cur=q.front(); q.pop();

        //1,2,3 앞으로 전진 하는 케이스 
        for(int i=1;i<4;i++){
            int next_row=cur.row+i*dir_drow[cur.dir];
            int next_col=cur.col+i*dir_dcol[cur.dir];
            
            if(map[next_row][next_col]==1) break;
            if(visited[next_row][next_col][cur.dir]!=0) continue;
            visited[next_row][next_col][cur.dir]= cur.count +1;
            q.push({next_row,next_col,cur.dir,cur.count+1});
        }

        // 왼쪽 또는 오른쪽으로 회전하는 케이스 
        int leftTurn_dir= turn_left(cur.dir);
        if(leftTurn_dir!=-1 && !visited[cur.row][cur.col][leftTurn_dir]){
            visited[cur.row][cur.col][leftTurn_dir]=cur.count +1;
            q.push({cur.row,cur.col,leftTurn_dir,cur.count+1});
        }
        
        int rightTurn_dir= turn_right(cur.dir);
        if(rightTurn_dir!=-1 && !visited[cur.row][cur.col][rightTurn_dir]){
            visited[cur.row][cur.col][rightTurn_dir]=cur.count +1;
            q.push({cur.row,cur.col,rightTurn_dir,cur.count+1});
        }        
        
        
    }
    
    cout<<visited[end_row][end_col][end_dir]-1;


}
