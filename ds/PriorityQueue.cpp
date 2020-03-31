#include<iostream>
#include<vector>
#include<string>
#include <initializer_list>
#include <cmath>
#include <stdexcept>

using namespace std;

class PriorityQueue {
vector<int> arr;
int l;
public:
    PriorityQueue(std::initializer_list<int> lst):arr(lst),l(lst.size()){
        buildHeap();
    }

    void heapify(int i){
        if(2*i+1 >= l){
            return;
        }
        int x = 2*i+1;
        int m = arr[x];
        if(2*i+2 < l && m < arr[2*i+2]){
            x = 2*i+2;
            m = arr[x];
        }
        if(arr[i] < arr[x]){
            std::swap(arr[i],arr[x]);
            heapify(x);
        }else{
            return;
        }
    }

    void buildHeap(){
        int pi = (arr.size() - 1 -1 )/2;
        for(int i = pi ; i>=0 ; --i){
            heapify(i);
        }
    }

    void remove(){
        if(l > 0 ){
            std::swap(arr[0],arr[l-1]);
            --l;
            heapify(0);
        }else{
            throw std::out_of_range("out of range");
        }
    }

    int get(){
        if(l>0){
            return arr[0];
        }else{
            throw std::out_of_range("out of range");
        }
    }
    int size(){
        return l;
    }
};

//Driver Program
int main(){
    PriorityQueue pq({1,2,3,4,5,6});
    while(pq.size()){
        std::cout<<pq.get()<<std::endl;
        pq.remove();
    }  
}