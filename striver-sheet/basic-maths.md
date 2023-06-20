# BASIC MATHS - 
## Question 1: [Count Digits](https://practice.geeksforgeeks.org/problems/count-digits5716/1)
### Statement:
Given a number N. Count the number of digits in N which evenly divides N.

Note :- Evenly divides means whether N is divisible by a digit i.e. leaves a remainder 0 when divided.
Input:
N = 12
Output:
2
Explanation:
1, 2 both divide 12 evenly

### Solution:
```c++
int evenlyDivides(int n){
    int org = n;
    int count = 0;
    while(n > 0) {
        int r = n % 10;
        n = n / 10;
        if(r > 0 && org % r == 0) {
            count++;
        }
    }
    return count;
    
}
```

## Question 2: [Reverse Bits](https://practice.geeksforgeeks.org/problems/reverse-bits3556/1)
### Statement:
Given a 32 bit number X, reverse its binary form and print the answer in decimal.
Input:
X = 1
Output:
2147483648 
Explanation:
Binary of 1 in 32 bits representation-
00000000000000000000000000000001
Reversing the binary form we get, 
10000000000000000000000000000000,
whose decimal value is 2147483648.

Input:
X = 5
Output:
2684354560 
Explanation:
Binary of 5 in 32 bits representation-
00000000000000000000000000000101
Reversing the binary form we get, 
10100000000000000000000000000000,
whose decimal value is 2684354560.

### Solution:
```c++
long long reversedBits(long long x) {
    // code here
    int power = 31;
    long long res = 0;
    while(x != 0) {
        res += ((x & 1) << power);
        x = x >> 1;
        power--;
    }
    return res;
}
```

## Question 3: [LCM & GCD](https://practice.geeksforgeeks.org/problems/lcm-and-gcd4516/1)
### Statement: 
Given two numbers A and B. The task is to find out their LCM and GCD.

Input:
A = 5 , B = 10

Output: 10 5

Explanation:
LCM of 5 and 10 is 10, while
thier GCD is 5.

### Solution:
```c++
int getGcd(long long a, long long b) {
    if(b == 0) {
        return a;
    }
    return getGcd(b, a % b);
}

vector<long long> lcmAndGcd(long long A , long long B) {
    long long gcd = getGcd(A, B);
    long long lcm = (A*B)/gcd;
    
    vector<long long> res;
    res.push_back(lcm);
    res.push_back(gcd);
    return res;
}
```

## Question 4: [Armstrong Numbers](https://practice.geeksforgeeks.org/problems/armstrong-numbers2727/1)

### Statement:
For a given 3 digit number, find whether it is armstrong number or not. An Armstrong number of three digits is an integer such that the sum of the cubes of its digits is equal to the number itself. Return "Yes" if it is a armstrong number else return "No".
NOTE: 371 is an Armstrong number since 33 + 73 + 13 = 371

Example 1:

Input: N = 153
Output: "Yes"
Explanation: 153 is an Armstrong number
since 13 + 53 + 33 = 153.
Hence answer is "Yes".

### Solution:
#### Explanation:
1. Method 1: is to get every digit of the number, sum its cubes and compare
2. Method 2: As we know there are only 3 digits numbers in input
   1. No need to run a loop
   2. Just consider the sum of all the three digits and compare

```c++
string armstrongNumber2(int n) {
    int sum = ( pow((n / 100), 3) + pow((n % 100)/10, 3) + pow((n % 10), 3));
    if(sum == n) {
        return "Yes";
    }
    return "No";
}

string armstrongNumber1(int n){
    int orgNum = n;
    int cubesSum = 0;
    while(n > 0) {
        int r = n % 10;
        n = n / 10;
        cubesSum += (r * r * r);
    }
    if(cubesSum == orgNum) {
        return "Yes";
    }
    return "No";
}
```

## Question 5: [Sum of all divisors from 1 to n](https://practice.geeksforgeeks.org/problems/sum-of-all-divisors-from-1-to-n4738/1)

### Statement:
Given a positive integer N., The task is to find the value of    \sum_{i=1}^{i=n} F(i)  where function F(i) for the number i be defined as the sum of all divisors of ‘i‘.

Example 1:

Input:
N = 4
Output:
15
Explanation:
F(1) = 1
F(2) = 1 + 2 = 3
F(3) = 1 + 3 = 4
F(4) = 1 + 2 + 4 = 7
ans = F(1) + F(2) + F(3) + F(4)
    = 1 + 3 + 4 + 7
    = 15

### Solution:
#### Explanation:
Observe properly, you will find that all the numbers in total appear (N/i) times.

Like in 4

1s = 4/1 = 4 times  ==> 1x4 = 4

2s = 4/2 = 2times   ==> 2x2 = 4

3s = 4/3 = 1 times  ==> 3x1 = 3

4s = 4/4 = 1 times  ==> 4x1 = 4

Total sum = 4+4+3+4 = 15 (Ans)
```c++
long long sumOfDivisors(int N)
{
    long long ans = 0;
    for(int i = 1; i <= N; i++) {
        ans = ans + (i * (N/i));
    }
    return ans;
}
```
## Question 6: [Minimum number of jumps](https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1)

### Statement:
Given an array of N integers arr[] where each element represents the maximum length of the jump that can be made forward from that element. This means if arr[i] = x, then we can jump any distance y such that y ≤ x.
Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.

Note: Return -1 if you can't reach the end of the array.


Example 1:

Input:
N = 11 
arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9} 
Output: 3 
Explanation: 
First jump from 1st element to 2nd 
element with value 3. Now, from here 
we jump to 5th element with value 9, 
and from here we will jump to the last.

### Solution:

#### Explanation:
1. There is a recursive approach and a linear (non-recursive) approach

```c++
int solveRec(int arr[], int n, int ci) {
    if(ci > n-2 || (ci + arr[ci] > n-2)) {
        return 1;
    }
    if(arr[ci] == 0) {
        return -1;
    }
    
    int ans = -1;
    
    for(int jmp = 1; jmp <= arr[ci]; jmp++) {
        int thisAns = solveRec(arr, n, ci + jmp);
        if(thisAns > 0) {
            if(ans == -1) {
                ans = thisAns;
            } else if(ans > 0) {
                ans = min(thisAns, ans);
            }
        }
    }
    return (ans > 0) ? ans+1 : -1;
}

int solveMem(int arr[], int n, int ci, vector<int>& dp) {
    if(ci > n-2 || (ci + arr[ci] > n-2)) {
        return 1;
    }
    if(arr[ci] == 0) {
        return -1;
    }
    
    if(dp[ci] > -2) {
        return dp[ci];
    }
    
    int ans = -1;
    
    for(int jmp = 1; jmp <= arr[ci]; jmp++) {
        int thisAns = INT_MIN;
        if(dp[ci + jmp] > -2) {
            thisAns = dp[ci+jmp];
        } else {
            thisAns = solveRec(arr, n, ci + jmp);
        }
        //int thisAns = solveRec(arr, n, ci + jmp);
        if(thisAns > 0) {
            if(ans == -1) {
                ans = thisAns;
            } else if(ans > 0) {
                ans = min(thisAns, ans);
            }
        }
    }
    dp[ci] = (ans > 0) ? ans+1 : -1;
    return dp[ci];
}

int minJumps(int arr[], int n){
    
    int jumps = 0, des = 0, pos = 0;
    
    for(int i = 0; i < n-1; i++) {
        if(i == pos && arr[pos] == 0 && pos == des) {
            return -1;
        }
        
        des = max(des, arr[i] + i);
        
        if(pos == i) {
            pos = des; jumps++;
        }
    }
    return jumps;
    
    vector<int> dp(n+1, -2);
    return solveMem(arr, n, 0, dp);
    
    return solveRec(arr, n, 0);
    
}
```

# SORTING
## Question 1: [Selection sort](https://practice.geeksforgeeks.org/problems/selection-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=selection-sort)

### Statement:
Given an unsorted array of size N, use selection sort to sort arr[] in increasing order.

### Solution:

#### Explanation:
1. Find the minimum element and replace it with element at 0 index
2. Find the next minimum element and replace it with element at 1 index.. and so on

```c++
void selectionSort(int arr[], int n)
{
    for(int i = 0; i < n; i++) {
        int minInd = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[minInd]) {
                minInd = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minInd];
        arr[minInd] = temp;
    }
}
```

## Question 2: [Bubble Sort](https://practice.geeksforgeeks.org/problems/bubble-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bubble-sort)

### Statement: 
Given an Integer N and a list arr. Sort the array using bubble sort algorithm.

### Solution:

```c++
void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n; i++) {
        bool swaped = false;
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swaped = true;
            }
        }
        if(!swaped) {
            break;
        }
    }
}
```

## Question 3: [Insertion sort](https://practice.geeksforgeeks.org/problems/insertion-sort/0?category[]=Algorithms&page=1&query=category[]Algorithmspage1&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=insertion-sort)

### Statement:
The task is to complete the insert() function which is used to implement Insertion Sort.

### Solution:

```c++
void insert(int arr[], int i)
{
    // Your code here
    int key = arr[i];
    int j = i-1;
    while(j >= 0 && arr[j] > key) {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = key;
}
//Function to sort the array using insertion sort algorithm.
void insertionSort(int arr[], int n)
{
    //code here
    for(int i = 1; i < n; i++) {
        insert(arr, i);
    }
}
```

## Question 4: [Merge sort](https://practice.geeksforgeeks.org/problems/merge-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=merge-sort)

### Statement:
Given an array arr[], its starting position l and its ending position r. Sort the array using merge sort algorithm.
Example 1:

Input:
N = 5
arr[] = {4 1 3 9 7}
Output:
1 3 4 7 9

### Solution:
```c++
void merge(int arr[], int l, int m, int r)
{
    int leftSize = m-l+1;
    int rightSize = r-m;
    vector<int> leftArr(leftSize);
    vector<int> rightArr(rightSize);
    for(int i = 0; i < leftSize; i++) {
        leftArr[i] = arr[l+i];
    }
    for(int i = 0; i < rightSize; i++) {
        rightArr[i] = arr[m+1+i];
    }
    
    int i = 0, j = 0, k = l;
    while(i < leftSize && j <= rightSize) {
        if(leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++; k++;
        } else if(leftArr[i] > rightArr[j]) {
            arr[k] = rightArr[j];
            j++; k++;
        }
    }
    
    while(i < leftSize) {
        arr[k] = leftArr[i];
        i++; k++;
    }
    while(j < rightSize) {
        arr[k] = rightArr[j];
        j++; k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if(l >= r) {
        return;
    }
    int mid = (l+r)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, mid, r);
}
```

## Question 5: [Quick sort](https://practice.geeksforgeeks.org/problems/quick-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=quick-sort)

### Statement:
Quick Sort is a Divide and Conquer algorithm. It picks an element as a pivot and partitions the given array around the picked pivot.
Given an array arr[], its starting position is low (the index of the array) and its ending position is high(the index of the array).

Note: The low and high are inclusive.

Implement the partition() and quickSort() functions to sort the array.


Example 1:

Input: 
N = 5 
arr[] = { 4, 1, 3, 9, 7}
Output:
1 3 4 7 9

### Solution:
```c++
void quickSort(int arr[], int low, int high)
{
    if(low >= high) {
        return;
    }
    int p = partition(arr, low, high);
    
    // after lomuto's partition - pivot is at index p - pivot is at its correct index
    // so exclude index p in further fxn calls
    // quickSort(arr, low, p-1);
    // quickSort(arr, p+1, high);
    
    
    // after hoare's partition
    // We havn't changed the position of the pivot - so need to include it in one of the fxn calls
    quickSort(arr, low, p);
    quickSort(arr, p+1, high);
}

int lomutoPartition(int arr[], int low, int high) {
    int pivot = arr[high]; // last element as pivot
    
    // partition the elements using pivot
    int i = low-1;
    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    // keep pivot at correct index
    int temp = arr[high];
    arr[high] = arr[i+1];
    arr[i+1] = temp;
    
    // return pivot index
    return (i+1);
}

int hoarePartition(int arr[], int low, int high) {
    int pivot = arr[low]; // first element is the pivot
    int i = low-1; int j = high+1;
    
    // do partition
    while(true) {
        do {
            i++;
        } while(arr[i] < pivot);
        
        do {
            j--;
        } while(arr[j] > pivot);
        
        if(i >= j) {
            return j;
        }
        
        // swap elements at i & j - so that they can be on the correct side
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    // Hoare's partition confirms that - 
    // all elements left of j are <= pivot
    // all elements right of j are  >= pivot
}

int partition (int arr[], int low, int high)
{
    // Your code here
    //return lomutoPartition(arr, low, high);
    return hoarePartition(arr, low, high);
}
```


# Arrays - easy
## Question 1: [Second Largest](https://practice.geeksforgeeks.org/problems/second-largest3735/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=second-largest)

### Statement:
Given an array Arr of size N, print second largest distinct element from an array.

Example 1:

Input: 
N = 6
Arr[] = {12, 35, 1, 10, 34, 1}
Output: 34
Explanation: The largest element of the 
array is 35 and the second largest element
is 34.

### Solution:
```c++
int print2largest(int arr[], int n) {
    int secLar = -1, lar = arr[0];
    for(int i = 0; i < n; i++) {
        if(arr[i] > lar) {
            secLar = lar;
            lar = arr[i];
        } else if(arr[i] != lar) {
            if(arr[i] > secLar) {
                secLar = arr[i];
            }
        }
    }
    return secLar;
}
```

## Question 2: [Remove duplicate elements from sorted Array](https://practice.geeksforgeeks.org/problems/remove-duplicate-elements-from-sorted-array/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=remove-duplicate-elements-from-sorted-array)

### Statement:
Given a sorted array A[] of size N, delete all the duplicated elements from A[]. Modify the array such that if there are X distinct elements in it then the first X positions of the array should be filled with them in increasing order and return the number of distinct elements in the array.

Note:
1. Don't use set or HashMap to solve the problem.
2. You must return the number of distinct elements(X) in the array, the generated output will print all the elements of the modified array from index 0 to X-1.

Example 1:

Input:
N = 5
Array = {2, 2, 2, 2, 2}
Output: {2}
Explanation: After removing all the duplicates 
only one instance of 2 will remain.

### Solution:
#### Explanation:
1. The element at index 0 : we can consider it to be a unique one
2. Start iterating from 1 to n-1
   1. if the currElm is != arr[count] -- swap the currElm and arr[count]
   2. increase count by 1
```c++
int remove_duplicate(int arr[],int n) {
    // code here
    int count = 1;
    for(int i = 1; i < n; i++) {
        if(arr[i] != arr[count-1]) {
            int temp = arr[count];
            arr[count] = arr[i];
            arr[i] = temp;
            count++;
        }
    }
    return count;
}
```

## Question 3: [Quick left rotations](https://practice.geeksforgeeks.org/problems/quick-left-rotation3806/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=quick-left-rotation)

### Statement:
Given an array arr[] of size N and an integer K, the task is to left rotate the array K indexes

Example 1:
Input: N = 7, K = 2, arr[] = {1, 2, 3, 4, 5, 6, 7}
Output: 3 4 5 6 7 1 2
Explanation: Rotation of the above 
array by 2 will make the output array .

### Solution:
```c++
void reverseArr(int arr[], int low, int high) {
    while(low < high) {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++; high--;
    }
}
void leftRotate(int arr[], int k, int n) 
{
    if(k >= n && (k % n) == 0) {
        return;
    }
    if(k > n) {
        k = k % n;
    }
    int d = k;
    reverseArr(arr, 0, d-1);
    reverseArr(arr, d, n-1);
    reverseArr(arr, 0, n-1);
}
```

## Question 4: [Move all 0s to the end of array](https://practice.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=move-all-zeroes-to-end-of-array)

### Statement:
Given an array arr[] of N positive integers. Push all the zeros of the given array to the right end of the array while maitaining the order of non-zero elements.

Example 1:

Input:
N = 5, Arr[] = {3, 5, 0, 0, 4}
Output: 3 5 4 0 0
Explanation: The non-zero elements
preserve their order while the 0
elements are moved to the right.

### Solution:
```c++
void pushZerosToEnd(int arr[], int n) {
    int currIdx = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] > 0) {
            int temp = arr[i];
            arr[i] = arr[currIdx];
            arr[currIdx] = temp;
            currIdx++;
        }
    }
}
```

# Array - medium
## Question 1: [Find all pairs with a given sum](https://practice.geeksforgeeks.org/problems/find-all-pairs-whose-sum-is-x5808/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-all-pairs-whose-sum-is-x)

### Statement:
Given two unsorted arrays A of size N and B of size M of distinct elements, the task is to find all pairs from both arrays whose sum is equal to X.

Note: All pairs should be printed in increasing order of u. For eg. for two pairs (u1,v1) and (u2,v2), if u1 < u2 then
(u1,v1) should be printed first else second.

Example 1:

Input:
A[] = {1, 2, 4, 5, 7}
B[] = {5, 6, 3, 4, 8} 
X = 9 
Output: 
1 8
4 5 
5 4
Explanation:
(1, 8), (4, 5), (5, 4) are the
pairs which sum to 9.

### Solution:
```c++
bool binarySrch(int arr[], int l, int h, int x) {
    while(l <= h) {
        int m = (l+h)/2;
        if(arr[m] == x) {
            return true;
        } else if(arr[m] < x) {
            l = m+1;
        } else {
            h = m-1;
        }
    }
    return false;
}

vector<pair<int,int>> allPairs(int a[], int b[], int n, int m, int x)
{
    sort(a, a+n);
    sort(b, b+m);
    vector<pair<int, int>> res;
    
    for(int i = 0; i < n; i++) {
        int toFind = x - a[i];
        if(binarySrch(b, 0, m-1, toFind)) {
            res.push_back(make_pair(a[i], toFind));
        }
    }
    
    return res;
}
```

## Question 2: [Sort an array of 0s, 1s and 2s](https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=sort-an-array-of-0s-1s-and-2s)

### Statement:
Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.


Example 1:

Input: 
N = 5
arr[]= {0 2 1 2 0}
Output:
0 0 1 2 2
Explanation:
0s 1s and 2s are segregated 
into ascending order.

### Solution:
```c++
void sort012(int arr[], int n)
{
    int low = 0, mid = 0, high = n-1;
    while(mid <= high) {
        if(arr[mid] == 0) {
            // swap mid and low
            int temp = arr[mid];
            arr[mid] = arr[low];
            arr[low] = temp;
            mid++; low++;
        } else if(arr[mid] == 1) {
            mid++;
        } else {
            int temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;
            high--;
        }
    }
}
```

## Question 3: [Majority Element](https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=majority-element)

### Statement:
Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.
 

Example 1:

Input:
N = 3 
A[] = {1,2,3} 
Output:
-1
Explanation:
Since, each element in 
{1,2,3} appears only once so there 
is no majority element.

### Solution:
#### Explanation:
1. First half: Provides us a possible solution
2. Second half: Need to check and confirm if what we recieved in first half is indeed an answer or not
```c++
int majorityElement(int arr[], int size)
{
    int resInd = 0, count = 1;

    // First half
    for(int i = 1; i < size; i++) {
        if(arr[i] == arr[resInd]) {
            count++;
        } else {
            count--;
        }
        if(count == 0) {
            resInd = i; count = 1;
        }
    }
    
    // Second half
    count = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i] == arr[resInd]) {
            count++;
        }
    }
    
    if(count > (size/2)) {
        return arr[resInd];
    }
    return -1;
}
```

## Question 4: [Maximum Triplet product](https://practice.geeksforgeeks.org/problems/d54c71dc974b7db3a200eb63f34e3d1cba955d86/1?page=4&difficulty[]=1&category[]=Arrays&sortBy=submissions)

### Statement:
Given an array arr of size n, the task is to find the maximum triplet product in the array.


Example 1:

Input:
n = 4
arr[] = {1, 2, 3, 5}
Output:
30
Explanation:
5*3*2 gives 30. This is the maximum possible
triplet product in the array.

### Solution:
#### Explanation:
1. Either it can be product of max 3 number - if there are no negetive numbers
2. Or, it can be product of two least number and one max number: if we have >1 negetive numbers
3. Maximum of 1 and 2
```c++
long long maxTripletProduct(long long arr[], int n)
{
    sort(arr, arr+n);
    
    int firstNegIdx = -1, lastNegIdx = -1;
    long long ans = arr[n-1] * arr[n-2] * arr[n-3];
    if(arr[0] < 0) {
        firstNegIdx = 0;
    }
    for(int i = 0; i < n; i++) {
        if(arr[i] >= 0 && arr[i-1] < 0) {
            lastNegIdx = i-1;
        }
    }
    
    if(lastNegIdx > firstNegIdx && firstNegIdx != -1) {
        long long thisAns = arr[firstNegIdx] * arr[firstNegIdx+1] * arr[n-1];
        ans = max(ans, thisAns);
    }
    
    return ans;
}
```

## Question 5: [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)

### Statement:
Given an integer array nums, find the 
subarray
 with the largest sum, and return its sum.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

### Solution:
#### Explanation: Kadane's algo
```c++
long long maxSubarraySum(int arr[], int n)
{
    long long maxSum = arr[0];
    long long thisSum = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > (thisSum + arr[i])) {
            thisSum = arr[i];
        } else {
            thisSum += arr[i];
        }

        maxSum = max(maxSum, thisSum);
    }
    if(maxSum < 0) {
        // If question says - we can consider empty array also
        return 0;
    }
    return maxSum;
}
```