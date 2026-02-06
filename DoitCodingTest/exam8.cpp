//https://www.acmicpc.net/problem/1253

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N; cin>>N;
    vector<long long> arr;
    for(int i=0;i<N;i++){
        long long temp; cin>>temp;
        arr.push_back(temp);
    }
    sort(arr.begin(),arr.end());
    
    //N^2 가능 
    int K=0;
    if(N<3){
        cout<<0;
        return 0;
    }
    int count=0;
    while(K<N){

        //음수일수도 있으니 전범위를 대상으로 탐색 투포인터(N)를이용해서 찾는다 
        int start=0,end=N-1;
        while(start<end){
            int sum=arr[start]+arr[end];
            int goal=arr[K];
            //cout<<K<<" "<<start<<" "<<end<<" "<<sum<<" "<<goal<<"\n";
            if(sum<goal) start++;
            else if(sum>goal) end--;
            else{
                if(start == K) start++;
                else if(end ==K) end--;
                else{
                    count++;
                    break;
                }                
            }
        }

        K++;
    }
    cout<<count;

    return 0;   
}