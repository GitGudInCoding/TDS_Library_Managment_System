#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>

#include "Book.cpp"
#include "Book.h"

using namespace std;

int main()
{
    Book a; // Create object of Book class

    system("cls");
    char choice;
    bool exit = false;
    int delNo1,editNo1;
    string bname,bau,bpu,inputyn;

    do{
    system("cls");
    cout << "\n\n\n\n\n";
    cout << "\t\t\t\t    ������������������������������������������������" << endl;
    cout << "\t\t\t\t    ���������� LIBRARY MANAGEMENT SYSTEM �����������" << endl;
    cout << "\t\t\t\t    ������������������������������������������������" << endl;
    cout << "\n" << endl;
    cout << "\t\t\t\t\t 1. Add Book Record \t\t\t\t\t" << endl;
    cout << "\t\t\t\t\t 2. Display All Book Records \t\t\t\t\t" << endl;
    cout << "\t\t\t\t\t 3. Delete Book Record \t\t\t\t\t" << endl;
    cout << "\t\t\t\t\t 4. Edit Book Record \t\t\t\t\t" << endl;
    cout << "\t\t\t\t\t 5. Search Book Record \t\t\t\t\t" << endl;
    cout << "\t\t\t\t\t 6. Load Book Record \t\t\t\t\t" << endl;
    cout << "\t\t\t\t\t 7. Save Book Record \t\t\t\t\t" << endl;
    cout << "\t\t\t\t\t 8. Sort Book By Name \t\t\t\t\t" << endl;
    cout << "\t\t\t\t\t 9. Sort Book By ID \t\t\t\t\t" << endl;
    cout << "\t\t\t\t\t 0. Exit \t\t\t\t\t" << endl;
    cout << "" << endl;
    cout << "\n";
    cout << "\t\t\t\t\t Enter Your Selection: ";
    cin >> choice;
    cin.sync(); //clear the input buffer;


    switch(choice)
    {
    case '1' :
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "\t\t\t\t    ������������������������������������������������" << endl;
        cout << "\t\t\t\t    ����������������� Add New Book �����������������" << endl;
        cout << "\t\t\t\t    ������������������������������������������������" << endl;
        cout << "\n";
        cout << "\t\t\t\t\t\t Book ID: " << a.size+1 << endl;
        cout << "\t\t\t\t\t\t Book Name: ";
        getline(cin,bname);
        cout << "\t\t\t\t\t\t Book Author: ";
        getline(cin,bau);
        cout << "\t\t\t\t\t\t Book Publisher: ";
        getline(cin,bpu);

        if(bname.empty() || bau.empty() || bpu.empty() ){
            cout << "\n\n\n\t\t\t\t\t Please Fill All the Information! . . . ";
            getch();
            break;
        }

        a.addBook(bname,bau,bpu);
        break;

    case '2' :
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "\t\t\t\t    ������������������������������������������������" << endl;
        cout << "\t\t\t\t    ��������������� All Book Records ���������������" << endl;
        cout << "\t\t\t\t    ������������������������������������������������" << endl;
        cout << "\n";

        gotoxy(5,10);
        cout << "| Book ID";
        gotoxy(15,10);
        cout << "| Book Name";
        gotoxy(40,10);
        cout <<  "| Book Author";
        gotoxy(60,10);
        cout << "| Book Publisher";
        gotoxy(80,10);
        cout  << "| Book Status";
        gotoxy(95,10);
        cout  << "| Borrower Student ID |" << endl;
        a.displayBook();
        getch();
        system("cls");
        break;

    case '3' :
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "\t\t\t\t    ������������������������������������������������" << endl;
        cout << "\t\t\t\t    �������������� Delete Book Record ��������������" << endl;
        cout << "\t\t\t\t    ������������������������������������������������" << endl;
        cout << "\n\n";
        cout << "\t\t\t\t    Enter Book ID that you want to delete: ";
        cin >> delNo1;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "\n\n\n\n";
            cout << "\t\t\t\t    Invalid Input! Please Enter Number Only! . . . ";

        }else{
            a.delBook(delNo1);
        }




        getch();
        system("cls");
        break;

    case '4' :
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "\t\t\t\t    ������������������������������������������������" << endl;
        cout << "\t\t\t\t    ��������������� Edit Book Record ���������������" << endl;
        cout << "\t\t\t\t    ������������������������������������������������" << endl;
        cout << "\n\n";
        cout << "\t\t\t\t    Enter Book ID that you want to edit: ";
        cin >> editNo1;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "\n\n\n\n";
            cout << "\t\t\t\t    Invalid Input! Please Enter Number Only! . . . ";

        }else{

        a.editBook(editNo1);

        }

        getch();
        system("cls");
        break;

    case '5' :
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "\t\t\t\t    ������������������������������������������������" << endl;
        cout << "\t\t\t\t    �������������� Search Book Record ��������������" << endl;
        cout << "\t\t\t\t    ������������������������������������������������" << endl;
        cout << "\n";
        a.searchBook();
        cout << "\n\n";



        getch();
        system("cls");
        break;

    case '6' :
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "\t\t\t\t    ������������������������������������������������" << endl;
        cout << "\t\t\t\t    ��������������� Load Book Record ���������������" << endl;
        cout << "\t\t\t\t    ������������������������������������������������" << endl;
        cout << "\n\n";
        cout << "\t\t\tRecent Record That Haven't Been Saved Will No Longer Exist If You Load from File" << endl;
        cout << "\n\t\t\t\t    Are You Sure You Want to Load Now ?(Enter y/n): ";

        cin >> inputyn;
        cin.sync();

        if(inputyn == "y"){

        for(int i = 1; i< a.size+1; i++ )
        {
            a.delBook(i);
        }
        a.size = 0;

        system("cls");
        cout << "\n\n\n\n\n";
        cout << "\t\t\t\t    ������������������������������������������������" << endl;
        cout << "\t\t\t\t    ��������������� Load Book Record ���������������" << endl;
        cout << "\t\t\t\t    ������������������������������������������������" << endl;
        cout << "\n\n";

        a.loadBook();
        getch();
        }else if(inputyn == "n"){
            system("cls");
            break;
        }

        system("cls");
        break;

    case '7' :
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "\t\t\t\t    ������������������������������������������������" << endl;
        cout << "\t\t\t\t    ��������������� Save Book Record ���������������" << endl;
        cout << "\t\t\t\t    ������������������������������������������������" << endl;
        cout << "\n\n";
        cout << "\t\t\tExisting Record That Haven't Been Load Will be Repalced If You Save to File" << endl;
        cout << "\n\t\t\t\t    Are You Sure You Want to Save Now ?(Enter y/n): ";

        cin >> inputyn;
        cin.sync();

        if(inputyn == "y"){

        system("cls");
        cout << "\n\n\n\n\n";
        cout << "\t\t\t\t    ������������������������������������������������" << endl;
        cout << "\t\t\t\t    ��������������� Save Book Record ���������������" << endl;
        cout << "\t\t\t\t    ������������������������������������������������" << endl;
        cout << "\n\n";

        a.saveBook();
        getch();

        }else if(inputyn == "n"){
            system("cls");
            break;
        }

        system("cls");
        break;

    case '8' :
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "\t\t\t\t    ������������������������������������������������" << endl;
        cout << "\t\t\t\t    ����������������� Sort Book Name ���������������" << endl;
        cout << "\t\t\t\t    ������������������������������������������������" << endl;
        cout << "\n\n";

        a.sortBook();

        getch();
        system("cls");
        break;

    case '9' :
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "\t\t\t\t    ������������������������������������������������" << endl;
        cout << "\t\t\t\t    ������������������ Sort Book ID ����������������" << endl;
        cout << "\t\t\t\t    ������������������������������������������������" << endl;
        cout << "\n\n";

        a.sortID();

        getch();
        system("cls");
        break;

    case '0' :
        exit = true;
        break;
        }
    }while(!exit);{
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n";
     cout << "\t\t\t\t    ������������������������������������������������" << endl;
    cout << "\t\t\t\t    ���������� LIBRARY MANAGEMENT SYSTEM �����������" << endl;
    cout << "\t\t\t\t    ������������������������������������������������" << endl;
    cout << "\n" << endl;
    cout<<"\t \t \t \t \t \t See You Next Time! \n\n\n\n"<<endl;
    }
}



