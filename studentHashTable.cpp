#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
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
    searchStudent(int id);

};

hashTableClass::hashTableClass(){ //Constructor

    for(int i = 0; i < HASHTABLESIZE; i++){

       hashTable[i] = new student;
       hashTable[i] -> id = 0;
       hashTable[i] -> name = "none";
       hashTable[i] -> next = NULL;
    }
}

int hashTableClass::hashFunction(int key){

    int index;
    index = key % HASHTABLESIZE;

    return index;
}

void hashTableClass::addStudent(int id, string name){

    int index = hashFunction(id);         //Calculate the index value based on the hash function

    if(id == 0){
        return;
    }

    if(hashTable[index] -> id == id && hashTable[index] -> name == name){
        return;
    }

    if(hashTable[index] -> id == 0){      //If the specific bucket is uninitialized, place the student ID and student in this bucket
        hashTable[index] -> id = id;
        hashTable[index] -> name = name;
    }else{
        student * ptr = hashTable[index]; // Point to the specific block based on the index given by hash function
        student * temp = new student;     // Create a new pointer which points a student node (currently unrelated to the original array)
        temp -> id = id;                  // Insert the ID provided by the user to the student node
        temp -> name = name;              // Insert the name provided by the user to the student node
        temp -> next = NULL;              // Declare the next pointer as NULL as there is nothing link to the back of it


        while(ptr->next != NULL){         // Traverse through the chain of the specific block
            ptr  = ptr->next;

            if(ptr-> id == id && ptr-> name == name){
                return;
            }
        }

        ptr -> next = temp;                   // Make the next pointer of the last node point to the student node we created just now
    }


    cout << "Student " << name << " added." << endl;

}

void hashTableClass::deleteStudent(int id){

     //Use hash function to calculate the index number of the item
    //Store the calculated index number in var "index"
    int index = hashFunction(id);

    student * delPtr;
    student * p1;
    student * p2;

    //Case 0 - the entire hash table is empty

    if(hashTable[index]->id == 0){
        cout << id << " was not found in the Hash Table\n";
    }

    //Case 1 - hash table has only 1 student and it matches

    else if(hashTable[index] -> id == id && hashTable[index]->next == NULL){

        hashTable[index]-> id = 0;
        hashTable[index]-> name = "none";

        cout << id << " was removed from the Hash Table\n";
    }

    //Case 2 - hash table have many items and first student matches

    else if(hashTable[index] -> id == id){
        delPtr = hashTable[index];
        hashTable[index] = hashTable[index] -> next;
        delete delPtr;

        cout << id << " was removed from the Hash Table\n";
    }

    //Case 3 - hash table have many items and first student cannot match

    else{
        p1 = hashTable[index]->next;
        p2 = hashTable[index];

        while(p1 != NULL && p1->id != id){

            p2 = p1;
            p1 = p1->next;
        }

      //Case 3.1 - no match

        if(p1 == NULL){
            cout << id << " was not found in the Hash Table\n";
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
            cout << id << " was removed from the Hash Table\n";
        }
    }
}

void hashTableClass::display(){                                                             //Display contents of the hash table

    student * tempPtr;                                                                 //Declare a temporary pointer to traverse the linked list


    cout << "Display Student:" << endl;

    for(int i=0; i<10; i++){                                                            //Use a for loop to traverse the entire hash table
        cout << "Index " << i << endl;
        tempPtr = hashTable[i];                                                         // Let the temporary pointer point to the first index of the hash table
        cout << tempPtr -> id <<endl;
        cout << tempPtr -> name <<endl;

        while(tempPtr -> next != NULL){                                                    //Checking if the bucket under that index have extra student nodes
            tempPtr = tempPtr -> next;                                                  //If yes, use the temporary pointer to traverse the linked list
            cout << tempPtr -> id <<endl;
            cout << tempPtr -> name <<endl;
        }

    }

}

void hashTableClass::saveStudent(){

    student * tempPtr;                                                                  //Declare a temporary pointer to traverse the linked list

    ofstream saveStudentFile("student.txt", ios::out);                                 // ofstream to output the content of the hash table to a text file

    if(!saveStudentFile.is_open()){
        cout << "Error opening file!" << endl;
    }

    for(int i=0; i<HASHTABLESIZE; i++){                                                // Traversing the entire hash table
            tempPtr = hashTable[i];                                                     // Points to the first element of the hash table

            saveStudentFile << "Index :" << i <<endl;                                   // Indicate the index of bucket
            saveStudentFile << tempPtr -> id << " " << tempPtr -> name  <<endl;         // Output the student ID and name to the text file

        while(tempPtr->next != NULL){                                                      // Checking if the bucket under that index have extra student nodes
            tempPtr = tempPtr -> next;                                                  // If yes, use the temporary pointer to traverse the linked list
            saveStudentFile << tempPtr -> id << " " << tempPtr -> name <<endl;          // Output the student ID and name to the text file
        }

    }

    saveStudentFile.close();                                                            //Close the file before exiting the function

    cout << "Student list saved successfully!" << endl;
}

void hashTableClass::loadStudent(){

    int tempId;
    string tempName;
    string tempLine;

    ifstream loadStudentFile("student.txt");

    if(!loadStudentFile.is_open()){
        cout << "Error opening file!" << endl;
    }

    while(getline(loadStudentFile,tempLine)){

        if (tempLine.find("Index")==tempLine.npos){

            istringstream linestream(tempLine);
            linestream >> tempId >> tempName;

            addStudent(tempId,tempName);

        }

    }

    loadStudentFile.close();

    cout << "Student list loaded successfully!" << endl;

}

hashTableClass::searchStudent(int id){

    int index = hashFunction(id);

    if(hashTable[index] -> id == id){
        cout << "Student found at " << index << "th place." << endl;
        cout << "Student ID: " << hashTable[index] -> id << endl;
        cout << "Student Name: " << hashTable[index] -> name << endl;
    }else{
        student * ptr = hashTable[index];
        while(ptr->next != NULL){
            ptr  = ptr->next;
        }
    }

}

int main(){

    hashTableClass h1;

    cout << "add student:" << endl;
    h1.addStudent(97,"Ali");
    h1.addStudent(98,"Abu");
    h1.addStudent(194,"May");
    h1.addStudent(291,"June");
    h1.addStudent(195,"Akau");
    h1.addStudent(196,"Ako");
    h1.addStudent(197,"Atan");
    h1.display();

    cout << "load student:" <<endl;
    h1.loadStudent();
    h1.display();

    cout << "save student:" <<endl;
    h1.saveStudent();
    h1.display();

    return 0;
}
