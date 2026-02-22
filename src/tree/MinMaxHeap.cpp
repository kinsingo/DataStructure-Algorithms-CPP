#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "stack.h"
using namespace std;



// 1. Heap : Complete Binary Tree (좌측부터 채워지는 노드, 중간에 비어있는거 X, 즉 height = logN 보장됨)
// 2. Max Heap : 모든 부모는 자식보다는 크다 (Root가 가장 큼)
// 3. Min Heap : 모든 부모는 자식보다는 작다 (Root가 가장 작음)
// 4. Heap 에서는 오직 Root Element만 지울 수 있음.
template <class T>
class MaxHeap
{
private:
    vector<T> vec;
public:

    T GetFirstElement()
    {
        if (vec.size() == 0)
            throw runtime_error("the heap is empty");
        return vec[0];
    }


    //Unoptimized : O(N*logN)
    void CreateHeap(const vector<T>& arr)
    {
        for (const T& ele : arr)
            Insert(ele);
    }


    //Heapify runs in O(n) time because most nodes are near the leaves and require very little work, 
    //while only a few nodes near the root incur O(log n) cost.
    void CreateHeap_Optimized(const vector<T>& arr)
    {
        //1. 배열 복사
        vec = arr;

        //2. 마지막 부모 노드부터 Heapify 진행
        for (int i = (vec.size() - 2) / 2; i >= 0; i--)
            Heapify(i);
    }

    void Heapify(int i)
    {
        while (((i + 1) * 2 - 1) < vec.size())
        {
            int lchild = (i + 1) * 2 - 1;
            int rchild = lchild + 1;

            int nextIndex = lchild;
            if (rchild < vec.size() && (vec[lchild] < vec[rchild]))
                nextIndex = rchild;

            if (vec[nextIndex] > vec[i])
            {
                int tmp = vec[i];
                vec[i] = vec[nextIndex];
                vec[nextIndex] = tmp;
                i = nextIndex;
            }
            else
                break;
        }
    }

    //Time : O(logN)
    void Delete()
    {
        if (vec.size() == 0)
            return;

        if (vec.size() == 1)
        {
            vec.pop_back();
            return;
        }

        //Tree의 Last Element를 First로 하고 heapify 진행
        vec[0] = vec.back();
        vec.pop_back();
        Heapify(0);
    }

    //Time : O(logN)
    void Insert(T data)
    {
        vec.push_back(data);
        int i = vec.size() - 1;

        //좀 더 직관적인 방법
        while (i > 0 && vec[i] > vec[(i - 1) / 2])
        {
            int tmp = vec[(i - 1) / 2];
            vec[(i - 1) / 2] = vec[i];
            vec[i] = tmp;
        }

        //좀 더 최적화된 방법
        //while (i > 0 && data > vec[(i - 1) / 2])
        //{
        //    vec[i] = vec[(i - 1) / 2];
        //    i = (i - 1) / 2;
        //}   
        //vec[i] = data;
    }

    void Display()
    {
        if (vec.size() == 0)
            return;

        cout << "maximum : " << vec[0] << endl;
        for (int v : vec)
        {
            cout << v << " ";
        }
        cout << endl;

    }
};

template <class T>
class MinHeap
{
private:
    vector<T> vec;
public:

    T GetFirstElement()
    {
        if (vec.size() == 0)
            throw runtime_error("the heap is empty");
        return vec[0];
    }

    //Unoptimized : O(N*logN)
    void CreateHeap(const vector<T>& arr)
    {
        for (const T& ele : arr)
            Insert(ele);
    }


    //Heapify runs in O(n) time because most nodes are near the leaves and require very little work, 
    //while only a few nodes near the root incur O(log n) cost.
    void CreateHeap_Optimized(const vector<T>& arr)
    {
        //1. 배열 복사
        vec = arr;

        //2. 마지막 부모 노드부터 Heapify 진행
        for (int i = (vec.size() - 2) / 2; i >= 0; i--)
            Heapify(i);
    }

    //Time : O(logN)
    void Insert(T data)
    {
        vec.push_back(data);
        int i = vec.size() - 1;
        while (i > 0 && data < vec[(i - 1) / 2])
        {
            vec[i] = vec[(i - 1) / 2];
            i = (i - 1) / 2;
        }
        vec[i] = data;
    }

    void Heapify(int i)
    {
        while (((i + 1) * 2 - 1) < vec.size())
        {
            int lchild = (i + 1) * 2 - 1;
            int rchild = lchild + 1;

            int nextIndex = lchild;
            if (rchild < vec.size() && (vec[lchild] > vec[rchild]))//if (rchild < vec.size() && (vec[lchild] < vec[rchild]))
                nextIndex = rchild;

            if (vec[nextIndex] < vec[i])//if (vec[nextIndex] > vec[i])
            {
                int tmp = vec[i];
                vec[i] = vec[nextIndex];
                vec[nextIndex] = tmp;
                i = nextIndex;
            }
            else
                break;
        }
    }

    //Time : O(logN)
    void Delete()
    {
        if (vec.size() == 0)
            return;

        if (vec.size() == 1)
        {
            vec.pop_back();
            return;
        }

        //Tree의 Last Element를 First로 하고 heapify 진행
        vec[0] = vec.back();
        vec.pop_back();
        Heapify(0);
    }

    void Display()
    {
        if (vec.size() == 0)
            return;

        cout << "minimum : " << vec[0] << endl;
        for (int v : vec)
        {
            cout << v << " ";
        }
        cout << endl;
    }
};

//Time : O(N*logN)
template<class T>
void AcendingOrderHeapSort(vector<T>& arr)
{
    MaxHeap<T> maxHeap;
    //O(N)
    maxHeap.CreateHeap_Optimized(arr);

    //O(N*logN)
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = maxHeap.GetFirstElement();
        maxHeap.Delete();
    }
}

//Time : O(N*logN)
template<class T>
void DcendingOrderHeapSort(vector<T>& arr)
{
    MinHeap<T> minHeap;
    //O(N)
    minHeap.CreateHeap_Optimized(arr);

    //O(N*logN)
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = minHeap.GetFirstElement();
        minHeap.Delete();
    }
}

/*
int main()
{
    MaxHeap<int> maxHeap;
    MinHeap<int> minHeap;
    for (int i = 0; i < 10; i++)
    {
        int randomNum = rand() % 100 + 1;
        maxHeap.Insert(randomNum);
        maxHeap.Display();
        minHeap.Insert(randomNum);
        minHeap.Display();
        cout << endl;
    }

    for (int i = 0; i < 10; i++)
    {
        maxHeap.Delete();
        maxHeap.Display();
        minHeap.Delete();
        minHeap.Display();
        cout << endl;
    }

    vector<int> arr = { 20,15,25,5,10,35,3 };
    vector<int> arr_2 = arr;

    AcendingOrderHeapSort<int>(arr);
    for (int ele : arr)
        cout << ele << " ";
    cout << endl;

    DcendingOrderHeapSort<int>(arr_2);
    for (int ele : arr_2)
        cout << ele << " ";
    cout << endl;

    system("pause");
    return 0;
}
*/