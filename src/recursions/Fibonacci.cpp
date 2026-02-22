/*


#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace std::chrono;

//O(2^n)
double Fibonacci_Recursive(int n)
{
    if (n <= 1)
        return n;
    return Fibonacci_Recursive(n - 1) + Fibonacci_Recursive(n - 2);
}

//O(n)
double Fibonacci_Memoization(int n, bool init = true)
{
    static vector<double> v;
    if (init)
        v.resize(n + 1, -1);

    if (v[n] >= 0)
        return v[n];

    if (n <= 1)
    {
        v[n] = n;
        return v[n];
    }

    v[n - 1] = Fibonacci_Memoization(n - 1, false);
    v[n - 2] = Fibonacci_Memoization(n - 2, false);
    v[n] = v[n - 1] + v[n - 2];
    return v[n];
}

//O(n)
double Fibonacci_Iteration(int n)
{
    int t0 = 0, t1 = 1, s = 0;
    if (n == 0)
        return t0;
    if (n == 1)
        return t1;

    for (int i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }

    return s;
}



int main()
{
    auto start = high_resolution_clock::now();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << fixed << setprecision(6);

    // Fibonacci tests
    start = high_resolution_clock::now();
    auto result13 = Fibonacci_Recursive(30);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << "Fibonacci of 30 is: " << result13 << " (Time: " << duration.count() / 1000.0 << " ms)" << endl;

    start = high_resolution_clock::now();
    auto result14 = Fibonacci_Memoization(30);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << "Fibonacci of 30 is: " << result14 << " (Time: " << duration.count() / 1000.0 << " ms)" << endl;

    start = high_resolution_clock::now();
    auto result15 = Fibonacci_Iteration(30);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << "Fibonacci of 30 is: " << result15 << " (Time: " << duration.count() / 1000.0 << " ms)" << endl;

    return 0;
}

*/