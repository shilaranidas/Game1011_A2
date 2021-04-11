#include <iostream>
using namespace std;

template<class T>
class DynTempQueue
{
private:
	class QueueNode
	{
		friend class DynTempQueue;
		T value;
		QueueNode* next;
		QueueNode(T value1, QueueNode* next1 = NULL)
		{
			value = value1;
			next = next1;
		}
	};
	// These track the front and rear of the queue
	QueueNode* front;
	QueueNode* rear;
public:
	// Constructor and Destructor
	DynTempQueue();
	~DynTempQueue();

	// Member functions
	void enqueue(T);
	void dequeue(T&);
	bool isEmpty() const;
	void clear();
	void displayList() const;
};

template<class T>
DynTempQueue<T>::DynTempQueue()
{
	front = NULL;
	rear = NULL;
}

template<class T>
DynTempQueue<T>::~DynTempQueue()
{
	clear();
}

template<class T>
void DynTempQueue<T>::enqueue(T num)
{
	if (isEmpty())
	{
		front = new QueueNode(num);
		rear = front;
	}
	else
	{
		rear->next = new QueueNode(num);
		rear = rear->next;
	}
}

template<class T>
void DynTempQueue<T>::dequeue(T& num)
{
	QueueNode* temp;
	if (isEmpty())
	{
		cout << "The queue is empty.\n";
		exit(1);
	}
	else
	{
		num = front->value;
		temp = front;
		front = front->next;
		delete temp;
	}
}

template<class T>
bool DynTempQueue<T>::isEmpty() const
{
	if (front == NULL)
		return true;
	else
		return false;
}

template<class T>
void DynTempQueue<T>::clear()
{
	T value;   // Dummy variable for dequeue

	while (!isEmpty())
		dequeue(value);
}

template<class T>
void DynTempQueue<T>::displayList() const
{
	cout << "The current element of queue is: ";
	QueueNode* nodePtr = front;
	while (nodePtr)
	{
		cout << nodePtr->value << " ";
		nodePtr = nodePtr->next;
	}
	cout << endl;
}
