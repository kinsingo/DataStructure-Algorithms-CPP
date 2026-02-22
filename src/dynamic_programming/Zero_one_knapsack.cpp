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
////Recursive DP
//static int maxProfit = 0;
//void zero_one_Knapsack_Recursive(int box_capacity, int item_weights[], int item_values[], int curValue, int num_items)
//{
//	if (box_capacity < 0)
//		return;
//
//	if (maxProfit < curValue)
//		maxProfit = curValue;
//
//	if (num_items <= 0)
//		return;
//
//	//last weight selected
//	int lastWeight = item_weights[num_items - 1];
//	int lastValue = item_values[num_items - 1];
//	zero_one_Knapsack_Recursive(box_capacity - lastWeight, item_weights, item_values, curValue + lastValue, num_items - 1);
//
//	//last weight not selected
//	zero_one_Knapsack_Recursive(box_capacity, item_weights, item_values, curValue, num_items - 1);
//}
//
////Memoization DP (Recursive + Memoization)
//unordered_map<string, int> result_map;
//int zero_one_Knapsack_Memoization(int box_capacity, int item_weights[], int item_values[], int num_items)
//{
//	string key = to_string(box_capacity) + "#" + to_string(num_items);
//	if (box_capacity <= 0 || num_items <= 0)
//		return 0;
//	
//	if (result_map.find(key) != result_map.end())
//		return result_map[key];
//
//	//last weight selected
//	int lastWeight = item_weights[num_items - 1];
//	int lastValue = item_values[num_items - 1];
//	if (lastWeight <= box_capacity)
//	{
//		int no = zero_one_Knapsack_Memoization(box_capacity, item_weights, item_values, num_items - 1);
//		int yes = zero_one_Knapsack_Memoization(box_capacity - lastWeight, item_weights, item_values, num_items - 1);
//		yes += lastValue;
//		result_map[key] = (yes > no) ? yes : no;
//	}
//	else
//	{
//		result_map[key] = zero_one_Knapsack_Memoization(box_capacity, item_weights, item_values, num_items - 1);
//	}
//	return result_map[key];
//}
//
////Tabulation DP 
////it minimizes stack memory usage from avoiding recursive function call.
////Before writing, mathamatically the related formula should be defined clearly.
////T[i,j] = max(T[i-1,j], T[i-1, j-w[i-1]] + V[i-1]);
////T[0,j] = T[i,0] = 0
//int zero_one_Knapsack_Tabulation(int box_capacity, int item_weights[], int item_values[], int num_items)
//{
//	vector<vector<int>> T(num_items + 1);
//	for (int i = 0; i < T.size(); i++)
//		T[i] = vector<int>(box_capacity + 1, 0);
//
//	for (int i = 1; i < num_items + 1; i++)
//	{
//		for (int j = 1; j < box_capacity + 1; j++)
//		{
//			int first = T[i - 1][j];
//			if (j - item_weights[i - 1] >= 0)
//			{
//				int second = T[i - 1][j - item_weights[i - 1]] + item_values[i - 1];
//				T[i][j] = (first > second) ? first : second;
//			}
//			else
//			{
//				T[i][j] = first;
//			}
//		}
//	}
//	return T[num_items][box_capacity];
//}
//
//
//int main()
//{
//	//19
//	int box_capacity = 5;
//	int item_values[] = { 6,5,3,8 };
//	int item_weights[] = { 1,2,1,2 };
//
//	//8
//	//int box_capacity = 8;
//	//int item_values[] = {1,2,5,6};
//	//int item_weights[] = {2,3,4,5};
//
//	int num_items = sizeof(item_weights) / sizeof(item_weights[0]);
//	zero_one_Knapsack_Recursive(box_capacity, item_weights, item_values, 0, num_items);
//	cout << "max profit 1 : " << maxProfit << endl;
//	cout << "max profit 2 : " << zero_one_Knapsack_Memoization(box_capacity, item_weights, item_values, num_items) << endl;
//	cout << "max profit 3 : " << zero_one_Knapsack_Tabulation(box_capacity, item_weights, item_values, num_items) << endl;
//
//	system("pause");
//	return 0;
//}
