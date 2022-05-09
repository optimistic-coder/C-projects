#include <iostream>
#include <string.h>
using namespace std;

class Library
{
public:
    int id;
    char book_name[50];
    char book_author[50];

public:
    void createBook();
    void displayBooks();
};

void Library::createBook()
{
    cout << "Enter Book ID : " << endl;
    cin >> id;
    cout << "Enter Book Name: " << endl;
    cin >> book_name;
    cout << "Enter book author: " << endl;
    cin >> book_author;
}

void Library::displayBooks()
{
    cout << "ID     : " << id << endl;
    cout << "NAME   : " << book_name << endl;
    cout << "AUTHOR : " << book_author << endl;
}

int main()
{
    Library books[10];
    int count = 0;
    int choice;
    int searchID;
    while (choice != 4)
    {
        cout << "1. INSERT BOOK" << endl;
        cout << "2. DISPLAY BOOK" << endl;
        cout << "3. SEARCH BOOK" << endl;
        cout << "4. EXIT BOOK" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            books[count].createBook();
            count++;
            break;
        case 2:
            for (int i = 0; i < count; i++)
            {
                books[i].displayBooks();
            }
            cout << "_______________________" << endl;
            break;
        case 3:
            cout << "Enter Book ID" << endl;
            cin >> searchID;
            for (int i = 0; i < count; i++)
            {

                if (books[i].id == searchID)
                {
                    books[i].displayBooks();
                }
            }
            cout << "_______________________" << endl;
            break;
        default:
            exit(0);
            break;
        }
    }

    return 0;
}