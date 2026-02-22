/*
#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace std::chrono;

//Time : O(n)
long long Factorial(int x)
{
    if (x == 0)
        return 1;
    return x * (Factorial(x - 1));
}

//nCr = n! / (r! * (n - r)!)
//Time : O(n) (= 3*O(n) + 1)
double nCr(int n, int r)
{
    long long t1 = Factorial(n);
    long long t2 = Factorial(r);
    long long t3 = Factorial(n - r);
    return t1 / (double)(t2 * t3);
}


double nCr_recursive(int n, int r)
{
    if (r == 0 || n == r)
        return 1;
    return nCr_recursive(n - 1, r - 1) + nCr_recursive(n - 1, r);
}

double nCr_recursive_memoization(int n, int r, bool init = true)
{
    static vector<vector<double>> v;
    if (init)
        v.resize(n + 1, vector<double>(r + 1, -1));

    if (v[n][r] > 0)
        return v[n][r];

    if (r == 0 || n == r)
    {
        v[n][r] = 1;
        return v[n][r];
    }

    v[n - 1][r - 1] = nCr_recursive_memoization(n - 1, r - 1, false);
    v[n - 1][r] = nCr_recursive_memoization(n - 1, r, false);
    v[n][r] = v[n - 1][r - 1] + v[n - 1][r];
    return v[n][r];
}


int main()
{
    auto start = high_resolution_clock::now();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << fixed << setprecision(6);


    start = high_resolution_clock::now();
    auto result = nCr(20, 10);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << "nCr(20, 10) is: " << result << " (Time: " << duration.count() / 1000.0 << " ms)" << endl;

    start = high_resolution_clock::now();
    result = nCr_recursive(20, 10);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << "nCr_recursive(20, 10) is: " << result << " (Time: " << duration.count() / 1000.0 << " ms)" << endl;

    start = high_resolution_clock::now();
    result = nCr_recursive_memoization(20, 10);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << "nCr_recursive_memoization(20, 10) is: " << result << " (Time: " << duration.count() / 1000.0 << " ms)" << endl;

    return 0;
}
*/