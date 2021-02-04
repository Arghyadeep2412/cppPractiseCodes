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
        int temp = arr[startInd];
        arr[startInd] = arr[endInd];
        arr[endInd] = temp;
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

//------------------left rotate the array by one element-------------
void leftRotateByOne(int arr[], int n) {
    int temp = arr[0];
    for(int i = 1; i < n; i++) {
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
}

//-----------------left rotate an array by d elements----------------
// we assume that d <= n(length of the array)
void leftRotateByD(int arr[], int n, int d) {
    // time complexity -- O(n*d)
    for(int i = 0; i < d; i++) {
        leftRotateByOne(arr, n);
    }
}
void reverse(int arr[], int start, int end) {
    while(start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void leftRotateByDReverse(int arr[], int n, int d) {
    // time complexity -- O(2*n)
    reverse(arr, 0, d-1);
    reverse(arr, d, n-1);
    reverse(arr, 0, n-1);
}

//------------------need to get the leaders in an array -- an element is a leader if all the elements to the right are smaller than the element

#include<vector>
vector<int> getLeadersFromArr(int arr[], int n) {
    int thisLeader = arr[n - 1];
    vector<int> leaders;
    leaders.push_back(thisLeader);
    for(int i = n - 2; i >= 0; i--) {
        if(thisLeader < arr[i]) {
            thisLeader = arr[i];
            leaders.insert(leaders.begin(), thisLeader);
        }
    }
    return leaders;
}

// get the max difference -> arr[j] - arr[i] such that j > i----------------------------

int maxDiff(int arr[], int n) {
    int maxRes = arr[1] - arr[0];
    int min = arr[0];
    for(int j = 1; j < n; j++) {
        if((arr[j] - min) > maxRes ) {
            maxRes = (arr[j] - min);
        }
        if(arr[j] < min) {
            min = arr[j];
        }
    }
    return maxRes;
}

//--------get the frequencies in a sorted array------------------------
void printFreqInSortedArr(int arr[], int n) {
    // time complexity -- O(n)
    int count = 1;
    for(int i = 1; i < n; i++) {
        if(arr[i] == arr[i-1]) {
            count++;
        } else {
            cout << arr[i-1] << " --> " << count << endl;
            count = 1;
        }
    }
    cout << arr[n-1] << " --> " << count << endl;
}

int main() {
    return 0;
}