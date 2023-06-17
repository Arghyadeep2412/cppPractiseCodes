# Questions

## Question-1
### Statement
Given an array A[] of N positive integers. The task is to find the maximum of j - i subjected to the constraint of A[i] < A[j] and i < j. 
[problem link](https://practice.geeksforgeeks.org/batch/dsa-4/track/DSASP-Arrays/problem/maximum-index-1587115620)

### Solution
#### Non-recurrsive
- works fine - 
- code - 
```
int maxIndexDiff(int arr[], int n) {
    int lmin[n], rmax[n];
    lmin[0] = arr[0];
    for(int i = 1; i < n; i++) {
        lmin[i] = min(lmin[i-1], arr[i]);
    }
    rmax[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--) {
        rmax[i] = max(rmax[i+1], arr[i]);
    }
    int maxdiff=-1;
    int i=0;
    int j=0;

    while(i<n && j<n){
        if(lmin[i]<=rmax[j]){
            maxdiff=max(maxdiff,j-i);
            j=j+1;
        }
        else{
            i=i+1;
        }
    }
    return maxdiff;
}
```
#### Recurrsive
- Returns TLE even with memoization
- code - 
```
int solveRec(int arr[], int i, int j) {
    if(i >= j) {
        return 0;
    }
    if(arr[i] <= arr[j]) {
        return j-i;
    }
    int ans1 = solveRec(arr, i+1, j);
    int ans2 = solveRec(arr, i, j-1);
    return max(ans1, ans2);
}

int solveMem(int arr[], int i, int j, vector<vector<int>>& dp) {
    if(i >= j) {
        return 0;
    }
    if(dp[i][j] > -1) {
        return dp[i][j];
    }
    if(arr[i] <= arr[j]) {
        return j-i;
    }
    int ans1 = solveRec(arr, i+1, j);
    int ans2 = solveRec(arr, i, j-1);
    dp[i][j] = max(ans1, ans2);
    return dp[i][j];
}
int maxIndexDiff(int A[], int N) 
{
    vector<vector<int>> dp(N+1, vector<int>(N+1, -1));
    return solveMem(A, 0, N-1, dp);
    return solveRec(A, 0, N-1);
    // Your code here
}
```

## Question-2 : [Matchstick game](https://practice.geeksforgeeks.org/batch/dsa-4/track/DSASP-Arrays/problem/-matchsticks-game4906)
### Statement
Two friends, A and B, are playing the game of matchsticks. In this game, a group of N matchsticks is placed on the table. The players can pick any number of matchsticks from 1 to 4 (both inclusive) during their chance. The player who takes the last match stick wins the game. If A starts first, how many matchsticks should he pick on his 1st turn such that he is guaranteed to win the game or determine if it's impossible for him to win. Return -1 if it's impossible for A to win the game, else return the number of matchsticks should he pick on his 1st turn such that he is guaranteed to win.
Note : Consider both A and B play the game optimally.

Example 1:

Input:
N = 48
Output:
3
Explanation:
Player A is guaranteed a win if he
picks 3 matchsticks first.

### Solution
- exp - 
  - whoever leaves the other player with a number of sticks, which is divisable by 5, wins the game
- code - 
```
int matchGame(long long N) {
    // code here
    return N%5==0?-1:N%5;
}
```

## Question-3: [Check if array is sorted and rotated](https://practice.geeksforgeeks.org/batch/dsa-4/track/DSASP-Arrays/problem/check-if-array-is-sorted-and-rotated-clockwise-1587115620)

### Statement
Given an array arr[] of N distinct integers, check if this array is Sorted (non-increasing or non-decreasing) and Rotated counter-clockwise. Note that input array may be sorted in either increasing or decreasing order, then rotated.
A sorted array is not considered as sorted and rotated, i.e., there should be at least one rotation.

Example 1:

Input:
N = 4
arr[] = {3,4,1,2}
Output: Yes
Explanation: The array is sorted 
(1, 2, 3, 4) and rotated twice 
(3, 4, 1, 2).

### Solution
- explanation - 
  - assume cond1 = arr[i] > arr[j], i < j
  - assume cond2 = arr[i] < arr[j], i < j
  - For a sorted and rotated array - 
    - either, all consecutive pairs will follow cond1, except one
    - or, all consecutive pairs will follow cond2, except one
  - Need to figure out what is the case for
    - Sorted (asc) and rotated
    - Sorted (desc) and rotated
- code - 
```
bool checkRotatedAndSorted(int arr[], int num){
        
    // Your code here
    int moreCount = 0, lessCount = 0;
    for(int i = 1; i < num; i++) {
        if(arr[i] > arr[i-1]) {
            moreCount++;
        } else if(arr[i] < arr[i-1]) {
            lessCount++;
        }
    }
    if(moreCount >= lessCount && lessCount == 1 && arr[0] > arr[num-1]) {
        return true;
    }
    if(moreCount <= lessCount && moreCount == 1 && arr[0] < arr[num-1]) {
        return true;
    }
    return false;
}
```

## Question-4: [Rearrange an array with O(1) extra space](https://practice.geeksforgeeks.org/batch/dsa-4/track/DSASP-Arrays/problem/rearrange-an-array-with-o1-extra-space3142)

### Statement
Given an array arr[] of size N where every element is in the range from 0 to n-1. Rearrange the given array so that arr[i] becomes arr[arr[i]].

Example 1:

Input:
N = 2
arr[] = {1,0}
Output: 0 1
Explanation: 
arr[arr[0]] = arr[1] = 0.
arr[arr[1]] = arr[0] = 1.

### Solution
- explanation -
  - need to understand how to represent two values in one index
- code - 
```
void arrange(long long arr[], int n) {
    // Your code here
    long long maxNum = 0;
    for(int i = 0; i < n; i++) {
        maxNum = max(maxNum, arr[i]);
    }
    maxNum++;
    for(int i = 0; i < n; i++) {
        int newVal = arr[arr[i]] % maxNum;
        arr[i] = (maxNum * newVal) + arr[i];
    }
    for(int i = 0; i < n; i++) {
        arr[i] = arr[i]/maxNum;
    }
}
```
## Question5: [Rotate Array](https://practice.geeksforgeeks.org/batch/dsa-4/track/DSASP-Arrays/problem/rotate-array-by-n-elements-1587115621)

### Statement:
Given an unsorted array arr[] of size N. Rotate the array to the left (counter-clockwise direction) by D steps, where D is a positive integer. 

Example 1:

Input:
N = 5, D = 2
arr[] = {1,2,3,4,5}
Output: 3 4 5 1 2
Explanation: 1 2 3 4 5  when rotated
by 2 elements, it becomes 3 4 5 1 2.

### Solution:
```c++
void reverse(int arr[], int l, int h) {
    while(l < h) {
        int temp = arr[l];
        arr[l] = arr[h];
        arr[h] = temp;
        l++; h--;
    }
}
void rotateArr(int arr[], int d, int n){
    // code here
    if(d >= n) {
        d = d % n;
    }
    if(d <= 0) {
        return;
    }
    reverse(arr, 0, d-1);
    reverse(arr, d, n-1);
    reverse(arr, 0, n-1);
}
```

## Question6: [Missing element of AP](https://practice.geeksforgeeks.org/problems/missing-element-of-ap2228/1?page=2&difficulty[]=0&status[]=solved&category[]=Arrays&sortBy=submissions)

### Statement: 
Find the missing element from an ordered array arr[], consisting of N elements representing an Arithmetic Progression(AP).

Note: There always exists an element which upon inserting into sequence forms Arithmetic progression. Boundary elements (first and last elements) are not missing.

Input:
N = 6
Arr[] = {2, 4, 8, 10, 12, 14}

Output: 6

Explanation: Actual AP should be 2, 4, 6, 8, 10, 12, 14.

### Solution:
```c++
int solveBinarySearch(int arr[], int n) {
    int low = 0; int high = n-1;
    int d = (arr[n-1] - arr[0])/n;
    while(low <= high) {
        int mid = low + (high-low)/2;
        if(low > 0 && (arr[low]-arr[low-1]) > d) {
            return arr[low]-d;
        } else if(mid > 0 && (arr[mid]-arr[mid-1]) > d ) {
            return arr[mid]-d;
        } else if(high > 0 && (arr[high]-arr[high-1]) > d ) {
            return arr[high]-d;
        }
        
        int elmsByIndexLeft = mid-low-1;
        int elmsByApLeft = ((arr[mid]-arr[low])/d)-1;
        if(elmsByApLeft > elmsByIndexLeft) {
            high = mid-1;
            continue;
        }
        int elmsByIndexRight = high-mid-1;
        int elmsByApRight = ((arr[high]-arr[mid])/d)-1;
        if(elmsByApRight > elmsByIndexRight) {
            low = mid+1;
            continue;
        }
        
    }
}
int findMissing(int arr[], int n) {
    // code here
    return solveBinarySearch(arr, n);
    // int d = (arr[n-1] - arr[0])/n;
    // int prevNum = arr[0];
    // for(int i = 1; i < n; i++) {
    //     int shouldBe = prevNum + d;
    //     if(shouldBe != arr[i]) {
    //         return shouldBe;
    //     }
    //     prevNum = shouldBe;
    // }
    // return -1;
}
```
## Question 7: [Peak element](https://practice.geeksforgeeks.org/problems/peak-element/1?page=1&difficulty[]=0&category[]=Arrays&sortBy=submissions)

### Statement
An element is called a peak element if its value is not smaller than the value of its adjacent elements(if they exists).
Given an array arr[] of size N, Return the index of any one of its peak elements.
Note: The generated output will always be 1 if the index that you return is correct. Otherwise output will be 0.

Input:
N = 3
arr[] = {3,4,2}

Possible Answer: 1

Output: 1

Explanation: 4 (at index 1) is the 
peak element as it is greater than 
it's neighbor elements 3 and 2.
If 1 is returned then the generated output will be 1 else 0.

### Solution:
```c++
int solveLogn(int arr[], int n) {
    int low = 0;
    int high = n-1;
    int mid = low + (high-low)/2;
    while(low <= high) {
        mid = low + (high-low)/2;
        if(mid == 0 && arr[mid] >= arr[mid+1]) {
            return mid;
        }
        if(mid == n-1 && arr[mid] >= arr[mid-1]) {
            return mid;
        }
        if(arr[mid] >= arr[mid-1] && arr[mid] >= arr[mid+1]) {
            return mid;
        }
        if(mid > 0 && arr[mid-1] > arr[mid]) {
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    return -1;
}
int peakElement(int arr[], int n)
{
    return solveLogn(arr, n);
    // Your code here
    if(arr[0] >= arr[1]) {
        return 0;
    }
    if(arr[n-1] >= arr[n-2]) {
        return n-1;
    }
    for(int i = 1; i < n-1; i++) {
        if(arr[i] >= arr[i-1] && arr[i] >= arr[i+1]) {
            return i;
        }
    }
    return -1;
}
```
