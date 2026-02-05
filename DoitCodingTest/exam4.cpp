//https://www.acmicpc.net/problem/11660


#if 0
#include <iostream>
#include <vector>
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N,M;
    std::cin>>N>>M;
    std::vector<std::vector<int>> arr(N+1,std::vector<int>(N+1,0));
    for(int i=1;i<N+1;i++){
        for(int j=1;j<N+1;j++){
            int temp;
            std::cin>>temp;
            arr[i][j]=temp+arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
        }
    }

    // for(int i=1;i<N+1;i++){
    //     for(int j=1;j<N+1;j++){
    //         std::cout<<arr[i][j]<<" ";
    //     }
    //     std::cout<<"\n";
    // }

    while(M>0){
        int start_row,start_col,end_row,end_col;
        std::cin>>start_row>>start_col>>end_row>>end_col;
        std::cout<<arr[end_row][end_col]-arr[start_row-1][end_col]-arr[end_row][start_col-1] + arr[start_row-1][start_col-1]<<"\n";

        M--;
    }

    return 0;
}
#endif


//c언어 풀이 
#if 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_2array(int** arr,int N){
    for(int i=0;i<N+1;i++){
        for(int j=0;j<N+1;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int N,M;
    scanf("%d %d",&N,&M);
    int** arr = (int**)malloc(sizeof(int*)*(N+1));

    for(int i=0;i<N+1;i++){
        // arr[i] = (int*)malloc(sizeof(int)*(N+1));
        // memset(arr[i],0,sizeof(int)*(N+1));

        arr[i] = (int*)calloc(N+1,sizeof(int));//0으로 초기화 됨
    }

    
    for(int i=1;i<N+1;i++){
        for(int j=1;j<N+1;j++){
            int temp; scanf("%d",&temp);
            arr[i][j]=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1]+temp;
        }
    }

    //print_2array(arr,N);

    while(M>0){
        int start_row,start_col,end_row,end_col;
        scanf("%d %d %d %d",&start_row,&start_col,&end_row,&end_col);
        printf("%d\n",arr[end_row][end_col]-arr[start_row-1][end_col]-arr[end_row][start_col-1]+arr[start_row-1][start_col-1]);
        M--;
    }

    for(int i=0;i<N;i++){
        free(arr[i]);
    }
    free(arr);
    return 0;
}

#endif