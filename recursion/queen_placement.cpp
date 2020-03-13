/*
 * queen_placement.cpp
 *
 *  Created on: 11-Mar-2020
 *      Author: rajverm2
 */

#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<iterator>
#include<cmath>
#include<sstream>

//Inclusion for some simple utilities e.g. print collection
#include "../util/util.h"

using namespace std;

/*
 * return false if a queens placement at row r and column c is attacked by a queen
 * else return true
 */
bool isDiagonallySafe(vector<int> assigned,int i,int offset, int j){
    for(int r=0;r<offset;++r){
        if(std::abs(assigned[r]-j) == std::abs(r - i)){
            return false;
        }
    }
    return true;
}

void queenNonAttachingPlacements(vector<vector<int>>& results,vector<int>& columns, int r,int offset){

    //we are done when we have exhausted all pending columns
    if(offset == columns.size()){
        results.emplace_back(columns);
    }

    /*
     * Go over all pending columns in a row and attempt to place queen there
     * for first row, will try all 4 columns, for 2nd row queen can only be placed in remaining 3 columns, and so on
     */
    for(int i=offset; i < columns.size(); ++i){
        if(isDiagonallySafe(columns, r,offset,columns[i])){ // continue if queen is not diagonally attacked by other queens
            //keep all used columns on the left, all candidate columns would be placed after offset
            std::swap(columns[offset],columns[i]);
            queenNonAttachingPlacements(results,columns,r+1,offset+1);
            std::swap(columns[offset],columns[i]);
        }

    }
}

bool queenNonAttachingPlacement(vector<int>& columns, int r,int offset){
    //we are done when we have exhausted all pending columns
    if(offset == columns.size()){
        return true;
    }

    /*
     * Go over all pending columns in a row and attempt to place queen there
     * for first row, will try all 4 columns, for 2nd row queen can only be placed in remaining 3 columns, and so on
     */
    for(int i=offset; i < columns.size(); ++i){
        if(isDiagonallySafe(columns, r,offset,columns[i])){ // continue if queen is not diagonally attacked by other queens
            //keep all used columns on the left, all candidate columns would be placed after offset
            std::swap(columns[offset],columns[i]);
            if(queenNonAttachingPlacement(columns,r+1,offset+1)){
                return true;
            }
            std::swap(columns[offset],columns[i]);
        }
    }
    return false;
}

//Placement of N queens on NxN board
vector<int> queenNonAttachingPlacement(int N){
    vector<int> columns;
    int i=0;
    std::generate_n(std::back_inserter(columns),N,[&i](void)-> int {return i++;});
    if(!queenNonAttachingPlacement(columns,0,0)){
        return vector<int>();
    }
    return columns;
}

//All queen placements of N queens on NxN board
void queenNonAttachingPlacements(vector<vector<int>>& placements, int N){
    vector<int> columns;
    int i=0;
    std::generate_n(std::back_inserter(columns),N,[&i](void)-> int {return i++;});
    queenNonAttachingPlacements(placements,columns,0,0);
}

//Driver program
int main(){

    //Get a non attacking position for 4 queens on 4x4 board
    {
        std::cout<<"A Non attacking position for 4x4 board : "<<std::endl;
        vector<int> placement  = queenNonAttachingPlacement(4);
        util::print(placement);
    }

    //Get a non attacking position for 8 queens on 8x8 board
    {
        std::cout<<"A Non attacking position for 8x8 board : "<<std::endl;
        vector<int> placement  = queenNonAttachingPlacement(8);
        util::print(placement);
    }

    //Get all non attacking position for 4 queens on 4x4 board
    {
        std::cout<<"All non attacking position for 4x4 board : "<<std::endl;
        vector<vector<int>> placements;
        queenNonAttachingPlacements(placements,4);
        for(auto& placement : placements){
            util::print(placement);
        }
    }


    //Get all non attacking position for 8 queens on 8x8 board
    {
        std::cout<<"All non attacking position for 8x8 board : "<<std::endl;
        vector<vector<int>> placements;
        queenNonAttachingPlacements(placements,8);
        for(auto& placement : placements){
            util::print(placement);
        }
    }
}
