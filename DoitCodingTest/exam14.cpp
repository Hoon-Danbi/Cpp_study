//https://www.acmicpc.net/problem/11286

#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

struct cmp{
    bool operator()(int a,int b){
        //1. 절댓값이 가장 작은 값
        if(abs(a) != abs(b)){
            return abs(a) > abs(b);
        }

        //2. 만약에 같다면 그중 작은 수
        return a>b;
    }
};

int main(){

    int N; cin>>N;
    priority_queue<int,vector<int>,cmp> pq;

    for(int i=0;i<N;i++){
        int num; cin>>num;
        if(num != 0){
            pq.push(num);
        }else{
            if(pq.empty()){
                cout<<0<<"\n";
                continue;
            }
            cout<<pq.top()<<"\n";
            pq.pop();
        }

    }

    return 0;
}
