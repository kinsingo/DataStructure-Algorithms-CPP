#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

void permute(int k, const string& str, vector<char>& res, vector<bool>& selected)
{
    if (k == str.size())
    {   
        cout << string(res.begin(), res.end()) << endl;
        return;
    }

    for (int i = 0; i < str.size(); i++)
    {
        char c = str[i];
        if (selected[i] == false)
        {
            selected[i] = true;
            res[k] = c;
            permute(k + 1, str, res, selected);
            selected[i] = false;
        }
    }
}

void permutation(const string& str)
{
    vector<bool> selected(str.size(), false);
    vector<char> res(str.size());
    int k = 0;
    permute(0, str, res, selected);
}

int main()
{
    permutation("ABC");
    system("pause");
    return 0;
}
