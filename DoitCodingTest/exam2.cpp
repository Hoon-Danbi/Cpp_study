//https://www.acmicpc.net/problem/1546

/*
모든 점수를  점수/Max_value *100 고치고 나서 새로운 평균을 도출 
*/

#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> score(n);

    float sum=0;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        score[i]=temp;
        sum+=temp;   
    }
    int max_value= *max_element(score.begin(),score.end());
    float average = (sum/n)*(100/(float)max_value);
    printf("%f",average);
    // {점수1/M *100} + {점수2/M *100} + {점수3/M *100}  /3
    // (점수1 + 점수2 + 점수3)/3
    return 0;
}
#endif

//c언어 풀이

#if 0
#include <stdio.h> 
int main(){
    int N;
    int score[1001];
    scanf("%d",&N);

    int i=0,max=0,sum=0;
    while(i<N){
        int temp;
        scanf("%d",&temp);
        sum+=temp;
        if(max<temp) max=temp;
        i++;
    }
    float average = (float)(sum*100)/(max*N);
    printf("%f",average);


    return 0;

}

#endif

//동적할당으로 1차원 배열 메모리 관리 하기 
#if 0
#include <stdio.h> 
#include <stdlib.h>
int main(){
    int N;
    scanf("%d",&N);

    int* score = (int*)malloc(sizeof(int)*N); //1차원 배열 동적할당
    int i=0,max=0,sum=0;
    while(i<N){
        int temp;
        scanf("%d",&temp);
        sum+=temp;
        if(max<temp) max=temp;
        i++;
    }
    float average = (float)(sum*100)/(max*N);
    printf("%f",average);

    free(score);
    return 0;

}

#endif


//2차원 배열 동적 할당 개인 스터디
#if 0
#include <stdio.h>
#include <stdlib.h>
int main(){
    int row=3,col=5;

    //행 만큼 동적 할당(int**)
    int** arr=(int**)malloc(sizeof(int*)*row);

    //열 만큼 동적 할당 int*
    for(int i=0;i<row;i++){
        //arr[i] = (int*)malloc(sizeof(int)*col);
        *(arr+i) = (int*)malloc(sizeof(int)*col);
        
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            //arr[i][j]=i+j;
            *(*(arr+i)+j) = i+j;
        }
    }

    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("arr[%d][%d] : %d ",i,j,arr[i][j]);
        }
        printf("\n");
    }

    //열 만큼 동적 할당 int*
    for(int i=0;i<row;i++){
        free(arr[i]);   
    }
    free(arr);

    return 0;
}

#endif