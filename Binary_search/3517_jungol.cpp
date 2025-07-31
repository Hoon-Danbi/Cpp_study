//https://jungol.co.kr/problem/3517?cursor=OCwzLDM=

#include <iostream>
#include <vector>
using namespace std;
vector<long long> arr;
int Q;
int N;

//이진 탐색으로 정확한 값을 찾는 문제  
//while 문으로 해결 하는 방법 ver1!!
int find_num_ver1(int target){
    int start=0;
    int end=N-1;
    while(start <=end){
        int mid=(start+end)/2;
        if(arr[mid]==target) return mid;
        if(arr[mid] > target){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return -1;
}

//재귀함수로 이진탐색을 수행하는 방법 ver2!
int find_num_ver2(int start,int end,int target){
    if(start>end) return -1;
    int mid = (start+end)/2;
    if(arr[mid]==target) return mid;
    if(arr[mid]>target) return find_num_ver2(start,mid-1,target);
    return find_num_ver2(mid+1,end,target);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    //이미 오름 차순으로 정렬된 정수 입력
    arr.resize(N);
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    cin>>Q;
    long long num;

    
    ////ver1
    // for(int i=0;i<Q;i++){
    //     cin>>num;
    //     cout<<find_num_ver1(num)<<" ";
    // }

    ////ver2
    int start=0;
    int end=N-1;
    for(int i=0;i<Q;i++){
        cin>>num;
        cout<<find_num_ver2(start,end,num)<<" ";
    }
    
}