//https://jungol.co.kr/problem/1006?cursor=OCw1LDg%3D
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Point {
    int r, c, d, cost;
};

int convert_dir(int d) {
    //  1:동, 2:서, 3:남, 4:북 
    //→ 0:동, 1:남, 2:서, 3:북
    if (d == 1) return 0;
    if (d == 2) return 2;
    if (d == 3) return 1;
    if (d == 4) return 3;
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n+2, vector<int>(m+2, 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> map[i][j];

    int sr, sc, sd, er, ec, ed;
    cin >> sr >> sc >> sd >> er >> ec >> ed;

    sd = convert_dir(sd); 
    ed = convert_dir(ed);

    // 동 남 서 북
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    vector<vector<vector<int>>> dist(n+2, vector<vector<int>>(m+2, vector<int>(4, INT_MAX)));

    queue<Point> q;
    q.push({sr, sc, sd, 0});
    dist[sr][sc][sd] = 0;

    while (!q.empty()) {
        Point cur = q.front(); q.pop();

        // 최소만 도달하게 이전 값과 비교
        if (cur.cost > dist[cur.r][cur.c][cur.d]) continue;

        // 도착했을때 cost
        if (cur.r == er && cur.c == ec && cur.d == ed) {
            cout << cur.cost << '\n';
            return 0;
        }

        // 1 2 3칸 직진
        for (int k = 1; k <= 3; k++) {
            int nr = cur.r + dr[cur.d]*k;
            int nc = cur.c + dc[cur.d]*k;

            if (map[nr][nc]==1) break;
            // 중간 경로에서 이전에 이미 더 작은 값으로 도달했으면 가지 않음-가지치기
            if (dist[nr][nc][cur.d] <= cur.cost + 1) continue; 
            dist[nr][nc][cur.d] = cur.cost + 1;
            q.push({nr, nc, cur.d, cur.cost+1});            
        }

        // 회전(왼쪽/오른쪽 90도‧180도)
        for (int nd = 0; nd < 4; nd++) {
            if (nd == cur.d) continue;

            int turn = abs(cur.d - nd);
            if (turn == 3) turn = 1; // 3은 방향 변화량이 1이다.

            int ncost = cur.cost + turn;
            if (dist[cur.r][cur.c][nd] <= ncost) continue;
            dist[cur.r][cur.c][nd] = ncost;
            q.push({cur.r, cur.c, nd, ncost});
            
        }
    }
    return 0;
}
