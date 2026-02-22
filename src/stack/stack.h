#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using namespace std::chrono;

template<class T>
class IStack
{
public:
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual T peek() = 0;
    virtual T peek(int index) = 0;
    virtual bool isEmpty() = 0;
};

template<class T>
class ArrayStack : public IStack<T>
{
    int size;
    int top;
    T* s;

public:
    ArrayStack(int size)
    {
        this->size = size;
        this->s = new T[size];
        this->top = -1;
    }

    virtual void push(T value) override
    {
        if (top == size - 1)
            throw runtime_error("stack overflow");

        s[++top] = value;
    }

    virtual T pop() override
    {
        if (isEmpty())
            throw runtime_error("stack is empty");

        return s[top--];
    }

    virtual T peek() override
    {
        if (isEmpty())
            throw runtime_error("stack is empty");

        return s[top];
    }

    virtual T peek(int index) override
    {
        if (top - index < 0)
            throw runtime_error("index out of range");

        return s[top - index];
    }

    virtual bool isEmpty() override
    {
        return (top == -1);
    }

    virtual ~ArrayStack()
    {
        delete[] s;
    }
};

template <class T>
class LinkedListStack : public IStack<T>
{
    struct Node
    {
        T data;
        Node* next;
        Node(T value)
        {
            data = value;
            next = nullptr;
        }
    };

    Node* top;

public:
    LinkedListStack()
    {
        top = nullptr;
    }

    virtual void push(T value) override
    {
        Node* newNode = new Node(value);
        if (newNode == nullptr)//The heap is full
            throw runtime_error("stack overflow");

        newNode->next = top;
        top = newNode;
    }

    virtual T pop() override
    {
        if (isEmpty())
            throw runtime_error("stack is empty");

        T value = top->data;
        Node* original_top = top;
        top = top->next;
        delete original_top;
        return value;
    }
    virtual T peek() override
    {
        if (isEmpty())
            throw runtime_error("stack is empty");

        return top->data;

    }
    virtual T peek(int index) override
    {
        if (isEmpty())
            throw runtime_error("stack is empty");

        Node* current = top;

        for (int i = 0; i < index && current; i++)
            current = current->next;

        if (current)
            return current->data;
        else
            throw runtime_error("index out of range");
    }
    virtual bool isEmpty() override
    {
        return top == nullptr;
    }
};
