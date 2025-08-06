//https://jungol.co.kr/problem/2581?cursor=OCwzLDY=
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr;
int N,K;

//예산에 맞게 쓰이는지 확인하는 함수  전체 국가예산: K , 상한액: bill
bool bill_OK(int bill){
    int maxi=K;
    
    for(int i=1;i<=N;i++){
        if(arr[i]>=bill){
            maxi -=bill;
        }
        else{
            maxi -=arr[i];
        }
        if(maxi<0) return false;
        
    }
    return true;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    arr.resize(N+1,0);
    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }

    //오름차순 정렬
    sort(arr.begin(),arr.end());

    //시작점이 1이어야 한다. 
    int start=1;
    int end=arr[N];

    cin>>K;
    //상한액이 국가예산에 충족하는지 안하는지에 따라서 start, end를 mid기준 변동     
    int ans=0;
    while(start<=end){
        int mid=(start+end)/2;
        
        if(bill_OK(mid)){
            ans=mid;
            start = mid+1;
        }
        else{
            end = mid -1;
        }
        }
    cout<<ans;
    return 0;
}

