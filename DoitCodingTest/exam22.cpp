//https://www.acmicpc.net/problem/10989


//vector<int>에 N 10 000 000개를 저장하면  4* 1000000 바이트 40MB 이상이라서 메모리 초과가 도출 된다. 

// 숫자를 저장 하는 방식을 달리 해야 한다. 
//N 숫자가 있으면 그 배열에 ++로 기록을 해서 있는지 유무로 정렬 및 해당 숫자 몇개인지 기록 한다. 

#include <iostream>

using namespace std;

// 1. 숫자의 범위가 1~10,000이므로 크기가 10,001인 배열 선언
// 전역 변수로 선언하면 자동으로 0으로 초기화됩니다.
int count[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // 2. 숫자를 배열에 저장하지 않고, 해당 숫자의 인덱스 값을 1씩 증가시킴
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        count[num]++; // num이라는 숫자가 나올 때마다 카운트 업
    }

    // 3. 1부터 10,000까지 돌면서 카운트된 횟수만큼 숫자 출력
    for (int i = 1; i <= 10000; i++) {
        while (count[i] > 0) {
            cout << i << "\n";
            count[i]--;
        }
    }

    return 0;
}