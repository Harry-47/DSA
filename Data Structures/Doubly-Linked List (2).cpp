#include <iostream>
using namespace std;

// Node class definition
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int d) : data(d), next(NULL), prev(NULL) {}
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() : head(NULL) {}

    // Insert at the head
    void insertAtHead(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Inserted " << data << " at head.\n";
    }

    // Insert at the end
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
        cout << "Inserted " << data << " at end.\n";
    }

    // Insert before a particular node
    void insertBefore(int targetData, int data) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        while (temp != NULL && temp->data != targetData) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Node with data " << targetData << " not found.\n";
            return;
        }

        Node* newNode = new Node(data);
        newNode->next = temp;
        newNode->prev = temp->prev;

        if (temp->prev != NULL) {
            temp->prev->next = newNode;
        } else {
            head = newNode; // Update head if inserting before the first node
        }
        temp->prev = newNode;

        cout << "Inserted " << data << " before " << targetData << ".\n";
    }

    // Insert after a particular node
    void insertAfter(int targetData, int data) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        while (temp != NULL && temp->data != targetData) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Node with data " << targetData << " not found.\n";
            return;
        }

        Node* newNode = new Node(data);
        newNode->prev = temp;
        newNode->next = temp->next;

        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;

        cout << "Inserted " << data << " after " << targetData << ".\n";
    }

    // Delete at head
    void deleteAtHead() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        if (head->next == NULL) {
            head = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }
        delete temp;
        cout << "Deleted node at head.\n";
    }

    // Delete at end
    void deleteAtEnd() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        if (head->next == NULL) {
            head = NULL;
        } else {
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->prev->next = NULL;
        }
        delete temp;
        cout << "Deleted node at end.\n";
    }

    // Delete a particular node
    void deleteParticular(int targetData) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        while (temp != NULL && temp->data != targetData) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Node with data " << targetData << " not found.\n";
            return;
        }

        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next; // Update head if deleting the first node
        }

        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }

        delete temp;
        cout << "Deleted node with data " << targetData << ".\n";
    }

    // Delete before a particular node
    void deleteBefore(int targetData) {
        if (head == NULL || head->next == NULL) {
            cout << "Insufficient nodes to perform delete before.\n";
            return;
        }

        Node* temp = head;
        while (temp != NULL && temp->data != targetData) {
            temp = temp->next;
        }

        if (temp == NULL || temp->prev == NULL) {
            cout << "No node exists before " << targetData << ".\n";
            return;
        }

        deleteParticular(temp->prev->data);
    }

    // Delete after a particular node
    void deleteAfter(int targetData) {
        if (head == NULL || head->next == NULL) {
            cout << "Insufficient nodes to perform delete after.\n";
            return;
        }

        Node* temp = head;
        while (temp != NULL && temp->data != targetData) {
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL) {
            cout << "No node exists after " << targetData << ".\n";
            return;
        }

        deleteParticular(temp->next->data);
    }

    // Display the list
    void display() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Doubly Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList list;

    list.insertAtHead(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertBefore(20, 15);
    list.insertAfter(20, 25);

    list.display();

    list.deleteAtHead();
    list.deleteAtEnd();
    list.deleteParticular(15);
    list.deleteBefore(25);
    list.deleteAfter(20);

    list.display();

    return 0;
}