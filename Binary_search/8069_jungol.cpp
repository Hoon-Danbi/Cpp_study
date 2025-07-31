//https://jungol.co.kr/problem/8069?cursor=OCwzLDQ=
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> arr(N);
    for(int i = 0; i < N; i++) cin >> arr[i];
    
    while(M--) {
        int target;
        cin >> target;

        int idx_lower = lower_bound(arr.begin(), arr.end(), target) - arr.begin();

        if (idx_lower == 0) {
            cout << arr[0] << '\n';
        }
        else if (idx_lower == N) {
            cout << arr[N - 1] << '\n';
        }
        else {
            int left = arr[idx_lower - 1];
            int right = arr[idx_lower];

            int dist_left = abs(target - left);
            int dist_right = abs(right - target);

            if (dist_left <= dist_right) {
                cout << left << '\n';
            } else {
                cout << right << '\n';
            }
        }
    }

    return 0;
}
