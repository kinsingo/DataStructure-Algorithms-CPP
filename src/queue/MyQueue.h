#pragma once
#include <iostream>
#include <vector>
using namespace std;

class IQueue
{
public:
    virtual void enQueue(int val) = 0;
    virtual int deQueue() = 0;
    virtual bool isEmpty() = 0;
    virtual void displayAll() = 0;
};

class CircularQueue : public IQueue
{
    int* array;
    int front;
    int rear;
    int size;
    const int emptyVal = -999;//For debugging using displayAll()
private:
    bool isFull();
public:
    CircularQueue(int size);
    void enQueue(int val) override;
    int deQueue() override;
    bool isEmpty() override;
    void displayAll() override;
    ~CircularQueue();
};

class LinkedListQueue : public IQueue
{
    struct Node
    {
        int data;
        Node* next;
        Node(int data)
        {
            this->data = data;
            next = nullptr;
        }
    };

private:
    Node* first;
    Node* last;

public:
    LinkedListQueue();
    void enQueue(int val) override;
    int deQueue() override;
    bool isEmpty() override;
    void displayAll() override;
};

