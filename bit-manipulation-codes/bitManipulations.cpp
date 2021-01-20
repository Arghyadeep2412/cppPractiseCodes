#include<iostream>
using namespace std;

//---------------------check if kth bit is n is 1 or 0---------------------
bool isKthBitSetLeftShift(int n, int k) {
    bool kthBitIsSet = false;
    if((n & (1 << (k-1))) != 0) {
        kthBitIsSet = true;
    }
    return kthBitIsSet;
}

bool isKthBitSetRightShift(int n, int k) {
    bool kthBitIsSet = false;
    if(((n >> (k-1)) & 1) == 1) {
        kthBitIsSet = true;
    }
    return kthBitIsSet;
}

//---------------count the number of set bits---------------------
int countSetBitsNaive(int n) {
    int res = 0;
    while(n > 0) {
        // if((n % 2) != 0) {
        //     res++;
        // }
        res = res + (n & 1);
        n = (n/2);
        // if((n & 1) == 1) {
        //     res++;
        // }
        // n = (n >> 1);
    }
}

int countSetBitsBrianKerningamAlgo(int n) {
    // time complexity -- theta(count of set bits)
    int res = 0;
    while(n > 0) {
        n = n & (n - 1);
        res++;
    }
    return res;
}

int table[256];
void initialize() {
    table[0] = 0;
    for(int i = 1; i < 256; i++) {
        table[i] = table[i/2] + (i & 1);
    }
}

int count(int n) {
    int res = 0;
    initialize();
    res = res + table[n & 0xff];
    n = n >> 8;
    res = res + table[n & 0xff];
    n = n >> 8;
    res = res + table[n & 0xff];
    n = n >> 8;
    res = res + table[n & 0xff];
    return res;
}

//-----------------------check if n is a power of 2--------------------
bool checkPowOf2(int n) {
    if(n == 0) {
        return false;
    }

    while(n > 1) {
        if((n % 2) != 0) {
            return false;
        }
        n = n / 2;
    }
    return true;
}

bool checkPowOf2BrianKerningham (int n) {
    bool isPowerOf2 = false;
    if(n <= 1) {
        return isPowerOf2;
    }

    int res = n & (n - 1);
    // all the bits after the first set(from left) bit in n --- will be set
    // and the right most set bit will be converted to 0
    if(res == 0) {
        isPowerOf2 = true;
    }
    return isPowerOf2;
}

//-------------need to find a number which is occuring odd number of times (only one in the given array)---------------------
int findOddOccuringNum(int arr[], int length) {
    int n = arr[0];
    for(int i = 1; i < length; i++) {
        n = n ^ arr[i];
    }
    return n;
}

//-----------------------given a array of integers---------
// all of them appear even number of times
// only two of them appear odd number of times
// need to find the odd occuring elements -- input array size is atleast 2
#include<vector>
vector<int> listOddOccuringElms(int arr[], int n) {
    vector<int> res;
    int res1 = 0;
    int res2 = 0;
    int xor = 0;
    for(int i = 0; i < n; i++) {
        xor = xor ^ arr[i];
    }
    int rightMostSetBit = xor & (~(xor - 1)); // a num which has the only set bit as the last set bit in xor
    for(int i = 0; i < n; i++) {
        if((arr[i] & rightMostSetBit) != 0) {
            res1 = res1 ^ arr[i];
        } else {
            res2 = res2 ^ arr[i];
        }
    }
    res.push_back(res1);
    res.push_back(res2);
    return res;
}

//--------------------create subsets of the given string---------------------------
// string has - n chars -- there are pow(2, n) subsets in all
// time complexity -- O(n * (2 ^ n))
#include<vector>
#include<string>
#include<cmath>
vector<string> getPowerSet(string str) {
    vector<string> res;
    if(str.empty()) {
        return res;
    }
    int len = str.length();
    string thisStr = "";
    int powSetLen = pow(2, len);
    for(int i = 0; i < powSetLen; i++) {
        thisStr = "";
        for(int j = 0; j < len; j++) {
            if((i & (1 << j)) != 0) {
                thisStr = thisStr + str[j];
            }
        }
        res.push_back(thisStr);
    }
    return res;
}


int main() {
    return 0;
}