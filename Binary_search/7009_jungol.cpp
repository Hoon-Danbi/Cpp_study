//https://jungol.co.kr/problem/7009?cursor=OCwzLDU=
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr;
int N,M;

bool find_num(int target){
    int start=1;
    int end=N;

    while(start<=end){
        int mid=(start+end)/2;

        if(arr[mid]==target){
            return true;
        } 
        if(arr[mid]>target) end=mid-1;
        else start=mid+1;        
    }

    return false;

}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>M;
    arr.resize(N+1,0);
    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }
    
    sort(arr.begin(),arr.end());

    int count = M;
    for(int i=0;i<M;i++){
        int tmp;
        cin>>tmp;
        if(find_num(tmp)){
            count--;
            //cout<<"count: "<<count<<'\n';
            continue;
        }
        cout<<tmp<<" ";
        
        //cout<<"count: "<<count<<'\n';
    } 
    if(count==0) cout<<"-1";
    return 0;
}