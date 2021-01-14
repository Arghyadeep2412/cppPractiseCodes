#include<iostream>
using namespace std;

//--------------get the first occurence of an element in a sorted vector----------------------
#include<vector>
int getFirstOcc(vector<int>res, int elm) {
    int f = 0;
    int l = res.size() - 1;
    int m = 0;
    int result = -1;
    while(f <= l) {
        m = (f + l)/2;
        if(res[m] < elm) {
            f = m + 1;
        } else if(res[m] > elm) {
            l = m - 1;
        } else {
            result = m;
            l = m - 1;
        }
    }
    return result;
}

//--------------------get the total number of digits in integer-----------------
#include<cmath>
int getDigitsCount(int n) {
    if(n == 0) {
        return 1;
    }
    double res = log10(n);
    int digitCount = floor(1 + res);
    return digitCount;
}

//----------------to check if a number is palindrome or not----------------------
bool checkPalindrome(int n) {
    // time complexity - theta(number of digits in n)
    bool isPalindrome = false;
    int revNum = 0;
    int thisNum = n;
    int rem = 0;
    while(thisNum > 0) {
        rem = thisNum % 10;
        thisNum /= 10;
        revNum = (revNum * 10) + rem;
    }
    if(revNum == n) {
        isPalindrome = true;
    }
    return isPalindrome;
}

//---------------------get the factorial--------------------------------assunmed that n >= 0
long long int getFactorial(int n) {
    // iterative solution -- O(n) - time complexity
    long long int res = 1;
    for(int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

long long int getFactorialRecc(int n) {
    // recursive solu -- 
    // time complexity - O(n) and space complexity - O(n)(as we will be having function call stack from level n to level 0)
    if(n == 0) {
        return 1;
    }
    return(n * getFactorialRecc(n - 1));
}

//------------trailing zeros in factorial------------------------------------
int countTrailingZerosInFac(int n) {
    // time complexity -- O(log(n))!!
    int a = 5;
    int num = (n / a);
    int res = 0;
    int i = 1;
    while(num > 0) {
        a *= a;
        res += num;
        num = (n / a);
    }
    return res;
}

//--------------gcd of two integers-----------------------------------------
#include<algorithm>
int getGcd(int a, int b) {
    // time complexity -- O(min(a,b))
    int minNum = min(a,b);
    int gcd = 1;
    while(minNum > 0) {
        if(((a % minNum) == 0) && ((b % minNum) == 0)) {
            gcd = minNum;
            break;
        }
        minNum--;
    }
    return gcd;
}

int getGcdEuclidean(int a, int b) {
    // basic euclidean algo using repeated subtraction
    while(a != b) {
        if(a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    return a;
}

int getGcdEuclideanOpt(int a, int b) {
    // optimised euclidean approach -- time complexity - O(log(min(a, b)))
    if(b == 0) {
        return a;
    } else {
        return getGcdEuclideanOpt(b, (a % b));
    }
}

//---------------lcm of tow integers------------------------------------
#include<algorithm>
int getLcm(int a, int b) {
    // naive approach -- O((a * b) - max(a))
    int res = max(a, b);
    while(true) {
        if(((res % a) == 0) && ((res % b) == 0)) {
            break;
        }
        res++;
    }
    return res;
}

int getLcmOpt(int a, int b) {
    // efficient approach -- time complexity - O(log(min(a, b)))
    return ((a * b) / getGcdEuclideanOpt(a, b));
}

//-------------------------checking prime number ------------------
bool checkIfPrime(int n) {
    // naive method -- time complexity O(n)
    bool isPrime = true;
    if(n == 1) {
        isPrime = false;
        return isPrime;
    }
    for(int i = 2; i < n; i++) {
        if((n % i) == 0) {
            isPrime = false;
            break;
        }
    }
    return isPrime;
}

bool checkIfPrimeEff(int n) {
    // comparatively efficient -- time complexity - O(sqrt(n))
    bool isPrime = true;
    if(n == 1) {
        isPrime = false;
    }
    for(int i = 2; (i*i <= n); i++) {
        if((n % i) == 0) {
            isPrime = false;
            break;
        }
    }
    return isPrime;
}

bool checkIfPrime23(int n) {
    bool isPrime = true;
    if(n == 1) {
        isPrime = false;
        return isPrime;
    } else if(n == 2 || n == 3) {
        isPrime = true;
        return isPrime;
    }

    if(((n % 2) == 0) || ((n % 3) == 0)) {
        isPrime = false;
        return isPrime;
    }
    for(int i = 5; (i*i < n); i=i+6) {
        if(((n % i) == 0) || ((n % (i + 2)) == 0)) {
            isPrime = false;
            break;
        }
    }
    return isPrime;
}

//--------------------------------get all the prime factors of a number------------------
#include<vector>
vector<int> getAllPrimeFactors(int m) {
    vector<int> allPrimeFacs;
    if(m <= 1) {
        return allPrimeFacs;
    }
    int n = m;
    for(int i = 2; (i * i) <= n; i++) {
        while((n % i) == 0) {
            allPrimeFacs.push_back(i);
            n = (n / i);
        }
    }
    if(n > 1) {
        allPrimeFacs.push_back(n);
    }
    return allPrimeFacs;
}

#include<vector>
vector<int> getAllPrimeFactorsEfficient(int m) {
    // time complexity - for prime nums -- O(sqrt(n/6)) --- worst case
    vector<int> allPrimeFacs;
    if(m <= 1) {
        return allPrimeFacs;
    }
    int n = m;
    while((n % 2) == 0) {
        allPrimeFacs.push_back(2);
        n = n / 2;
    } 
    while((n % 3) == 0) {
        allPrimeFacs.push_back(3);
        n = n / 3;
    }
    for(int i = 5; (i * i) < n; i+=6) {
        while((n % i) == 0) {
            allPrimeFacs.push_back(i);
            n = n / i;
        }

        while((n % (i + 2)) == 0) {
            allPrimeFacs.push_back(i + 2);
            n = n / (i + 2);
        }
    }

    if(n > 3) {
        allPrimeFacs.push_back(n);
    }
    return allPrimeFacs;
}

//---------------------get all divisors in increasing order----------------------

#include<vector>
vector<int> getAllDivsorsAsc(int n) {
    // naive solution - O(n) and O(1) -- auxiliary space
    vector<int> allDivsors;
    allDivsors.push_back(1);
    for(int i = 2; i <= n; i++) {
        if((n % i) == 0) {
            allDivsors.push_back(i);
        }
    }
    return allDivsors;
}

vector<int> getAllDivsorsEff(int n) {
    // not necessarily in ascending order!!
    vector<int> allDivsors;
    for(int i = 1; (i * i) <= n; i++) {
        if((n % i) == 0) {
            allDivsors.push_back(i);
            if((i * i) < n) {
                allDivsors.push_back(n / i);
            } 
        }
    }
    return allDivsors;
}

vector<int> getAllDivisorsEffAsc(int n) {
    // time complexity -- O(sqrt(n)), space complexity -- O(1)
    vector<int> res;
    int i = 1;
    for(; (i * i) < n; i++) {
        if((n % i) == 0) {
            res.push_back(i);
        }
    }
    if((i * i) > n) {
        i--;
    }
    for(; i >= 1; i--) {
        if((n % i) == 0) {
            res.push_back(n / i);
        }
    }
    return res;
}

//----------------seive of eratosthenes----------------------------------
//- given a number n - need to print all the prime numbers smaller or equall to n
#include<vector>
vector<int> getPrimesTillN(int n) {
    // timeComplexity -- O(n * sqrt(n))
    vector<int> res;
    for(int i = 2; i <= n; i++) {
        if(checkIfPrime23(i)) {
            res.push_back(i);
        }
    }
    return res;
}

vector<int> getPrimesTillNSOE(int n) {
    // simple implementation of seive algo!! -- O(n*log(log(n)))
    vector<int> res;
    vector<bool> allNumsState(n+1, true);
    for(int i = 2; (i * i) <= n; i++) {
        if(allNumsState[i]) {
            for(int j = (i * i); j <= n; j += i) {
                allNumsState[j] = false;
            }
        }
    }

    for(int i = 2; i <= n; i++) {
        if(allNumsState[i]) {
            res.push_back(i);
        }
    }
    return res;
}

//-----------------------power(x, n)------------------------------
long long int getPower(int x, int n) {
    // time complexity ---  O(log(n)) -- T(n) = T(n/2) + O(const)
    // this is a recursive solution -- space complexity -  O(log(n))
    if(n == 0) {
        return 1;
    }

    long long int halfRes = getPower(x, n/2);
    if((n % 2) == 0) {
        return(halfRes * halfRes);
    } else {
        return (halfRes * halfRes * x);
    }
}

long long int getPowerItr(int x, int n) {
    // this is an iterative solution
    // time complexity -- O(n), space complexity -- O(1)
    long long int res = 1;
    while(n > 0) {
        if(n & 1) { // same as (n % 2 == 0)
            res = res * x;
        }
        x = x * x;
        n = n >> 1; // same as n / 2
    }
    return res;
}

int main() {
    string name = "";
    cout << "Please enter your first name" << endl;
    cin >> name;
    cout << "Good morning " << name << endl;
    return 0;
}

