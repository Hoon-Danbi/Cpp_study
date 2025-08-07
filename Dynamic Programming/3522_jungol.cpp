//https://jungol.co.kr/problem/3522?cursor=OCw4LDA=

#include <iostream>
using namespace std;

const long long MOD = 1000000007;
int N;

int fibo(long long first, long long second, int cnt) {
    if (cnt == N) return second % MOD;
    return fibo(second, (first + second) % MOD, cnt + 1);
}

int main() {
    cin >> N;
    if (N == 1 || N == 2) cout << 1;
    else cout << fibo(1, 1, 2);
}

