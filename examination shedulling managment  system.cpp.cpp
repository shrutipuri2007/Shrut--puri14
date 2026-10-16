#include <iostream>
#include <string>
using namespace std;

struct Exam {
    int id;
    string subject;
    string date;
    string time;
    string hall;
    Exam* next;
};

Exam* head = NULL;

// Function to add an exam
void addExam() {
    Exam* newNode = new Exam;

    cout << "\nEnter Exam ID: ";
    cin >> newNode->id;

    cin.ignore();

    cout << "Enter Subject: ";
    getline(cin, newNode->subject);

    cout << "Enter Exam Date: ";
    getline(cin, newNode->date);

    cout << "Enter Exam Time: ";
    getline(cin, newNode->time);

    cout << "Enter Exam Hall: ";
    getline(cin, newNode->hall);

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Exam* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "\nExam added successfully!\n";
}

// Function to search an exam
void searchExam() {
    if (head == NULL) {
        cout << "\nNo exams available.\n";
        return;
    }

    int id;
    cout << "\nEnter Exam ID to search: ";
    cin >> id;

    Exam* temp = head;

    while (temp != NULL) {
        if (temp->id == id) {
            cout << "\nExam Found!\n";
            cout << "Exam ID: " << temp->id << endl;
            cout << "Subject: " << temp->subject << endl;
            cout << "Date: " << temp->date << endl;
            cout << "Time: " << temp->time << endl;
            cout << "Hall: " << temp->hall << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "\nExam not found.\n";
}

// Function to delete an exam
void deleteExam() {
    if (head == NULL) {
        cout << "\nNo exams available to delete.\n";
        return;
    }

    int id;
    cout << "\nEnter Exam ID to delete: ";
    cin >> id;

    Exam* temp = head;
    Exam* prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "\nExam not found.\n";
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;

    cout << "\nExam deleted successfully!\n";
}

// Function to display all exams
void displayExams() {
    if (head == NULL) {
        cout << "\nNo exams scheduled.\n";
        return;
    }

    Exam* temp = head;

    cout << "\n===== COLLEGE EXAMINATION SCHEDULE =====\n";

    while (temp != NULL) {
        cout << "\nExam ID: " << temp->id << endl;
        cout << "Subject: " << temp->subject << endl;
        cout << "Date: " << temp->date << endl;
        cout << "Time: " << temp->time << endl;
        cout << "Hall: " << temp->hall << endl;

        temp = temp->next;
    }
}

// Function to free memory
void freeMemory() {
    Exam* temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

// Main function
int main() {
    int choice;

    do {
        cout << "\n====================================";
        cout << "\n COLLEGE EXAMINATION SCHEDULE SYSTEM";
        cout << "\n====================================";
        cout << "\n1. Add Exam";
        cout << "\n2. Search Exam";
        cout << "\n3. Delete Exam";
        cout << "\n4. Display All Exams";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                addExam();
                break;

            case 2:
                searchExam();
                break;

            case 3:
                deleteExam();
                break;

            case 4:
                displayExams();
                break;

            case 5:
                freeMemory();
                cout << "\nExiting the system. Thank you!\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
