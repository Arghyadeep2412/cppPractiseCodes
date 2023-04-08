# Questions
## Question1: [Check if strings are rotations of each other or not](https://practice.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1?page=1&difficulty[]=-1&category[]=Strings&sortBy=submissions)

### Statement:
Given two strings s1 and s2. The task is to check if s2 is a rotated version of the string s1. The characters in the strings are in lowercase.

Input:
geeksforgeeks
forgeeksgeeks

Output: 
1

Explanation: s1 is geeksforgeeks, s2 is
forgeeksgeeks. Clearly, s2 is a rotated
version of s1 as s2 can be obtained by
left-rotating s1 by 5 units.

### Solution
```c++
bool areRotations(string s1,string s2)
{
    // Your code here
    if(s1.length() != s2.length()) {
        return false;
    }
    s1 += s1;
    if(s1.find(s2) == string::npos) {
        return false;
    }
    return true;
}
```

## Question2: [Subarray with given sum](https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1?page=1&difficulty[]=0&category[]=Arrays&sortBy=submissions)

### Statement:
Given an unsorted array A of size N that contains only positive integers, find a continuous sub-array that adds to a given number S and return the left and right index(1-based indexing) of that subarray.

In case of multiple subarrays, return the subarray indexes which come first on moving from left to right.

Note:- You have to return an ArrayList consisting of two elements left and right. In case no such subarray exists return an array consisting of element -1.

Input:
N = 5, S = 12
A[] = {1,2,3,7,5}

Output: 2 4

Explanation: The sum of elements 
from 2nd position to 4th position 
is 12.

### Solution
```c++
vector<int> subarraySum(vector<int>arr, int n, long long s)
{
    // Your code here
    int li = 0, ri = 0;
    long long sum = arr[li];
    bool found = false;
    while(li < n && ri < n) {
        if(sum < s) {
            ri++;
            sum += arr[ri];
        } else if(sum > s) {
            sum -= arr[li];
            li++;
            if(li > ri) {
                ri = li;
                sum = arr[li];
            }
        } else {
            found = true;
            break;
        }
    }
    int leftIdx = -1;
    int rightIdx = -1;
    vector<int> res;
    if(found) {
        leftIdx = li+1;
        rightIdx = ri+1;
        res.push_back(leftIdx);
        res.push_back(rightIdx);
    } else {
        res.push_back(-1);
    }
    return res;
}
```