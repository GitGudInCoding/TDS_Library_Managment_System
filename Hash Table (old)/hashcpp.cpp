#include <iostream>
#include <string>

#include "hashheader.h"

using namespace std;


//Constructor (initialize the hash table)
hashClass::hashClass(){

    for(int i = 0; i < tableSize; i++){

       hashTable[i] = new student;
       hashTable[i] -> id = 0;
       hashTable[i] -> name = "none";
       hashTable[i] -> next = NULL;
    }

}


//Hash Function (divide by table size)
int hashClass::hashFunction(int key){

    int index;
    index = key % tableSize;

    return index;

}

//Add Function
void hashClass::addStudent(int key, string name){

    int index = hashFunction(key);

    //If the place is empty, add the id and name
    if(hashTable[index]-> id == 0){
        hashTable[index] -> id = key;
        hashTable[index] -> name = name;
    //If it is not, add a new student
    }else{
        student * ptr = hashTable[index];
        student * temp = new student;
        temp -> id = key;
        temp -> name = name;
        temp -> next = NULL;

        //Traversing through the entire list until there is an empty space
        while(ptr->next != NULL){
            ptr  = ptr->next;
        }
        //Place the new student in the empty space
        ptr ->next = temp;


    }
}

//Delete Function
void hashClass::deleteStudent (int key){

    //Use hash function to calculate the index number of the item
    //Store the calculated index number in var "index"
    int index = hashFunction(key);

    student * delPtr;
    student * p1;
    student * p2;

    //Case 0 - hash table is empty

    if(hashTable[index]->id == 0){
        cout << key << "was not found in the Hash Table\n";
    }

    //Case 1 - hash table has only 1 student and it matches

    else if(hashTable[index] -> id == key && hashTable[index]->next == NULL){

        hashTable[index]-> id = 0;
        hashTable[index]-> name = "none";

        cout << key << "was removed from the Hash Table\n";
    }

    //Case 2 - hash table have many items and first student matches

    else if(hashTable[index] -> id == key){
        delPtr = hashTable[index];
        hashTable[index] = hashTable[index] -> next;
        delete delPtr;

        cout << key << "was removed from the Hash Table\n";
    }

    //Case 3 - hash table have many items and first student cannot match

    else{
        p1 = hashTable[index]->next;
        p2 = hashTable[index];

        while(p1 != NULL && p1->id != key){

            p2 = p1;
            p1 = p1->next;
        }

      //Case 3.1 - no match

        if(p1 == NULL){
            cout << key << "was not found in the Hash Table\n";
        }

    //Case 3.2 - match

        else{
            //delPtr points to p1 (the one we want to delete)
            delPtr = p1;
            //p1 moves to the next place
            p1 = p1->next;
            //p2 next pointer pointing to current place of p1 (which is p1->next)
            p2->next = p1;
            //Only delPtr is pointing to the one we want to delete at this step

            delete delPtr;
            cout << key << "was removed from the Hash Table\n";
        }
    }




}
