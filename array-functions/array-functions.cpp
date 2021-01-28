#include<iostream>
using namespace std;

//----------------------------get the second largest element in an array------------------
int getSecLargestElmInd(int arr[], int n) {
    // this traveses the whole array twice!
    int largestInd = getLargestElmIndex(arr, n);
    int res = (-1);
    for(int i = 0; i < n; i++) {
        if(arr[i] != arr[n - 1]) {
            if(res == (-1)) {
                res = i;
            } else if(arr[i] > arr[res]) {
                res = i;
            }
        }
    }
    return res;
}

int getSecLargestElmEff(int arr[], int n) {
    int res = -1, largestInd = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] > arr[largestInd]) {
            res = largestInd;
            largestInd = i;
        } else {
            if(arr[i] < arr[largestInd]) {
                if(res == (-1)) {
                    res = i;
                } else if ()
                res = i;
            }
        }
    }
    return res;
}

//------------------------------get the largest element in an array------------------
int getLargestElmIndex(int arr[], int n) {
    // time complexity -- O(n)
    int leargestInd = 0;
    for(int i = 1; i < n; i++) {
        if(arr[leargestInd] < arr[i]) {
            leargestInd = i;
        }
    }
    return leargestInd;
}

int main() {
    return 0;
}