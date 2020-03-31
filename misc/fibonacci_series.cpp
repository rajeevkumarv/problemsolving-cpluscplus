#include <iostream>
using namespace std;

int nth_fibonacci_num(int n){
    int x = 0;
    int num = 1;
    for(int i=2; i<=n;++i){
        int t = num;
        num = num + x;
        x = t;
    }
    return num;
}

//Driver
int main(){
    for(int i=1; i<=10;++i){
        std::cout<<i<<"th number is "<< nth_fibonacci_num(i)<<std::endl;
    }
}