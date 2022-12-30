#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
using namespace std;

class hashTableClass{

private:

    static const int HASHTABLESIZE = 101;  //Declaring the hash table size to a prime number can decrease the chances of collision

    struct student{                         //Structure named student used as nodes for hash table
        int id;
        string name;
        student * next;

    };

    student * hashTable[HASHTABLESIZE]; //Creates an array with the size of HASHTABLESIZE that contain pointers that points to student

public:

    hashTableClass(); //Constructor
    ~hashTableClass();
    int hashFunction(int key);
    void addStudent (int id, string name);
    void deleteStudent (int id);
    void display();
    void saveStudent();
    void loadStudent();
    void searchStudent(int id);
    bool checkStudentId(int id);

};

#endif
