#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_N (102)
enum {East, West, South, North};
int dr[] = {0, 0, 1, -1 };  // 방향: 인덱스 0=동,1=서,2=남,3=북
int dc[] = {1, -1, 0, 0 };
int turn[][4] = { 
    { North, South, East, West },
    { South, North, West, East }
};

int map[MAX_N][MAX_N];
int visit[MAX_N][MAX_N][4];

typedef struct _node {
    int r, c, dir;
}node;
node Queue[MAX_N * MAX_N * 4];
int front, rear;

int R, C;
node sPos, ePos;

void input_data(void) {
    int temp;
    scanf("%d %d", &R, &C);
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            scanf("%d", &temp);
            map[i][j] = !temp;
        }
    }
    scanf("%d %d %d", &sPos.r, &sPos.c, &sPos.dir);
    scanf("%d %d %d", &ePos.r, &ePos.c, &ePos.dir);
    --sPos.dir;
    --ePos.dir;
}

void print_data(void) {
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_visit(void) {
    for (int k = 0; k < 4; ++k) {
        for (int i = 1; i <= R; ++i) {
            for (int j = 1; j <= C; ++j) {
                printf("%d ", visit[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
   
}

int BFS(void) {
    // 시작위치를 Queue에 넣고, 방문표시
    Queue[rear++] = sPos;
    visit[sPos.r][sPos.c][sPos.dir] = 1;

    while (front != rear) {
        // 하나의 노드꺼내기
        node curr = Queue[front++];
        int cnt = visit[curr.r][curr.c][curr.dir];
        if (curr.r == ePos.r && curr.c == ePos.c && curr.dir == ePos.dir) {
            printf("front %d\n", front);
            return cnt - 1;
        }
        
        // 인접찾기
        // 1, 2, 3 이동
        for (int i = 1; i <= 3; ++i) {
            int nR = curr.r + dr[curr.dir] * i;
            int nC = curr.c + dc[curr.dir] * i;
            if (!map[nR][nC]) break;  // 이동 실패시 나머지도 이동하면 안됨
            if (visit[nR][nC][curr.dir]) continue;

            //if (nR == ePos.r && nC == ePos.c && curr.dir == ePos.dir) {
            //    printf("front %d\n", front);
            //    return cnt;
            //}

            //  범위 밖에 0으로 채워놓았기 때문에 범위 검사는 생략
            Queue[rear++] = (node){ nR, nC, curr.dir };
            visit[nR][nC][curr.dir] = cnt + 1;
        }
        // left, right Turn
        for (int i = 0; i < 2; ++i) {
            int nDir = turn[i][curr.dir];
 
            if (visit[curr.r][curr.c][nDir]) continue;
            //if (curr.r == ePos.r && curr.c == ePos.c && nDir == ePos.dir) {
            //    printf("front %d\n", front);
            //    return cnt;
            //}
            Queue[rear++] = (node){ curr.r, curr.c, nDir };
            visit[curr.r][curr.c][nDir] = cnt + 1;

        }
    }
    return -1;  // 도착 못함
}

int main(void) {
    input_data();
    //print_data();
    printf("%d\n", BFS());
    return 0;
}
