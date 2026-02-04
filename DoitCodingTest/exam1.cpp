//https://www.acmicpc.net/problem/11720

//Cpp 문제 풀이 
#include <iostream>
using namespace std;
#if 0 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string num;
    cin >> n >> num;

    int res = 0;
    for (int i = 0; i < n; i++) res += num[i] - '0';

    cout << res;
    return 0;
}
#endif

//----------------------------------------------------------

//C 문제 풀이 
#include <stdio.h>

//배열을 통해서 문자열을 입력 받기 
#if 0
int main(){
    int n;
    scanf("%d",&n);
    char num[101]; //문자열은 \0 이 제일 마지막에 나옴
    scanf("%s",num);
    
    int res=0;
    for(int i=0;i<n;i++){
        res += num[i] - '0';
    }
    printf("%d",res);
}
#endif

// char* 로 문자열 입력 받기

#include <stdlib.h>
#if 1
int main(){
    int n;
    scanf("%d",&n);
    char* num = (char*)malloc(sizeof(char)*n);
    //scanf("%s",num);
    scanf("%s",&num[0]);
    
    int res=0;
    int i=0;
    while(i<n){
        res+= num[i] -'0';
        i++;
    }
    printf("%d",res);
    return 0;
}

#endif