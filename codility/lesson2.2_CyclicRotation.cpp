vector<int> solution(vector<int> &A, int K) {
    if (A.size() == 0)
    {
        return A;   
    }
    
    int offset = K % A.size();
    if (offset == 0)
    {
        return A;
    }
    
    auto itr = A.end() - offset;
    auto rotated = vector<int>(itr, A.end());
    for(auto itr1=A.begin(); itr1 != itr; itr1++)
    {
        rotated.push_back(*itr1);
    }
    return rotated;
}