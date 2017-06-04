#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    sort(A.begin(), A.end());
    int N = A.size();
    
    // number of positive, negative and 0s in A
    int posCnt = 0;
    int negCnt = 0;
    int zeroCnt = 0;
    
    for(auto a : A){
        if(a > 0) posCnt++;
        if(a < 0) negCnt++;
        if(a == 0) zeroCnt++;
    }
    
    int res = 0;
    if(posCnt >= 2 && negCnt <= 1){
        res = A[N-1] * A[N-2] * A[N-3];   
    } else if(posCnt >= 2 && negCnt > 1){
        res = A[N-1] * A[N-2] * A[N-3];
        if(A[0] * A[1] * A[N-1] > res){
            res = A[0] * A[1] * A[N-1];
        }
    } else if(posCnt == 1) {
        res = A[0] * A[1] * A[N-1];
    } else { // posCnt == 0
        res = A[N-1] * A[N-2] * A[N-3];
    }
    
    return res;
}