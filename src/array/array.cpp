
/*
#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using namespace std::chrono;

void Shift_and_Rotate(int* A, int size)
{
    int temp = A[0];
    for (int i = 1; i < size; i++)
        A[i - 1] = A[i];
    A[size - 1] = temp;
}

void Display(int* A, int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}

void Display(const vector<int>& A)
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}



void Reverse(int* A, int size)
{
    for (int i = 0, j = size - 1; i < j; i++, j--)
    {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}

void ReArrange(int* A, int size)
{
    int i = 0;
    int j = size - 1;
    while (i < j)
    {
        while (A[i] < 0)
            i++;
        while (A[j] >= 0)
            j--;

        if (i < j)
        {
            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }

}

//Time : O(m+n)
int* GetMergedSortedArrays(int* A, int size_A, int* B, int size_B)
{
    int* C = new int[size_A + size_B];

    int i = 0;
    int j = 0;
    int index = 0;


    while (i < size_A && j < size_B)
    {
        if (A[i] < B[j])
            C[index++] = A[i++];
        else
            C[index++] = B[j++];
    }

    while (j < size_B)
        C[index++] = B[j++];

    while (i < size_A)
        C[index++] = A[i++];

    return C;
}


int main()
{
    auto start = high_resolution_clock::now();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << fixed << setprecision(6);

    const int size = 10;
    int* A = new int[size];
    for (int i = 0; i < size; i++)
        A[i] = (i % 2 == 0) ? i * 2 : -i * 2;

    Display(A, size);
    Reverse(A, size);
    Display(A, size);
    ReArrange(A, size);
    Display(A, size);


    int* A = new int[5];
    for (int i = 0; i < 4; i++)
        A[i] = i * 4;
    A[4] = 12;

    int* B = new int[10];
    for (int i = 0; i < 9; i++)
        B[i] = i * 3;
    B[9] = 24;

    Display(A, 5);
    Display(B, 10);
    int* C = GetMergedSortedArrays(A, 5, B, 10);
    Display(C, 15);

    for (int i = 0; i < 5; i++)
    {
        Shift_and_Rotate(A, size);
        Display(A, size);
    }
    return 0;
}
*/