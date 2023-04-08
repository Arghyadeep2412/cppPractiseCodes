#include<iostream>
#include<vector>
#include<limits>
using namespace std;

/*
*/
/*Given a rod of length ‘N’ units. 
The rod can be cut into different sizes and each size has a cost associated with it. 
Determine the maximum cost obtained by cutting the rod and selling its pieces.*/
int solveRec(vector<int>& length, vector<int> &price, int n, int remLen) {
	if(n == 0 || remLen == 0) {
		return 0;
	}
	int inclPrice = 0, exclPrice = 0;
	if(length[n-1] <= remLen) {
		inclPrice = price[n-1] + solveRec(length, price, n, remLen-length[n-1]);
	}
	exclPrice = solveRec(length, price, n-1, remLen);
	return max(inclPrice, exclPrice);
}

int solveMem(vector<int>& length, vector<int> &price, int n, int remLen, vector<vector<int>>& dp) {
    if(n == 0 || remLen == 0) {
		return 0;
	}
    if(dp[n][remLen] > -1) {
        return dp[n][remLen];
    }
    int inclPrice = 0, exclPrice = 0;
	if(length[n-1] <= remLen) {
		inclPrice = price[n-1] + solveMem(length, price, n, remLen-length[n-1], dp);
	}
	exclPrice = solveMem(length, price, n-1, remLen, dp);
	dp[n][remLen] = max(inclPrice, exclPrice);
    return dp[n][remLen];
}

int solveTab(vector<int>& length, vector<int> &price, int n) {
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    for(int i = 0; i <= n; i++) {
        dp[0][i] = 0;
        dp[i][0] = 0;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int inclPrice = 0, exclPrice = 0;
            if(length[i-1] <= j) {
                inclPrice = price[i-1] + dp[i][j-length[i-1]];
            }
            exclPrice = dp[i-1][j];
            dp[i][j] = max(inclPrice, exclPrice);
        }
    }
    return dp[n][n];
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	if(n == 0) {
		return 0;
	}
	vector<int> length(n, 0);
	for(int i = 0; i < n; i++) {
		length[i] = i+1;
	}
	//return solveRec(length, price, n, n);
    vector<vector<int>> dpMem(n+1, vector<int>(n+1, -1));
    return solveMem(length, price, n, n, dpMem);
}
