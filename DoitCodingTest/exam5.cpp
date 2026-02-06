//https://www.acmicpc.net/problem/10986

#if 1
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N,M;
    cin>>N>>M;
    vector<long long> arr(M,0);
    arr[0]=1;

    int past=0;
    for(int i=1;i<N+1;i++){
        int temp; cin>>temp;
        long long num= (past+temp)%M;
        arr[num]++;
        past = num;
    }    


    long long sum=0;
    for(int i=0;i<M;i++){
        long long num=(arr[i]*(arr[i]-1))/2;
        sum+=num;
    }
    cout<<sum;
    return 0;
}

#endif

//c로 풀기 
