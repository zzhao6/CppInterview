int solution(vector<int> &A) {
    
    int countZero = 0;
    int countOne = 0;
    
    bool countedZeroAlready = false;
    bool foundFirstZero = false;
    
    vector<pair<int, int>> pieceVecRaw;
    
    for(auto a : A){
        if(!foundFirstZero){
            if(a == 1){
                continue;    // skip all one before the first zero
            } else {
                foundFirstZero = true;
                countZero++;
            }
        } else {
            
            if(a == 0 && !countedZeroAlready){ // have not finished count zero in this piece
                countZero++;
            } else if(a == 1){ // finished counting zero in this piece, move to one
                countOne++;
                countedZeroAlready = true;
            } else {  // a == 0 && countedZeroAlready, finished this piece, move to next
                pieceVecRaw.push_back(make_pair(countZero, countOne));
                countOne = 0;
                countZero = 1;
            }
        }
    }
    
    // at the end of A
    // if there are trailing 0s in A, ignore
    // if A ends by several 1s, add to raw list
    if(*(--A.end()) == 1){
        pieceVecRaw.push_back(make_pair(countZero, countOne));
    }
    
    // for(auto a1 : pieceVecRaw){
    //     cout << a1.first << " " << a1.second << endl;   
    // }
    
    if(pieceVecRaw.size() <= 0){
        return 0;
    }
    
    // now do prefix sum on raw vec
    auto revItr = pieceVecRaw.rbegin();
    vector<pair<int, int>> resVec;
    resVec.push_back(*revItr);
    
    int prefixSum = revItr->second;
    revItr++;    // do prefix sum from the second
    for(revItr; revItr!=pieceVecRaw.rend(); revItr++){
        prefixSum += revItr->second;
        resVec.push_back(make_pair(revItr->first, prefixSum));
    }
    
    // cout << endl << endl;
    // for(auto a1 : resVec){
    //     cout << a1.first << " " << a1.second << endl;   
    // }
    
    long res = 0;
    for(auto p : resVec){
        res += p.first * p.second;
        if(res > 1000000000){
            return -1;
        }
    }
    
    return res;
}