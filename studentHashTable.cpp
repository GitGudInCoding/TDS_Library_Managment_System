#include <iostream>
#include<string>
#include <fstream>
#include <sstream>
using namespace std;

class hashTableClass{

private:

    static const int HASHTABLESIZE = 97;
    static const int STUDENTATTR = 2;

    struct student{
        int id;
        string name;
        student * next;

    };

    student * hashTable[HASHTABLESIZE]; //Creates a pointer that points to students with the size of HASHTABLESIZE

public:

    hashTableClass(); //Constructor
    int hashFunction(int key);
    addStudent (int key, string name);
    deleteStudent (int key);
    display();
    saveStudent();
    loadStudent();

};

hashTableClass::hashTableClass(){ //Constructor

    for(int i = 0; i < HASHTABLESIZE; i++){

       hashTable[i] = new student;
       hashTable[i] -> id = 0;
       hashTable[i] -> name = "none";
       hashTable[i] -> next = NULL;
    }
}

hashTableClass::hashFunction(int key){

    int index;
    index = key % HASHTABLESIZE;

    return index;
}

hashTableClass::addStudent(int id, string name){

    int index = hashFunction(id);

    if(hashTable[index] -> id == 0){
        hashTable[index] -> id = id;
        hashTable[index] -> name = name;
    }else{
        student * ptr = hashTable[index]; // Point to the specific block based on the index given by hash function
        student * temp = new student;    // Create a new pointer which points a student struct (currently unrelated to the original array)
        temp -> id = id;                // Insert the ID provided by the user to the student struct
        temp -> name = name;             // Insert the name provided by the user to the student struct
        temp -> next = NULL;             // Declare the next pointer as NULL as there nothing link to the back of i


        while(ptr->next != NULL){           // Traverse the entire linked list until there is a empty space (linear probing)
            ptr  = ptr->next;
        }

    ptr -> next = temp;
    }                // Make the next pointer of the last node point to the student node we created just now
}

hashTableClass::deleteStudent(int id){

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

hashTableClass::display(){ //display contents of the hash table

    for(int i=0; i<10; i++){
        cout << hashTable[i] -> id <<endl;
        cout << hashTable[i] -> name <<endl;
    }

}

hashTableClass::saveStudent(){

    string tempIdArray [HASHTABLESIZE];
    string tempNameArray [HASHTABLESIZE];

    for(int i = 0; i < HASHTABLESIZE; i++){

        string stringId = to_string(hashTable[i] -> id);

        tempIdArray[i] = stringId;
        tempNameArray[i] = hashTable[i] -> name;

    }

    ofstream saveStudentFile("student.txt", ios::out);

    for(int i=0; i<HASHTABLESIZE; i++){
        saveStudentFile << tempIdArray[i];
        saveStudentFile << " ";
        saveStudentFile << tempNameArray[i] <<endl;
    }

    saveStudentFile.close();
}

hashTableClass::loadStudent(){

    string tempLine;
    ifstream loadStudentFile("student.txt");


    while(getline(loadStudentFile,tempLine)){

        int tempIndex = 0;
        int tempIntId;
        string tempName;
        stringstream linestream(tempLine);

        linestream >> tempIntId >> tempName;

        hashTable[tempIndex] -> id = tempIntId;
        hashTable[tempIndex] -> name = tempName;

        tempIndex++;
    }
}

int main(){

    hashTableClass h1;

    cout << "add student:" << endl;
    h1.addStudent(97,"Ali");
    h1.addStudent(98,"Abu");
    h1.display();
    cout << "delete student:" << endl;
    h1.deleteStudent(97);
    h1.display();
    cout << "save student:" <<endl;
    h1.saveStudent();
    cout << "load student:" <<endl;
    h1.loadStudent();
    h1.display();

    return 0;
}
