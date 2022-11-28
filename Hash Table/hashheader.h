#include <iostream>
#include <string>

using namespace std;

#ifndef HASH_H
#define HASH_H

class hashClass{

    private:

        //Declaring static and const to prevent the table size from being changed
        //Table size is 97 which is a prime number to reduce chances of collision
        static const int tableSize = 97;

        //Declaring a struct which contains the parameter that we will store
        struct student{
            int id;
            string name;
            student * next;
        };

        //Creating hash table that contains a pointer
        student * hashTable[tableSize];

    public:
        hashClass();
        int hashFunction(int key);
        void addStudent (int key, string name);
        void deleteStudent (int key);



};


#endif // HASH_H
