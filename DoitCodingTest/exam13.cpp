//https://www.acmicpc.net/problem/2164

#include <iostream>
#include <queue>
using namespace std;

int main(){
    int N; cin>>N;
    queue<int> q;
    for(int i=1;i<=N;i++){
        q.push(i);
    }
    while(q.size()!=1){
        int num1,num2;
        
        //1.꺼내서 버리기 
        num1=q.front();
        q.pop();

        //2.꺼내서 맨뒤로 보내기 
        num2=q.front();
        q.pop(); q.push(num2);
    }
    int res = q.front();
    cout<<res;
    return 0;
}