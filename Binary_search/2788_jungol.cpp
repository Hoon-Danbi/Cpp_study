//https://jungol.co.kr/problem/2788
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int N;
    cin>>N;
    vector<int> map(N);
    for(int i=0;i<N;i++) cin>>map[i]; // 맵 값을 입력 받기 
    sort(map.begin(),map.end()); // 오름 차순으로 정렬 
    int count=0;
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            int err1=map[j]-map[i]; // 1구간 오차 도출
            if (err1 == 0) continue;
            /*
            x1 이상 x2 이하   =>  x1 lower(이상의 값을 도출)이상  x2 upper(초과 되는 인덱스 도출)미만의 값이 정답이다. !  
            */
            auto it_lower = lower_bound(map.begin()+j+1, map.end(), map[j]+err1);
            auto it_upper = upper_bound(map.begin()+j+1, map.end(), map[j]+err1 * 2);

            int idx_lower = it_lower - map.begin();
            int idx_upper = it_upper - map.begin();
            /*
            int lo = lower_bound(map.begin() + j + 1, map.end(), map[j] + err) - (map.begin() + j + 1);
            int hi = upper_bound(map.begin() + j + 1, map.end(), map[j] + err * 2) - (map.begin() + j + 1);
            count += (hi - lo);
            이렇게 인덱스를 바로 뽑을수가 있다. 
            */
            // cout<<idx_upper - idx_lower<<'\n';
            // for(int k=idx_lower;k<idx_upper;k++){
            //     cout<<"i j k:"<<i<<j<<k<<'\n';
            // }
            
            count += idx_upper - idx_lower;

        }
    }
    cout<<count;

    return 0;
}