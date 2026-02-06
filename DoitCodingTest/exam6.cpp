//https://www.acmicpc.net/problem/2018

/*
two-pointer
범위를 능동적으로 포인터(start,end)를 이용해 -> 한방향으로 쓸어 가면서 확인할수 있다. 
시간 복잡도:O(n) 
*/


#if 0
#include <iostream>
using namespace std;
int main(){
    int N; cin>>N;
    int start=0,end=0;
    int sum=0,count=0;
    
    while(end <= N){
        if(sum >N){
            sum -=start;
            start++;
        }
        else if(sum <N){
            end++;
            sum +=end;
        }
        else{
            count++; 
            end++;
            sum += end;
        }
    }
    cout<<count;
    

    return 0;
}

#endif

#if 1
#include <iostream>
using namespace std;
int main(){
    int N; cin>>N;
    int start=0,end=0;
    int sum=0,count=0;
    


    while(end <= N){
        

        if(sum >N){
            sum -=start;
            start++;
        }
        else if(sum <N){
            end++;
            sum +=end;
        }
        else{
            count++; 
            end++;
            sum += end;
        }
    }
    cout<<count;
    

    return 0;
}

#endif