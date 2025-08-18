//https://www.acmicpc.net/problem/20058
/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,Q;
vector<vector<int>> arr;
int N_size;
struct node {
    int x,y;
};
vector<vector<int>> visited;
void check_ice(){
    for(int i=1;i<=N_size;i++){
        for(int j=1;j<=N_size;j++){
            int count=0;
            if(arr[i-1][j]<0) count++;
            if(arr[i+1][j]<0) count++;
            if(arr[i][j-1]<0) count++;
            if(arr[i][j+1]<0) count++;
            if(count<3) arr[i][j] -=1;
        }
    }
}
int sum_ice(){
    int tmp=0;
    for(int i=1;i<=N_size;i++){
        for(int j=1;j<=N_size;j++){
            tmp+=arr[i][j];
        }
    }
    return tmp;
}
int drow[4]={-1,1,0,0};
int dcol[4]={0,0,-1,1};
int BFS_ice(int start_row,int start_col){
    queue<node> q;
    q.push({start_row,start_col});
    visited[start_row][start_col]=1;
    int temp_ice_block=0;
    while(!q.empty()){
        node cur=q.front(); q.pop();
        temp_ice_block++;
        for(int i=0;i<4;i++){
            int next_row=cur.x+drow[i];
            int next_col=cur.y+dcol[i];
            if(next_row <1 ||next_row>N_size||next_col<1||next_col>N_size) continue;
            if(visited[next_row][next_col]==1) continue;
            q.push({next_row,next_col});
            visited[next_row][next_col]=1;
        }
    }
    return temp_ice_block;
    
}
void map_rotation(int cur_row,int cur_col,int L_size){
    vector<vector<int>> tmp(L_size,vector<int>(L_size));
    int block=L_size/2;
    for(int i=cur_row;i<cur_row+block;i++){
        for(int j=cur_col;j<cur_col+block;j++){
            tmp[i-cur_row][j-cur_col]=arr[i][j];
        }
    }
    
    
    //up
    for(int i=cur_row;i<cur_row+block;i++){
        for(int j=cur_col;j<cur_col+block;j++){
            arr[i][j]=arr[i+block][j];
        }
    }  

    //left
    for(int i=cur_row;i<cur_row+block;i++){
        for(int j=cur_col;j<cur_col+block;j++){
            arr[i+block][j]=arr[i+block][j+block];
        }
    }

    //down
    for(int i=cur_row;i<cur_row+block;i++){
        for(int j=cur_col;j<cur_col+block;j++){
            arr[i+block][j+block]=arr[i][j+block];
        }
    }

    //right
    for(int i=cur_row;i<cur_row+block;i++){
        for(int j=cur_col;j<cur_col+block;j++){
            arr[i][j+block]=tmp[i-cur_row][j-cur_col];
        }
    }
}

void split(int L){
    for(int i=1;i<=N_size;i+=(1<<L)){
        for(int j=1;j<=N_size;j+=(1<<L)){
            map_rotation(i,j,(1<<L));
        }
    }
}

int main() {
    cin>>N>>Q;
    N_size= 1<<N;

    arr.resize(N_size+2, vector<int>(N_size+2,0));
    visited.resize(N_size+2, vector<int>(N_size+2,0));
    
    for (int i = 1; i <= N_size; i++) {
        for (int j = 1; j <= N_size; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i=0;i<Q;i++){
        int tmp;
        cin>>tmp;
        if(tmp <1) continue;
        split(tmp);
        check_ice();
    }
    
    int max_ice_block=0;
    for (int i = 1; i <= N_size; i++) {
        for (int j = 1; j <= N_size; j++) {
            int temp_block=BFS_ice(i,j);
            if(temp_block>max_ice_block) max_ice_block=temp_block;
        }
    }    

    cout<<sum_ice()<<'\n';
    cout<<max_ice_block;
    
    // for (int i = 1; i <= N_size; i++) {
    //     for (int j = 1; j <= N_size; j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    return 0;
}



*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, Q;
int N_size;
vector<vector<int>> arr;
vector<vector<int>> visited;
int drow[4] = {-1, 1, 0, 0};
int dcol[4] = {0, 0, -1, 1};

struct node {
    int x, y;
};

void map_rotation(int cur_row, int cur_col, int L_size) {
    vector<vector<int>> tmp(L_size, vector<int>(L_size));
    for (int i = 0; i < L_size; i++) {
        for (int j = 0; j < L_size; j++) {
            tmp[j][L_size - 1 - i] = arr[cur_row + i][cur_col + j];
        }
    }
    for (int i = 0; i < L_size; i++) {
        for (int j = 0; j < L_size; j++) {
            arr[cur_row + i][cur_col + j] = tmp[i][j];
        }
    }
}

void split(int L) {
    int len = 1 << L;
    for (int i = 1; i <= N_size; i += len) {
        for (int j = 1; j <= N_size; j += len) {
            map_rotation(i, j, len);
        }
    }
}

void check_ice() {
    vector<vector<int>> next_arr = arr;
    for (int i = 1; i <= N_size; i++) {
        for (int j = 1; j <= N_size; j++) {
            int cnt = 0;
            if (arr[i - 1][j] > 0) cnt++;
            if (arr[i + 1][j] > 0) cnt++;
            if (arr[i][j - 1] > 0) cnt++;
            if (arr[i][j + 1] > 0) cnt++;
            if (cnt < 3 && arr[i][j] > 0) next_arr[i][j]--;
        }
    }
    arr = next_arr;
}

int sum_ice() {
    int total = 0;
    for (int i = 1; i <= N_size; i++) {
        for (int j = 1; j <= N_size; j++) {
            if (arr[i][j] > 0)
                total += arr[i][j];
        }
    }
    return total;
}

int BFS_ice(int start_row, int start_col) {
    if (visited[start_row][start_col] || arr[start_row][start_col] <= 0)
        return 0;

    queue<node> q;
    q.push({start_row, start_col});
    visited[start_row][start_col] = 1;
    int ice_block = 0;

    while (!q.empty()) {
        node cur = q.front();
        q.pop();
        ice_block++;

        for (int i = 0; i < 4; i++) {
            int nr = cur.x + drow[i];
            int nc = cur.y + dcol[i];

            if (nr < 1 || nr > N_size || nc < 1 || nc > N_size) continue;
            if (visited[nr][nc]) continue;
            if (arr[nr][nc] <= 0) continue;

            visited[nr][nc] = 1;
            q.push({nr, nc});
        }
    }
    return ice_block;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q;
    N_size = 1 << N;
    arr.resize(N_size + 2, vector<int>(N_size + 2, 0));
    visited.resize(N_size + 2, vector<int>(N_size + 2, 0));

    for (int i = 1; i <= N_size; i++)
        for (int j = 1; j <= N_size; j++)
            cin >> arr[i][j];

    for (int i = 0; i < Q; i++) {
        int L;
        cin >> L;
        if (L > 0)
            split(L);
        check_ice();
    }

    int max_ice_block = 0;
    visited.assign(N_size + 2, vector<int>(N_size + 2, 0));

    for (int i = 1; i <= N_size; i++) {
        for (int j = 1; j <= N_size; j++) {
            if (arr[i][j] > 0 && !visited[i][j]) {
                int size = BFS_ice(i, j);
                if (size > max_ice_block)
                    max_ice_block = size;
            }
        }
    }

    cout << sum_ice() << '\n';
    cout << max_ice_block;

    return 0;
}
