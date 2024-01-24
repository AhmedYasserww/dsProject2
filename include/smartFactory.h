#ifndef SMARTFACTORY_H
#define SMARTFACTORY_H
#include "Product.h"
#include "subLinkedList.h"
template <typename T>
class smartFactory
{
private:
    subLinkedList<Product<T>> factory;
public:
    smartFactory(){}
    void add(){
        Product<T> product;
        cin>>product;
        factory.push(product);
    }
    void deleteProduct(){
        factory.pop();
    }
    Product<T> printFront(){
        return factory.getHead();
    }
    void printAll(){
        factory.print();
    }
    ~smartFactory(){}


};

#endif // SMARTFACTORY_H
