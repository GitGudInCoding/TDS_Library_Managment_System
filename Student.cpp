#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Student.h"
using namespace std;



hashTableClass::hashTableClass(){ //Constructor

    for(int i = 0; i < HASHTABLESIZE; i++){             //Initializing an array based on HASHTABLESIZE

       hashTable[i] = new student;
       hashTable[i] -> id = 0;
       hashTable[i] -> name = "none";
       hashTable[i] -> next = NULL;
    }
}

hashTableClass::~hashTableClass(){

    for(int i=0; i<HASHTABLESIZE; i++){                  //Traverse through the hash table to deallocate student structure created by "new"
        student * delPtr = hashTable[i];

        while(delPtr -> next != NULL){
            delete delPtr;
            delPtr = delPtr ->next;
        }
        delete delPtr;
    }

}


int hashTableClass::hashFunction(int key){

    int index;
    index = key % HASHTABLESIZE;

    return index;
}

void hashTableClass::addStudent(int id, string name){   //Add student to the hash table, collision are handled by using separate chaining

    int index = hashFunction(id);         //Calculate the index value based on the hash function

    if(id == 0 && name == "none"){                                                //Exception handling: Invalid ID and name format
        cout << "\n\n\n";
        cout << "\t\t\t\t\t Please enter valid ID and name format!"<<endl;
        cout << "\t\t\t\t\t Press any button to return to main menu...";
        return;
    }

    if (hashTable[index] -> id == id){                                            //Exception handling: repeated student ID

        cout << "\n\n\n";
        cout << "\t\t\t\t\t This ID have been registered in the system!"<<endl;
        cout << "\t\t\t\t\t Press any button to return to main menu...";
        return;
    }

    if(hashTable[index] -> id == 0 ){      //If the specific bucket is uninitialized, place the student ID and student in this bucket
        hashTable[index] -> id = id;
        hashTable[index] -> name = name;

        cout << "\n\n\n";
        cout << "\t\t\t\t\t Student " << name <<" added successfully!"<<endl;
        cout << "\t\t\t\t\t Press any button to return to main menu...";

    }else{
        student * ptr = hashTable[index]; // Point to the specific block based on the index given by hash function
        student * temp = new student;     // Create a new pointer which points a student node (currently unrelated to the original array)
        temp -> id = id;                  // Insert the ID provided by the user to the student node
        temp -> name = name;              // Insert the name provided by the user to the student node
        temp -> next = NULL;              // Declare the next pointer as NULL as there is nothing link to the back of it


        while(ptr->next != NULL){         // Traverse through the chain of the specific block
            ptr = ptr->next;

            if(ptr-> id == id){             //Exception handling: repeated student ID in chaining
                cout << "\n\n\n";
                cout << "\t\t\t\t\t This ID have been registered in the system!"<<endl;
                cout << "\t\t\t\t\t Press any button to return to main menu...";
                return;
            }
        }

    ptr -> next = temp;                   // Make the next pointer of the last node point to the student node we created just now
    cout << "\n\n\n";
    cout << "\t\t\t\t\t Student " << name <<" added successfully!"<<endl;
    cout << "\t\t\t\t\t Press any button to return to main menu...";

    }
}

void hashTableClass::deleteStudent(int id){     //Delete student in hash table

     //Use hash function to calculate the index number of the item
    //Store the calculated index number in var "index"
    int index = hashFunction(id);

    student * delPtr;
    student * p1;
    student * p2;

    //Case 0 - the entire hash table is empty

    if(hashTable[index]->id == 0){
        cout << "\n\n\n";
        cout << "\t\t\t\t\t Student with ID of "<< id << " was not found in the system."<< endl;
        cout << "\t\t\t\t\t Press any button to return to main menu...";
    }

    //Case 1 - hash table has only 1 student and it matches

    else if(hashTable[index] -> id == id && hashTable[index]->next == NULL){

        hashTable[index]-> id = 0;
        hashTable[index]-> name = "none";

        cout << "\n\n\n";
        cout << "\t\t\t\t\t Student with ID of "<< id << " was deleted successfully."<<endl;
        cout << "\t\t\t\t\t Press any button to return to main menu...";
    }

    //Case 2 - hash table have many items and first student matches

    else if(hashTable[index] -> id == id){
        delPtr = hashTable[index];
        hashTable[index] = hashTable[index] -> next;
        delete delPtr;

        cout << "\n\n\n";
        cout << "\t\t\t\t\t Student with ID of "<< id << " was deleted successfully."<<endl;
        cout << "\t\t\t\t\t Press any button to return to main menu...";
    }

    //Case 3 - hash table have many items and first student cannot match

    else{
        p1 = hashTable[index]->next;            //using 2 pointers to traverse the index's linked list
        p2 = hashTable[index];

        while(p1 != NULL && p1->id != id){

            p2 = p1;
            p1 = p1->next;
        }

      //Case 3.1 - unable to found the specific id in the index's linked list

        if(p1 == NULL){
            cout << "\n\n\n";
            cout << "\t\t\t\t\t Student with ID of " << id << " was not found in the system."<<endl;
            cout << "\t\t\t\t\t Press any button to return to main menu...";
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
            cout << "\n\n\n";
            cout << "\t\t\t\t\t Student with ID of " << id << " was deleted successfully."<<endl;
            cout << "\t\t\t\t\t Press any button to return to main menu...";
        }
    }
}

void hashTableClass::display(){                 //Display students records in the hash table

    int counter;
    int num = 1;

    student * ptr;

    for(int i = 0; i < HASHTABLESIZE; i++){
        if(hashTable[i] -> id != 0 && hashTable[i] != NULL){
            cout << "\t" << num++;
            cout << "\t\t" << i;
            cout << "\t\t" << hashTable[i] -> id;
            cout << "\t\t" << hashTable[i] -> name;
            cout << "\n" ;

            counter++;

            ptr = hashTable[i];


            if(ptr -> next != NULL){
                ptr = ptr -> next;
                cout << "\t" << num++;
                cout << "\t\t" << i;
                cout << "\t\t" << ptr -> id;
                cout << "\t\t" << ptr -> name;
                cout << "\n" ;
                counter++;
            }
        }
    }
    if(counter == 0){
        cout << "\n No student in the list" << endl;
    }
    else{
        cout << "\n Number of student = " << counter << endl;
    }
}

void hashTableClass::searchStudent(int id){     //Search student in hash table

    int i = hashFunction(id);
    bool foundStudent = false;

    student * ptr = hashTable[i];

    if(ptr != NULL){
    while(ptr != NULL){
        if(ptr -> id == id){
            cout << " \33[2K \n\t\t\t\t\t-------- Student Information -------" << endl;
            cout << "\n";
            cout << "\t\t\t\t\t Student ID: " << ptr -> id << endl;
            cout << "\t\t\t\t\t Student Name: " << ptr-> name << endl;
            cout << "\t\t\t\t\t Student Found!" << endl;
            foundStudent = true;
        }
        ptr  = ptr->next;
        }
    }

        if(!foundStudent){
            cout << "\n\t\t\t\t\t No student found" << endl;
        }
     }

void hashTableClass::saveStudent(){             //Save student records to an external text file

    student * tempPtr;                                                                  //Declare a temporary pointer to traverse the linked list

    ofstream saveStudentFile("student.txt", ios::out);                                 // ofstream to output the content of the hash table to a text file

    if(!saveStudentFile.is_open()){                                                     //Exception handling: file is open
        cout << "\n\n\n";
        cout << "\t\t\t\t\t Error opening file!" << endl;
        cout << "\t\t\t\t\t Press any button to return to main menu...";
    }

    for(int i=0; i<HASHTABLESIZE; i++){                                                // Traversing the entire hash table
            tempPtr = hashTable[i];                                                     // Points to the first element of the hash table

            saveStudentFile << "Index :" << i <<endl;                                   // Indicate the index of bucket
            saveStudentFile << tempPtr -> id << " " << tempPtr -> name  <<endl;         // Output the student ID and name to the text file

        while(tempPtr->next != NULL){                                                   // Checking if the bucket under that index have extra student nodes
            tempPtr = tempPtr -> next;                                                  // If yes, use the temporary pointer to traverse the linked list
            saveStudentFile << tempPtr -> id << " " << tempPtr -> name <<endl;          // Output the student ID and name to the text file
        }

    }

    saveStudentFile.close();                                                            //Close the file before exiting the function

    cout << "\n\n\n";
    cout << "\t\t\t\t\t Student list saved successfully!"<<endl;
    cout << "\t\t\t\t\t Press any button to return to main menu...";
}

void hashTableClass::loadStudent(){

    int tempId;
    string tempName;
    string tempLine;

    ifstream loadStudentFile("student.txt");

    if(!loadStudentFile.is_open()){
        cout << "\n\n\n";
        cout << "\t\t\t\t\t Error opening file!" << endl;
        cout << "\t\t\t\t\t Press any button to return to main menu...";
    }

    while(getline(loadStudentFile,tempLine)){

        if (tempLine.find("Index")==tempLine.npos){

            istringstream linestream(tempLine);
            linestream >> tempId >> tempName;

            addStudent(tempId,tempName);

        }

    }

    loadStudentFile.close();
    system("cls");
}

bool hashTableClass::checkStudentId(int id){

    if(id == 0){                                                //Exception handling: Invalid ID format
        cout << "\n\n\n";
        cout << "\t\t\t\t\t Invalid ID! Please enter ID with correct format."<<endl;
        cout << "\t\t\t\t\t Press any button to return to main menu...";
        return 0;
    }

    for(int i=0; i<HASHTABLESIZE; i++){                         //Traverse through the hash table to check if the student exist in the system

        student * temp = hashTable[i];

        if(temp->id == id){
            return 1;

        }else{

            while(temp->next != NULL){
                temp = temp -> next;

                if(temp->id == id){
                    return 1;
                }

            }
        }
    }
    cout << "\n\n\n";
    cout << "\t\t\t\t\t Student with this ID does not exist in the system."<< endl;
    cout << "\t\t\t\t\t Press any button to return to main menu...";
    return 0;
}



