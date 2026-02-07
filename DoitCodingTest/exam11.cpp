//https://www.acmicpc.net/problem/1874
 
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    int n; cin>>n;
    stack<int> st;
    vector<char> result;
    int num; cin>>num;
    for(int i=1;i<=n;i++){
        //cout<<"i: "<<i<<"\n";
        //i vs input_num 같을떄 까지 i 푸시 
        st.push(i);
        result.push_back('+');  

        while(!st.empty() && st.top() ==num){
            st.pop();
            result.push_back('-');
            cin>>num;    
        }
    }
    
    if(st.empty()){
        for(auto ch:result) cout<<ch<<"\n";
    }else{
        cout<<"NO";
    }
    return 0;
}