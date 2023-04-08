#include<iostream>
#include<vector>
#include<limits>
#include<string>
#include<unordered_map>
using namespace std;

/* Egg droping problem
You are given N identical eggs and you have access to a K-floored building from 1 to K.

There exists a floor f where 0 <= f <= K such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break. There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
Return the minimum number of moves that you need to determine with certainty what the value of f is.

Input:
N = 1, K = 2
Output: 2
Explanation: 
1. Drop the egg from floor 1. If it 
   breaks, we know that f = 0.
2. Otherwise, drop the egg from floor 2.
   If it breaks, we know that f = 1.
3. If it does not break, then we know f = 2.
4. Hence, we need at minimum 2 moves to
   determine with certainty what the value of f is.
*/
int solveRec(int e, int f) {
    if(f <= 1) {
        return f;
    }
    if(e == 1) {
        return f;
    }
    int ans = INT_MAX;
    for(int k = 1; k <= f; k++) {
        int breaks = solveRec(e-1, k-1);
        int breaksNot = solveRec(e, f-k);
        int tempAns = 1 + max(breaks, breaksNot); // for worst case possible
        ans = min(ans, tempAns);
    }
    return ans;
}

int solveMem(int e, int f, vector<vector<int>>& dp) {
    if(f <= 1) {
        return f;
    }
    if(e == 1) {
        return f;
    }
    if(dp[e][f] > -1) {
        return dp[e][f];
    }
    int ans = INT_MAX;
    for(int k = 1; k <= f; k++) {
        int breaks = solveMem(e-1, k-1, dp);
        int breaksNot = solveMem(e, f-k, dp);
        int tempAns = 1 + max(breaks, breaksNot); // for worst case possible
        ans = min(ans, tempAns);
    }
    dp[e][f] = ans;
    return dp[e][f];
}
int eggDrop(int n, int k) 
{
    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
    return solveMem(n, k, dp);
    return solveRec(n, k);
    // your code here
}

/* Scrambled string -- 
Given two strings S1 and S2 of equal length, the task is to determine if S2 is a scrambled form of S1.

Scrambled string: Given string str, we can represent it as a binary tree by partitioning it into two non-empty substrings recursively.
Below is one possible representation of str = coder:

To scramble the string, we may choose any non-leaf node and swap its two children. 
Suppose, we choose the node co and swap its two children, it produces a scrambled string ocder.
Similarly, if we continue to swap the children of nodes der and er, it produces a scrambled string ocred.

Note: Scrambled string is not the same as an Anagram.

*/
bool solveRec(string s1, string s2) {
    if(s1.length() != s2.length()) {
        return false;
    }
    if(s1 == s2) {
        return true;
    }
    if(s1.length() <= 1) {
        return false;
    }
    int n = s1.length();
    bool isScrambled = false;
    for(int i = 1; i < n; i++) {
        string ls1 = s1.substr(0, i);
        string rs1 = s1.substr(i, n-i);
        string ls2 = s2.substr(0, i);
        string rs2 = s2.substr(i, n-i);

        bool ifSwapped = false;
        if(solveRec(s1.substr(0, i), s2.substr(n-i, i)) && solveRec(s1.substr(i, n-i), s2.substr(0, n-i))) {
            ifSwapped = true;
        }

        bool ifNotSwapped = false;
        if(solveRec(s1.substr(0, i), s2.substr(0, i)) && solveRec(s1.substr(i, n-i), s2.substr(i, n-i))) {
            ifNotSwapped = true;
        }

        isScrambled = ifSwapped || ifNotSwapped;
        if(isScrambled) {
            break;
        }
    }
    return isScrambled;
}

string getkey(string s1, string s2) {
    return (s1 + "#" + s2);
}
bool solveMem(string s1, string s2, unordered_map<string, bool>& mp) {
    if(s1.length() != s2.length()) {
        return false;
    }
    if(s1 == s2) {
        return true;
    }
    if(s1.length() <= 1) {
        return false;
    }
    string currKey = getkey(s1, s2);
    if(mp.find(currKey) != mp.end()) {
        return mp[currKey];
    }
    int n = s1.length();
    bool isScrambled = false;
    for(int i = 1; i < n; i++) {
        bool ifSwapped = false;
        if(solveMem(s1.substr(0, i), s2.substr(n-i, i), mp) && solveMem(s1.substr(i, n-i), s2.substr(0, n-i), mp)) {
            ifSwapped = true;
        }

        bool ifNotSwapped = false;
        if(solveMem(s1.substr(0, i), s2.substr(0, i), mp) && solveMem(s1.substr(i, n-i), s2.substr(i, n-i), mp)) {
            ifNotSwapped = true;
        }

        isScrambled = ifSwapped || ifNotSwapped;
        if(isScrambled) {
            break;
        }
    }
    mp[currKey] = isScrambled;
    return isScrambled;
}
bool isScramble(string s1, string s2){
    //code here
    unordered_map<string, bool> mp;
    return solveMem(s1, s2, mp);
    return solveRec(s1, s2);
}

/* Boolean Parenthesization
Given a boolean expression S of length N with following symbols.
Symbols
    'T' ---> true
    'F' ---> false
and following operators filled between symbols
Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

Input: N = 7
S = T|T&F^T
Output: 4
Explaination: The expression evaluates 
to true in 4 ways ((T|T)&(F^T)), 
(T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).
*/
long getTotalWays(long leftTrueCount, long leftFalseCount, long rightTrueCount, long rightFalseCount, char opr, bool target) {
    long ans = 0;
    if(target) {
        if(opr == '&') {
            ans += (leftTrueCount * rightTrueCount) % 1003;
        } else if(opr == '|') {
            ans += (leftTrueCount * rightFalseCount) % 1003;
            ans += (leftTrueCount * rightTrueCount) % 1003;
            ans += (leftFalseCount * rightTrueCount) % 1003;
        } else if(opr == '^') {
            ans += (leftTrueCount * rightFalseCount) % 1003;
            ans += (leftFalseCount * rightTrueCount) % 1003;
        }
    } else {
        if(opr == '&') {
            ans += (leftTrueCount * rightFalseCount) % 1003;
            ans += (leftFalseCount * rightFalseCount) % 1003;
            ans += (leftFalseCount * rightTrueCount) % 1003;
        } else if(opr == '|') {
            ans += (leftFalseCount * rightFalseCount) % 1003;
        } else if(opr == '^') {
            ans += (leftTrueCount * rightTrueCount) % 1003;
            ans += (leftFalseCount * rightFalseCount) % 1003;
        }
    }
    ans = ans % 1003;
    return ans;
}

int solveRec(string& str, int i, int j, bool targetBoolRes) {
    if(i > j) {
        return 0;
    }
    if(i == j) {
        if(targetBoolRes) {
            return str[i] == 'T';
        } else {
            return str[i] == 'F';
        }
    }

    int ans = 0;
    for(int k = i+1; k < j; k += 2) {
        int leftTrueCount = solveRec(str, i, k-1, true);
        int leftFalseCount = solveRec(str, i, k-1, false);
        int rightTrueCount = solveRec(str, k+1, j, true);
        int rightFalseCount = solveRec(str, k+1, j, false);
        ans += getTotalWays(leftTrueCount, leftFalseCount, rightTrueCount, rightFalseCount, str[k], targetBoolRes);
    }
    return ans;
}

string getKey(int i, int j, bool target) {
    string str = "";
    str += (i + '#');
    str += (j+'#');
    str += (target ? ('t') : ('f'));
    return str;
}
long solveMemMap(string& str, int i, int j, bool target, unordered_map<string, long>& mp) {
    if(i > j) {
        return 0;
    }
    if(i == j) {
        if(target) {
            return str[i] == 'T' ? 1 : 0;
        } else {
            return str[i] == 'F' ? 1 : 0;
        }
    }
    string currKey = getKey(i, j, target);
    if(mp.find(currKey) != mp.end()) {
        return mp[currKey];
    }
    long targetAns = 0; //long complimentTragetAns = 0;
    for(int k = i+1; k < j; k += 2) {
        string key = getKey(i, k-1, true);
        long leftTrueCount = 0;
        if(mp.find(key) != mp.end()) {
            leftTrueCount = mp[key];
        } else {
            leftTrueCount = solveMemMap(str, i, k-1, true, mp) % 1003;
            mp[key] = leftTrueCount;
        }
        
        long leftFalseCount = 0;
        key = getKey(i, k-1, false);
        if(mp.find(key) != mp.end()) {
            leftFalseCount = mp[key];
        } else {
            leftFalseCount = solveMemMap(str, i, k-1, false, mp) % 1003;
            mp[key] = leftFalseCount;
        }
        
        long rightTrueCount = 0;
        key = getKey(k+1, j, true);
        if(mp.find(key) != mp.end()) {
            rightTrueCount = mp[key];
        } else {
            rightTrueCount = solveMemMap(str, k+1, j, true, mp) % 1003;
            mp[key] = rightTrueCount;
        }
        
        long rightFalseCount = 0;
        key = getKey(k+1, j, false);
        if(mp.find(key) != mp.end()) {
            rightFalseCount = mp[key];
        } else {
            rightFalseCount = solveMemMap(str, k+1, j, false, mp) % 1003;
            mp[key] = rightFalseCount;
        }

        targetAns += getTotalWays(leftTrueCount, leftFalseCount, rightTrueCount, rightFalseCount, str[k], target);
        //complimentTragetAns += getTotalWays(leftTrueCount, leftFalseCount, rightTrueCount, rightFalseCount, str[k], !target);
    }
    mp[currKey] = targetAns;
    return targetAns;
}

long solveMem(string& str, int i, int j, bool target, vector<vector<long>>& dpTrue, vector<vector<long>>& dpFalse) {
    if(i > j) {
        return 0;
    }
    if(i == j) {
        if(target) {
            return str[i] == 'T' ? 1 : 0;
        } else {
            return str[i] == 'F' ? 1 : 0;
        }
    }
    if(target) {
        if(dpTrue[i][j] > -1) {
            return dpTrue[i][j];
        }
    } else {
        if(dpFalse[i][j] > -1) {
            return dpFalse[i][j];
        }
    }
    long targetAns = 0; long complimentTragetAns = 0;
    for(int k = i+1; k < j; k += 2) {
        long leftTrueCount = dpTrue[i][k-1] > -1 ? dpTrue[i][k-1] : solveMem(str, i, k-1, true, dpTrue, dpFalse);
        long leftFalseCount = dpFalse[i][k-1] > -1 ? dpFalse[i][k-1] : solveMem(str, i, k-1, false, dpTrue, dpFalse);
        long rightTrueCount = dpTrue[k+1][j] > -1 ? dpTrue[k+1][j] : solveMem(str, k+1, j, true, dpTrue, dpFalse);
        long rightFalseCount = dpFalse[k+1][j] > -1 ? dpFalse[k+1][j] : solveMem(str, k+1, j, false, dpTrue, dpFalse);
        targetAns += getTotalWays(leftTrueCount, leftFalseCount, rightTrueCount, rightFalseCount, str[k], target);
        complimentTragetAns += getTotalWays(leftTrueCount, leftFalseCount, rightTrueCount, rightFalseCount, str[k], !target);
    }
    if(target) {
        dpTrue[i][j] = targetAns;
        dpFalse[i][j] = complimentTragetAns;
    } else {
        dpTrue[i][j] = complimentTragetAns;
        dpFalse[i][j] = targetAns;
    }
    return targetAns;
}

int countWays(int n, string S){
    vector<vector<long>> dpTrue(n+1, vector<long>(n+1, -1));
    vector<vector<long>> dpFalse(n+1, vector<long>(n+1, -1));
    return solveMem(S, 0, n-1, true, dpTrue, dpFalse) % 1003;
    return solveRec(S, 0, n-1, true) % 1003;
}

/* minimum number of palindromic partition
Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of the given string.
Input: str = "ababbbabbababa"
Output: 3
Explaination: After 3 partitioning substrings 
are "a", "babbbab", "b", "ababa"
*/

bool isPalindrome(string& str, int i, int j) {
    while(i < j) {
        if(str[i] != str[j]) {
            return false;
        }
        i++; j--;
    }        
    return true;
}

int solveRec(string& str, int i, int j) {
    if(i >= j || isPalindrome(str, i, j)) {
        return 0;
    }
    int ans = INT_MAX;
    for(int k = i; k <= j-1; k++) {
        int leftAns = solveRec(str, i, k);
        int rightAns = solveRec(str, k+1, j);
        ans = min(ans, (leftAns + rightAns + 1));
    }
    return ans;
}

int solveMem(string& str, int i, int j, vector<vector<int>>& dp) {
    if(i >= j || isPalindrome(str, i, j)) {
        return 0;
    }
    if(dp[i][j] > -1) {
        return dp[i][j];
    }
    int ans = INT_MAX;
    for(int k = i; k <= j-1; k++) {
        // int leftAns = solveRec(str, i, k); // to optimize further - check before calling
        // int rightAns = solveRec(str, k+1, j); // to optimize further - check before calling
        int leftAns = (dp[i][k] > -1 ? dp[i][k] : solveMem(str, i, k, dp));
        int rightAns = (dp[k+1][j] > -1 ? dp[k+1][j] : solveMem(str, k+1, j, dp));
        ans = min(ans, (leftAns + rightAns + 1));
    }
    dp[i][j] = ans;
    return dp[i][j];
}

int solveTab(string str) {
    int n = str.length();
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(i >= j || isPalindrome(str, i, j)) {
                dp[i][j] = 0;
            }
        }
    }

    for(int i = n; i >= 0; i--) {
        for(int j = 0; j <= n; j++) {
            if(dp[i][j] == 0) {
                continue;
            }
            int ans = INT_MAX;
            for(int k = i; k <= j-1; k++) {
                int leftAns = dp[i][k]; // solveRec(str, i, k);
                int rightAns = dp[k+1][j]; // solveRec(str, k+1, j);
                ans = min(ans, (leftAns + rightAns + 1));
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][n-1];
}

int palindromicPartition(string str)
{
    // code here
    int n = str.length();
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return solveMem(str, 0, n-1, dp);
    //return solveRec(str, 0, str.length()-1);
}

/* MCM
Given a chain of matrices A1, A2, A3,.....An. Your task is to find out the minimum cost to multiply these matrices. The cost of matrix multiplication is defined as the number of scalar multiplications. A Chain of matrices A1, A2, A3,.....An is represented by a sequence of numbers in an array ‘arr’ where the dimension of 1st matrix is equal to arr[0] * arr[1] , 2nd matrix is arr[1] * arr[2], and so on.
Sample Input 1:
2
4
4 5 3 2
4
10 15 20 25
Sample Output 1:
8000
70
*/
int solveRec(vector<int>& arr, int i, int j) {
    if(i >= j) {
        return 0;
    }
    int ans = INT_MAX;
    for(int k = i; k <= j-1; k++) {
        int leftCost = solveRec(arr, i, k);
        int rightCost = solveRec(arr, k+1, j);
        int thisCost = arr[i-1]*arr[k]*arr[j];
        int tempAns = leftCost + rightCost + thisCost;
        ans = min(tempAns, ans);
    }
    return ans;
}

int solveMem(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
    if(i >= j) {
        return 0;
    }
    if(dp[i][j] > -1) {
        return dp[i][j];
    }
    int ans = INT_MAX;
    for(int k = i; k <= j-1; k++) {
        int leftCost = solveMem(arr, i, k, dp);
        int rightCost = solveMem(arr, k+1, j, dp);
        int thisCost = arr[i-1]*arr[k]*arr[j];
        int tempAns = leftCost + rightCost + thisCost;
        ans = min(tempAns, ans);
    }
    dp[i][j] = ans;
    return dp[i][j];
}
int matrixMultiplication(vector<int> &arr, int n)
{
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return solveMem(arr, 1, n-1, dp);
    // Write your code here.
    return solveRec(arr, 1, arr.size()-1);
}