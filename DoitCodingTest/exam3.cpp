//https://www.acmicpc.net/problem/11659


#if 0
#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M;
    cin>>N>>M;
    vector<int>arr(N+1,0); // 0 5 9 12 14 15
    for(int i=0;i<N;i++){
        int temp;
        cin>>temp;
        arr[i+1]=arr[i] +temp;
        
    }

    for(int i=0;i<M;i++){
        int start,end;
        cin>>start>>end;
        cout<<arr[end]-arr[start-1]<<"\n";
    }


    return 0;
}

#endif


//c언어 풀이

#if 1
#include <stdio.h>
#include <stdlib.h>

int main(){
    int N,M;
    scanf("%d %d",&N,&M);
    int* arr=(int*)malloc(sizeof(int)*(N+1));
    arr[0]=0;
    for(int i=1;i<=N;i++){
        int temp;
        scanf("%d",&temp);
        arr[i]=arr[i-1] + temp;
    }
    
    while(M>0){
        int start,end;
        scanf("%d %d",&start,&end);
        printf("%d\n",arr[end]-arr[start-1]);
        M--;
    }

    free(arr);
    return 0;
}
#endif