#include <stack>
using namespace std;


int solution(vector<int> &A, vector<int> &B) {
    int N = A.size();
    if(N == 1){
        return 1;   
    }
    
    stack<int> zeroStack;
    int res = 0;
    bool findFirstZeroReverseB = false;
    for(int i=0; i<N; i++){
        int rIdx = N - 1 - i;
        if(findFirstZeroReverseB){
            if(B[rIdx] == 0){
                // put in stack    
                zeroStack.push(A[rIdx]);
            } else {
                // compaure to the top of stack, and eat
                if(zeroStack.empty()){
                    res++;  // stack is empty, no 0s, this 1 is survived.   
                }
                
                while(!zeroStack.empty()){
                    // keep eating
                    if(A[rIdx] < zeroStack.top()){  // 1 is eaten by top 0 in the stack
                        break;
                    } else { // 0 is eaten, we go to next
                        zeroStack.pop();
                        if(zeroStack.empty()){
                            res++;  // zeroStack is empty, this 1 is survived.   
                        }
                    }
                }
            }
        } else {
            if(B[rIdx] == 0){
                findFirstZeroReverseB = true;
                zeroStack.push(A[rIdx]);
            } else {
                res++;  // B has trailing 1s, all will survive
            }
        }
    }
    
    return res + zeroStack.size();
}