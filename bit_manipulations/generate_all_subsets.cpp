/*
 * generate_all_permutations.cpp
 *
 *  Created on: 23-Mar-2020
 *      Author: rajverm2
 */
#include<vector>
#include<iostream>
#include<string>
#include<cmath>

#include "../util/util.h"

using namespace std;

/*
 * Binary representation from 1-n naturally represents combination sequence at positions
 * This function finds binary representation of all numbers and finds position of 1s in it.
 * These position of 1s will point to items to be selected in subset
 */
vector<vector<char>> generate_all_subsets(vector<char>& arr){

    int count = std::pow(2,arr.size());
    vector<vector<char>> result;

    for(int i=0;i<count;++i){
        vector<char> out;
        //find all 1s in i's binary representations
        int y = i;
        while(y){
        y = (y-1)&y;
        int pos = (int) std::log2(i^y);
        y = y&~pos;
        out.push_back(arr[pos]);
        }
       result.push_back(out);
    }
    return result;
}


//Driver Program
int main(){

    vector<char> arr = {'A','B','C'};
    auto all_subsets = generate_all_subsets(arr);
    for(auto subset : all_subsets){
        util::print(subset);
    }

    std::cout<<" ----- "<<std::endl;

    arr = {'A'};
    all_subsets = generate_all_subsets(arr);
    for(auto subset : all_subsets){
        util::print(subset);
    }


}
