//https://www.acmicpc.net/problem/1940

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N,M; cin>>N>>M;
    vector<int> arr;
    
    int i=N;
    while(i>0){
        int temp; cin>>temp;
        arr.push_back(temp);
        i--;
    }
    sort(arr.begin(),arr.end());

    int start=0, end=N-1,sum=0,count=0;
    while(start < end){
        sum = arr[start]+arr[end];
        if(sum<M) start++;
        else if(sum>M) end--;
        else{
            count++;end--;
        }
    }
    cout<<count;

    return 0;
}