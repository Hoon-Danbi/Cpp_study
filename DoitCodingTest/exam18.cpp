//https://www.acmicpc.net/problem/11399

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int index;
    int value;
};

bool cmp(node a,node b){
    return a.value < b.value;
}

int main(){
    int N; cin>>N;
    // index & value 구조체로 명시 
    vector<node> arr;
    for(int i=0;i<N;i++){
        int n; cin>>n;
        arr.push_back({i,n});
    }
    // value 기준으로 정렬 
    sort(arr.begin(),arr.end(),cmp);

    // for(node ch:arr){
    //     cout<<ch.index<<" "<<ch.value<<"\n";
    // }
    
    // for 문 돌면서 합 구하기 
    int sum =0;
    for(int i=0;i<arr.size();i++){
        sum += (arr[i].value*(arr.size()-i));
        //cout<<sum<<" ";

    }
    //cout<<"\n";
    cout<<sum;


}