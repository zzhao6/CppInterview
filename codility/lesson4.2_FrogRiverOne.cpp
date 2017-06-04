int solution(int X, vector<int> &A){
    auto riverVec = vector<int>(X, false);
    int N = A.size();
    int countNoLeaf = X;
    
    for (int i=0; i<N; i++){
        
        int a = A[i];
        
        if(riverVec[a-1] == false){
    
            riverVec[a-1] = true;    
            countNoLeaf--;
            
            if(countNoLeaf == 0){
                return i;
            }
        }
        
    }
    
    return -1;
}