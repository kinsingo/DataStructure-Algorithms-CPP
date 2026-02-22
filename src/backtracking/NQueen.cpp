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
//class NQueen
//{
//    vector<int> colPositionByRow;
//    int N;
//public:
//    void Solve(int N)
//    {
//        this->N = N;
//        colPositionByRow = vector<int>(N, -1);
//        FindQueenColumnPosition(0);
//    }
//
//private:
//    bool isValid(int row, int col)
//    {
//        for (int prevRow = 0; prevRow < row; prevRow++)
//        {
//            int prevCol = colPositionByRow[prevRow];
//
//            //Case 1 (vertically attacked)
//            if (prevCol == col)
//                return false;
//
//            //Case 2 (diagonally attacked)
//            if (abs(prevCol - col) == abs(prevRow - row))
//                return false;
//        }
//        return true;
//    }
//
//    void PrintResults()
//    {
//        cout << endl;
//        cout << "N : " << N << endl;
//        for (int row = 0; row < N; row++)
//            cout << "(" << row << "," << colPositionByRow[row] << ")" << endl;
//    }
//
//    void FindQueenColumnPosition(int row)
//    {
//        for (int col = 0; col < N; col++)
//        {
//            if (isValid(row, col))
//            {
//                colPositionByRow[row] = col;
//                if (row == N - 1)
//                {
//                    PrintResults();
//                    return;
//                }
//                FindQueenColumnPosition(row + 1);
//            }
//        }
//    }
//};
//
//int main()
//{
//    NQueen q;
//    q.Solve(4);
//    system("pause");
//    return 0;
//}
