//https://jungol.co.kr/problem/1889?cursor=OCw1LDE%3D
#include <iostream>
#include <vector>
using namespace std;
vector<vector<bool>> visited;
int res=0;
int N;
int drow[8]={-1,1,0,0,-1,-1,1,1};
int dcol[8]={0,0,-1,1,1,-1,-1,1};



void mark_visit(int r, int c, bool val) {
    visited[r][c] = val;
    for(int dir = 0; dir < 8; dir++) {
        int nr = r + drow[dir];
        int nc = c + dcol[dir];
        while(nr >= 1 && nr <= N && nc >= 1 && nc <= N) {
            visited[nr][nc] = val;
            nr += drow[dir];
            nc += dcol[dir];
        }
    }
}

void DFS(int cnt) {
    if(cnt == 4) {  
        res++;
        return;
    }

    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            if(visited[r][c]) continue;  
            
            mark_visit(r, c, true);
            DFS(cnt + 1);
            mark_visit(r, c, false);
        }
    }
}

int main() {

    cin>>N;
    visited.resize(N+1,vector<bool>(N+1,false));

    DFS(0);
    cout<<res;
    
    
    
    
    return 0;
}


//참고 링크: https://cryptosalamander.tistory.com/58
