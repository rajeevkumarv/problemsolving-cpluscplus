/*
 * stack_with_max.cpp
 *
 *  Created on: 24-Mar-2020
 *      Author: rajverm2
 */

#include<vector>
#include<string>
#include<iostream>
#include <stdexcept>
using namespace std;

class StackEmptyException : public std::runtime_error{
public:
    StackEmptyException(std::string what):std::runtime_error(what){

    }
};

//Provide stack operations
class Stack {
    vector<int> S;
public:
    void push(int x){
        S.push_back(x);
    }
    void pop() throw (StackEmptyException){
        if(S.empty()) throw StackEmptyException("Stack is empty");
        S.pop_back();
    }
    int top() throw (StackEmptyException){
        if(S.empty()) throw StackEmptyException("Stack is empty");
        return S.back();
    }
    unsigned int size() {
        return S.size();
    }
};


//Extend stack to provide max api. Max api should return max in stack in O(1) time complexity
class StackWithMax : public Stack {
    vector<int> minStack;
public:
    void push(int x){
        if(size() == 0){
            minStack.push_back(x);
        }else if(x  > minStack.back()){
            minStack.push_back(x);
        }
        Stack::push(x);
    }

    void pop() throw (StackEmptyException){
        if(size() != 0 && top() == minStack.back()){
            minStack.pop_back();
        }
        Stack::pop();
    }

    int getMax() throw (StackEmptyException){
        if(minStack.empty()) throw StackEmptyException("Stack is empty");

        return minStack.back();
    }
};


//Driver Program
int main(){

    StackWithMax stack;
    stack.push(2);
    stack.push(1);
    stack.push(0);
    stack.push(4);
    stack.push(2);

    //Drop all from stack
    while(stack.size()){
        std::cout<<"Shall remove from stack -> "<<stack.top()<<" . Current max is -> "<<stack.getMax()<<std::endl;
        stack.pop();
    }

    //Expected here is exception
    try{
        int max = stack.getMax();
        std::cout<<"Max in stack "<<max<<std::endl;
    }catch(StackEmptyException& e){
        std::cout<<"Exception occurred! - Reason is  '"<<e.what()<<"'"<<std::endl;
    }
}


