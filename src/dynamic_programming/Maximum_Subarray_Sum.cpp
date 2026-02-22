//#include <iostream>
//#include <vector>
//#include <cstdlib>
//#include <ctime>
//#include <unordered_set>
//#include <unordered_map>
//#include <queue>
//#include <stack>
//#include <algorithm>
//#include <string>
//using namespace std;
//
////Maximum SubArray Sum
//
////Naive Algo - O(n^2)
//int MSS_1(const vector<int>& A)
//{
//	int maxSum = INT32_MIN;
//	int start_index = 0;
//	int end_index = 0;
//	for (int i = 0; i < A.size(); i++)
//	{
//		int sum = 0;
//		for (int j = i; j < A.size(); j++)
//		{
//			sum += A[j];
//			if (maxSum < sum)
//			{
//				maxSum = sum;
//				start_index = i;
//				end_index = j;
//			}
//
//		}
//	}
//	cout << "startIndex : " << start_index << ", endIndex : " << end_index << endl;
//	return maxSum;
//}
//
////DP(Tabulation) - O(n) : mathamatically observed, (Space : O(n))
//int MSS_DP(const vector<int>& A)
//{
//	vector<int> sum(A.size(), 0);
//	sum[0] = A[0];
//
//	for (int i = 1; i < A.size(); i++)
//	{
//		if (sum[i - 1] < 0)
//			sum[i] = A[i];
//		else
//			sum[i] = sum[i - 1] + A[i];
//	}
//
//	int maxSum = INT32_MIN;
//	for (int i = 0; i < A.size(); i++)
//		if (maxSum < sum[i])
//			maxSum = sum[i];
//
//	return maxSum;
//}
//
////DP(Tabulation) - O(n) : mathamatically observed, (Space : O(1))
//int MSS_DP_2(const vector<int>& A)
//{
//	vector<int> sum(A.size(), 0);
//	int prevSum = A[0];
//	int currentSum;
//	int startIndex = 0, endIndex = 0, subStart = 0;
//	int maxSum = INT32_MIN;
//	for (int i = 1; i < A.size(); i++)
//	{
//		if (prevSum < 0)
//		{
//			currentSum = A[i];
//			subStart = i;
//		}
//
//		else
//			currentSum = prevSum + A[i];
//
//		if (maxSum < currentSum)
//		{
//			maxSum = currentSum;
//			startIndex = subStart;
//			endIndex = i;
//		}
//
//		prevSum = currentSum;
//	}
//
//	cout << "startIndex : " << startIndex << ", endIndex : " << endIndex << endl;
//	return maxSum;
//}
//
////DAC - O(nlogn)
////핵심: Cross sum은 mid를 반드시 포함하면서 양쪽으로 확장되는 부분배열의 합.
////아래 (1), (2)가 지켜져야지, leftSum + rightSum 가 하나의 Subarray 의 maxSum 으로 볼 수 있음
//int crossSume(const vector<int>& A, int l, int h)
//{
//	int mid = (l + h) / 2;
//	int leftSum = INT32_MIN;
//	int sum = 0;
//
//	//(1) 반드시 mid부터 왼쪽으로
//	for (int i = mid; i >= l; i--)
//	{
//		sum += A[i];
//		if (leftSum < sum)
//			leftSum = sum;
//	}
//
//	int rightSum = INT32_MIN;
//	sum = 0;
//
//	//(2) 반드시 mid+1 부터 오른쪽으로
//	for (int i = mid + 1; i <= h; i++)
//	{
//		sum += A[i];
//		if (rightSum < sum)
//			rightSum = sum;
//	}
//
//	return leftSum + rightSum;
//}
//
//int MSS_DAC(const vector<int>& A, int l, int h)
//{
//	if (l == h)
//		return A[l];
//
//
//	int mid = (l + h) / 2;
//	int left = MSS_DAC(A, l, mid);
//	int right = MSS_DAC(A, mid + 1, h);
//	int cross = crossSume(A, l, h);
//
//	int max = (left > right) ? left : right;
//	return (max > cross) ? max : cross;
//}
//
//int main()
//{
//	vector<int> A = { 4,-5, 8,-2,-1,7,-6 };
//	cout << "MSS 1 : " << MSS_1(A) << endl;
//	cout << "MSS 2 : " << MSS_DP(A) << endl;
//	cout << "MSS 3 : " << MSS_DP_2(A) << endl;
//	cout << "MSS 4 : " << MSS_DAC(A, 0, A.size() - 1) << endl;
//	system("pause");
//	return 0;
//}
