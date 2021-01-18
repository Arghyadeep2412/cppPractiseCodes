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

int main() {
    return 0;
}