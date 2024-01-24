#ifndef SUBLINKEDLIST_H
#define SUBLINKEDLIST_H
#include "Node.h"
template <class T>
class subLinkedList: public Node<T>
{
private:
    Node<T>* Head;
    Node<T>* Tail;
    int length;

public:
    subLinkedList()
    {
        Head = nullptr;
        Tail = nullptr;
        length = 0;
    }
    bool is_empty()
    {
        return length == 0;
    }
    int get_lengh()
    {

        return length;
    }
    void push (const T& newItem)
    {
        if (Head == nullptr || Tail->isFull())
        {
            Node<T>* newNode = new Node<T>;
            newNode->enqueue(newItem);
            newNode->Next=nullptr;
            newNode->prev = nullptr;
            length++;
            if(Head == nullptr)
            {
                Head=Tail=newNode;
            }
            else
            {
                Tail->Next= newNode;
                newNode->prev=Tail;
                Tail = newNode;
            }
        }
        else
        {
            Tail->enqueue(newItem);
        }
    }
    T getHead(){
        return Head->getArr(Head->getFront());
    }
    void pop(){
        if (Head != nullptr){
            Head->dequeue();
            Node<T>* current = Head;
            while (current != nullptr && current->Next != nullptr){
                T removedElement = current->Next->getArr(current->Next->getFront());
                current->Next->dequeue();
                current->enqueue(removedElement);
                current = current->Next;
                if(Tail->isEmpty()){
                    Tail=Tail->prev;
                    Tail->Next=nullptr;
                    length--;
                }
            }

            if (Head->isEmpty()){
                Node<T>* temp = Head;
                Head = Tail = nullptr;
                delete temp;
            }


        }
    }

    void print()
    {
        Node<T>* current = Head;
        while(current != nullptr)
        {
            current->printQueue();
            current=current->Next;
        }
        cout<<endl;
    }
};

#endif // SUBLINKEDLIST_H
