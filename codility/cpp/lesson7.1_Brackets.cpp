#include <iostream>
#include <string>
#include <stack>
#include <typeinfo>
#include <map>

using namespace std;

int solution(string &S) {
    map<char, char> myMap;
    myMap[')'] = '(';
    myMap[']'] = '[';
    myMap['}'] = '{';

    stack<char> myStack;
    
    for(auto s : S){
        
        if(myStack.empty()){
            myStack.push(s);
            continue;
        }
        
        if(myMap.find(s) != myMap.end()){
            if(myMap[s] == myStack.top()){
                myStack.pop();   
            } else {
                myStack.push(s);   
            }
        } else {
            myStack.push(s);   
        }
    }
    
    return myStack.empty();
}