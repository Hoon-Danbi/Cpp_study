//https://www.acmicpc.net/problem/1920

/*
*/

//n log n;

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool find_num(int num, vector<int>&arr);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M;
    cin>>N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        int num; cin>>num;
        arr[i]= num;
    }

    //오름차순으로 정렬 
    sort(arr.begin(),arr.end());

    //이진 탐색으로 해당 숫자 찾기 
    cin>>M;
    for(int i=0;i<M;i++){
        int num;cin>>num;
        if(find_num(num,arr)) cout<<1<<"\n";
        else cout<<0<<"\n";
    }

    
    return 0;
}

bool find_num(int num, vector<int>&arr){
    int start=0;
    int end =arr.size()-1;
    
    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid]==num){
            return true;
        }
        else if(arr[mid] < num){
            start = mid +1;
        }
        else{
            end = mid -1;
        }
    }

    return false;
    
} 