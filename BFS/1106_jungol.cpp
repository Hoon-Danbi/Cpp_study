//https://jungol.co.kr/problem/1106/submission?cursor=OCw1LDM%3D&sid=11388482
//장기 
/*
BFS 다음 포인터 찍는 부분 for 문 돌릴때 할일이 늘어나면 기하 급수적으로 시간이 오래 걸린다.
가급적이면 자제 하자. 
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N,M,R,C,S,K;
vector<vector<int>> map;
vector<vector<int>> visited;
int drow[8] = {-2,-1,1,2,2,1,-1,-2};
int dcol[8] = {1,2,2,1,-1,-2,-2,-1};

struct node {
    int row,col;
};

void BFS(int cur_row,int cur_col,int goal_row,int goal_col,int count){
    
    queue<node> q;
    q.push({cur_row,cur_col});
    visited[cur_row][cur_col]=1;

    while(!q.empty())
    {
        node cur=q.front(); q.pop();
        //cout<<"cur_row:"<<cur.row<<" cur_col:"<<cur.col<<" count:"<<visited[cur_row][cur_col]<<'\n';    
    
        if(cur.row==goal_row && cur.col==goal_col) break;
    
        for (int i=0; i<8; i++) {
            int next_row = cur.row +drow[i];
            int next_col = cur.col + dcol[i];
            if(next_row <1 ||next_row >N ||next_col<1||next_col>M) continue;
            if(visited[next_row][next_col]>0) continue;
            if(next_row == goal_row &&next_col ==goal_col){
                visited[next_row][next_col] = visited[cur.row][cur.col]+1;
                return;
            }
            q.push({next_row,next_col});
            visited[next_row][next_col] = visited[cur.row][cur.col]+1;
            
        }
    }
}



int main() {
    cin>>N>>M>>R>>C>>S>>K;
    map.resize(N+1,vector<int>(M+1,0));
    visited.resize(N+1,vector<int>(M+1,0));
    BFS(R,C,S,K,0);
    
    
    // for (int i=0; i<=N; i++) {
    //     for (int j=0; j<=N; j++) {
    //         cout<<visited[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    cout<<visited[S][K] -1;
    return 0;
}






// 다른 사람 풀이   cpp, c 를 문법적으로 잘 푼 케이스 
#if 0


#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
/*
4189_장기2
*/

#include<stdio.h>

const int LM_MAP = 1001;
const int dy[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
const int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int N, M;
int sy, sx, ey, ex;

struct Point {
    int y, x, cnt;
};

struct Queue {
    Point queue[LM_MAP * LM_MAP];
    int read, write, visitCnt;
    int visit[LM_MAP][LM_MAP];

    inline bool isArea(int y, int x) {
        return y >= 1 && y <= N && x >= 1 && x <= M;
    }

    void init() {
        read = 0, write = 0, visitCnt = 0;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                visit[i][j] = 0;
            }
        }
    }

    void clear() {
        read = 0, write = 0, visitCnt++;
    }

    bool empty() {
        return read == write;
    }

    void enqueue(Point p) {
        queue[write++] = p;
    }

    Point dequeue() {
        return queue[read++];
    }

    int doBFS(Point s) {
        clear();

        enqueue(s);
        visit[s.y][s.x] = visitCnt;
        while (!empty()) {
            Point curr = dequeue();
            if (curr.y == ey && curr.x == ex) {
                return curr.cnt;
            }

            for (int k = 0; k < 8; ++k) {
                int ny = curr.y + dy[k];
                int nx = curr.x + dx[k];

                if (!isArea(ny, nx)) continue;
                if (visit[ny][nx] == visitCnt) continue;
                enqueue({ ny, nx, curr.cnt + 1 });
                visit[ny][nx] = visitCnt;
            }
        }

        return -1;
    }
} queue;

int main()
{
    scanf("%d %d", &N, &M);
    scanf("%d %d %d %d", &sy, &sx, &ey, &ex);

    queue.init();
    printf("%d\n", queue.doBFS({ sy, sx, 0 }));

    return 0;
}


#endif