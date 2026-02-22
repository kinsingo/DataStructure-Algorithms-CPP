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

void convertToLowerOrUppderCase(char* b)
{
    int offset = 'A' - 'a';
    for (int i = 0; b[i] != '\0'; i++)
    {
        int val = b[i];
        if (val >= 'a' && val <= 'z')
            b[i] += offset;
        else if (val >= 'A' && val <= 'Z')
            b[i] -= offset;
    }
}

int getLength(char* b)
{
    int i = 0;
    while (b[i] != '\0')
        i++;
    return i;
}

void ReverseString(char* b)
{
    int length = getLength(b);
    int i = 0;
    int j = length - 1;
    while (i < j)
    {
        char tmp = b[i];
        b[i] = b[j];
        b[j] = tmp;
        i++;
        j--;
    }
}

bool isPalindrome(char* b)
{
    int length = getLength(b);
    int i = 0;
    int j = length - 1;
    while (i < j)
    {
        if (b[i] != b[j])
            return false;
        i++;
        j--;
    }
    return true;
}

void FindDuplicate(char* b)
{
    int H = 0;
    for (int i = 0; b[i] != '\0'; i++)
    {
        int X = 1;
        X = X << b[i] - 'a';

        if ((X & H) > 0)
            cout << "duplicate : " << b[i] << endl;
        else
            H = X | H;
    }
}

//이거 동작 원리는, 복습할 필요가 있음.
//직접 다시한번 구현해보기
bool isAnagram(char* a, char* b)
{
    int offset = 'z' - 'a';
    vector<int> table(offset + 1);

    for (int i = 0; a[i] != '\0'; i++)
    {
        int index = 'z' - a[i];
        table[index]++;
    }

    for (int i = 0; b[i] != '\0'; i++)
    {
        int index = 'z' - b[i];
        table[index]--;
        if (table[index] < 0)
            return false;
    }
    return true;
}

//이거 동작 원리는, 복습할 필요가 있음.
//직접 다시한번 구현해보기
void PermuationOfString(char* a, int currentDepth)
{
    static int length = getLength(a);
    static bool isIncluded[10] = { false };
    static char Res[10];
    int i;
    if (a[currentDepth] == '\0')
    {
        Res[currentDepth] = '\0';
        cout << Res << endl;
    }
    else
    {
        for (i = 0; a[i] != '\0'; i++)
        {
            if (isIncluded[i] == false)
            {
                Res[currentDepth] = a[i];
                isIncluded[i] = true;
                PermuationOfString(a, currentDepth + 1);
                isIncluded[i] = false;
            }
        }
    }
}


//이거 동작 원리는, 복습할 필요가 있음.
//직접 다시한번 구현해보기
void swap(char& a, char& b)
{
    char tmp = a;
    a = b;
    b = tmp;
}
void PermuationOfString(char* a, int low, int high)
{
    if (low == high)
    {
        cout << a << endl;
    }
    else
    {
        for (int i = low; i <= high; i++)
        {
            swap(a[low], a[i]);
            PermuationOfString(a, low + 1, high);
            swap(a[low], a[i]);
        }
    }
}


int main()
{
    auto start = high_resolution_clock::now();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << fixed << setprecision(6);

    
    char b[] = "aAbBcC";
    cout << b << endl;
    convertToLowerOrUppderCase(b);
    cout << b << endl;
    ReverseString(b);
    cout << b << endl;

    cout << isPalindrome(b) << endl;//false

    char c[] = "abcba";
    cout << isPalindrome(c) << endl;//true

    char d[] = "abba";
    cout << isPalindrome(d) << endl;//true

    char e[] = "abc";
    cout << isPalindrome(e) << endl;//false

    //FindDuplicate(b);
    char example[] = "finding";
    FindDuplicate(example);
    

    
    char a[] = "decimal";
    char b[] = "medical";
    cout << isAnagram(a, b) << endl;//true

    char c[] = "medicall";
    cout << isAnagram(a, c) << endl;//false

    char d[] = "medacal";
    cout << isAnagram(a, d) << endl;//false

    char e[] = "aabdcc";
    char f[] = "dcacba";
    cout << isAnagram(e, f) << endl;//true
    

    char a[] = "ABC";
    PermuationOfString(a, 0);
    cout << endl;
    PermuationOfString(a, 0, 2);

    return 0;
}
*/