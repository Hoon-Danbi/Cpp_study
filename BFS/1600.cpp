//https://www.acmicpc.net/problem/1600
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node {
    int row,col,sum,k_num;
};

int main() {
    int K,W,H;
    cin>>K>>W>>H;

    vector<vector<int>> map(H,vector<int>(W));
    for (int i=0; i<H;i++) {
        for (int j=0;j<W;j++) {
            cin>>map[i][j];
        }
    }

    // [row][col][k번 말뛰기] 몇번 뛰냐에 따라 결과 최소 값이 달라지기에 변수로 넣는다! 
    vector<vector<vector<int>>> visited(H, vector<vector<int>>(W, vector<int>(K + 1, 0)));

    int drow[12] = {-1,1,0,0,-2,-2,-1,-1,1,1,2,2};
    int dcol[12] = {0,0,-1,1,-1,1,-2,2,-2,2,-1,1};

    //시작접 visit처리, push
    queue<node> q;
    q.push({0,0,0,0});
    visited[0][0][0] = 1;

    while (!q.empty()) {
        node cur = q.front();
        q.pop();

        if (cur.row==H-1 && cur.col==W-1) {
            cout << cur.sum;
            return 0;
        }

        for (int i=0;i<12;i++) {
            //다음 지점 셋팅
            int next_row = cur.row + drow[i];
            int next_col = cur.col + dcol[i];

            //장애물 못가는 지점 건너 띄기
            if (next_row < 0 || next_row >= H || next_col < 0 || next_col >= W) continue;
            if (map[next_row][next_col] == 1) continue;  

            //벙문 하지 않은 포인트  방문 처리 하고 push!!! 
            if (i < 4) {  
                if (visited[next_row][next_col][cur.k_num] == 0) {
                    visited[next_row][next_col][cur.k_num] = 1;
                    q.push({next_row, next_col, cur.sum + 1, cur.k_num});
                }
            } else {  
                if (cur.k_num < K && visited[next_row][next_col][cur.k_num + 1] == 0) {
                    visited[next_row][next_col][cur.k_num + 1] = 1;
                    q.push({next_row,next_col,cur.sum+1,cur.k_num+1});
                }
            }
        }
    }

    cout << -1;
    return 0;
}
