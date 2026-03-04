//https://www.acmicpc.net/problem/11047

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    long long K;
    cin>>N>>K;
    
    vector<int> arr(N,0);
    for(int i=N-1;i>=0;--i){ //N-1 ~ 0
        cin>>arr[i];
    }

    int res=0,cnt=0;  
    
    while(K!=0){
        res += K / arr[cnt];
        K %= arr[cnt];
        //cout<<"res: "<<res<<"cnt: "<<cnt<<"\n";
        
        cnt++;
    }
    cout<<res;


    return 0;
}