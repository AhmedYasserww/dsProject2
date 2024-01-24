#ifndef NODE_H
#define NODE_H
#include <iostream >
using namespace std;
template <typename T>
class Node
{
private:
    int front, rear ;
    int size;
    T arr[4];
public:
    Node<T>* Next;
    Node<T>* prev;
    Node()
    {
        size=front=0;
        rear=-1;
        Next =nullptr;
        prev=nullptr;
    }
    int getFront(){
        return front;
    }
    T getArr(int index){
        return arr[index];
    }
    bool isEmpty()
    {
        return size ==0;
    }
    bool isFull()
    {
        return size==4;
    }
    void enqueue(T val)
    {
        rear = (rear + 1) % 4;
        arr[rear] = val;
        size++;
    }
    void dequeue()
    {
        front = (front + 1) % 4;
        size--;
    }
    void printQueue()
    {
        for (int i = front; i != rear; i = (i + 1) % 4)
        {
            cout << arr[i] << " ";
        }
        cout << arr[rear]<<endl;
    }
};
#endif // NODE_H
