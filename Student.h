#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
using namespace std;

class hashTableClass{

private:

    static const int HASHTABLESIZE = 97;

    struct student{
        int id;
        string name;
        student * next;

    };

    student * hashTable[HASHTABLESIZE]; //Creates a pointer that points to students with the size of HASHTABLESIZE

public:

    hashTableClass(); //Constructor
    int hashFunction(int key);
    void addStudent (int id, string name);
    void deleteStudent (int id);
    void display();
    void saveStudent();
    void loadStudent();
    void searchStudent(int id);
    void checkStudentId(int id);

};

#endif
