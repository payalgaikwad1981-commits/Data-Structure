#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student {
    int rollNo;
    string name;
    vector<string> courses;
    Student* next;
};

struct HashNode {
    int rollNo;
    Student* student;
    HashNode* next;
};

const int SIZE = 10;

Student* head = NULL;
HashNode* hashTable[SIZE] = {NULL};

// Hash Function
int hashFunction(int rollNo) {
    return rollNo % SIZE;
}

// Search Student
Student* searchStudent(int rollNo) {
    int index = hashFunction(rollNo);
    HashNode* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->rollNo == rollNo)
            return temp->student;

        temp = temp->next;
    }
    return NULL;
}

// Insert into Hash Table
void insertHash(Student* s) {
    int index = hashFunction(s->rollNo);

    HashNode* newNode = new HashNode;
    newNode->rollNo = s->rollNo;
    newNode->student = s;
    newNode->next = hashTable[index];

    hashTable[index] = newNode;
}

// 1. Register Student
void registerStudent() {
    Student* s = new Student;

    cout << "Enter Roll Number: ";
    cin >> s->rollNo;

    if (searchStudent(s->rollNo) != NULL) {
        cout << "Roll Number already exists!\n";
        delete s;
        return;
    }

    cin.ignore();

    cout << "Enter Student Name: ";
    getline(cin, s->name);

    s->next = head;
    head = s;

    insertHash(s);

    cout << "Student Registered Successfully!\n";
}

// 2. Update Student Information
void updateStudent() {
    int roll;

    cout << "Enter Roll Number: ";
    cin >> roll;

    Student* s = searchStudent(roll);

    if (s == NULL) {
        cout << "Student Not Found!\n";
        return;
    }

    cin.ignore();

    cout << "Enter Updated Name: ";
    getline(cin, s->name);

    cout << "Student Information Updated Successfully!\n";
}

// 3. Withdraw Student from Course
void withdrawStudent() {
    int roll;
    string course;

    cout << "Enter Roll Number: ";
    cin >> roll;

    Student* s = searchStudent(roll);

    if (s == NULL) {
        cout << "Student Not Found!\n";
        return;
    }

    cin.ignore();

    cout << "Enter Course Name: ";
    getline(cin, course);

    for (int i = 0; i < s->courses.size(); i++) {
        if (s->courses[i] == course) {
            s->courses.erase(s->courses.begin() + i);
            cout << "Course Withdrawn Successfully!\n";
            return;
        }
    }

    cout << "Course Not Found!\n";
}

// Main Function
int main() {
    int choice;

    do {
        cout << "\n===== UNIVERSITY STUDENT SYSTEM =====\n";
        cout << "1. Register Student\n";
        cout << "2. Update Student Information\n";
        cout << "3. Withdraw Student from Course\n";
        cout << "4. Exit\n";

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerStudent();
                break;

            case 2:
                updateStudent();
                break;

            case 3:
                withdrawStudent();
                break;

            case 4:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}










Conv
