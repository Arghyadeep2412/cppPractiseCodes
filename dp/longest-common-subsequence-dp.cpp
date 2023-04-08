#include<iostream>
#include<vector>
#include<limits>
#include<string>
using namespace std;

/* Longest common substring
You have been given two strings 'STR1' and 'STR2'. You have to find the length of the longest common substring.
A string “s1” is a substring of another string “s2” if “s2” contains the same characters as in “s1”, in the same order and in continuous fashion also.
Sample Input 1:
2
abcjklp acjkp
wasdijkl wsdjkl
Sample Output 1:
3
3
*/

int solveTab1(string& str1, string& str2) {
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    for(int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for(int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }
	int res = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int ans = INT_MIN;
            if(str1[i-1] == str2[j-1]) {
                ans = 1 + dp[i-1][j-1];
            } else {
				ans = 0;
                //ans = max(dp[i][j-1], dp[i-1][j]);
            }
            dp[i][j] = ans;
			if(ans > res) {
				res = ans;
			}
        }
    }
	return res;
    //return dp[n][m];
}

int lcs(string &str1, string &str2){
	//	Write your code here.
    return solveTab1(str1, str2);
    //return solveRec1(str1, str1.length(), str2, str2.length(), 0);
}

/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Input: text1 = "abcde", text2 = "ace" 
Output: 3  -- length of longest common subsequence
Explanation: The longest common subsequence is "ace" and its length is 3.

subsequence - can be discontinuous
substring - has to be continuous
*/

int solveRec(string str1, int n, string str2, int m) {
    if(n == 0 || m == 0) {
        return 0;
    }
    int ans = INT_MIN;
    if(str1[n-1] == str2[m-1]) {
        ans = 1 + solveRec(str1, n-1, str2, m-1);
    } else {
        int a = solveRec(str1, n, str2, m-1);
        int b = solveRec(str1, n-1, str2, m);
        ans = max(a,b);
    }
    return ans;
}

int solveMem(string str1, int n, string str2, int m, vector<vector<int>>& dp) {
    if(n == 0 || m == 0) {
        return 0;
    }
    if(dp[n][m] > -1) {
        return dp[n][m];
    }
    int ans = INT_MIN;
    if(str1[n-1] == str2[m-1]) {
        ans = 1 + solveMem(str1, n-1, str2, m-1, dp);
    } else {
        int a = solveMem(str1, n, str2, m-1, dp);
        int b = solveMem(str1, n-1, str2, m, dp);
        ans = max(a,b);
    }
    dp[n][m] = ans;
    return dp[n][m];
}

int solveTab(string str1, string str2) {
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    for(int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for(int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int ans = INT_MIN;
            if(str1[i-1] == str2[j-1]) {
                ans = 1 + dp[i-1][j-1];
            } else {
                ans = max(dp[i][j-1], dp[i-1][j]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[n][m];
}

int longestCommonSubsequence(string str1, string str2) {
    return solveTab(str1, str2);
    // int n = str1.length();
    // int m = str2.length();
    // vector<vector<int>> dpMem(n+1, vector<int>(m+1, -1));
    // return solveMem(str1, n, str2, m, dpMem);
    //return solveRec(str1, n, str2, m);
}

