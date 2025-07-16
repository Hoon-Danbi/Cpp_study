//https://jungol.co.kr/problem/1006?cursor=OCw1LDg%3D
//https://www.acmicpc.net/problem/1726
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
struct Point{
    int row,col,dir;
};

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    
    int row_length,col_length;
    cin>>row_length>>col_length;
    //1로 패딩 해서 장애물 설치해두기
    vector<vector<int>> map(row_length + 2, vector<int>(col_length + 2, 1));
    vector<vector<int>> dist_map(row_length + 2, vector<int>(col_length + 2, 0));
    
    for(int i=1;i<=row_length;i++){
        for(int j=1;j<=col_length;j++){
            cin>>map[i][j]; 
        }
    }
    /*
    for(int i=1;i<=row_length;i++){
        for(int j=1;j<=col_length;j++){
            cout<<map[i][j]<<" "; 
        }
        cout<<'\n';
    }
    
    */
    Point start,end;
    cin>>start.row>>start.col>>start.dir;
    cin>>end.row>>end.col>>end.dir;
    
    //cout<<start.row<<start.col<<start.dir<<'\n';
    //cout<<end.row<<end.col<<end.dir<<'\n';
    
    if (start.dir==1) start.dir =0;
    if (start.dir==3) start.dir =1;
    if (start.dir==4) start.dir =3;
    
    if (end.dir==1) end.dir =0;
    if (end.dir==3) end.dir =1;
    if (end.dir==4) end.dir =3;
    
    //cout<<start.row<<start.col<<start.dir<<'\n';
    //cout<<end.row<<end.col<<end.dir<<'\n';
    // 동 -1  , 남-3 , 서-2 , 북-4 입력시 
    // 동 -0  , 남-1 , 서-2 , 북-3 BFS 내부에서 
    
    int drow[4]={0,1,0,-1};
    int dcol[4]={1,0,-1,0};
    
    queue<Point> q;
    q.push(start);
    
    map[start.row][start.col]=1;//방문 처리.
    dist_map[start.row][start.col]=0;
    
    while(!q.empty()){
        Point cur=q.front(); q.pop();
        //cout<<"cur Point: "<<cur.row<<" "<<cur.col<<" "<<cur.dir<<'\n';
        // 동,남,서,북 방향 다음 next포인트 지정,
        
       if(cur.row==end.row && cur.col==end.col){
           int plus_dir=abs(cur.dir -end.dir); // 방향 오차 (0~2) 0 1 2 3
           if(plus_dir==3) plus_dir=1; //3인 경우 방향 변화량 1로 조정 0 1 1 2 
           //cout<<"trace END plus_dir: "<<plus_dir<<" ";
           // 목적지 도달 했을때 방향 마지막으로 조절
           dist_map[cur.row][cur.col]=dist_map[cur.row][cur.col]+plus_dir;
           break;
       }
        
        for(int i=0;i<4;i++){
            int plus_cur=1;
            for(int j=1;j<=3;j++){  
                //1  2  3칸 씩 이동
                Point next={cur.row + drow[i]*j,cur.col + dcol[i]*j,i};
                if(map[next.row][next.col]==1) break; //장애물을 만났을때 아웃,방문 한곳은 1로 변경 되어 있음
                
                int plus_dir=abs(cur.dir -i); // 방향 오차 (0~2) 0 1 2 3
                if(plus_dir==3) plus_dir=1; //3인 경우 방향 변화량 1로 조정 0 1 1 2 
                //cout<<"trace plus_dir: "<<plus_dir<<" ";
               
                dist_map[next.row][next.col] = dist_map[cur.row][cur.col]+plus_cur+plus_dir;
                //cout<<" trace plus: "<<plus_cur+plus_dir<<"\n";               
                q.push(next);
                map[next.row][next.col] = 1; // 방문 처리                

            }
        }
    }
    cout<<dist_map[end.row][end.col]<<'\n';

    /*
    for(int i=1;i<=row_length;i++){
        for(int j=1;j<=col_length;j++){
            cout<<map[i][j]<<" "; 
        }
        cout<<'\n';
    }
    cout<<'\n';
    for(int i=1;i<=row_length;i++){
        for(int j=1;j<=col_length;j++){
            cout<<dist_map[i][j]<<" "; 
        }
        cout<<'\n';
    }

    */
    
    
    
    
    
    
    return 0;
}