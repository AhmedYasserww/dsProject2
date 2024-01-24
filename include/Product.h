#ifndef PRODUCT_H
#define PRODUCT_H
#include "Stack.h"
#include <iostream>
using namespace std;
template<typename T>
class Product
{
private:
    Stack<T> productOrder;
    int productId;
    string productName;
    int brand;
    string description;
public:
    Product() {}
    void addOrder(T order)
    {
        productOrder.push(order);
    }

    void popOrder()
    {
        productOrder.pop();
    }
    void printOrders()
    {
        productOrder.display();
    }
    bool is_empty()
    {
        return productOrder.isEmpty();
    }

    int sizeOfOrder()
    {
        return productOrder.get_size();

    }
    Product(string name, string desc, int id,int brand)
    {
        this->productName = name;
        this->description = desc;
        this->productId = id;
        this->brand = brand;

    }
    friend ostream &operator<<(ostream &out, Product<T> &product)
    {
        out << "*Product id is  : " << product.productId << endl;
        out << "*Product name is : " << product.productName << endl;
        out << "*Brand is : " << product.brand << endl;
        out << " Description is  : " << product.description << endl;
        cout << "*Number of orders is : "<<product.sizeOfOrder()<<endl;
        product.printOrders();
        cout<<"SAVED SUCCESSFULLY.....";
       // out << "-------------------------------------------" << endl;


        return out;
    }

    friend istream &operator>>(istream &in, Product<T> &product)
    {
        cout << "*Enter Product Id : ";
        in>>product.productId;
        cout << "*Enter Name of Product : ";
        in >> product.productName;
        cout << "*Enter Brand of Product : ";
        in>>product.brand;
        cout << "*Enter The Description of Product : ";
        in>>product.description;
        cout << "*Enter Number of Orders : ";
        int num;
        in>>num;
        for(int i=1;i<=num;i++)
        {
            cout << " - Enter Order "<<i<<" : ";
            T order;
            in>>order;
            product.addOrder(order);
        }
        cout << "-------------------------------------------" << endl;
        return in;
    }

};

#endif // PRODUCT_H
