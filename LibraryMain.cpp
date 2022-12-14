#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <cstring>

#include "Book.cpp"
#include "Student.cpp"

using namespace std;

char opt4;

int main()
{
    Book a; // Create object of Book class
    hashTableClass h1; //Create hash table for Student class

    system("cls");
    static char choice;
    bool exit = false;
    int delNo1,editNo1,sid,bid;
    string bname,bau,bpu,inputyn;

    //temporary variables for class student & borrow and return function

    int studentIdInt;
    string studentIdString;
    string studentName;

menuPage1:
    do{
    system("cls");
    cout << "\n\n\n\n\n";
    cout << "\t\t\t\t    =========================================================" << endl;
    cout << "\t\t\t\t    =============== LIBRARY MANAGEMENT SYSTEM ===============" << endl;
    cout << "\t\t\t\t    =========================================================" << endl;
    cout << "\n" << endl;
    cout << "\t\t\t\t\t 1. Add Book Record \t\t\t\t\t" << endl;
    cout << "\t\t\t\t\t 2. Display All Book Records \t\t\t\t\t" << endl;
    cout << "\t\t\t\t\t 3. Delete Book Record \t\t\t\t\t" << endl;
    cout << "\t\t\t\t\t 4. Edit Book Record \t\t\t\t\t" << endl;
    cout << "\t\t\t\t\t 5. Search Book Record \t\t\t\t\t" << endl;
    cout << "\t\t\t\t\t 6. Load Book Record \t\t\t\t\t" << endl;
    cout << "\t\t\t\t\t 7. Save Book Record \t\t\t\t\t" << endl;
    cout << "\t\t\t\t\t 8. Sort Book Record \t\t\t\t\t" << endl;
    cout << "\t\t\t\t\t a. Borrow Book \t\t\t\t\t" << endl;
    cout << "\t\t\t\t\t b. Return Book \t\t\t\t\t" << endl;
    cout << "\t\t\t\t\t 9. Next page \t\t\t\t\t" << endl;
    cout << "" << endl;
    cout << "\n";
    cout << "\t\t\t\t\t Enter Your Selection: ";
    cin >> choice;
    cin.sync(); //clear the input buffer;


    switch(choice)
    {
        case '1' :{
            system("cls");
            cout << "\n\n\n\n\n";
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\t\t\t\t    ===================== Add New Book ======================" << endl;
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\n";
            cout << "\t\t\t\t\t Book ID: " << a.size+1 << endl;
            cout << "\t\t\t\t\t Book Name: ";
            getline(cin,bname);
            cout << "\t\t\t\t\t Book Author: ";
            getline(cin,bau);
            cout << "\t\t\t\t\t Book Publisher: ";
            getline(cin,bpu);

            if(bname.empty() || bau.empty() || bpu.empty() ){
                cout << "\n\n\n\t\t\t\t\t Please Fill All the Information! . . . ";
                getch();
                break;
            }

            a.addBook(bname,bau,bpu);
            break;
        }

        case '2' :{
            system("cls");
            cout << "\n\n\n\n\n";
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\t\t\t\t    =================== All Book Records ====================" << endl;
            cout << "\t\t\t\t    =========================================================" << endl;
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
        }

        case '3' :{
            system("cls");
            cout << "\n\n\n\n\n";
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\t\t\t\t    =================== Delete Book Record ==================" << endl;
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\n";
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
        }

        case '4' :{
            system("cls");
            cout << "\n\n\n\n\n";
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\t\t\t\t    =================== Edit Book Record ====================" << endl;
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\n";
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
        }

        case '5' :{
            system("cls");
            cout << "\n\n\n\n\n";
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\t\t\t\t    =================== Search Book Record ==================" << endl;
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\n";
            a.searchBook();
            cout << "\n\n";



            getch();
            system("cls");
            break;
        }

        case '6' :{
            system("cls");
            cout << "\n\n\n\n\n";
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\t\t\t\t    =================== Load Book Record ====================" << endl;
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\n";
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
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\t\t\t\t    =================== Load Book Record ====================" << endl;
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\n";

            a.loadBook();
            getch();
            }else if(inputyn == "n"){
                system("cls");
                break;
            }

            system("cls");
            break;
        }

        case '7' :{
            system("cls");
            cout << "\n\n\n\n\n";
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\t\t\t\t    =================== Save Book Record ====================" << endl;
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\n";
            cout << "\t\t\tExisting Record That Haven't Been Load Will be Replaced If You Save to File" << endl;
            cout << "\n\t\t\t\t    Are You Sure You Want to Save Now ?(Enter y/n): ";

            cin >> inputyn;
            cin.sync();

            if(inputyn == "y"){

            system("cls");
            cout << "\n\n\n\n\n";
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\t\t\t\t    =================== Save Book Record ====================" << endl;
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\n";

            a.saveBook();
            getch();

            }else if(inputyn == "n"){
                system("cls");
                break;
            }

            system("cls");
            break;
        }

        case '8' :{
            system("cls");
            cout << "\n\n\n\n\n";
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\t\t\t\t    ======================= Sort Book =======================" << endl;
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\n";
            cout << "\t\t\t\t\t 1. Sort by Name \t\t\t\t\t" << endl;
            cout << "\t\t\t\t\t 2. Sort by Author \t\t\t\t\t" << endl;
            cout << "\t\t\t\t\t 3. Sort by ID \t\t\t\t\t" << endl;
            cout << "\t\t\t\t\t 4. Back to Menu \t\t\t\t\t" << endl;
            char c;
            cout << "\n";
            cout << "\t\t\t\t\t Enter Your Selection: ";
            cin >> c;
            cin.sync();

            switch(c)
            {
              case '1':
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "\t\t\t\t    =========================================================" << endl;
                cout << "\t\t\t\t    ===================== Sort Book Name ====================" << endl;
                cout << "\t\t\t\t    =========================================================" << endl;
                cout << "\n";
                a.sortBook();
                getch();
                system("cls");
                break;

              case '2' :
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "\t\t\t\t    =========================================================" << endl;
                cout << "\t\t\t\t    ==================== Sort Book Author ===================" << endl;
                cout << "\t\t\t\t    =========================================================" << endl;
                cout << "\n";
                a.sortAuthor();

                getch();
                system("cls");
                break;


              case '3':
                  system("cls");
                cout << "\n\n\n\n\n";
                cout << "\t\t\t\t    =========================================================" << endl;
                cout << "\t\t\t\t    ===================== Sort Book ID ======================" << endl;
                cout << "\t\t\t\t    =========================================================" << endl;
                cout << "\n";
                a.sortID();
                getch();
                system("cls");
                break;


              case '4':
                system("cls");
                break;
            }
            break;
            }

        case 'a' :{
            system("cls");
            cout << "\n\n\n\n\n";
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\t\t\t\t    ====================== Borrow Book ======================" << endl;
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\n";

            cout << "\t\t\t\t\t Enter Student ID: ";
            cin >> sid;

            if(cin.fail()){
                cin.clear();
                cin.ignore();
                cout << "\n\n\n";
                cout << "\t\t\t\t\t Invalid Input! Please Enter Number Only! . . . "<< endl;
                cout << "\t\t\t\t\t Press any button to return to main menu...";
                getch();
                system("cls");
                break;
            }

            if(h1.checkStudentId(sid) == false){
                getch();
                system("cls");
                break;
            }

            cout << "\t\t\t\t\t Enter Book ID that you want to borrow: ";
            cin >> bid;

            if(cin.fail()){
                cin.clear();
                cin.ignore();
                cout << "\n\n\n";
                cout << "\t\t\t\t\t Invalid Input! Please Enter Number Only! . . . "<<endl;
                cout << "\t\t\t\t\t Press any button to return to main menu...";
                getch();
                system("cls");
                break;
            }

            a.borrowBook(bid,sid);

            getch();
            system("cls");
            break;
            }


        case 'b' :{

            system("cls");
            cout << "\n\n\n\n\n";
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\t\t\t\t    ====================== Return Book ======================" << endl;
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\n";

            a.returnBook(bid);

            getch();
            system("cls");
            break;

            }

        case'9':{
            goto menuPage2;
            }
        }
    }while(!exit);{
    system("cls");
    cout << "\n\n\n\n\n";
    cout << "\t\t\t\t    =========================================================" << endl;
    cout << "\t\t\t\t    =============== LIBRARY MANAGEMENT SYSTEM ===============" << endl;
    cout << "\t\t\t\t    =========================================================" << endl;
    cout << "\n" << endl;
    cout<<"\t \t \t \t \t \t See You Next Time! \n\n\n\n"<<endl;
    }

menuPage2:
    do{
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "\t\t\t\t    =========================================================" << endl;
        cout << "\t\t\t\t    =============== LIBRARY MANAGEMENT SYSTEM ===============" << endl;
        cout << "\t\t\t\t    =========================================================" << endl;
        cout << "\n" << endl;
        cout << "\t\t\t\t\t 1. Add Student \t\t\t\t\t" << endl;
        cout << "\t\t\t\t\t 2. Display All Students \t\t\t\t\t" << endl;
        cout << "\t\t\t\t\t 3. Delete Student \t\t\t\t\t" << endl;
        cout << "\t\t\t\t\t 4. Search Student Record \t\t\t\t\t" << endl;
        cout << "\t\t\t\t\t 5. Save Student Record \t\t\t\t\t" << endl;
        cout << "\t\t\t\t\t 6. Load Student Record \t\t\t\t\t" << endl;
        cout << "\t\t\t\t\t 7. Previous Page \t\t\t\t\t" << endl;
        cout << "\t\t\t\t\t 0. Exit \t\t\t\t\t" << endl;
        cout << "" << endl;
        cout << "\n";
        cout << "\t\t\t\t\t Enter Your Selection: ";
        cin >> choice;
        cin.sync(); //clear the input buffer;

    switch(choice){

        case '1' :{

            system("cls");
            cout << "\n\n\n\n\n";
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\t\t\t\t    ================== Add Student Record ===================" << endl;
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\n";

            cout << "\t\t\t\t\t Student ID: ";
            getline(cin, studentIdString);

            cout << "\t\t\t\t\t Student Name: ";
            getline(cin, studentName);

            for (int i = 0; i < studentIdString.length(); i++) {
                if(isdigit(studentIdString[i]) == false){
                   cout << "\n\n\n";
                   cout << "\t\t\t\t\t Invalid Input! Please enter numeric digits for student ID!"<<endl;
                   cout << "\t\t\t\t\t Press any button to return to main menu...";
                   getch();
                   goto menuPage2;
                }
            }

            if(studentName.empty()){
                cout << "\n\n\n";
                cout << "\t\t\t\t\t Please fill in all of the blanks!"<<endl;
                cout << "\t\t\t\t\t Press any button to return to main menu...";
                getch();
                goto menuPage2;
            }else if(studentIdString == "0"){
                cout << "\n\n\n";
                cout << "\t\t\t\t\t Invalid Input! Please enter valid student ID!"<<endl;
                cout << "\t\t\t\t\t Press any button to return to main menu...";
                getch();
                goto menuPage2;
            }
            else{
                studentIdInt = stoi(studentIdString);
            }

            h1.addStudent(studentIdInt,studentName);
            getch();
            break;
        }

        case '2' :{
            system("cls");
            cout << "\Loading";
                for(int a = 1; a < 6; a++)
                    {
                        Sleep(500);
                        cout << "...";
                    }
            cout << "\33[2K\n\n\n\n";
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\t\t\t\t    ==================== Student Record =====================" << endl;
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\n ----------------------------------------------------------------------";
            cout << "\n ||     NO     ||     INDEX     ||      ID      ||       Name        ||";
            cout << "\n ----------------------------------------------------------------------";
            cout << "\n";

            h1.display();
            cout << "\n\n\nPress any button to continue..............";
            getch();
            system("cls");
            break;
        }

        case '3' :{
            system("cls");
            cout << "\n\n\n\n\n";
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\t\t\t\t    ================= Delete Student Record =================" << endl;
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\n";
            cout << "\t\t\t\t\t Enter the ID of the student record that you want to delete: ";
            cin >> delNo1;
            if(cin.fail()){
                cin.clear();
                cin.ignore();
                cout << "\n\n\n\n";
                cout << "\t\t\t\t\t Invalid Input! Please enter numeric digits only."<<endl;
                cout << "\t\t\t\t\t Press any button to return to main menu...";

            }else{
                h1.deleteStudent(delNo1);
            }

            getch();
            system("cls");
            break;
        }

        case '4' :{
            system("cls");
            cout << "\Loading";
                for(int a = 1; a < 6; a++)
                    {
                        Sleep(500);
                        cout << "...";
                    }
            do{
                system("cls");
                cout << "\33[2K\n\n\n\n";
                cout << "\t\t\t\t    =========================================================" << endl;
                cout << "\t\t\t\t    ================= Search Student Record =================" << endl;
                cout << "\t\t\t\t    =========================================================" << endl;
                cout << "\n";
                cout << "Please enter student ID: " ;

                while(!(cin >> studentIdInt)){
                    cout << "\n";
                    cout << "Invalid Input! Please enter student ID again: ";
                    cin.clear();
                    cin.ignore();
                }

                cout << "\nSearching";
                for(int a = 1; a < 6; a++)
                    {
                        Sleep(500);
                        cout << "...";
                    }

                cout << "\33[2K";

                h1.searchStudent(studentIdInt);

                cout << "\n\n";

                cout << "Do you want to search for another student?(y/n): " << endl;
                cin >> opt4;

                if(opt4 == 'n' || opt4 == 'N'){
                    cout << "\nReturning to Menu";
                    for(int a = 1; a < 6; a++)
                    {
                        Sleep(500);
                        cout << "...";
                    }
                    goto menuPage2;
                }

            }while(opt4 == 'y' || opt4 == 'Y');
            break;
        }

        case '5' :{
            system("cls");
            cout << "\n\n\n\n\n";
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\t\t\t\t    ================== Save Student Record ==================" << endl;
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\n";
            cout << "\t\t\tExisting Record That Haven't Been Load Will be Replaced If You Save to File" << endl;
            cout << "\n\t\t\t\t    Are You Sure You Want to Save Now ?(Enter y/n): ";
            cin >> inputyn;
            cin.sync();

            if(inputyn == "y"){

            system("cls");
            cout << "\n\n\n\n\n";
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\t\t\t\t    ================== Save Student Record ==================" << endl;
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\n";

            h1.saveStudent();
            getch();

            }else if(inputyn == "n"){
                system("cls");
                break;
            }

            system("cls");
            break;
        }



        case '6' :{
            system("cls");
            cout << "\n\n\n\n\n";
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\t\t\t\t    ================== Load Student Record ==================" << endl;
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\n";
            cout << "\t\t\tRecent Record That Haven't Been Saved Will No Longer Exist If You Load from File" << endl;
            cout << "\n\t\t\t\t    Are You Sure You Want to Load Now ?(Enter y/n): ";

            cin >> inputyn;
            cin.sync();

            if(inputyn == "y"){

            system("cls");
            h1.loadStudent();
            cout << "\n\n\n\n\n";
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\t\t\t\t    ================== Load Student Record ==================" << endl;
            cout << "\t\t\t\t    =========================================================" << endl;
            cout << "\n";

            cout << "\t\t\t\t\t Student list loaded successfully!";


            getch();
            }else if(inputyn == "n"){
                system("cls");
                break;
            }

            system("cls");
            break;
        }

        case '7' :{
            system("cls");
            goto menuPage1;
            break;
        }


        case '0' :{
            exit = true;
            break;
        }
        }
    }while(!exit);{
    system("cls");
    cout << "\n\n\n\n\n";
    cout << "\t\t\t\t    =========================================================" << endl;
    cout << "\t\t\t\t    =============== LIBRARY MANAGEMENT SYSTEM ===============" << endl;
    cout << "\t\t\t\t    =========================================================" << endl;
    cout << "\n" << endl;
    cout<<"\t \t \t \t \t \t See You Next Time! \n\n\n\n"<<endl;
    }
}

