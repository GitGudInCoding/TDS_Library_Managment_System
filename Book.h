#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include <iostream>

using namespace std;


class Book
{
private:
    struct BookNode
    {
        //Declare data type and items in the linked list
        int bookID,stuID;
        string bookName,auth,publ;
        bool stat;

        BookNode *next; //Pointer to the next node
    };

    BookNode *head;  //Head pointer of linked list
    BookNode *temp;  //Pointer point to the latest node in linked list
    BookNode *disp; //Pointer for display, search and getStatus function



public:

    Book(); //Default constructor

    ~Book(); //Destructor

    string getStatus() const;
    int getSize();
    void addBook(string bname1,string bau1,string bpu1);
    void delBook(int delNo);
    void editBook(int editNo);
    void searchBook();
    void displayBook();
    void loadBook();
    void saveBook();
    void sortBook();
    void sortID();
    void borrowBook(int bid,int sid);
    void returnBook(int bid);
    void sortAuthor();


    int size;    //Number of book in linked list
};

#endif // BOOK_H_INCLUDED
