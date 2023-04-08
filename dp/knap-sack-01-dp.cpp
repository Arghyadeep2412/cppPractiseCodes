#include<iostream>
#include<vector>
#include<limits>
using namespace std;

// 0-1 knapsack

// recursive
int knapSack0_1Rec(vector<int> wt, vector<int> val, int w, int n) {
    if(n == 0 || w == 0) {
        return 0;
    }
    int inclVal = INT_MIN;
    if(wt[n-1] <= w) {
        inclVal = val[n-1] + knapSack0_1Rec(wt, val, w-wt[n-1], n-1);
    }
    int exclVal = knapSack0_1Rec(wt, val, w, n-1);
    return max(inclVal, exclVal);
}

// memoization -- bottom up approach
int knapSack0_1Mem(vector<int> wt, vector<int> val, int w, int n, vector<vector<int>> dp) {
    if(n == 0 || w == 0) {
        return 0;
    }
    if(dp[n][w] > -1) {
        return dp[n][w];
    }
    int inclVal = INT_MIN;
    if(wt[n-1] <= w) {
        inclVal = val[n-1] + knapSack0_1Mem(wt, val, w-wt[n-1], n-1, dp);
    }
    int exclVal = knapSack0_1Mem(wt, val, w, n-1, dp);
    dp[n][w] = max(inclVal, exclVal);
    return dp[n][w];
}

// tabulation -- top-down approach
int knapSack0_1Tab(vector<int> wt, vector<int> val, int w, int n) {
    vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
    for(int i = 0; i <= w; i++) {
        dp[0][i] = 0;
    }
    for(int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= w; j++) {
            int inclVal = INT_MIN;
            if(wt[i-1] <= j) {
                inclVal = val[i-1] + dp[i-1][j-wt[i-1]];
            }
            int exclVal = dp[i-1][j];
            dp[i][j] = max(inclVal, exclVal);
        }
    }
    return dp[n][w];
}

int main() {
    // int wt[4];
    // int val[4];
    vector<int> wt(4, 0);
    vector<int> val(4, 0);
    int n = 4, w = 10;
    int ans = knapSack0_1Rec(wt, val, w, n);

    vector<vector<int>> dpMem(n+1, vector<int>(w+1, -1));
    int ans = knapSack0_1Mem(wt, val, w, n, dpMem);
}