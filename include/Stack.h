#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;
template <class T>
class Stack
{
public :
    struct Node
    {
        T item;
        Node* next;
    };
    Node* top;
    int size;

    Stack()
    {
        top = nullptr;
        size =0;
    }
    void push (const T& newItem)
    {
        Node* newNode = new Node;
        newNode->item=newItem;
        newNode->next=nullptr;
        if(top==nullptr)
        {
            top=newNode;
        }
        else
        {
            newNode->next = top;
            top = newNode;
        }
        size ++;

    }
    bool isEmpty()
    {
        return top ==nullptr;

    }
    void pop()
    {
        if(isEmpty())
        {
            cout <<"!!Stack empty can not pop"<<endl;
        }
        else
        {
            Node* temp = top;
            top = top->next;
            delete temp;
            size--;
        }
    }
    int get_size()
    {
        return size;
    }

    void display()
    {
        Node* curr = top;
        int i=1;
        while (curr !=nullptr)
        {
            cout<<" - Order "<<i<<" is  :  ";
            cout<<curr->item << endl;
            curr=  curr->next;
            i++;
        }
    }

};

#endif // STACK_H
