/*
 * utils.h
 *
 *  Created on: 13-Mar-2020
 *      Author: rajverm2
 */

#ifndef PROBLEMSOLVING_CPLUSCPLUS_UTIL_UTIL_H_
#define PROBLEMSOLVING_CPLUSCPLUS_UTIL_UTIL_H_

#include<iostream>
#include<iterator>
#include<string>

namespace util {

/**
 * Print any collection which supports forward iterator
 */
template<typename Collection> void print(const Collection& collection,std::string msg = "",bool endWithNewLine=true){
    typedef typename Collection::value_type ValueType;
    if(!msg.empty()){
        std::cout<<msg<<std::endl;
    }
    std::cout<<" [ ";
    std::copy(collection.begin(),
            collection.end(),
            std::ostream_iterator<ValueType>(std::cout,", "));
    std::cout<<"]";
    if(endWithNewLine){
        std::cout<<std::endl;
    }
}

}

#endif /* PROBLEMSOLVING_CPLUSCPLUS_UTIL_UTIL_H_ */
