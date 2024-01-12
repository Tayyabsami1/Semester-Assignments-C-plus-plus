#include <iostream>
#include <cstring>
#include<string>

using namespace std;

class Pizza
{
    char *name;    
    char *topping;
    char *size;    
    bool is_ready; 
    double price; 

public:
    // Default Constructor
    Pizza()
    {
        name = new char[1];
        name[0] = '\0';

        topping = new char[1];
        topping[0] = '\0';

        size = new char[1];
        size[0] = '\0';

        is_ready = false;
        price = 0.0;
    }

    // Parameterized Constructor
    Pizza(char *toppingVal, double priceVal)
    {
        name = new char[1];
        name[0] = '\0';

        size = new char[1];
        size[0] = '\0';

        is_ready = false;

        this->topping = toppingVal;
        this->price = priceVal;
    }

    // 2nd Parameterized Constructor
    Pizza(char *toppingVal, double priceVal, char *nameVal, char *sizeVal, bool ready_status)
    {
        this->topping = toppingVal;
        this->price = priceVal;
        this->name = nameVal;
        this->size = sizeVal;
        this->is_ready = ready_status;
    }

    // Copy Constructor
    Pizza(const Pizza &pizza)
    {
        this->topping = new char[strlen(pizza.topping) + 1]; // Adding a space for \0
        this->name = new char[strlen(pizza.name) + 1];      
        this->size = new char[strlen(pizza.size) + 1];  

        this->topping = pizza.topping;
        this->name = pizza.name;
        this->size = pizza.size;

        this->price = pizza.price;
        this->is_ready = pizza.is_ready;
    }

    // Getters and Setters  
    void setTopping(char *toppingVal)
    {
        this->topping = new char[strlen(toppingVal) + 1]; // Adding a space for \0

        this->topping = toppingVal;
    }

    void setPrice(double priceVal)
    {
        
        this->price = priceVal;
    }

    void setName(char *nameVal)
    {
        this->name = new char[strlen(nameVal) + 1];      

        this->name = nameVal;
    }

    void setSize(char *sizeVal)
    {
        this->size = new char[strlen(sizeVal) + 1];  

        this->size = sizeVal;
    }

    char *getTopping()
    {
        return topping;
    }

    double getPrice()
    {
        return price;
    }

    char *getName()
    {
        return name;
    }

    char *getSize()
    {
        return size;
    }

    // CHecking if Topping is not eympty 
    void makePizza()
    {
        if (topping[0] != '\0')
        {
            is_ready = true;
        }
    }
    
    bool check_status()
    {
        return is_ready;
    }
};

int main()
{
    // Pizza p1;
    // char*str=new char[100];
    // cin.get(str,100);
    // p1.setTopping(str);
    // p1.setPrice(10.99);
    // p1.setName(str);
    // p1.setSize(str);
    // p1.makePizza();

    // // Create another Pizza object using the second constructor
    // Pizza p2(str, 8.99);

    // // Create a third Pizza object using the third constructor
    // Pizza p3(str, 6.99,str , str, false);

    // // Use the copy constructor to create a fourth Pizza object
    // Pizza p4 = p3;

    // // Print out the details of each pizza
    // cout << "Pizza 1: " << p1.getName() << " (" << p1.getSize() << ")" << endl;
    // cout << "Topping: " << p1.getTopping() << endl;
    // cout << "Price: $" << p1.getPrice() << endl;
    // cout << "Ready? " << (p1.check_status() ? "Yes" : "No") << endl;

    // cout << "Pizza 2: " << p2.getName() << " (" << p2.getSize() << ")" << endl;
    // cout << "Topping: " << p2.getTopping() << endl;
    // cout << "Price: $" << p2.getPrice() << endl;
    // cout << "Ready? " << (p2.check_status() ? "Yes" : "No") << endl;

    // cout << "Pizza 3: " << p3.getName() << " (" << p3.getSize() << ")" << endl;
    // cout << "Topping: " << p3.getTopping() << endl;
    // cout << "Price: $" << p3.getPrice() << endl;
    // cout << "Ready? " << (p3.check_status() ? "Yes" : "No") << endl;

    // cout << "Pizza 4: " << p4.getName() << " (" << p4.getSize() << ")" << endl;
    // cout << "Topping: " << p4.getTopping() << endl;
    // cout << "Price: $" << p4.getPrice() << endl;
    // cout << "Ready? " << (p4.check_status() ? "Yes" :"No")<<endl;

    return 0;
}