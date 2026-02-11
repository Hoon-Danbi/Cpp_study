//https://www.acmicpc.net/problem/2023

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;


bool is_prime(int num){
    for(int i=2;i<=sqrt(num);i++){
        if(num %i ==0) return false;
    }
    return true;
}

void Dfs(int num, int depth){
    // depth가 N 과 같을때 해당숫자 출력, return
    if(depth == N){
        cout<<num<<"\n";
        return;
    }

    //새로운 숫자는 num + 10*i  => (소수일때) DFS(새로운 숫자,깊이+1)
    for(int i=1;i<10;i++){
        int next_num=(num*10+i);
        if(is_prime(next_num)){
            Dfs(next_num,depth+1);
        }
    }
}

int main(){
    //DFs의 최대 깊이가 N이 된다. 
    cin>>N;

    Dfs(2,1);
    Dfs(3,1);
    Dfs(5,1);
    Dfs(7,1);
    

    return 0;
}