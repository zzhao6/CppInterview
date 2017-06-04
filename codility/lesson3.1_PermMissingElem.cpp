int solution(vector<int> &A) {
    long N = A.size();
    
    long sum = (N+2) * (N+1) / 2;
    long sumA = 0;
    for(auto a : A)
    {
        sumA += a;   
    }
    
    return int(sum - sumA);
}