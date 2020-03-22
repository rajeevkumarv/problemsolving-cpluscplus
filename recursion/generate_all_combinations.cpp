/*
 * generate_all_combinations.cpp
 *
 *  Created on: 21-Mar-2020
 *      Author: rajeevkumarv84@gmail.com
 */

#ifndef PROBLEMSOLVING_CPLUSCPLUS_RECURSION_GENERATE_ALL_COMBINATIONS_CPP_
#define PROBLEMSOLVING_CPLUSCPLUS_RECURSION_GENERATE_ALL_COMBINATIONS_CPP_

#include<iostream>
#include<string>
#include<vector>
#include<iterator>

//Some simple utility functions
#include "../util/util.h"

using namespace std;

/**
 * Generate all combinations of a set
 * e.g. set {a,b,c} will have 2^n i.e. 8 combinations
 *
 * {}
 * {a}
 * {b}
 * {c}
 * {a,b}
 * {b,c}
 * {a,c}
 * {a,b,c}
 *
 */


/*
 * Actual recursive implementation
 */
void generate_all_combinations(vector<char>& input, vector<char>& out, int i){
    if(i == input.size()){
        util::print(out);
        return;
    }

    /*
     *Either input[i] would be in subset or it wont be
     *e.g. consider recursion tree for generating all subset of {a,b}
     *
     * out=[] (a,b) //initially out is empty
     *
     * out=[a] (b) ------ out[]  (b)  //a would be part of set or it wont be
     *
     * out[a, b] ()  ---- out[a, ] () --- out[b] () --- out[] ()  //b would be part of set or it wont be
     */
    out.emplace_back(input[i]);
    generate_all_combinations(input,out,i+1);
    out.pop_back();
    generate_all_combinations(input,out,i+1);

}


//Driver Programm
//int main(){
//
//    vector<char> v ={ 'A','B','C','D'};
//    vector<char> out;
//    generate_all_combinations(v,out,0);
//}



#endif /* PROBLEMSOLVING_CPLUSCPLUS_RECURSION_GENERATE_ALL_COMBINATIONS_CPP_ */
