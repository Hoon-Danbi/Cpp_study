//https://www.acmicpc.net/problem/12891

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N,M; cin>>N>>M;
    string str; cin>>str;
    vector<int> check(4,0);
    //0-A, 1-C , 2-G , 3-T
    int goal_A,goal_C,goal_G,goal_T;
    cin>>goal_A>>goal_C>>goal_G>>goal_T;

    for(int i=0;i<M;i++){
        int temp = str[i];
        switch(temp){
            case 'A':
                check[0]++;
                break;
            case 'C':
                check[1]++;
                break;
            case 'G':
                check[2]++;
                break;
            case 'T':
                check[3]++;
                break;
        }
    }
    // for(auto ch:check) cout<<ch<<" ";
    // cout<<"\n";
    // cout<<"\n";

    int start=0,end=M-1,count=0;
    while(end<=(N-1)){
        // cout<<end<<" "<<N-1<<"\n";
        // cout<<check[0]<<" "<<check[1]<<" "<<check[2]<<" "<<check[3]<<"\n";
        if(goal_A <=check[0] && goal_C <=check[1] &&goal_G <=check[2] &&goal_T <=check[3] ){
            count++;
        }

        switch(str[start]){
            case 'A':
                check[0]--;
                break;
            case 'C':
                check[1]--;
                break;
            case 'G':
                check[2]--;
                break;
            case 'T':
                check[3]--;
                break;
        }

        start++;
        end++;
    
        switch(str[end]){
            case 'A':
                check[0]++;
                break;
            case 'C':
                check[1]++;
                break;
            case 'G':
                check[2]++;
                break;
            case 'T':
                check[3]++;
                break;
        }
    }
    cout<<count;
    return 0;
}