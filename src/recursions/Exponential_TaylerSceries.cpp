/*

#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace std::chrono;

//e^n = 1 + x/1! + x^2/2! + x^3/3! + ... + x^n/n! (Taylor Series)
double E_Recursive(double x, int n)
{
    static double power = 1;
    static double factorial = 1;

    if (n == 0)
    {
        power = 1;
        factorial = 1;
        return 1;
    }

    double result = E_Recursive(x, n - 1);//이거 반드시 power *= x 및 factorial *= n 이전에 호출 필요
    power *= x;
    factorial *= n;

    return result + power / factorial;
}

double E_Iteration(double x, int n)
{
    double s = 1;
    for (; n > 0; n--)
        s = 1 + x / n * s;
    return s;
}

double E_Recursive_2(double x, int n)
{
    static double s;
    if (n == 0)
        return s;
    s = 1 + x / n * s;
    return E_Recursive_2(x, n - 1);
}

int main()
{
    auto start = high_resolution_clock::now();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << fixed << setprecision(6);

    // E_Recursive tests
    start = high_resolution_clock::now();
    auto result1 = E_Recursive(5, 5);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    std::cout << "Value of e^5 is: " << result1 << " (Time: " << duration.count() / 1000.0 << " ms)" << std::endl;

    start = high_resolution_clock::now();
    auto result2 = E_Recursive(5, 10);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    std::cout << "Value of e^5 is: " << result2 << " (Time: " << duration.count() / 1000.0 << " ms)" << std::endl;

    start = high_resolution_clock::now();
    auto result3 = E_Recursive(5, 15);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    std::cout << "Value of e^5 is: " << result3 << " (Time: " << duration.count() / 1000.0 << " ms)" << std::endl;

    start = high_resolution_clock::now();
    auto result4 = E_Recursive(5, 20);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    std::cout << "Value of e^5 is: " << result4 << " (Time: " << duration.count() / 1000.0 << " ms)" << std::endl << endl;


    // E_Iteration tests
    start = high_resolution_clock::now();
    auto result5 = E_Iteration(5, 5);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    std::cout << "Value of e^5 is: " << result5 << " (Time: " << duration.count() / 1000.0 << " ms)" << std::endl;

    start = high_resolution_clock::now();
    auto result6 = E_Iteration(5, 10);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    std::cout << "Value of e^5 is: " << result6 << " (Time: " << duration.count() / 1000.0 << " ms)" << std::endl;

    start = high_resolution_clock::now();
    auto result7 = E_Iteration(5, 15);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    std::cout << "Value of e^5 is: " << result7 << " (Time: " << duration.count() / 1000.0 << " ms)" << std::endl;

    start = high_resolution_clock::now();
    auto result8 = E_Iteration(5, 20);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    std::cout << "Value of e^5 is: " << result8 << " (Time: " << duration.count() / 1000.0 << " ms)" << std::endl << endl;

    // E_Recursive_2 tests
    start = high_resolution_clock::now();
    auto result9 = E_Recursive_2(5, 5);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    std::cout << "Value of e^5 is: " << result9 << " (Time: " << duration.count() / 1000.0 << " ms)" << std::endl;

    start = high_resolution_clock::now();
    auto result10 = E_Recursive_2(5, 10);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    std::cout << "Value of e^5 is: " << result10 << " (Time: " << duration.count() / 1000.0 << " ms)" << std::endl;

    start = high_resolution_clock::now();
    auto result11 = E_Recursive_2(5, 15);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    std::cout << "Value of e^5 is: " << result11 << " (Time: " << duration.count() / 1000.0 << " ms)" << std::endl;

    start = high_resolution_clock::now();
    auto result12 = E_Recursive_2(5, 20);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    std::cout << "Value of e^5 is: " << result12 << " (Time: " << duration.count() / 1000.0 << " ms)" << std::endl << endl;

    return 0;
}
*/