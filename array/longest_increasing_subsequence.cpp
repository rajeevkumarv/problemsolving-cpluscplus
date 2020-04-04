#include<vector>
#include<iostream>

using namespace std;

int longest_increasing_subsequence(vector<int>& nums){
    vector<int> maxLen(nums.size(),0);
    int msf = 0 ;
    for(int i=0; i < nums.size(); ++i){
        for(int j=0; j < i ; ++j ){
            if(nums[i] > nums[j] ){
                maxLen[i] = std::max(maxLen[i],maxLen[j]);
            }
        }
        maxLen[i]+=1; //Add for self count
        msf = std::max(msf,maxLen[i]); //update max so far
    }  
    return msf;
}

//Driver
int main(){
    {
        vector<int> num = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9};
        int res = longest_increasing_subsequence(num);
        std::cout<<"(expected is 4) Longest increasing susequence length is "<< res << std::endl;
    }
}