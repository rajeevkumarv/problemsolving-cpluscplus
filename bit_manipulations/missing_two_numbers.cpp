/**
 * Given an array containing all the numbers from 1 to n except two, find the two missing numbers
 */

#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <stdexcept>

using namespace std;

std::pair<int,int> find_two_missing_numbers(vector<int>&  v) {
    int size = v.size() + 2;
    int total_sum = (size*(size+1))/2;
    int array_sum = 0;
    std::for_each(v.begin(),v.end(),[&array_sum](int x)-> void {array_sum+=x;});

    int missing_sum = total_sum - array_sum;

    //two elements are certainly not equal, so one is going to less than missing_sum / 2 and other would be greater than missing_sum / 2
    int pivot = missing_sum / 2;
    int total_lower_sum = 0;
    for(int i=1;i<=pivot;++i) {
        total_lower_sum^=i;
    }

    int total_upport_sum = 0;
    for(int i=pivot+1;i<=size;++i) {
        total_upport_sum^=i;
    }

    int left_sum = 0 ;
    int right_sum = 0 ;
    for(auto i: v){
        if(i <= pivot){
            left_sum^=i;
        }else{
            right_sum^=i;
        }
    }

    int x = left_sum^total_lower_sum;
    int y = right_sum^total_upport_sum;

    return std::make_pair(x,y);
}

//Driver Program
int main(){
    //Case 1
    vector<int> v = {1,4,3};
    auto p = find_two_missing_numbers(v);
    std::cout<<"Two missing numbers are "<<p.first<<" , "<<p.second << std::endl;

    //Case 2
    v = {1};
    p = find_two_missing_numbers(v);
    std::cout<<"Two missing numbers are "<<p.first<<" , "<<p.second << std::endl;
}