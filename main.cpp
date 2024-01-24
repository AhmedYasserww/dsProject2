#include <iostream>
#include <unistd.h>
#include "Node.h"
#include "subLinkedList.h"
#include "Product.h"
#include "Stack.h"
#include "smartFactory.h"
using namespace std;

int main()
{
    smartFactory<int> smart;
     while (true)
    {
        cout <<"\t\t\t\t-------------------------------------"<<endl;
        cout << "\t\t\t\t\tSmart Factory Manufacturing " << endl;
        cout <<"\t\t\t\t-------------------------------------"<<endl;
        cout<<"\n=> Main Menu:-\n"<<endl;
        cout << "1. Add a PRODUCT." << endl;
        cout << "2. PRINT FRONT PRODUCT." << endl;
        cout << "3. DELETE PRODUCT." << endl;
        cout << "4. PRINT ALL PRODUCT." << endl;
        cout << "5. EXIT." << endl;
        cout << "**Enter your choice: ";

        int choice;
        cin >> choice;
        system ("cls");
        switch (choice)
        {
        case 1:
        {
            smart.add();
            sleep(1);
            system ("cls");
            break;
        }

        case 2:
        {
            Product<int> head = smart.printFront();
            cout<< head<<endl;
            break;
        }
        case 3 :
        {
            smart.deleteProduct();
            cout<<"**Product deleted successfully...\n";
            sleep(1);
            system ("cls");
            break;
        }
        case 4:
        {
            smart.printAll();
            break;
        }

        case 5:
        {
            cout << "THANKS...\n   SEE YOU LATER ^_^" << endl;
            return 0;
        }
        default:
            cout << "!!ERROR\nTRY AGAIN..." << endl;
        }
    }

    return 0;

}

