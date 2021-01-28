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
                } else if (arr[i] > arr[res]) {
                    res = i;
                }
            }
        }
    }
    return res;
}

//------------------------------get the largest element in an array------------------
int getLargestElmIndex(int arr[], int n) {
    // time complexity -- O(n) gets the first occurence
    int leargestInd = 0;
    for(int i = 1; i < n; i++) {
        if(arr[leargestInd] < arr[i]) {
            leargestInd = i;
        }
    }
    return leargestInd;
}

//-----------------check if the array is sorted -- in non decreasing order----------------
bool isArraySortedNonDec(int arr[], int n) {
    // time complexity -- O(n)
    bool isSorted = true;
    for(int i = 0; i < (n-1); i++) {
        if(arr[i + 1] < arr[i]) {
            isSorted = false;
            break;
        }
    }
    return isSorted;
}

//-----------reverse an array ---------------------------
int* getArrayReversed(int arr[], int n) {
    int startInd = 0;
    int endInd = n - 1;
    for(; startInd < endInd; startInd++, endInd--) {
        arr[startInd] = arr[startInd] ^ arr[endInd];
        arr[endInd] = arr[startInd] ^ arr[endInd];
        arr[startInd] = arr[startInd] ^ arr[endInd];
    }
    return arr;
}

//---------remove the duplicate elements in a sorted array towards the front and return the count of unique ones---------
int returnUniqueElmsCount(int arr[], int n) {
    int res = 0;
    if(n > 0) {
        res = 1;
    }
    for(int i = 1; i < n; i++) {
        if(arr[i] != arr[res - 1]) {
            arr[res] = arr[i];
            res++;
        }
    }
    return res;
}

//----------move 0s to the end-------------------
void moveZeroToTheEnd(int arr[], int n) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] != 0) {
            int temp = arr[count];
            arr[count] = arr[i];
            arr[i] = temp;
            count++;
        }
    }
}

int main() {
    return 0;
}