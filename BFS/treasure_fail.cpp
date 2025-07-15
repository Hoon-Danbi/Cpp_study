//https://jungol.co.kr/problem/1462?cursor=OCw1LDM%3D
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<char>> input_map;
vector<vector<bool>> visited;
struct Node {
    int x, y;
    int count;
};
vector<pair<int,int>> visited_nodes;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int find_treasure(int start_x, int start_y) {
    
    queue<Node> q;
    Node max_node = {start_x, start_y, 0};
    visited_nodes.push_back({start_y, start_x});
    int max_dist = 0;

    q.push({start_x, start_y, 0});
    visited[start_y][start_x] = true;

    while (!q.empty()) {
        Node cur = q.front(); q.pop();
        if (cur.count > max_dist) {
            max_dist = cur.count;
            max_node = cur;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
            if (input_map[ny][nx] == 'W' || visited[ny][nx]) continue;

            visited[ny][nx] = true;
            visited_nodes.push_back({ny, nx});
            q.push({nx, ny, cur.count + 1});
        }
    }

    for (pair<int, int> pos : visited_nodes){
    visited[pos.first][pos.second] = false;
    }
    visited_nodes.clear();

    q.push({max_node.x, max_node.y, 0});
    visited[max_node.y][max_node.x] = true;
    max_dist = 0;

    while (!q.empty()) {
        Node cur = q.front(); q.pop();
        max_dist = max(max_dist, cur.count);

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
            if (input_map[ny][nx] == 'W' || visited[ny][nx]) continue;

            visited[ny][nx] = true;
            q.push({nx, ny, cur.count + 1});
        }
    }

    return max_dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    input_map.resize(N, vector<char>(M));
    visited = vector<vector<bool>>(N, vector<bool>(M, false));
    string temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        for (int j = 0; j < M; j++) {
            input_map[i][j] = temp[j];
        }
    }

    int max_result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (input_map[i][j] == 'L' && !visited[i][j]) {
                max_result = max(max_result, find_treasure(j, i)); 
            }
        }
    }

    cout << max_result << '\n';
    return 0;
}
