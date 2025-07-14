//https://www.acmicpc.net/problem/9935
#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string str="";
    cin>>str;

    string com="";
    cin>>com;
    int str_leng=str.length();
    int com_leng=com.length();

    stack<int> num;

    for(int i=0;i<str_leng;i++){
        if(com[0]==str[i]){
            num.push(i);
            //cout<<" i= "<<i<<'\n';
        } 
    }
    
    

    while(!num.empty())
    {
        int k=num.top();
        //cout<<"K: "<<k<<'\n';
        num.pop();
        string temp(str.begin()+k,str.begin()+k+com_leng);
        //cout<<"슬라이스: "<<temp<<'\n';
        if(com==temp) str.erase(k,com_leng);
        //cout<<"슬라이스 결과: "<<str<<'\n';
    }
    if(str.empty()) cout<<"FRULA"<<'\n';
    else cout<<str<<'\n';
    return 0;
}