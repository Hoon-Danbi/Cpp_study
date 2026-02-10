//https://www.acmicpc.net/problem/1427


#if 0

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(int a,int b){
    return a>b;
}

int main(){
    //문자열로 숫자 입력
    string str;
    cin>>str;
    
    //문자열 인덱스로 접근후 숫자로 변환 
    vector<int> number;
    for(int i=0;i<str.size();i++){
        int num = str[i] - '0';
        number.push_back(num);
    }

    //정렬- 오름차순
    sort(number.begin(),number.end(),cmp);

    for(auto ch:number){
        cout<<ch;
    }

    return 0;
}
#endif


//선택 정렬 방식 

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string str;
    cin>>str;
    vector<int> A(str.size(),0);

    for(int i=0;i<str.size();i++){
        A[i] = stoi(str.substr(i,1));
    }
    for(int i=0;i<str.length();i++){
        int Max=i;
        for(int j=i+1;j<str.length();j++){
            if(A[j]> A[Max]) Max = j;
        }
        if(A[i]<A[Max]){
            int temp = A[i];
            A[i] = A[Max];
            A[Max] = temp;
        }
    }
    for(int i=0;i<A.size();i++){
        cout<<A[i];
    }

    return 0;
}