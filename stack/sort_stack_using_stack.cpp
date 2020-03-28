#include <stack>
#include <iostream>

using namespace std;

/**
 * Given a stack, sort the elements in the stack using one additional stack.
 **/
void sort_stack_using_stack(stack<int>& s){
    stack<int> aux;
    while(!s.empty()){

        if(aux.empty()){
            aux.push(s.top());
            s.pop();
            continue;
        }
        if(s.top() > aux.top() ){
            aux.push(s.top());
            s.pop();
            continue;
        }else{
            int onTop = s.top();
            s.pop();
            int c = 0;
            while(!aux.empty() && onTop < aux.top()){
                s.push(aux.top());
                aux.pop();
                ++c;
            }
            aux.push(onTop);
        }
    }


    while(!aux.empty()){
        s.push(aux.top());
        aux.pop();
    }

}

//Driver Program
int main(){
    stack<int> s;
    for(auto e : {4,1,3,2,0}){
        s.push(e);
    }
    sort_stack_using_stack(s);
    while(!s.empty()){
        std::cout<<s.top()<<std::endl;
        s.pop();
    }
}