//https://www.acmicpc.net/problem/1744

#include <iostream>
#include <queue>

using namespace std;


int main(){
    int N; cin>>N;
    priority_queue<int> pqbig1;
    priority_queue<int,vector<int>,greater<int>> pqlow0;

    int num1=0;

    for(int i=0;i<N;i++){
        int temp; cin>>temp;
        if(temp>1) pqbig1.push(temp);
        else if(temp <=0) pqlow0.push(temp);
        else num1++;
    }

    long long res=0;
    //cout<<res<<"\n";
    while(pqbig1.size()>1){
        int first = pqbig1.top(); pqbig1.pop();
        int sec = pqbig1.top(); pqbig1.pop();
        res += first*sec;
    }
    if(pqbig1.size()==1){
        res+=pqbig1.top();pqbig1.pop();  
    } 
    //cout<<res<<"\n";
    res += num1;
    //cout<<res<<"\n";
    while(pqlow0.size() > 1){
        int first = pqlow0.top(); pqlow0.pop();
        int sec = pqlow0.top(); pqlow0.pop();
        res += first*sec;
    }
    if(pqlow0.size()==1){
        res+=pqlow0.top();pqlow0.pop();
    }
    //cout<<res<<"\n";
    cout<<res;

}