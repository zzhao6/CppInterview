#include<set>

int solution(vector<int> &A) {
    set<int> B;
    for(auto a : A){
        B.insert(a);   
    }
    
    return B.size();
}