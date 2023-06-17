# Questions
## Question 1: [Sort an array of 0s, 1s and 2s](https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1?page=1&difficulty[]=0&category[]=Arrays&sortBy=submissions)

### Statement
Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.
Input: 
N = 5
arr[]= {0 2 1 2 0}

Output:
0 0 1 2 2

Explanation:
0s 1s and 2s are segregated 
into ascending order.

### Solution
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
    // code here
    
}
```