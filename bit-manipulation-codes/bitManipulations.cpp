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

int main() {
    return 0;
}