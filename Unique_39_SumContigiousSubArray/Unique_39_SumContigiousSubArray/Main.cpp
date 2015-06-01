#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class MaxSubArray
{
public:
	int leftIndex;
	int rightIndex;
	int sum;
};

MaxSubArray FindMaxCrossingSum(vector<int> A, int low, int mid, int high)
{
	MaxSubArray output;
	int maxLeftSum = INT_MIN;
	int sum = 0;
	int leftIndex = 0;
	int rightIndex = 0;
	for (int i = low; i <= mid; i++)
	{
		sum += A[i-1];
		if (sum > maxLeftSum)
		{
			maxLeftSum = sum;
			leftIndex = i;
		}
	}

	sum = 0;
	int maxRightSum = INT_MIN;
	for (int i = mid + 1; i <= high; i++)
	{
		sum += A[i-1];
		if (sum > maxRightSum)
		{
			maxRightSum = sum;
			rightIndex = i;
		}
	}
	output.leftIndex = leftIndex;
	output.rightIndex = rightIndex;
	output.sum = maxLeftSum + maxRightSum;
	return output;
}

MaxSubArray FindMaximumSubArray(vector<int> A, int low, int high)
{
	if (low == high-1) // base case for array of at least size 2
	{
		MaxSubArray output;
		output.leftIndex = low;
		output.rightIndex = high;
		output.sum = A[low - 1] + A[high - 1];
		return output;
	}
	else
	{
		MaxSubArray maxSubArray;
		int mid = floor((low + high) / 2);
		MaxSubArray leftArray = FindMaximumSubArray(A, low, mid);
		MaxSubArray rightArray = FindMaximumSubArray(A, mid + 1, high);
		MaxSubArray crossArray = FindMaxCrossingSum(A,low, mid, high);
		if (leftArray.sum > rightArray.sum && leftArray.sum > crossArray.sum)
		{
			maxSubArray.leftIndex = leftArray.leftIndex;
			maxSubArray.rightIndex = leftArray.rightIndex;
			maxSubArray.sum = leftArray.sum;
		}
		else if (rightArray.sum > leftArray.sum && rightArray.sum > crossArray.sum)
		{
			maxSubArray.rightIndex = rightArray.rightIndex;
			maxSubArray.leftIndex = rightArray.leftIndex;
			maxSubArray.sum = rightArray.sum;
		}
		else
		{
			maxSubArray.rightIndex = crossArray.rightIndex;
			maxSubArray.leftIndex = crossArray.leftIndex;
			maxSubArray.sum = crossArray.sum;
		}
		return maxSubArray;
	}
}

vector<int> GetMaxSubArray(vector<int> inputArray)
{
	MaxSubArray outputArray = FindMaximumSubArray(inputArray, 1, inputArray.size());
	vector<int> maxSubArray;
	for (int i = outputArray.leftIndex - 1; i <= outputArray.rightIndex - 1; i++)
	{
		maxSubArray.push_back(inputArray[i]);
	}
	return maxSubArray;
}

int main()
{
	vector<int> inputArray = { 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
	vector<int> maxSubArray = GetMaxSubArray(inputArray);
}