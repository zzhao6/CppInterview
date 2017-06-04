#include <set>


int solution(vector<int> &A) {
    int N = A.size();
    if(N < 3){
        return 0;   
    }
    
    multiset<int> ms;
    for(auto a : A){
        ms.insert(a);   
    }
    
    auto itr1 = ms.begin();
    auto itr2 = ++ms.begin();
    auto itr3 = ++++ms.begin();
    
    while(itr3 != ms.end()){
        
        if(*itr1 + *itr2 > *itr3 &&
            *itr2 + *itr3 > *itr1 &&
            *itr3 + *itr1 > *itr2){
            
            return 1;    
                    
        }
        
        itr1++;
        itr2++;
        itr3++;
    }
    
    return 0;
}