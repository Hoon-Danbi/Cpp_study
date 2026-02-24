//https://www.acmicpc.net/problem/2343

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N,M;
    cin>>N>>M;
    vector<int> A(N);
    int start=0,end=0;
    for(int i=0;i<N;i++){
        cin>>A[i];
        if(start < A[i]) start = A[i];
        end += A[i];
    }

    while(start <= end){
        int middle = (start+end)/2;
        int sum=0;
        int count =0;

        for(int i=0;i<N;i++){
            if(sum+A[i] > middle){
                count++;
                sum=0;
            }
            sum += A[i];
        }
        //middle 크기 만큼 딱 맞아 떨어 진것이 아니기 때문에 +1
        if(sum != 0 ) count++;

        // count= 블루레이 갯수
        if(count > M) start=middle+1;
        else end = middle -1;
    }
    cout<<start;
    return 0;
}

