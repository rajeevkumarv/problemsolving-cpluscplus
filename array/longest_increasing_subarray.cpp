#include<iostream>
#include<vector>
using namespace std;

std::pair<int,int> longest_increasing_subarray(vector<int>& nums){
    int start=0,end=0;
    int cs = 0;

    int i = 1;
    for( ;i<nums.size(); ++i){
        if(nums[i] <= nums[i-1]){
            if( (end-start+1) < (i - cs) ){
                start = cs;
                end = i-1;
            }
            cs = i;
        }
    }

    if( (end-start+1) < (i - cs) ){
        start = cs;
        end = i-1;
    }

    return std::make_pair(start,end);
}

//Driver
int main(){
    {
        vector<int> nums = {2, 11, 3, 5, 13, 7, 19, 17, 23};
        auto p = longest_increasing_subarray (nums);
        std::cout<<p.first<<", "<<p.second<<" expected is 2,4"<<std::endl;
    }
    {
        vector<int> nums = {1,2,3,4};
        auto p = longest_increasing_subarray (nums);
        std::cout<<p.first<<", "<<p.second<<" expected is 0,3"<<std::endl;
    }
    {
        vector<int> nums = {4,3,2,1};
        auto p = longest_increasing_subarray (nums);
        std::cout<<p.first<<", "<<p.second<<" expected is 0,0"<<std::endl;
    }
    {
        vector<int> nums = {4,1,1,2,3,4,4};
        auto p = longest_increasing_subarray (nums);
        std::cout<<p.first<<", "<<p.second<<" expected is 2,5"<<std::endl;
    }
}