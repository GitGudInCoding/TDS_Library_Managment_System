#include <iostream>
#include <conio.h>

using namespace std;

class Book
{
private:
    struct BookNode
    {
        //Declare data type and items in the linked list
        int bookID;
        string bookName,auth,publ,filename;
        bool stat;

        BookNode *next; //Pointer to the next node
    };

    BookNode *head;  //Head pointer of linked list
    BookNode *temp;  //Pointer point to the latest node in linked list
    BookNode *disp; //Pointer for display, search and getStatus function

    int size;    //Number of book in linked list

public:

    Book(); //Default constructor

    ~Book(); //Destructor

    void menu();
    string getStatus() const;
    void addBook();
    void delBook();
    void editBook();
    void searchBook();
    void display();
    void sort();

};

Book::Book() : size(0), head(NULL), temp(NULL), disp(NULL)
{
}// Default constructor set size start from 0 and head start from NULL

Book::~Book()
{
    BookNode *dallp = head;
    while(dallp != NULL){
        BookNode *dnext = dallp -> next;
        delete dallp;
        dallp = dnext;
    }
    head = NULL;
}// Destructor destroy the linked list

void Book::menu()
{
    system("cls");
    char choice;
    bool exit = false;
    do{
    cout << "\n";
    cout << "1. Add Book Record" << endl;
    cout << "2. Display All Book Records" << endl;
    cout << "3. Delete Book Record" << endl;
    cout << "4. Edit Book Record" << endl;
    cout << "5. Search Book Record" << endl;
    cout << "8. Exit" << endl;
    cout << "\n";
    cout << "Enter Your Selection: ";
    cin >> choice;

    switch(choice)
    {
    case '1' :
        addBook();
        break;

    case '2' :
        sort();
        display();
        menu();
        break;

    case '3' :
        delBook();
        break;

    case '4' :
        editBook();
        break;

    case '5' :
        searchBook();
        break;

    case '6' :
        exit = true;
        break;
        }
    }while(!exit);{
    cout << "\n\n\n\n";
    cout<<"\t \t \t \t \t \t See You Next Time! \n\n\n\n"<<endl;
    }
}

string Book::getStatus() const
{
    if(disp -> stat==1){
        return "Available";
    }else{
        return "Unavailable";
    }
}

void Book::addBook()
{
    system("cls");
    BookNode *newPtr = new BookNode;
    size = size+1;
    newPtr -> bookID = size;

    cout << "\n";
    cout << "Book ID: " << newPtr -> bookID  << endl;
    cout << "Book Name: ";
    cin >> newPtr -> bookName;
    cout << "Book Author: ";
    cin >> newPtr -> auth;
    cout << "Book Publisher: ";
    cin >> newPtr -> publ;
    newPtr -> stat = true;
    newPtr -> next = NULL;

    if(head==NULL){
        temp = newPtr;
        head = temp;
    }else{
        temp -> next = newPtr;
        temp = newPtr;
    }

    cout << "\n";
    cout << "Book Added Successfully! . . . ";
    getch();
    system("cls");

}

void Book::delBook()
{
    system("cls");
    if(head==NULL)
    {
         cout << "\n";
         cout<<"Book Record is Empty!\n";
         getch();
         system("cls");
    }
    else
    {
        int delNo;
        BookNode *prev = head;
        BookNode *delp = head;
        cout << "Enter Book ID that you want to delete: ";
        cin >> delNo;
            if((delNo < head -> bookID) || (delNo > size)){
                cout << "\n";
                cout << "No Record Found! . . . ";

                getch();
                system("cls");

            }
            else
            {
                if(delp->bookID == delNo){
                head = delp -> next;
                delete(delp);
                }
                else
                {
                    while( prev -> bookID < delNo-1)
                    {
                        prev = prev -> next;
                    }
                    delp = prev -> next;
                    prev -> next = delp -> next;
                    delete(delp);
                }
            cout << "\n";
            cout << "Book Record Successfully Deleted! . . . ";
            getch();
            system("cls");
            }
    }
}

void Book::editBook()
{
   system("cls");
    if(head==NULL)
    {
         cout << "\n";
         cout<<"Book Record is Empty!\n";
         getch();
         system("cls");
    }
    else
    {
    int editNo;
    BookNode *edip = head;
    cout << "Enter Book ID that you want to edit: ";
    cin >> editNo;
    if((editNo < head -> bookID) || (editNo > size)){
        cout << "\n";
        cout << "No Record Found! . . . ";

        getch();
        system("cls");


    }else{
     while(edip != NULL){
            if(editNo == edip -> bookID){
                cout << "\n";
                cout << "Book ID: " << edip -> bookID  << endl;
                cout << "Book Name: ";
                cin >> edip -> bookName;
                cout << "Book Author: ";
                cin >> edip -> auth;
                cout << "Book Publisher: ";
                cin >> edip -> publ;
            }
        edip = edip -> next;
        }


    cout << "\n";
    cout << "Book Record Successfully ! . . . ";
    getch();
    system("cls");
    }

   }
}

void Book::searchBook()
{
    system("cls");
    if(head==NULL)
    {
         cout << "\n";
         cout<<"Book Record is Empty!\n";
         getch();
         system("cls");
    }
    else
    {
        int found = 0;
        string bname;
        disp = head;
        cout << "Enter Book Name that you want to search: ";
        cin >> bname;
        while(disp != NULL){
                if(bname == disp -> bookName){
                   cout << "\nBook ID: " << disp -> bookID << endl;
                   cout << "Book Name:" << disp -> bookName << endl;
                   cout << "Book Author:" << disp -> auth << endl;
                   cout << "Book Publisher:" << disp -> publ << endl;
                   cout << "Book Status:" << getStatus() << endl;
                   found++;
                }
            disp = disp -> next;
        }

        if(found == 0){

            cout << "\n";
            cout << "No Book Record Found! . . . ";
            getch();
            system("cls");

        }else{

        cout << "\n";
        cout << found << " Record Found! Press Any Key to Return to Menu . . . ";
        getch();
        system("cls");
        }
    }
}

void Book::sort(){ // Sort book by name

    int count=0,temp_bookID;
    string temp_bookName, temp_auth, temp_publ;
    BookNode*ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr -> next;
    }
    for(int i=1; i<count; i++){
        BookNode*ptr=head;
        for(int j=1; j<count; j++){
            if(ptr -> bookName > ptr -> next -> bookName)
            {
                temp_bookID = ptr -> bookID;
                temp_bookName = ptr -> bookName;
                temp_auth = ptr->auth;
                temp_publ = ptr -> publ;

                // Save book record into current node
                ptr -> bookID = ptr -> next -> bookID;
                ptr -> bookName = ptr -> next -> bookName;
                ptr -> auth = ptr -> next -> auth;
                ptr -> publ = ptr -> next -> publ;

                //Save book record into next node
                ptr -> next -> bookID = temp_bookID;
                ptr -> next -> bookName = temp_bookName;
                ptr -> next -> auth = temp_auth;
                ptr -> next -> publ = temp_publ;
                }
                ptr = ptr -> next;
        }
    }

}
void Book::display()
{
    system("cls");
    disp = head;
    if(disp==NULL){
        cout<<"Book Record is Empty!\n";
    }
    while(disp != NULL){
        cout << "\nBook ID: " << disp -> bookID << endl;
        cout << "Book Name:" << disp -> bookName << endl;
        cout << "Book Author:" << disp -> auth << endl;
        cout << "Book Publisher:" << disp -> publ << endl;
        cout << "Book Status:" << getStatus() << endl;
        disp = disp -> next;
    }

    cout << "\n";
    cout << "Press Any Key to Return to Menu . . . ";
    getch();
    system("cls");

}

int main()
{
    Book a; // Create object of Book class
    a.menu();   //Call menu function
}
