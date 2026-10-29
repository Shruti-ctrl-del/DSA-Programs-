#include <iostream>
using namespace std;

// Node class for doubly linked list
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// Doubly linked list class
class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    // Insert node at the end
    void insert(int val) {
        Node* p = new Node(val);

        if (head == nullptr) {
            head = p;
        } 
        else {
            Node* q = head;

            while (q->next != nullptr) {
                q = q->next;
            }

            q->next = p;
            p->prev = q;
        }
    }

    // Delete node by value
    void remove(int val) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* p = head;

        // Find the node
        while (p != nullptr && p->data != val) {
            p = p->next;
        }

        // Value not found
        if (p == nullptr) {
            cout << "Value " << val << " not found in the list.\n";
            return;
        }

        // If deleting the first node
        if (p == head) {
            head = head->next;

            if (head != nullptr) {
                head->prev = nullptr;
            }
        }
        else {
            p->prev->next = p->next;

            if (p->next != nullptr) {
                p->next->prev = p->prev;
            }
        }

        delete p;
    }

    // Display list forward
    void displayForward() {
        Node* q = head;

        cout << "Forward: ";

        while (q != nullptr) {
            cout << q->data << " <-> ";
            q = q->next;
        }

        cout << "NULL\n";
    }

    // Display list backward
    void displayBackward() {
        if (head == nullptr) {
            cout << "Backward: NULL\n";
            return;
        }

        Node* q = head;

        // Move to the last node
        while (q->next != nullptr) {
            q = q->next;
        }

        cout << "Backward: ";

        // Traverse backward
        while (q != nullptr) {
            cout << q->data << " <-> ";
            q = q->prev;
        }

        cout << "NULL\n";
    }
};

// Main function
int main() {
    DoublyLinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);

    list.displayForward();
    list.displayBackward();

    list.remove(20);

    cout << "\nAfter deleting 20:\n";

    list.displayForward();
    list.displayBackward();

    return 0;
}







//Outout
PS C:\shruti06> cd "c:\shruti06\" ; if ($?) { g++ dobly.cpp -o dobly } ; if ($?) { .\dobly }
Forward: 10 <-> 20 <-> 30 <-> NULL
Backward: 30 <-> 20 <-> 10 <-> NULL

After deleting 20:
Forward: 10 <-> 30 <-> NULL
Backward: 30 <-> 10 <-> NULL