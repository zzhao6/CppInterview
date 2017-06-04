int solution(vector<int> &A) {
    
    int missing = A[0];

    for (auto itr=++A.begin(); itr != A.end(); itr++)
    {
        missing = missing^(*itr);
    }
    
    return missing;
}