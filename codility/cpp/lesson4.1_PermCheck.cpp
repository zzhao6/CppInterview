int solution(vector<int> &A) {
    int N = A.size();
    
    if(N == 1)
    {
        return A[0] == 1;   
    }
    // create a sequence from 1 to N, and do XOR operation
    int missing = 1;
    for(int i=2; i<=N; i++)
    {
        missing ^= i;
    }
    // keep XORing on each element in A
    for(auto a : A)
    {
        missing ^= a;   
    }
    // if A is a permuatation, we should get 0 after all XOR
    if(missing == 0)
    {
        return 1;
    }
    else
    {
        return 0;   
    }
}