#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int missing_number(vector<int>& nums){

    //XOR of numbers from 1 to n
    int n_sum = 0;
    for(int i=1;i<=(nums.size()+1); ++i) n_sum^=i;

    //XOR of numbers of array
    int m_sum = 0;
    std::for_each(nums.begin(),nums.end(),[&m_sum](int x)->void { m_sum^=x; } );

    return n_sum^m_sum;
}


//Driver Program
int main(){
    vector<int> v = {1,2};
    std::cout<<"Missing number is "<<missing_number(v)<<std::endl;

    v = {1,3};
    std::cout<<"Missing number is "<<missing_number(v)<<std::endl;

    v = {1,3,2,4};
    std::cout<<"Missing number is "<<missing_number(v)<<std::endl;

    v = {};
    std::cout<<"Missing number is "<<missing_number(v)<<std::endl;
}