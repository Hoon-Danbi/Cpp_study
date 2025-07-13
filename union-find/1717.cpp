//https://www.acmicpc.net/problem/1717
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N,M;
vector<int> arr;
 
int find_parent(int num){
    if(num==arr[num]) return num;
    return arr[num] = find_parent(arr[num]);
}

void check_parent(int num1,int num2){
    int x1 = find_parent(num1);
    int x2 = find_parent(num2);
    if(x1==x2) cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
}
void union_parent(int num1,int num2){
    int x1 = find_parent(num1);
    int x2 = find_parent(num2);
    if(x1<x2) arr[x2] = x1;
    else arr[x1] = x2;
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

     cin>>N>>M;
     arr.resize(N+1);
     for (int i = 0; i <= N; i++)
     {
        arr[i]=i;
     }

     int sel,num1,num2;
     for(int i=0;i<M;i++){
        cin>>sel>>num1>>num2;
        if(sel==0) union_parent(num1,num2);        
        else if(sel==1) check_parent(num1,num2);
     }
     
}