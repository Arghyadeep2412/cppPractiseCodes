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

//-------------we need to get the maximum profit - given the prices of stocks for next few days ----------------
// - use graphical representation - cumulative effect
int maxProfit(int price[], int n) {
    int profit = 0;
    for(int i = 1; i < n; i++) {
        if(price[i] > price[i-1]) {
            profit += (price[i] - price[i-1]);
        }
    }
    return profit;
}

//------------trapping rain water-----------------
// input array contains -- non-negetive integers
int waterStoredMax(int bars[], int n) {
    int waterStoredTotal = 0;
    vector<int> leftMax(n);
    leftMax[0] = bars[0];
    for(int i = 1; i < n; i++) {
        leftMax[i] = leftMax[i-1];
        if(bars[i] > leftMax[i - 1]) {
            leftMax[i] = bars[i];
        }
    }

    vector<int> rightMax(n);
    rightMax[n-1] = bars[n-1];
    for(int i = (n-2); i >= 0; i--) {
        rightMax[i] = rightMax[i + 1];
        if(bars[i] > rightMax[i+1]) {
            rightMax[i] = bars[i];
        }
    }
    for(int i = 1; i < (n-1); i++) {
        int leastSideWall = rightMax[i];
        if(leftMax[i] < rightMax[i]) {
            leastSideWall = leftMax[i];
        }
        if((leastSideWall - bars[i]) > 0) {
            waterStoredTotal += (leastSideWall - bars[i]);
        }
    }
    return waterStoredTotal;
}

//-----------maximum consecutive ones in binary array -- array consists of 0's and 1's-----------
int maxConsecutiveOnesCount(int arr[], int n) {
    int maxCount = 0;
    int thisCount = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == 1) {
            thisCount++;
        } else {
            if(thisCount > maxCount) {
                maxCount = thisCount;
                thisCount = 0;
            }
        }
    }

    if(thisCount > maxCount) {
        maxCount = thisCount;
    }
    return maxCount;
}

// get the maximum subarray sum --- array might contains -ve integers
int getMaxSubArraySum(int arr[], int n) {
    int res = arr[0];
    int maxEnding = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > (arr[i] + maxEnding)) {
            maxEnding = arr[i];
        } else {
            maxEnding = (arr[i] + maxEnding);
        }

        if(maxEnding > res) {
            res = maxEnding;
        }
    }
    return res;
}

// get the max even odd length ----------------
int maxEvenOddLength(int arr[], int n) {
    int maxLength = 1;
    int thisLength = 1;
    for(int i = 1; i < n; i++) {
        if((((arr[i] % 2) == 0) && ((arr[i-1] % 2) != 0)) || ((arr[i] % 2) != 0) && ((arr[i-1] % 2) == 0)) {
            thisLength++;
        } else {
            if(maxLength < thisLength) {
                maxLength = thisLength;
            }
            thisLength = 1;
        }
    }
    if(thisLength > maxLength) {
        maxLength = thisLength;
    }
    return maxLength;
}

// get the max circular sum-----------------------

int getMaxCircularArraySum(int arr[], int n) {
    int resNormal = getMaxSubArraySum(arr, n);
    
    if(resNormal < 0) {
        return resNormal;
    }
    
    int arrSum = 0;
    for(int i = 0; i < n; i++) {
        arrSum += arr[i];
        arr[i] = (-arr[i]);
    }
    
    int maxCircular = arrSum + getMaxSubArraySum(arr, n);
    
    if(resNormal > maxCircular) {
        maxCircular = resNormal;
    }
    
    return maxCircular;
}

//------------------get the majority of an array - a num which is repeated more than n / 2

int findMajority(int arr[], int n) {
    // naive approach - O(n^2)
    int count = 0;
    for(int i = 0; i < n; i++) {
        count = 1;
        for(int j = (i + 1); j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
            }
        }

        if(count > (n/2)) {
            return i;
        }
    }
    return (-1);
}

int findMajority(int arr[], int n) {
    // moore's solution
    int res = 0, count = 1;
    for(int i = 1; i > n; i++) {
        if(arr[res] == arr[i]) {
            count++;
        } else {
            count--;
        }
        if(count == 0) {
            res = i;
            count = 1;
        }
    }

    count = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == arr[res]) {
            count++;
        }
    }

    if(count <= (n/2)) {
        res = (-1);
    }

    return res;
}

//-------------------------min number of flips required to make the boolean array elements equall------------------------
// all the elements in the array is either 0 or 1
// if arr[0] == arr[n-1] --> abs(totalPatchCount1 - totalPatchCount0) will be 1
// else it will be 0

int minGroups(int arr[], int n) {
    // naive approach 
    int totalPatchCount1 = 0;
    int totalPatchCount0 = 0;
    int thisPatchCount1 = 0;
    int thisPatchCount0 = 0;
    if(arr[0] == 1) {
        thisPatchCount1++;
    } else {
        thisPatchCount0++;
    }
    for(int i = 1; i < n; i++) {
        if(arr[i-1] == 1 && arr[i] == 1) {
            thisPatchCount1++;
        } else if(arr[i-1] == 0 && arr[i] == 0) {
            thisPatchCount0++;
        } else if(arr[i-1] == 0 && arr[i] == 1) {
            totalPatchCount0++;
            thisPatchCount1 = 1;
        } else if(arr[i-1] == 1 && arr[i] == 0) {
            totalPatchCount1++;
            thisPatchCount0 = 1;
        }
    }
    if(arr[n-1] == 0) {
        totalPatchCount0++;
    } else {
        totalPatchCount1++;
    }

    cout << "totalPatchCount0 --> " << totalPatchCount0 << " totalPatchCount1 --> " << totalPatchCount1 << endl;
    if(totalPatchCount1 < totalPatchCount0) {
        return totalPatchCount1;
    }
    return totalPatchCount0;
}

void flipMinGroupsToFlip(int arr[], int n) {
    // efficient method
    for(int i = 1; i < n; i++) {
        if(arr[i] != arr[i-1]) {
            if(arr[i] != arr[0]) {
                cout << "From " << i << " to ";
            } else {
                cout << (i-1) << endl;
            }
        }
    }

    if(arr[n-1] != arr[0]) {
        cout << (n-1) << endl;
    }
}

// window sliding technique---------------------------
// need to get the max sum of consecutive k elms
int getMax(int arr[], int n, int k) {
    int currSum = 0;
    for(int i = 0; i < k; i++) {
        currSum += arr[i];
    }
    int maxSum = currSum;
    for(int i = k; i < n; i++) {
        currSum += (arr[i] - arr[i-k]);
        if(currSum > maxSum) {
            maxSum = currSum;
        }
    }
    return maxSum;
}

// window sliding technique----- given an unsorted array of non-negetive integers, find if there is a subarray with given sum
// this solution is only worth when we have non-negetive elements
vector<int> getSubArray(int arr[], int n, int k) {
    int startInd = 0;
    int endInd = 0;
    int currSum = arr[startInd];
    vector<int> res;
    while(endInd < n) {
        if(currSum < k) {
            endInd += 1;
            currSum += arr[endInd];
        } else if(currSum > k) {
            if(startInd == endInd) {
                startInd = startInd + 1;
                endInd = endInd + 1;
                currSum = arr[startInd];
            } else {
                currSum -= arr[startInd];
                startInd += 1;
            }
        } else {
            res.push_back(startInd);
            res.push_back(endInd);
            break;
        }
    }
    return res;
}

// get the first m of n-bonachi numberseries ------------------------------------------
// if n = 3, first 3 numbers are 0,0,1

vector<int> getFirstMofNbonachiSeries(int n, int m) {
    vector<int> res(m, 0);
    if(m < n) {
        return res;
    }
    res[n-1] = 1;
    int currSum = 1;
    for(int i = n; i < m; i++) {
        res[i] = currSum;
        currSum += (res[i] - res[i-n]);
    }
    return res;
}

// count distinct element in every window of size k ---------------
// inp arr = [1,2,1,3,4,3,3] --> output arr = [3,4,3,2] ---> need to solve

// prefix sum -- 
// inp arr = [2,8,3,9,6,5,4] -- query --> getSum(0,2) = 13; getSum(1,3) = 20
int getSumByPreFixSumTechnique(int arr[], int n, int l, int r) {
    int sum = 0;
    vector<int> prefixSum;
    prefixSum.push_back(arr[0]);
    for(int i = 1; i < n; i++) {
        prefixSum.push_back(arr[i] + prefixSum[i-1]);
    }
    if(l == 0) {
        sum = prefixSum[r];
    } else {
        sum = prefixSum[r] - prefixSum[l-1];
    }
    return sum;
}

// given an array of integers - check if there is an equilibrium point -> sum of elements to the left == sum of elements to the right
// this is based on prefix sum technique
bool isEquilibriumPresent(int arr[], int n) {
    bool equilibPointPresent = false;
    int totalSum = 0;
    for(int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    int leftSum = 0;
    for(int i = 0; i < n; i++) {
        if((totalSum - arr[i]) == leftSum) {
            equilibPointPresent = true;
            break;
        }
        leftSum += arr[i];
        totalSum -= arr[i];
    }
    return equilibPointPresent;
}

//Smallest positive missing number -- https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1/?track=DSASP-Arrays&batchId=154
int shiftAllNegetivesTowardsStart(int arr[], int n) {
    int res = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] <= 0) {
            int temp = arr[i];
            arr[i] = arr[res];
            arr[res] = temp;
            res++;
        }
    }
    return (res);
}

int findMissingPositive(int arr[], int size)
{
	int i;

	// Mark arr[i] as visited by
	// making arr[arr[i] - 1] negative.
	// Note that 1 is subtracted
	// because index start
	// from 0 and positive numbers start from 1
	for (i = 0; i < size; i++) {
		if (abs(arr[i]) - 1 < size && arr[abs(arr[i]) - 1] > 0)
			arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
	}

	// Return the first index
	// value at which is positive
	for (i = 0; i < size; i++)
		if (arr[i] > 0)

			// 1 is added because
			// indexes start from 0
			return i + 1;

	return size + 1;
}

int findMissing(int arr[], int size)
{

	// First separate positive
	// and negative numbers
	int shift = shiftAllNegetivesTowardsStart(arr, size);

	// Shift the array and call
	// findMissingPositive for
	// positive part
    // yhi sara khel hai //////////////////////////////VVIMP LINE/////////
	return findMissingPositive(arr + shift, size - shift);
}

// Rearrange Array Alternately - https://practice.geeksforgeeks.org/problems/-rearrange-array-alternately-1587115620/1/?track=DSASP-Arrays&batchId=154

void rightRotateByOne(int arr[], int n) {
    int temp = arr[n-1];
    for(int i = n-2; i >= 0; i--) {
        arr[i+1] = arr[i];
    }
    arr[0] = temp;
}

void rearrangeArrayAlt(int arr[], int n) {
    int loopTill = (n/2) + 1;
    for(int i = 0; i <= loopTill; i+=2) {
        rightRotateByOne(arr+i, n-i);
    }
}

int main() {
    return 0;
}