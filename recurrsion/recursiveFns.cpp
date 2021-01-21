#include<iostream>
using namespace std;

//------------tail recursive function to get the factorial----------
int factTailRecurr(int n, int k = 1) {
    if(n == 0 || n == 1) {
        return k;
    }
    return factTailRecurr(n-1, (k*n));
}

int main() {
    return 0;
}