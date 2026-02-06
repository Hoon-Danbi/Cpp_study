//https://www.acmicpc.net/problem/11003

#include <iostream>
#include <deque>

using namespace std;

struct node{
    int index,value;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,L;cin>>N>>L;
    deque<node> dq;

    
    
    for(int i=1;i<N+1;i++){
        int temp; cin>>temp;
        // 새로들어 오는 index=i , value = temp;
        if(i==1) dq.push_back({i,temp});

        while(!dq.empty() && dq.back().value >temp){
            dq.pop_back();
        }
        dq.push_back({i,temp});
        while(!dq.empty() && dq.front().index <(i-L+1)){
            dq.pop_front();
        }
        cout<<dq.front().value<<" ";
    }

    return 0;
}