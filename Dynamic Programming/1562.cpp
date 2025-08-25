//https://www.acmicpc.net/problem/1562
#include <iostream>
using namespace std;

int N;
int dp[101][10][1<<10]={0,}; // 몇번째 자리 인지 , 어떤 숫자가 오는지 , 0~9번숫자 0b0000000000,
const int mod = 1000000000;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N;

    for(int i=1;i<=9;i++){
        dp[1][i][1<<i]=1;
    }
    for(int i=1;i<N;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<1024;k++){
                if(j<9){
                    dp[i+1][j+1][k|(1<<(j+1))] += dp[i][j][k];
                    dp[i+1][j+1][k|(1<<(j+1))] %=mod;
                } 
                if(j>0){
                    dp[i+1][j-1][k|(1<<(j-1))] += dp[i][j][k];
                    dp[i+1][j-1][k|(1<<(j-1))] %= mod;
                } 
            }
        }
    }
    
    long long sum=0;
    for (int i=0; i<=9; i++) {
        sum += dp[N][i][(1<<10) -1];
        sum %=mod;
    }
    cout<<sum<<'\n';
    return 0;
}