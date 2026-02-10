//https://www.acmicpc.net/problem/11004

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,K;
    cin>>N>>K;
    vector<int> arr;
    for(int i=0;i<N;i++){
        int temp; cin>>temp;;
        arr.push_back(temp);
    }
    sort(arr.begin(),arr.end());
    cout<<arr[K-1];
    return 0;
}