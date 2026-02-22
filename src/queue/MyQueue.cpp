#include "MyQueue.h"
using namespace std;

bool CircularQueue::isFull()
{
	return ((rear + 1) % this->size == front);
}


CircularQueue::CircularQueue(int size)
{
	this->size = size + 1;//empty 조건과, full 조건 비교되도록 하나는 항상 비어있어야함 그렇기에 실제로는 하나 더 메모리 할당
	array = new int[this->size];
	for (int i = 0; i < this->size; i++)
		array[i] = emptyVal;//For debugging using displayAll()
	front = 0;
	rear = 0;
}

void CircularQueue::enQueue(int val)
{
	if (isFull())
		throw runtime_error("Queue is full");

	rear = (rear + 1) % this->size;
	array[rear] = val;
}

int CircularQueue::deQueue()
{
	if (isEmpty())
		throw runtime_error("Queue is empty");

	front = (front + 1) % this->size;

	int val = array[front];
	array[front] = emptyVal;//For debugging using displayAll()
	return val;
}

bool CircularQueue::isEmpty()
{
	return (front == rear);
}

void CircularQueue::displayAll()
{
	cout << "front:" << front << ", rear:" << rear << " => ";
	for (int i = 0; i < size; i++)
	{
		if (array[i] != emptyVal)
			cout << array[i] << " ";
	}

	cout << endl;
}

CircularQueue::~CircularQueue()
{
	delete[] array;
}




LinkedListQueue::LinkedListQueue()
{
	first = nullptr;
	last = nullptr;
}

void LinkedListQueue::enQueue(int val)
{
	Node* newNode = new Node(val);

	if (isEmpty())
	{
		first = newNode;
		last = newNode;
	}
	else
	{
		last->next = newNode;
		last = newNode;
	}
}

int LinkedListQueue::deQueue()
{
	if (isEmpty())
		throw runtime_error("Queue is empty");

	int data = first->data;
	Node* node = first;
	first = first->next;
	delete node;
	return data;
}

bool LinkedListQueue::isEmpty()
{
	return first == nullptr;
}

void LinkedListQueue::displayAll()
{
	Node* current = first;
	while (current)
	{
		cout << current->data << " ";
		current = current->next;
	}

	cout << endl;
}

void TestQueue(IQueue* queue)
{
	queue->enQueue(1); queue->displayAll();
	queue->enQueue(2); queue->displayAll();
	queue->enQueue(3); queue->displayAll();
	queue->enQueue(4); queue->displayAll();
	queue->enQueue(5); queue->displayAll();
	cout << queue->deQueue() << endl; queue->displayAll();
	queue->enQueue(6); queue->displayAll();
	while (queue->isEmpty() == false)
		cout << queue->deQueue() << endl;
	queue->displayAll();
}

/*
int main()
{
	TestQueue(new CircularQueue(5));
	cout << endl;
	TestQueue(new LinkedListQueue());
	return 0;
}
*/