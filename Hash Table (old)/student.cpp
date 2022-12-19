#include <iostream>
#include<fstream>
#include <string>
using namespace std;

class Student{

    private:
        int studentID;
        string studentName;


    Student(int sid, string sn){

         studentID = sid;
         studentName = sn;

    }

};

void loadStudent(){

    //Declaring the size for the 2D array
    const int m = 4, n = 5;


    //Declare a 2D array to load student details from text file
    string arr[m][n];

    //Opening the text file by using fstream library
    fstream txtFile;
    txtFile.open("student.txt");

    //Read from the text file
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            txtFile >> arr[i][j];
        }
    }

    txtFile.close();

    //Print
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    /*
    txtFile.open("student.txt",ios::in);
    if(txtFile.is_open()){
        string line;
        while(getline(txtFile,line)){
            cout << line << endl;
        }
        txtFile.close();

    }
    */
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
