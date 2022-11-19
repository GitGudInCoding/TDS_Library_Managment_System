#include <iostream>
#include<fstream>
#include <string>
using namespace std;

class Student{

    public:
        int studentID;
        string studentName;
        int studentContactNo;
        string studentEmail;
        string studentMajor;

    Student(int sid, string sn, int scn, string se, string sm){

         studentID = sid;
         studentName = sn;
         studentContactNo = scn;
         studentEmail = se;
         studentMajor = sm;

    }

};

void loadStudent(){

    fstream txtFile;

    txtFile.open("student.txt",ios::in);//read
    if(txtFile.is_open()){
        string line;
        while(getline(txtFile,line)){
            cout << line << endl;
        }
        txtFile.close();

    }
}

int main(){

    loadStudent();
}






/*
fstream myFile;

    myFile.open("student.txt",ios::in);//read
    if(myFile.is_open()){
        string line;
        while(getline(myFile,line)){
            cout << line << endl;
        }
        myFile.close();
    }
*/
