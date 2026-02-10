#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1. 전역 변수 선언 (메모리 재할당 방지를 위해 전역 배열 선언)
static vector<int> A;
static vector<int> tmp;
static long result; // 버블 소트 swap 횟수는 int 범위를 넘을 수 있으므로 long 사용

void merge_sort(int s, int e);

int main() {
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    A = vector<int>(N + 1, 0);
    tmp = vector<int>(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    result = 0;
    merge_sort(1, N); // 병합 정렬 수행

    cout << result << "\n";

    return 0;
}

void merge_sort(int s, int e) {
    if (e - s < 1) return;

    // 분할 연산
    int m = s + (e - s) / 2;

    // 재귀 함수 형태로 구현
    merge_sort(s, m);
    merge_sort(m + 1, e);

    for (int i = s; i <= e; i++) {
        tmp[i] = A[i];
    }

    int k = s;
    int index1 = s;   // 앞쪽 그룹 시작점
    int index2 = m + 1; // 뒤쪽 그룹 시작점

    // 두 그룹을 병합하는 로직
    while (index1 <= m && index2 <= e) {
        if (tmp[index1] > tmp[index2]) {
            // 뒤쪽 데이터 값이 더 작아 선택되는 경우 (Swap 발생)
            A[k] = tmp[index2];
            // 중요: 현재 남아있는 앞쪽 데이터 개수만큼 result에 더함
            result = result + index2 - k; 
            k++;
            index2++;
        } else {
            // 앞쪽 데이터 값이 더 작거나 같은 경우
            A[k] = tmp[index1];
            k++;
            index1++;
        }
    }

    // 한쪽 그룹이 모두 선택된 후 남아있는 값 정리하기
    while (index1 <= m) {
        A[k] = tmp[index1];
        k++;
        index1++;
    }
    while (index2 <= e) {
        A[k] = tmp[index2];
        k++;
        index2++;
    }
}