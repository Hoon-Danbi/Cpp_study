#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/1806
int main(void){
    int N,M;
    cin>>N>>M;
    vector<int> arr(N+1);
    
    //배열 저장 하면서 누적합을 수행
    int tmp_sum=0;
    for (int i = 1; i <= N; i++)
    {
        int tmp;
        cin>>tmp;
        tmp_sum +=tmp;
        arr[i]=tmp_sum;
    }
    // for (int i = 0; i < N+1; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
        
    
    int st=1;
    int en=1;
    int min_res=N+1;
    for(st=1;st<=N;st++){
        while(en<N+1 && arr[en]-arr[st-1]<M) en++;
        if(en==N+1) break;
        // cout<<"en: "<<en<<" st: "<<st<<'\n';
        // cout<<"en-st+1: "<<en-st+1<<" min: "<<min_res<<'\n';
        
        min_res = min(min_res,en-st+1);
    }
    if(min_res==N+1) cout<<0;
    else cout<<min_res;
    return 0;
}