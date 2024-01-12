#include <iostream>

using namespace std;

class Library
{
    char *BookTitle, *Author;
    int BookId, Quantity;
    float Price, TPrice;
    static int TotalBooks;

public:
// Default Constructor 
    Library()
    {
        this->BookTitle = new char[1];
        this->BookTitle[0] = '\0';

        this->Author = new char[1];
        this->Author[0] = '\0';

        this->BookId = 0;
        this->Quantity = 0;
        this->Price = 0;
        this->TPrice = 0;
        TotalBooks = 0;
    }

    // Getters and Setters 
    char *getBookTitle()
    {
        return BookTitle;
    }

    char *getAuthor()
    {
        return Author;
    }

    int getBookID()
    {
        return BookId;
    }

    int getQuantity()
    {
        return Quantity;
    }

    float getPrice()
    {
        return Price;
    }

    void setBookTitle(char *title)
    {
        this->BookTitle = title;
    }

    void setAuthor(char *authorName)
    {
        this->Author = authorName;
    }

    void setBookID(int bookID)
    {
        this->BookId = bookID;
    }
// Validating the quantity of books while setting it 
    void setQuantity(int quantity)
    {
        if (quantity < 0)
        {
            cout << "Quantity of Books cannot be negative " << endl;
            return;
        }
        this->Quantity = quantity;
    }

    void setPrice(float price)
    {
        this->Price = price;
    }

    static void setTotalBooks(int totalBooks)
    {
        TotalBooks = totalBooks;
    }

    void calcTotalPrice()
    {
        this->TPrice = this->Price * this->Quantity;
    }

    static int getTotalBooks()
    {
        return TotalBooks;
    }
};

int Library::TotalBooks = 0;

// ! Public Functions

Library getBook_at(Library books[], int index)
{
    return books[index];
}

// Adding a Book and giving it a unique id and also updating the total number of books
void addBook(Library books[], Library newBook)
{
    int number = books[0].getTotalBooks();

    if (number < 100)
    {
        for (int i = 0; i < 100; i++)
        {
            char *Author = books[i].getAuthor();
            char *title = books[i].getBookTitle();
            if (title[0] == '\0' && Author[0] == '\0')
            {
                books[i] = newBook;
                books[i].setBookID(number + 1);
                number++;
                books->setTotalBooks(number);
                break;
            }
        }

        return;
    }
    else
    {
        cout << "Maximum Number of books reached " << endl;
        return;
    }
}

// Removing the book of the specific id from the Object Array  
void removeBook(Library books[], int bookID)
{
    for (int i = 0; i < 100; i++)
    {
        int id = books[i].getBookID();
        int n = books[i].getTotalBooks();

        if (id == bookID)
        {
            char *ptr = new char[1];
            ptr[0] = '\0';

            books[i].setAuthor(ptr);
            books[i].setBookTitle(ptr);
            books[i].setBookID(0);
            books[i].setQuantity(0);
            books[i].setPrice(0);

            n--;

            books[i].setTotalBooks(n);

            break;
        }
    }
}

// Sorting title in Alphabetical Order 
void SortByTitle(Library books[100])
{
    int n = books[0].getTotalBooks();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            char *Title = books[i].getBookTitle();

            char *Title2 = books[j].getBookTitle();

            if ((Title2[0] >= 65 && Title2[0] <= 90) && (Title[0] >= 65 && Title[0] <= 90))
            {
                if (Title[0] > Title2[0])
                {
                    Library temp = books[j];
                    books[j] = books[i];
                    books[i] = temp;
                    i--;
                    break;
                }
            }

            else if ((Title2[0] >= 97 && Title2[0] <= 122) && (Title[0] >= 97 && Title[0] <= 122))
            {

                if (Title[0] - 32 > Title2[0] - 32)
                {
                    Library temp = books[j];
                    books[j] = books[i];
                    books[i] = temp;
                    i--;
                    break;
                }
            }
            else
            {
                if ((Title[0] >= 97 && Title[0] <= 122) && (Title2[0] >= 65 && Title2[0] <= 90))
                {
                    if (Title[0] - 32 > Title2[0])
                    {
                        Library temp = books[j];
                        books[j] = books[i];
                        books[i] = temp;
                        i--;
                        break;
                    }
                }

                if ((Title2[0] >= 97 && Title2[0] <= 122) && (Title[0] >= 65 && Title[0] <= 90))
                {
                    if (Title[0] > Title2[0] - 32)
                    {
                        Library temp = books[j];
                        books[j] = books[i];
                        books[i] = temp;
                        i--;
                        break;
                    }
                }
            }
        }
    }
}

// Sorting Author name in Alphabetical order 
void SortByAuthor(Library books[])
{
    int n = books[0].getTotalBooks();

    for (int i = 0; i < n; i++)
    {
        char *Author = books[i].getAuthor();

        for (int j = i + 1; j < n; j++)
        {

            char *Author2 = books[j].getAuthor();

            if ((Author[0] >= 65 && Author[0] <= 90) && (Author2[0] >= 65 && Author2[0] <= 90))
            {
                if (Author[0] > Author2[0])
                {
                    Library temp = books[j];
                    books[j] = books[i];
                    books[i] = temp;
                    i--;
                    break;
                }
            }

            else if ((Author2[0] >= 97 && Author2[0] <= 122) && (Author[0] >= 97 && Author[0] <= 122))
            {

                if (Author[0] - 32 > Author2[0] - 32)
                {
                    Library temp = books[j];
                    books[j] = books[i];
                    books[i] = temp;
                    i--;
                    break;
                }
            }
            else
            {
                if ((Author[0] >= 97 && Author[0] <= 122) && (Author2[0] >= 65 && Author2[0] <= 90))
                {
                    if (Author[0] - 32 > Author2[0])
                    {
                        Library temp = books[j];
                        books[j] = books[i];
                        books[i] = temp;
                        i--;
                        break;
                    }
                }

                if ((Author2[0] >= 97 && Author2[0] <= 122) && (Author[0] >= 65 && Author[0] <= 90))
                {
                    if (Author[0] > Author2[0] - 32)
                    {
                        Library temp = books[j];
                        books[j] = books[i];
                        books[i] = temp;
                        i--;
                        break;
                    }
                }
            }
        }
    }
}

void SortByPrice(Library books[])
{
    int n = books[0].getTotalBooks();

    for (int i = 0; i < n; i++)
    {
        float P1 = books[i].getPrice();

        for (int j = i + 1; j < n; j++)
        {
            float P2 = books[j].getPrice();
            if (P1 > P2)
            {
                Library temp = books[j];
                books[j] = books[i];
                books[i] = temp;
                i--;
                break;
            }
        }
    }
}

Library mostExpensiveBook(Library books[])
{
    int n = books[0].getTotalBooks();

    int max = books[0].getPrice(), maxI = 0;

    for (int i = 1; i < n; i++)
    {
        int temp = books[i].getPrice();

        if (temp > max)
        {
            max = temp;
            maxI = i;
        }
    }

    return books[maxI];
}

int main()
{
    // // char *ptr = new char[100];
    // // cin.get(ptr, 100);

    // Library Books[100];
    // Library obj1, obj2, obj3, obj4;

    // // obj1.setBookTitle("Zindagi");
    // obj1.setAuthor("al");
    // // obj2.setBookTitle("xindagi");
    // obj1.setPrice(56);
    // obj2.setAuthor("zilal");
    // obj2.setPrice(100);

    // // obj3.setBookTitle("aindagi");
    // obj3.setAuthor("thmed");
    // obj3.setPrice(1);
    // // obj4.setBookTitle("bindagi");
    // obj4.setAuthor("iviar");
    // obj4.setPrice(58);

    // addBook(Books, obj1);
    // addBook(Books, obj2);
    // addBook(Books, obj3);
    // addBook(Books, obj4);

    // // SortByTitle(Books);
    // // SortByAuthor(Books);
    // SortByPrice(Books);

    // // cout << Books[0].getAuthor() << " ";
    // // cout << Books[0].getBookTitle() << " ";
    // cout << Books[0].getPrice() << " ";

    // // cout << Books[1].getAuthor() << " ";
    // // cout << Books[1].getBookTitle() << " ";
    // cout << Books[1].getPrice() << " ";

    // // cout << Books[2].getAuthor() << " ";
    // // cout << Books[2].getBookTitle() << " ";
    // cout << Books[2].getPrice() << " ";

    // // cout << Books[3].getAuthor() << " ";
    // // cout << Books[3].getBookTitle() << " ";
    // cout << Books[3].getPrice() << " ";

    // cout << Books[0].getTotalBooks();

    // Library temp = mostExpensiveBook(Books);

    // cout << temp.getPrice();

    // cout << endl;

    return 0;
}