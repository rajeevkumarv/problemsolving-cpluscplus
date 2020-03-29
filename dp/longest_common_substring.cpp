/**
 * Given two strings, write a function that returns the longest common substring.
 **/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Function returns longest substring using DP
 */
int lcsstr_dp(string s1,string s2){
    vector<vector<int>> table(s1.size()+1,vector<int>(s2.size()+1,0));
    int res = 0;
    for(int i=1; i<=s1.size();++i){
        for(int j=1; j<=s2.size(); ++j){
            if(s1[i-1] == s2[j-1]){
                table[i][j]=table[i-1][j-1]+1;
            }else{
                table[i][j]=std::max(table[i][j-1],table[i-1][j]);
            }
            res = res > table[i][j] ? res : table[i][j];
        }
    }
    return res;
}

/**
 * Function returns longest substring, with plain recursion
 */
int lcsstr(string s1,string s2,int m,int n,int count){
    if ( m < 0 || n < 0 ){
        return count;
    }

    if(s1[m] == s2[n]){
        return lcsstr(s1,s2,m-1,n-1,count+1);
    }
    return std::max(
        lcsstr(s1,s2,m-1,n,0),
        lcsstr(s1,s2,m,n-1,0)
    );
}


/**
 * Function returns longest substring with memoization
 */
int lcsstr_memoization(string s1,string s2,int m,int n,int count,vector<vector<int>>& table){
    if ( m < 0 || n < 0 ){
        return count;
    }
    if(table[m][n] == -1){
        int res = 0;
        if(s1[m] == s2[n]){
            res = lcsstr(s1,s2,m-1,n-1,count+1);
        }else {
            res = std::max(
                lcsstr(s1,s2,m-1,n,0),
                lcsstr(s1,s2,m,n-1,0)
            );
        }
        table[m][n]=res;
    }
    return table[m][n];
}

int lcsstr_memoization(string s1,string s2,int m,int n,int count){
    vector<vector<int>> table(s1.size(),vector<int>(s2.size(),-1));
    return lcsstr_memoization(s1,s2,m,n,count,table);
}


//Driver Program
int main(){
    //Case 1 : Try same strings
    {
        string s1 = "abc";
        string s2 = "abc";
        std::cout<<"lcsstr of "<<s1<<" and "<<s2 <<" is "<<lcsstr(s1,s2,s1.size()-1,s2.size()-1,0)<<std::endl;
        std::cout<<"lcstr with memoization of "<<s1<<" and "<<s2 <<" is "<<lcsstr_memoization(s1,s2,s1.size()-1,s2.size()-1,0)<<std::endl;
        std::cout<<"lcsstr with dp of "<<s1<<" and "<<s2 <<" is "<<lcsstr_dp(s1,s2)<<std::endl;
    }

    //Case 2 : Try nothing common
    {
        string s1 = "abc";
        string s2 = "xyz";
        std::cout<<"lcsstr of "<<s1<<" and "<<s2 <<" is "<<lcsstr(s1,s2,s1.size()-1,s2.size()-1,0)<<std::endl;
        std::cout<<"lcstr with memoization of "<<s1<<" and "<<s2 <<" is "<<lcsstr_memoization(s1,s2,s1.size()-1,s2.size()-1,0)<<std::endl;
        std::cout<<"lcsstr with dp of "<<s1<<" and "<<s2 <<" is "<<lcsstr_dp(s1,s2)<<std::endl;    }

    //Case 3 : Try some common case
    {
        string s1 = "abcd";
        string s2 = "xyzabmnabcdmn";
        std::cout<<"lcsstr of "<<s1<<" and "<<s2 <<" is "<<lcsstr(s1,s2,s1.size()-1,s2.size()-1,0)<<std::endl;
        std::cout<<"lcstr with memoization of "<<s1<<" and "<<s2 <<" is "<<lcsstr_memoization(s1,s2,s1.size()-1,s2.size()-1,0)<<std::endl;
        std::cout<<"lcsstr with dp of "<<s1<<" and "<<s2 <<" is "<<lcsstr_dp(s1,s2)<<std::endl;    }

    //Case 4 : Try some common case
    {
        string s1 = "abcd";
        string s2 = "xyzabcdmnabmn";
        std::cout<<"lcsstr of "<<s1<<" and "<<s2 <<" is "<<lcsstr(s1,s2,s1.size()-1,s2.size()-1,0)<<std::endl;
        std::cout<<"lcstr with memoization of "<<s1<<" and "<<s2 <<" is "<<lcsstr_memoization(s1,s2,s1.size()-1,s2.size()-1,0)<<std::endl;
        std::cout<<"lcsstr with dp of "<<s1<<" and "<<s2 <<" is "<<lcsstr_dp(s1,s2)<<std::endl;    }

}