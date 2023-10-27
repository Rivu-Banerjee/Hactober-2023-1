# Minimum Deletions
# GFG
# POTD_27-10-23

# Problem Statement

# Minimum Deletions
Given a string of S as input. Your task is to write a program to delete the minimum number of characters from the string so that the resultant string is a palindrome.
Note: The order of characters in the string should be maintained.

Example 1:
Input: 
S = "aebcbda"
Output: 
2
Explanation: 
Remove characters 'e' and 'd'.

Example 2:
Input: 
S = "geeksforgeeks"
Output: 
8
Explanation: 
One of the possible result string can be "eefee", so answer is 13 - 5 = 8.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function minimumNumberOfDeletions() which takes the string S as inputs and returns the minimum number of deletions required to convert S into a pallindrome.

Expected Time Complexity: O(|S|2)
Expected Auxiliary Space: O(|S|2)

Constraints:
1 ≤ |S| ≤ 103

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

# Solution in CPP

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int minimumNumberOfDeletions(string S) { 
        int n = S.size();
        string R =  string(S.rbegin(), S.rend()); // string reverese.
        
        int dp[n+1][n+1] = {}; // To initialize first row and column to '0'
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(S[i] == R[j])
                {
                    dp[i+1][j+1] = 1 + dp[i][j];
                }
                else
                {
                    dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        return n-dp[n][n];
    } 
};

int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
