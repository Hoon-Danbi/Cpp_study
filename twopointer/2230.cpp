//https://www.acmicpc.net/problem/2230
#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
int main(){
    int N,M;
    cin>>N>>M;
    vector<int> arr(N);
    
    for (int  i = 0; i < N; i++)
    {
        int tmp;
        cin>>tmp;
        arr[i]=tmp;    
    }
    sort(arr.begin(),arr.end());
//정렬을 해주지 않으면 모든 케이스를 구해야함으로 오름차순으로 정렬을 해준다.

    
    /*
    st: 0~N-1까지 순차 탐색 for문
        M이상의 값이 나올때 까지 en++
        최소값인지 체크,갱신 
    1 2 3 4 5 => (st,en) , (1,1),(1,2),(1,3),(1,4)  / (2,5) - break.
    ... 커서2개로 구간을 탐색한다. , 매 루프 st +1 를 기준으로 en을 움직여 
    M 조건을 만족하는 범위를 구한다. 만약 en을 움직여 탐색중 배열 끝에 도달 했을때
    조사는 끝이 나고 더이상 탐색을 안해도 뒤에 다른 경우의 수는 무시해도 된다는 
    결과가 나온다. 
    */
    int min_res=0x7FFFFFFF;
    int en=0; // 2번째 커서
    int st=0; // 1번째 커서 
   for(st=0;st<N;st++){
        while( en<N &&(arr[en]-arr[st])<M) en++;
        if(en==N) break; // en이 범위 밖에 도달했을때 종료
        min_res = min(min_res,arr[en]-arr[st]); 
   }
   cout<<min_res;
    

    return 0;
}
