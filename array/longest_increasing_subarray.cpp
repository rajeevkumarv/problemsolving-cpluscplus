/*
 * longest_increasing_contiguous_subarray.cpp
 *
 *  Created on: 22-Mar-2020
 *      Author: rajeevkumarv84@gmail.com
 */

#include<vector>
#include<string>
#include<iostream>
#include<numeric>

//inclusion for simple utility functions
#include "../util/util.h"

using namespace std;

std::pair<int,int> longest_increasing_subarray(vector<int> arr){

    if(arr.empty()) return std::make_pair(0,0);

    //Table to fill longest increasing subarray for every element
    vector<int> ls(arr.size());
    ls[0] =1; //for first element, it longest subarray would be 1
    int max_so_far =ls[0];
    int x=0;
    int y=0;
    int cur_start =0;

    for(int i = 1; i < arr.size(); ++i){
        if(arr[i] > arr[i-1]){
            ls[i]=ls[i-1]+1;
        }else{
            ls[i]=1;
            cur_start = i;
        }
        if(max_so_far < ls[i]){
            x = cur_start;
            y = i;
            max_so_far = ls[i];
        }
    }
    return std::make_pair(x,y);
}

void print(vector<int>& arr,std::pair<int,int> res){
    int i = res.first;
    int j = res.second;
    util::print(arr,"Longest increasing subsequence for ",false);
    std::cout<<" is --->>> "<< " [ ";
    for( ; i<=j ; ++i){
        std::cout<<arr[i]<< ", ";
    }
    std::cout<<" ] "<<std::endl;
}

//Driver program
int main(){
    vector<int> arr = {1};
    auto result = longest_increasing_subarray(arr);
    print(arr,result);

    arr = {3,2,1};
    result = longest_increasing_subarray(arr);
    print(arr,result);

    arr = {1,2,3};
    result = longest_increasing_subarray(arr);
    print(arr,result);

    arr = {2,11,3,5,13,7,19,17,23};
    result = longest_increasing_subarray(arr);
    print(arr,result);

}
