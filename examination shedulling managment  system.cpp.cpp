#include <iostream>
#include <string>
using namespace std;

struct Exam {
    string subject;
    string date;
    Exam* next;
};

int main() {
    Exam* head = NULL;
    Exam* temp;
    Exam* newNode;

    int n, i;

    cout << "Enter number of exams: ";
    cin >> n;

    for (i = 0; i < n; i++) {
        newNode = new Exam;

        cout << "\nEnter subject: ";
        cin >> newNode->subject;

        cout << "Enter exam date: ";
        cin >> newNode->date;

        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    cout << "\n--- College Examination Schedule ---\n";

    temp = head;

    while (temp != NULL) {
        cout << "Subject: " << temp->subject
             << " | Date: " << temp->date << endl;

        temp = temp->next;
    }

    temp = head;
    while (temp != NULL) {
        Exam* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    return 0;
}
