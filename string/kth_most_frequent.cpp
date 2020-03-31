
#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
#include<utility>

using namespace std;

string kth_most_frequent(vector<string>& strings,int k){
    std::unordered_map<string,int> freqs;
    std::for_each(strings.begin(),strings.end(),[&freqs](const string& s)->void {freqs[s]+=1;});
    typedef typename std::unordered_map<string,int>::value_type Val;
    std::vector<std::pair<string,int>> v(freqs.begin(),freqs.end());
    std::sort(v.begin(),v.end(),[](const Val& e1,const Val& e2)->bool {return e1.second > e2.second;});
    return k > v.size()? std::string() : v[k-1].first;
}

//Driver Program
int main(){
    {
        vector<string> v = {"a","a","b"};
        std::cout<<"Kth most frequent is "<<kth_most_frequent(v,1)<<std::endl;
        std::cout<<"Kth most frequent is "<<kth_most_frequent(v,2)<<std::endl;
        std::cout<<"Kth most frequent is "<<kth_most_frequent(v,3)<<std::endl;

    }
}