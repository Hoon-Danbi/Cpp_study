//https://jungol.co.kr/problem/1295
#include <iostream>
#include <vector>
using namespace std; 


int binary_search(const vector<int>& arr,int target){
    int left=1;
    int right=arr.size();
    while(left<=right){
        int mid=(left+right)/2;
        if(arr[mid]==target) return mid;
        else if(arr[mid] < target) left=mid+1;
        else right=mid -1;
    }
    return 0;
}

int main(void){
    int N,M;
    //cout<<"N: ";
    cin>>N;
    vector<int> arr(N+1);
    for(int i=1;i<=N;i++) cin>>arr[i];
    //for(int i=0;i<N;i++) cout<<arr[i]<<" ";
    //cout<<'\n';
    cin>>M;
    int tmp;
    for(int i=0;i<M;i++){
        cin>>tmp;
        cout<<binary_search(arr,tmp)<<'\n';
    }

    return 0;
}
