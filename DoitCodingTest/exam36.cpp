//https://www.acmicpc.net/problem/1715

#include <iostream>
#include <queue>

using namespace std;

struct cmp{
    bool operator()(const int &a,const int &b){
        return a>b;
    }
};

int main(){

   int N;
   cin>>N;
   
   //priority_queue<int,vector<int>,greater<int>> pq;
   priority_queue<int,vector<int>,cmp> pq;

   for(int i=0;i<N;i++){
    int temp; cin>>temp;
    pq.push(temp);
   }

   int res=0;
   while(pq.size() > 1){
    int num1 = pq.top(); pq.pop();
    int num2 = pq.top(); pq.pop();

    int temp = num1+num2;
    res += temp;
    //cout<<"temp:"<<temp<<" res:"<<res<<"\n";
    pq.push(temp);

   }

   cout<<res;



    return 0;
}