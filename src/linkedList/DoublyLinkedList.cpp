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

template <class T>
struct Vertex
{
    T data;
    Vertex<T>* prev;
    Vertex<T>* next;
    Vertex(T value)
    {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};


template <class T>
class DoublyLinkedList
{
    Vertex<T>* head;

private:
    Vertex<T>* getLastNode()
    {
        Vertex<T>* current = head;
        while (current->next)
            current = current->next;
        return current;
    }

public:
    DoublyLinkedList()
    {
        head == nullptr;
    }

    void AddNode(T value)
    {
        Vertex<T>* newNode = new Vertex<T>(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Vertex<T>* last = getLastNode();
            last->next = newNode;
            newNode->prev = last;
            last = newNode;
        }
    }

    int getLength()
    {
        Vertex<T>* current = head;
        int length = 0;
        while (current)
        {
            length++;
            current = current->next;
        }
        return length;
    }

    void Insert(T value, int index)
    {
        if (index < 0 || index > getLength())
            return;

        Vertex<T>* newNode = new Vertex<T>(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else if (index == 0)
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else
        {
            Vertex<T>* prev = head;
            Vertex<T>* current = head->next;
            for (int i = 1; i < index; i++)
            {
                prev = current;
                current = current->next;
            }

            prev->next = newNode;
            newNode->prev = prev;
            if (current)
            {
                newNode->next = current;
                current->prev = newNode;
            }
        }
    }

    void Reverse()
    {
        if (head->next == nullptr)
            return;

        Vertex<T>* prev = head;
        Vertex<T>* current = head->next;
        while (current)
        {
            prev->next = prev->prev;
            prev->prev = current;

            Vertex<T>* next = current->next;
            current->next = prev;

            prev = current;
            current = next;
        }
        prev->prev = current;
        head = prev;
    }

    void Delete(int index)
    {
        if (index < 0 || index >= getLength())
            return;

        if (index == 0)
        {
            Vertex<T>* current = head;
            head = current->next;
            if (head)
                head->prev = nullptr;
            delete current;
        }
        else
        {
            Vertex<T>* current = head;
            for (int i = 0; i < index; i++)
                current = current->next;

            Vertex<T>* prev = current->prev;
            Vertex<T>* next = current->next;
            prev->next = next;
            if (next)
                next->prev = prev;

            delete current;
        }

    }

    void Display()
    {
        Vertex<T>* current = head;
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void DisplayReversely()
    {
        Vertex<T>* current = getLastNode();
        while (current)
        {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};


int main()
{
    auto start = high_resolution_clock::now();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << fixed << setprecision(6);

    DoublyLinkedList<int> l1;
    l1.AddNode(3);
    l1.AddNode(2);
    l1.Display();
    l1.Reverse();
    l1.Display();
    l1.AddNode(6);
    l1.Display();


    l1.Insert(-100, -1);//index out of range
    l1.Display();

    l1.Insert(100, 0);
    l1.Display();

    l1.Insert(200, 3);
    l1.Display();

    l1.Insert(800, 5);
    l1.Display();

    l1.Insert(1000, 7);//index out of range
    l1.Display();

    l1.DisplayReversely();

    l1.Delete(5);
    l1.Delete(0);
    l1.Display();
    l1.DisplayReversely();

    l1.Delete(2);
    l1.Display();
    l1.DisplayReversely();

    l1.Reverse();
    l1.Display();
    l1.DisplayReversely();


    return 0;
}
*/