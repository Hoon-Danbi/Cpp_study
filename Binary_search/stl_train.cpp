#include <stdio.h>
#include <algorithm>

int main(){
    int A[9] = {1,4,9,11,11,11,20,20,45};
    int target = 11;
    int idx = std::lower_bound(A+0, A+9, target) - A;
    int idx_1=std::upper_bound(A+0,A+9,target)-A;
    //lower_bound를 사용하면 해당 값의 주소 값이 나온다. 
    //그래서 배열의 시작 주소값을 빼주면 인덱스를 구할수 있다.
    //찾지 못하면 -1 이 출력 된다. 
    //upper_bound는 해당 값이 초과 된 첫 위치의 주소를 반환한다. 
    
    printf("lower: %d , upper: %d", idx,idx_1); // 3 출력
    
    return 0;
}