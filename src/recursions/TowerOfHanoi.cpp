/*
#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <string>
using namespace std;
using namespace std::chrono;

//Time : O(2^n) = 1 + 2 + 2^2 + 2^3 ... + 2^n = 2^(n+1) - 1
void TowerOfHanoi(int n, string from, string intermediate, string to)
{
    if (n == 0)
        return;

    TowerOfHanoi(n - 1, from, to, intermediate);
    cout << "move " << n << " from " << from << " to " << to << " using " << intermediate << endl;
    TowerOfHanoi(n - 1, intermediate, from, to);
}


int main()
{
    auto start = high_resolution_clock::now();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << fixed << setprecision(6);

    start = high_resolution_clock::now();
    TowerOfHanoi(3, "A", "B", "C");
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    //cout << "nCr(20, 10) is: " << result << " (Time: " << duration.count() / 1000.0 << " ms)" << endl;

    return 0;
}
*/