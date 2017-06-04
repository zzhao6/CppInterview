int solution(vector<int> &A) {
    
    int N = A.size();
    auto resVec = vector<int>(N, false);
    
    for(int i=0; i<N; i++){
        int a = A[i];
        if(a <= 0 || a > N){
            continue;    // don't care non positive numbers
        }                // if some number larger than N, there must be at least one missing number between 1 and N
        
        resVec[a-1] = true;
    }
    
    for(int j=1; j<=N; j++){
        if(resVec[j-1] == false){
            return j;
        }
    }
    
    return N+1;
}