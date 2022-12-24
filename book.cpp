#include <iostream>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <string>
#include <cctype>

#include "Book.h"

using namespace std;

//TABLE POSITIONING FUNCTION
void gotoxy(short x,short y){
COORD p={x,y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}

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




string Book::getStatus() const
{
    if(disp -> stat==1){
        return "Available";
    }else{
        return "Unavailable";
    }
}

void Book::addBook(string bname1, string bau1, string bpu1)
{
    BookNode *newPtr = new BookNode;
    size = size+1;
    newPtr -> bookID = size;
    newPtr -> bookName = bname1;
    newPtr -> auth = bau1;
    newPtr -> publ = bpu1;
    newPtr -> stat = true;
    newPtr -> stuID = NULL;
    newPtr -> next = NULL;



    if(head==NULL){
        temp = newPtr;
        head = temp;
    }else{
        temp -> next = newPtr;
        temp = newPtr;
    }

    cout << "\n";
    cout << "\t\t\t\t\t Book Added Successfully! . . . ";
    getch();
    system("cls");

}

void Book::delBook(int delNo)
{

    if(head==NULL)
    {
        cout << "\n\n";
        cout<<"\t\t\t\t\t\t Book Record is Empty!\n";
    }
    else
    {
        BookNode *prev = head;
        BookNode *delp = head;
        int df = 0;



                if(delp->bookID == delNo){
                head = delp -> next;
                delete(delp);

                df = df+1;
                cout << "\n\n\n\n";
                cout << "\t\t\t\t\t Book Record Successfully Deleted! . . . ";

                }else if(delNo > getSize()-1){
                    while( delp -> next != NULL)
                    {
                        prev = delp;
                        delp = delp -> next;

                        if(delNo == delp-> bookID)
                        {
                             prev -> next = NULL;
                             delete(delp);
                             df=df+1;
                             temp = prev;


                             cout << "\n\n\n\n";
                             cout << "\t\t\t\t\t Book Record Successfully Deleted! . . . ";


                        }


                    }
                }
                else
                {
                    while( delp -> next != NULL)
                    {
                        prev = delp;
                        delp = delp -> next;

                        if(delNo == delp-> bookID)
                        {
                             prev -> next = delp -> next;
                             delete(delp);
                             df =df+1;
                             cout << "\n\n\n\n";
                             cout << "\t\t\t\t\t Book Record Successfully Deleted! . . . ";



                        }

                    }

                }
        if(df==0){
             cout << "\n\n";
             cout << "\t\t\t\t\t\t No Record Found! . . . ";
        }
    }



}

void Book::editBook(int editNo)
{

    if(head==NULL)
    {
         cout << "\n\n";
         cout<<"\t\t\t\t\t\t Book Record is Empty!\n";

    }
    else
    {

    BookNode *edip = head;

    if((editNo < head -> bookID) || (editNo > size)){
        cout << "\n\n";
        cout << "\t\t\t\t\t\t No Record Found! . . . ";



    }else{
     while(edip != NULL){
            if(editNo == edip -> bookID){
                string bname1,bau1,bpu1;
                cout << "\n";
                cout << "Book ID: " << edip -> bookID  << endl;
                cout << "Book Name: ";
                cin.ignore();
                getline(cin,bname1);
                cout << "Book Author: ";
                getline(cin,bau1);
                cout << "Book Publisher: ";
                getline(cin,bpu1);

                if(bname1.empty() || bau1.empty() || bpu1.empty() ){
                cout << "\n\n\n\t\t\t\t\t Please Fill All the Information! . . . ";
                break;
                }
                edip -> bookName = bname1;
                edip -> auth = bau1;
                edip -> publ = bpu1;
                cout << "\n\n\n\n";
                cout << "\t\t\t\t\t Book Record Edited Successfully ! . . . ";
            }
        edip = edip -> next;
        }



    }

   }
}

void Book::searchBook()
{
    if(head==NULL)
    {
         cout << "\n\n";
         cout<<"\t\t\t\t\t\t Book Record is Empty!\n\n\n\n\n\n";
    }
    else
    {
        int found = 0;
        string bname;
        disp = head;
        cout << "\t\t\t\t    Enter Book Name that you want to search: ";
        getline(cin,bname);
        int x1 = 7;
        int y1 = 14;
        while(disp != NULL){
                if(disp -> bookName.find(bname) != string::npos){

                    gotoxy(5,12);
                    cout << "| Book ID";
                    gotoxy(15,12);
                    cout << "| Book Name";
                    gotoxy(40,12);
                    cout <<  "| Book Author";
                    gotoxy(60,12);
                    cout << "| Book Publisher";
                    gotoxy(80,12);
                    cout  << "| Book Status";
                    gotoxy(95,12);
                    cout  << "| Borrower Student ID |" << endl;

                    gotoxy(x1,y1);
                    cout << disp -> bookID;
                    gotoxy(x1+10,y1);
                    cout << disp -> bookName;
                    gotoxy(x1+35,y1);
                    cout << disp -> auth;
                    gotoxy(x1+55,y1);
                    cout << disp -> publ;
                    gotoxy(x1+75,y1);
                    cout << getStatus();



        gotoxy(x1+90,y1);
        if(disp -> stat == false){
            cout << disp -> stuID << endl;
            }else{
            cout << "None" << endl;
            }
        y1 = y1+1;

                   found++;
                }
            disp = disp -> next;
        }

        if(found == 0){

            cout << "\n\n";
            cout << "\t\t\t\t\t   No Book Record Found! . . . ";

        }else{

        cout << "\n\n";
        cout << "\t\t\t\t " <<found << " Record Found! Press Any Key to Return to Menu . . . ";
        }
    }
}

void Book::displayBook()
{
    disp = head;
    if(disp==NULL){
        cout<<"\n\n\n\n\n\t\t\t\t\t\t Book Record is Empty!\n";
    }
    int x1 = 7;
    int y1 = 13;
    while(disp != NULL){

        gotoxy(x1,y1);
        cout << disp -> bookID;
        gotoxy(x1+10,y1);
        cout << disp -> bookName;
        gotoxy(x1+35,y1);
        cout << disp -> auth;
        gotoxy(x1+55,y1);
        cout << disp -> publ;
        gotoxy(x1+75,y1);
        cout << getStatus();



        gotoxy(x1+90,y1);
        if(disp -> stat == false){
            cout << disp -> stuID << endl;
            }else{
            cout << "None" << endl;
            }
        y1 = y1+1;

        disp = disp -> next;

    }

    cout << "\n\n\n\n\n";
    cout << "\t\t\t\t\t Press Any Key to Return to Menu . . . ";


}

void Book::loadBook()
{
    ifstream input;
    input.open("BookSave.txt");
    if(!input.is_open()){
        cout<< "Error Open File!";
    }

    int bid,sid;
    string bn,au,pu;
    bool stat;

    string inputLine;

    while(getline(input,inputLine))
    {
        stringstream ss(inputLine); //convert from string to int or bool, the stringstream is to treat a string as a stream and perform insertion just like cin.
        ss >>  bid;
        getline(input,bn);

        getline(input,au);

        getline(input,pu);

        getline(input,inputLine);
        ss.clear();
        ss.str(inputLine); //set the content of the stringstream to a new string
        ss >> stat;

        getline(input,inputLine);
        ss.clear();
        ss.str(inputLine);
        ss >> sid ;

        BookNode *newPtr = new BookNode;
        size = size+1;
        newPtr -> bookID = size;
        newPtr -> bookName = bn;
        newPtr -> auth = au;
        newPtr -> publ = pu;
        newPtr -> stat = stat;
        newPtr -> stuID = sid;
        newPtr -> next = NULL;

        if(head==NULL){
            temp = newPtr;
            head = temp;
        }else{
            temp -> next = newPtr;
            temp = newPtr;
        }

    }

    cout << "\n\n\n\n";
    cout << "\t\t\t\t\t Book Records Successfully Loaded! . . . " << endl;




}

void Book::saveBook()
{
    ofstream output;
    output.open("BookSave.txt");
    if(!output.is_open()){
        cout<< "Error Open File!";
    }

    BookNode *savb;
    savb = head;

    while(savb !=NULL){
        output << savb -> bookID << endl;
        output << savb -> bookName << endl;
        output << savb -> auth << endl;
        output << savb -> publ << endl;
        output << savb -> stat << endl;
        output << savb -> stuID << endl;

        savb = savb -> next;
    }

    cout << "\n\n\n\n";
    cout << "\t\t\t\t\t Book Records Successfully Saved! . . . " << endl;



}

void Book::sortBook(){ // Sort book name using bubble sort

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

    cout << "\n\n\n\n";
    cout << "\t\t\t\t   Book Records Successfully Sorted by Book Name! . . . " << endl;

}

void Book::sortID(){

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
            if(ptr -> bookID > ptr -> next -> bookID)
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
    cout << "\n\n\n\n";
    cout << "\t\t\t\t   Book Records Successfully Sorted by Book ID! . . . " << endl;


}

void Book::borrowBook()
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
        int bid;
        disp = head;
        cout << "Enter Book ID that you want to borrow: ";
        cin >> bid;
        BookNode *borrow1 = head;
        while(borrow1 != NULL){
                if(bid == borrow1 -> bookID ){
                cout << "The Book Details" << endl;
                   cout << "Book ID: " << borrow1 -> bookID << endl;
                   cout << "Book Name:" << borrow1 -> bookName << endl;
                   cout << "Book Author:" << borrow1 -> auth << endl;
                   cout << "Book Publisher:" << borrow1-> publ << endl;
                   cout << "Book Status:" << getStatus() << endl;


                   char response;
                    cout <<"\n";
                    cout << "Do you want to borrow book(y/n): ";
                    cin >> response;

                if (response =='y')
                  {
                    borrow1->stat = false;
                    cout << "\n";
                    cout << "Borrow successful..";
                }
               else{
                cout << "Borrow cancel";
               }
            }
            borrow1 = borrow1 -> next;

        }
    }
}



void Book::returnBook()
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
        char response;
                    cout <<"\n";
                    cout << "Do you want to return book(y/n): ";
                    cin >> response;

                if (response =='y')
                  {

        int bid;
        disp = head;
        cout << "Enter Book ID that you want to return: ";
        cin >> bid;
        BookNode *return1 = head;
        while(return1 != NULL){
                if(bid == return1 -> bookID && return1->stat == false){
                cout << "The Book Details" << endl;
                   cout << "Book ID: " << return1 -> bookID << endl;
                   cout << "Book Name:" << return1 -> bookName << endl;
                   cout << "Book Author:" << return1 -> auth << endl;
                   cout << "Book Publisher:" << return1-> publ << endl;
                   cout << "Book Status:" << getStatus() << endl;


                if (return1->stat == false){
                   return1->stat = true;
                    cout << "\n";
                    cout << "Return successful..";

                    }else{
                        cout << "\n";
                        cout <<" This book is still available. cannot return";
                        break;
                    }
                }


           return1 = return1 -> next;
        }

        }else {
            cout << "Return book cancel";
        }

    cout << "\n";
    cout << "Press Any Key to Return to Menu . . . ";
    getch();
    system("cls");

                  }
 }


int Book::getSize(){
    disp=head;
    int gs = 0;
    if(head==NULL){
        return gs;
    }else{
    while(disp != NULL){
        disp = disp -> next;
        gs = gs+1;
    }
    return gs;
    }
}




