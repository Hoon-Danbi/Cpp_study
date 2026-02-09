//https://www.acmicpc.net/problem/17298

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    int N; cin>>N;
    stack<int> s;
    vector<int> res(N,0);
    vector<int> A(N,0);

    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    
    s.push(0);
    for(int i=1;i<N;i++){
        while(!s.empty() && A[s.top()]<A[i]){
            res[s.top()] = A[i];
            s.pop();
        }
        s.push(i);
    }
    
    while(!s.empty()){
        res[s.top()]=-1;
        s.pop();
    }
    
    
    for(auto ch:res) cout<<ch<<" ";



    return 0;
}
