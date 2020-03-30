#include<string>
#include<iostream>
#include<vector>

using namespace std;

int lcssq(string s1,string s2,int m,int n){
    if ( m < 0 || n < 0){
        return 0;
    }

    int res = 0;
    if(s1[m] == s2[n]){
        res = 1 + lcssq(s1,s2,m-1,n-1);
    }
    return std::max(
        {res,
        lcssq(s1,s2,m-1,n),
        lcssq(s1,s2,m,n-1)}
    );
}

int lcssq_memoization(string s1,string s2,int m,int n,vector<vector<int>>& table){
    if ( m < 0 || n < 0){
        return 0;
    }

    if(table[m][n]==-1){
        int res = 0;
        if(s1[m] == s2[n]){
            res = 1 + lcssq(s1,s2,m-1,n-1);
        }
        res = std::max(
            {res,
            lcssq(s1,s2,m-1,n),
            lcssq(s1,s2,m,n-1)}
        );
        table[m][n]=res;
    }
    return table[m][n];
}

int lcssq_memoization(string s1,string s2,int m,int n){
    vector<vector<int>> table(s1.size(),vector<int>(s2.size(),-1));
    return lcssq_memoization(s1,s2,m,n,table);
}

int lcssq_dp(string s1,string s2){
    vector<vector<int>> table(s1.size()+1,vector<int>(s2.size()+1,0));
    for(int i=1;i<=s1.size();++i){
        for(int j=1; j<=s2.size(); ++j){
            int res = table[i-1][j-1]+(s1[i-1] == s2[j-1]? 1 : 0);
            table[i][j]=std::max(
                {
                    table[i-1][j],
                    table[i][j-1],
                    res
                }
            );
        }
    }
    return table[s1.size()][s2.size()];
}


//Driver Program
int main(){
    {
        string s1 = "abc";
        string s2 = "abc";
        std::cout<<"longest common subsequence with recursive is " << lcssq(s1,s2,s1.size()-1,s2.size()-1) <<std::endl;
        std::cout<<"longest common subsequence with memoization is " << lcssq_memoization(s1,s2,s1.size()-1,s2.size()-1) <<std::endl;
         std::cout<<"longest common subsequence with dp is " << lcssq_dp(s1,s2) <<std::endl;
    }
    {
        string s1 = "abc";
        string s2 = "xyz";
        std::cout<<"longest common subsequence with recursive is " << lcssq(s1,s2,s1.size()-1,s2.size()-1) <<std::endl;
         std::cout<<"longest common subsequence with memoization is " << lcssq_memoization(s1,s2,s1.size()-1,s2.size()-1) <<std::endl;
         std::cout<<"longest common subsequence with dp is " << lcssq_dp(s1,s2) <<std::endl;

    }
    {
        string s1 = "abc";
        string s2 = "xaybzc";
        std::cout<<"longest common subsequence with recursive is " << lcssq(s1,s2,s1.size()-1,s2.size()-1) <<std::endl;
         std::cout<<"longest common subsequence with memoization is " << lcssq_memoization(s1,s2,s1.size()-1,s2.size()-1) <<std::endl;
          std::cout<<"longest common subsequence with dp is " << lcssq_dp(s1,s2) <<std::endl;

    }
    {
        string s1 = "abc";
        string s2 = "xyzabc";
        std::cout<<"longest common subsequence with recursive is " << lcssq(s1,s2,s1.size()-1,s2.size()-1) <<std::endl;
         std::cout<<"longest common subsequence with memoization is " << lcssq_memoization(s1,s2,s1.size()-1,s2.size()-1) <<std::endl;
         std::cout<<"longest common subsequence with dp is " << lcssq_dp(s1,s2) <<std::endl;
    }
}