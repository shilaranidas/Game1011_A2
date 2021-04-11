#include <iostream>
using namespace std;
template<class T>
class DynTempStack
{
private:
    class StackNode
    {
        friend class DynTempStack;
        T value;
        StackNode* next;
        // Constructor
        StackNode(T value1, StackNode* next1 = NULL)
        {
            value = value1;
            next = next1;
        }
    };
    StackNode* top;
public:
    DynTempStack() { top = NULL; }
    void push(T);
    void pop(T&);
    bool isEmpty() const;
    void displayList() const;
};
template<class T>
void DynTempStack<T>::displayList() const
{
    cout << "The current element of stack is: ";
    StackNode* nodePtr = top;
    while (nodePtr)
    {
        cout << nodePtr->value << " ";
        nodePtr = nodePtr->next;
    }
    cout << endl;
}
template<class T>
void DynTempStack<T>::push(T num)
{
    top = new StackNode(num, top);
}

template<class T>
void DynTempStack<T>::pop(T& num)
{

    StackNode* temp;

    if (isEmpty())
    {
        cout << "The stack is empty.\n";
        exit(1);
    }
    else   // Pop value off top of stack
    {
        num = top->value;
        temp = top;
        top = top->next;
        delete temp;
        temp = nullptr;
    }
}

template<class T>
bool DynTempStack<T>::isEmpty() const
{
    if (!top)
        return true;
    else
        return false;
}
