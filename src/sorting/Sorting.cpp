#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;



//Min : O(N) -> If the arr is already sorted (By introducing isAlreadySorted)
//Max : O(N^2)
void BubbleSort(vector<int>& arr, bool isIncreasing)
{
    int numOfComputation = 0;
    for (int j = arr.size() - 1; j > 0; j--)
    {
        bool isAlreadySorted = true;
        for (int i = 0; i < j; i++)
        {
            numOfComputation++;
            if ((isIncreasing && arr[i] > arr[i + 1])
                || (!isIncreasing && arr[i] < arr[i + 1]))
            {
                swap(arr[i], arr[i + 1]);
                isAlreadySorted = false;
            }
        }

        if (isAlreadySorted)
            break;
    }

    for (int ele : arr)
        cout << ele << " ";
    cout << ",BubbleSort numOfComputation:" << numOfComputation << endl;
}

//Min : O(N) -> If the arr is already sorted
//Max : O(N^2)
void InsertionSort(vector<int>& arr, bool isIncreasing)
{
    if (arr.size() <= 1)
        return;

    int numOfComputation = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        int element = arr[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            numOfComputation++;
            if ((isIncreasing && arr[j] > element)
                || (!isIncreasing && arr[j] < element))
                arr[j + 1] = arr[j];
            else
                break;
        }
        arr[j + 1] = element;
    }

    for (int ele : arr)
        cout << ele << " ";
    cout << ",InsertionSort numOfComputation:" << numOfComputation << endl;
}

//Min : O(N^2)
//Max : O(N^2)
void SelectionSort(vector<int>& arr, bool isIncreasing)
{
    int numOfComputation = 0;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int targetIndex = -1;
        int target = arr[i];
        for (int j = i + 1; j < arr.size(); j++)
        {
            numOfComputation++;
            if ((isIncreasing && arr[j] < target) || (!isIncreasing && arr[j] > target))
            {
                targetIndex = j;
                target = arr[j];
            }
        }
        if (targetIndex > 0)
        {
            swap(arr[i], arr[targetIndex]);
        }
    }

    for (int ele : arr)
        cout << ele << " ";
    cout << ",SelectionSort numOfComputation:" << numOfComputation << endl;
}

//[아래는 Pivot을 항상 첫번째 요소로 가져가는 일반적인 구현에 한해서임]
//Min : O(N*logN) (If the pivot is always in the middle)
//Average : O(N*logN)
//Max : O(N^2) (Acending 혹은 Decending 으로 이미 Sort 되어있을때, 항상 pivot 이 맨 첫번째 혹은 마지막 요소가 됨)
//Merge Sort 대비 장점은, inplace 변환이기 때문에 별도의 array가 필요 없음.
void QuickSort(vector<int>& arr, int low, int high, bool isIncreasing, int& numOfComputation)
{
    if (low >= high)
        return;

    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j)
    {
        while (i <= high && ((isIncreasing && arr[i] < pivot) || (!isIncreasing && arr[i] > pivot)))
        {
            numOfComputation++;
            i++;
        }

        while (j > low && ((isIncreasing && arr[j] > pivot) || (!isIncreasing && arr[j] < pivot)))
        {
            numOfComputation++;
            j--;
        }

        if (i < j)
        {
            numOfComputation++;
            swap(arr[i++], arr[j--]);
        }
        else
        {
            break;
        }

    }

    numOfComputation++;
    swap(arr[low], arr[j]);
    QuickSort(arr, low, j - 1, isIncreasing, numOfComputation);
    QuickSort(arr, j + 1, high, isIncreasing, numOfComputation);
}

void QuickSort(vector<int>& arr, bool isIncreasing)
{
    int numOfComputation = 0;
    QuickSort(arr, 0, arr.size() - 1, isIncreasing, numOfComputation);
    for (int ele : arr)
        cout << ele << " ";
    cout << ", QuickSort numOfComputation:" << numOfComputation << endl;
}

//Min/Max : O(N*logN)
//Compared to Quicksort, it requires additional array for each function call (newArr in below)
void MergeSort(vector<int>& arr, int low, int high, bool isIncreasing, int& numOfComputation)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;
    MergeSort(arr, low, mid, isIncreasing, numOfComputation);
    MergeSort(arr, mid + 1, high, isIncreasing, numOfComputation);

    vector<int> newArr(high - low + 1);
    int i = low;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= high)
    {
        numOfComputation++;
        if ((isIncreasing && arr[i] < arr[j]) || (!isIncreasing && arr[i] > arr[j]))
            newArr[k++] = arr[i++];
        else
            newArr[k++] = arr[j++];
    }

    while (i <= mid)
    {
        numOfComputation++;
        newArr[k++] = arr[i++];
    }

    while (j <= high)
    {
        numOfComputation++;
        newArr[k++] = arr[j++];
    }

    for (int i = 0; i < newArr.size(); i++)
    {
        numOfComputation++;
        arr[i + low] = newArr[i];
    }

}

void MergeSort(vector<int>& arr, bool isIncreasing)
{
    int numOfComputation = 0;
    MergeSort(arr, 0, arr.size() - 1, isIncreasing, numOfComputation);
    for (int ele : arr)
        cout << ele << " ";
    cout << ", MergeSort numOfComputation:" << numOfComputation << endl;
}

//Index 기반 Sort : 0 이상의 정수에서만 사용 가능, 정수의 범위가 0~M 이어야 함. 
//가장 큰 Value(M) 가 전체 Memory 사용량을 결정함, 또한 그에 따른 Time Complexity 또한 증가함 
//즉, N개의 정수, 가장 큰 정수가 M 일경우, Time -> O(2N + M) -> O(N + M) -> O(N) 
//즉, O(N) 으로 볼 수도 있지만, 사실상 O(N+M) 이기 때문에, M에 따라 실제 실행 시간/메모리 사용량은 매우 커질 수 있음.
void CountSort(vector<int>& arr, bool isIncreasing)
{
    int numOfComputation = 0;
    int maxValue = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        numOfComputation++;
        if (arr[i] > maxValue)
            maxValue = arr[i];
        if (arr[i] < 0)
            throw new runtime_error("all value must be equal to or greater than 0");
    }

    vector<int> storage(maxValue + 1, 0);
    for (int value : arr)
    {
        numOfComputation++;
        storage[value]++;
    }


    int index = 0;

    if (isIncreasing)
    {
        for (int value = 0; value < storage.size(); value++)
        {
            numOfComputation++;
            while (storage[value] > 0)
            {
                numOfComputation++;
                arr[index++] = value;
                storage[value]--;
            }
        }
    }
    else
    {
        for (int value = storage.size() - 1; value >= 0; value--)
        {
            numOfComputation++;
            while (storage[value] > 0)
            {
                numOfComputation++;
                arr[index++] = value;
                storage[value]--;
            }
        }
    }

    for (int ele : arr)
        cout << ele << " ";
    cout << ", CountSort numOfComputation:" << numOfComputation << endl;
}



//Index 기반 Sort : 0 이상의 정수에서만 사용 가능, 정수의 범위가 0~M 이어야 함. 
//가장 큰 Value(M) 가 전체 Memory 사용량을 결정함, 또한 그에 따른 Time Complexity 또한 증가함 
//즉, N개의 정수, 가장 큰 정수가 M 일경우, Time -> O(2N + M) -> O(N + M) -> O(N) 
//즉, O(N) 으로 볼 수도 있지만, 사실상 O(N+M) 이기 때문에, M에 따라 실제 실행 시간/메모리 사용량은 매우 커질 수 있음.
//BucketSort(혹은 BinSort)는 방식만 Linked List 기반으로 변경된것, 사실상 Count Sort 와 유사
void BucketSort(vector<int>& arr, bool isIncreasing)
{
    int numOfComputation = 0;
    struct Node
    {
        Node* next;
        Node()
        {
            next = nullptr;
        }
    };

    int maxValue = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        numOfComputation++;
        if (arr[i] > maxValue)
            maxValue = arr[i];
        if (arr[i] < 0)
            throw new runtime_error("all value must be equal to or greater than 0");
    }

    vector<Node*> bins(maxValue + 1, nullptr);
    for (int value : arr)
    {
        numOfComputation++;
        Node* newNode = new Node();
        if (bins[value] == nullptr)
            bins[value] = newNode;
        else
        {
            Node* current = bins[value];
            while (current->next)
                current = current->next;
            current->next = newNode;
        }
    }

    int index = 0;
    if (isIncreasing)
    {
        for (int value = 0; value < bins.size(); value++)
        {
            numOfComputation++;
            while (bins[value])
            {
                numOfComputation++;
                arr[index++] = value;
                Node* current = bins[value];
                bins[value] = bins[value]->next;
                delete current;
            }
        }
    }
    else
    {
        for (int value = bins.size() - 1; value >= 0; value--)
        {
            numOfComputation++;
            while (bins[value])
            {
                numOfComputation++;
                arr[index++] = value;
                Node* current = bins[value];
                bins[value] = bins[value]->next;
                delete current;
            }
        }
    }


    for (int ele : arr)
        cout << ele << " ";
    cout << ", BucketSort numOfComputation:" << numOfComputation << endl;
}

//RadixSort (BucketSort의 개선버전)
//이거는 M 대신 10 개의 Bins 만 가지면 되서 O(M+N) 대신 O(10+N) -> O(N)임.
//대신 가장 큰 숫자 기준으로 자리수 d 만큼 O(N) 연산이 반복됨, 보통 d는 적은 숫자기 때문에 (4자리수의 경우 d=4)
//전체 연산을 O(dN) -> O(N)으로 볼 수 있음. 메모리도 M 이 아닌 10만 더 추가되기 떄문에 거의 무시 가능. 
void RadixSort(vector<int>& arr, bool isIncreasing)
{
    struct Node
    {
        int data;
        Node* next;
        Node(int data)
        {
            this->data = data;
            this->next = nullptr;
        }
    };

    int numOfComputation = 0;
    vector<Node*> Bins(10, nullptr);

    int maxValue = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        numOfComputation++;
        if (arr[i] > maxValue)
            maxValue = arr[i];
        if (arr[i] < 0)
            throw new runtime_error("all value must be equal to or greater than 0");
    }

    int count = 0;
    while (maxValue / 10 != 0 || maxValue % 10 != 0)
    {
        numOfComputation++;
        count++;
        maxValue /= 10;
    }

    for (int i = 0; i < count; i++)
    {
        int denominator = 1;
        for (int j = 0; ((i > 0) && (j < i)); j++)
            denominator *= 10;

        for (int ele : arr)
        {
            numOfComputation++;
            int digit = (ele / denominator) % 10;
            Node* newNode = new Node(ele);
            if (Bins[digit] == nullptr)
                Bins[digit] = newNode;
            else
            {
                Node* current = Bins[digit];
                while (current->next)
                    current = current->next;
                current->next = newNode;
            }
        }

        int index = 0;
        if (isIncreasing)
        {
            for (int digit = 0; digit < 10; digit++)
            {
                while (Bins[digit])
                {
                    numOfComputation++;
                    arr[index++] = Bins[digit]->data;
                    Node* current = Bins[digit];
                    Bins[digit] = Bins[digit]->next;
                    delete current;
                }
            }
        }
        else
        {
            for (int digit = 9; digit >= 0; digit--)
            {
                while (Bins[digit])
                {
                    numOfComputation++;
                    arr[index++] = Bins[digit]->data;
                    Node* current = Bins[digit];
                    Bins[digit] = Bins[digit]->next;
                    delete current;
                }
            }
        }
    }

    for (int ele : arr)
        cout << ele << " ";
    cout << ", RadixSort numOfComputation:" << numOfComputation << endl;
}

//Shell Sort
//이거는 Insertion Sort 의 장점을 취하고 단점을 없애는 방법
//O(N*LogN)
//Quicksort 처럼 Inplace 방식이라 별도 메모리 필요 없음.
void ShellSort(vector<int>& arr, bool isIncreasing)
{
    int numOfComputation = 0;
    for (int gap = arr.size() / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < arr.size(); i++)
        {
            int j = i - gap;
            int tmp = arr[i];
            for (; j >= 0; j -= gap)
            {
                numOfComputation++;
                if ((isIncreasing && arr[j] > tmp) || (!isIncreasing && arr[j] < tmp))
                    arr[j + gap] = arr[j];
                else
                    break;
            }
            arr[j + gap] = tmp;
        }
    }


    for (int ele : arr)
        cout << ele << " ";
    cout << ", ShellSort numOfComputation:" << numOfComputation << endl;
}

void Test(vector<int> v, bool isIncreasing)
{
    //Comparison
    vector<int> v1 = v;
    BubbleSort(v1, isIncreasing);
    vector<int> v2 = v;
    InsertionSort(v2, isIncreasing);
    vector<int> v3 = v;
    SelectionSort(v3, isIncreasing);
    vector<int> v4 = v;
    MergeSort(v4, isIncreasing);
    vector<int> v5 = v;
    ShellSort(v5, isIncreasing);
    vector<int> v6 = v;
    QuickSort(v6, isIncreasing);

    //Index
    vector<int> v7 = v;
    BucketSort(v7, isIncreasing);
    vector<int> v8 = v;
    CountSort(v8, isIncreasing);
    vector<int> v9 = v;
    RadixSort(v9, isIncreasing);
}

/*
int main()
{
    srand(static_cast<unsigned int>(time(0)));
    vector<int> v;
    vector<int> v_sequential_increasing;
    vector<int> v_sequential_decreasing;
    const int numOfData = 100;
    int j = numOfData;
    for (int i = 0; i < numOfData; i++)
    {
        //int randomNum = rand() % 100 + 1;

        //아래 처럼 하면 BucketSort / CountSort 에 큰 영향줌
        int randomNum = rand() % 100 + 1;

        v.push_back(randomNum);
        v_sequential_increasing.push_back(i + 1);
        v_sequential_decreasing.push_back(j--);
    }

    cout << "=== Random Test ===" << endl << endl;
    //모두 O(N*logN) 이지만 실제로는
    //1. Merge Sort는 값 복사에 따른 계산까지 추가되어 가장 느림
    //2. Inplace 계산 이기는 하지만, 아무래도 Gap 기반 접근의 Shell Sort가 Quick Sort 보다 보통 더 많은 계산이 이루어짐
    //계산/비교 횟수: Quick < Shell < Merge
    //메모리 접근 : Quick < Shell << Merge(메모리 복사)
    //maximum number가 작을 경우에는 Index 기반의 BucketSort,CountSort,RaditSort 성능이 가장 좋음
    Test(v, true);

    cout << "\n=== Sequential Acending Test ===" << endl << endl;
    //Best For : Bubble Sort, Insertion Sort
    //Worst For : Quicksort 
    Test(v_sequential_increasing, true);

    cout << "\n=== Sequential Dcending Test ===" << endl << endl;
    //Best For : Bubble Sort, Insertion Sort
    //Worst For : Quicksort 
    Test(v_sequential_decreasing, false);

    system("pause");
    return 0;
}
*/