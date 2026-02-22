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
////Longest Common Subsequence
//
////Recursive DP (O(2^n) or O(2^m)) -- exponential
//int LCS_Recursive(string A, string B, int i, int j)
//{
//	if (i >= A.size() || j >= B.size())
//		return 0;
//
//	char first = A[i];
//	char second = B[j];
//	if (first == second)
//		return LCS_Recursive(A, B, i + 1, j + 1) + 1;
//
//	int left = LCS_Recursive(A, B, i + 1, j);
//	int right = LCS_Recursive(A, B, i, j + 1);
//	return (left > right) ? left : right;
//}
//
////Recursive + Memoization DP (O(nm)) -- polynomial
//unordered_map<string, int> result;
//int LCS_Recursive_Memoization(string A, string B, int i, int j)
//{
//	string key = to_string(i) + "#" + to_string(j);
//	if (i >= A.size() || j >= B.size())
//		return 0;
//
//	if (result.find(key) != result.end())
//		return result[key];
//
//	char first = A[i];
//	char second = B[j];
//	if (first == second)
//	{
//		result[key] = LCS_Recursive_Memoization(A, B, i + 1, j + 1) + 1;
//		return result[key];
//	}
//
//	int left = LCS_Recursive_Memoization(A, B, i + 1, j);
//	int right = LCS_Recursive_Memoization(A, B, i, j + 1);
//	result[key] = (left > right) ? left : right;
//	return result[key];
//}
//
////Recursive + Memoization DP (O(nm)) -- polynomial
//vector<vector<int>> T;
//int LCS_Recursive_Memoization_2(string A, string B, int i, int j)
//{
//	//initialize only once
//	if (T.size() < 1)
//		T = vector<vector<int>>(A.size(), vector<int>(B.size(), -1));
//
//	if (i >= A.size() || j >= B.size())
//		return 0;
//
//	if (T[i][j] != -1)
//		return T[i][j];
//
//	char first = A[i];
//	char second = B[j];
//	if (first == second)
//	{
//		T[i][j] = LCS_Recursive_Memoization_2(A, B, i + 1, j + 1) + 1;
//		return T[i][j];
//	}
//
//	int left = LCS_Recursive_Memoization_2(A, B, i + 1, j);
//	int right = LCS_Recursive_Memoization_2(A, B, i, j + 1);
//	T[i][j] = (left > right) ? left : right;
//	return T[i][j];
//}
//
////Tabulation (O(nm)) -- polynomial, with iterative approach 
////it minimizes stack memory usage from avoiding recursive function call.
//int LCS_Tabulation(string A, string B)
//{
//	vector<vector<int>> T = vector<vector<int>>(A.size() + 1, vector<int>(B.size() + 1, 0));
//
//	for (int i = 1; i < A.size() + 1; i++)
//	{
//		for (int j = 1; j < B.size() + 1; j++)
//		{
//			if (A[i - 1] == B[j - 1])
//				T[i][j] = T[i - 1][j - 1] + 1;
//			else
//			{
//				int left = T[i - 1][j];
//				int right = T[i][j - 1];
//				T[i][j] = (left > right) ? left : right;
//			}
//		}
//	}
//	return T[A.size()][B.size()];
//}
//
//int main()
//{
//	//3
//	//string A = "ace";
//	//string B = "abcde";
//
//	//4
//	string A = "abcdefg";
//	string B = "dbcfmg";
//	cout << "LCS 1 : " << LCS_Recursive(A, B, 0, 0) << endl;
//	cout << "LCS 2 : " << LCS_Recursive_Memoization(A, B, 0, 0) << endl;
//	cout << "LCS 3 : " << LCS_Recursive_Memoization_2(A, B, 0, 0) << endl;
//	cout << "LCS 4 : " << LCS_Tabulation(A, B) << endl;
//	system("pause");
//	return 0;
//}
