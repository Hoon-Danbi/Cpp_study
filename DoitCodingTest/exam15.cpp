//https://www.acmicpc.net/problem/2750
// 버블 정렬   O(n^2) swap하는 방식

#include <stdio.h>
#include <stdlib.h>




int main(){
    int N;
    scanf("%d",&N);
//N 크기 만큼 동적 할당 받기 
    int* arr = (int*)malloc(sizeof(int)*N);

//배열 입력 받기
    for(int i=0;i<N;i++){
        int num; scanf("%d",&num);
        arr[i]=num;
    }
//배열 오름차순으로 버블 정렬 하기 
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            if(arr[i] > arr[j]){
                int temp;
                temp=arr[i];
                arr[i] = arr[j]; //swap
                arr[j] = temp;
            }
        }
    }
//배열 출력하기 
    for(int i=0;i<N;i++) printf("%d\n",arr[i]);
    
    free(arr);
    return 0;
}