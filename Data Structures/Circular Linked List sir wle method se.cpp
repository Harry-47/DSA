#include <iostream>
using namespace std;

// Node class definition
class Node {
public:
    int data;
    Node* next;

    Node(int d) : data(d), next(NULL) {}
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() : head(NULL) {}

    // Insert at head
    void insertAtHead(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) { // Empty list
            newNode->next = newNode; // Circular reference
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
        cout << "Inserted " << data << " at head.\n";
    }

    // Insert at end
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) { // Empty list
            newNode->next = newNode; // Circular reference
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        cout << "Inserted " << data << " at end.\n";
    }

    // Insert before a particular node
    void insertBefore(int targetData, int data) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* curr = head;
        Node* prev = NULL;

        do {
            if (curr->data == targetData) {
                Node* newNode = new Node(data);
                newNode->next = curr;

                if (prev == NULL) { // Inserting before head
                    Node* temp = head;
                    while (temp->next != head) {
                        temp = temp->next;
                    }
                    temp->next = newNode;
                    head = newNode;
                } else {
                    prev->next = newNode;
                }
                cout << "Inserted " << data << " before " << targetData << ".\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);

        cout << "Node with data " << targetData << " not found.\n";
    }

    // Insert after a particular node
    void insertAfter(int targetData, int data) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* curr = head;

        do {
            if (curr->data == targetData) {
                Node* newNode = new Node(data);
                newNode->next = curr->next;
                curr->next = newNode;
                cout << "Inserted " << data << " after " << targetData << ".\n";
                return;
            }
            curr = curr->next;
        } while (curr != head);

        cout << "Node with data " << targetData << " not found.\n";
    }

    // Delete at head
    void deleteAtHead() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;

        if (head->next == head) { // Single-node list
            delete head;
            head = NULL;
        } else {
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            last->next = head->next;
            head = head->next;
            delete temp;
        }
        cout << "Deleted node at head.\n";
    }

    // Delete at end
    void deleteAtEnd() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* curr = head;
        Node* prev = NULL;

        if (head->next == head) { // Single-node list
            delete head;
            head = NULL;
        } else {
            while (curr->next != head) {
                prev = curr;
                curr = curr->next;
            }
            prev->next = head;
            delete curr;
        }
        cout << "Deleted node at end.\n";
    }

    // Delete a particular node
    void deleteParticular(int targetData) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* curr = head;
        Node* prev = NULL;

        do {
            if (curr->data == targetData) {
                if (prev == NULL) { // Deleting the head
                    deleteAtHead();
                } else {
                    prev->next = curr->next;
                    delete curr;
                    cout << "Deleted node with data " << targetData << ".\n";
                }
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);

        cout << "Node with data " << targetData << " not found.\n";
    }

    // Delete before a particular node
    void deleteBefore(int targetData) {
        if (head == NULL || head->next == head) {
            cout << "Insufficient nodes to perform delete before.\n";
            return;
        }

        Node* curr = head;
        Node* prev = NULL;
        Node* prePrev = NULL;

        do {
            if (curr->data == targetData) {
                if (prev == head) { // Delete last node (before head)
                    deleteAtEnd();
                } else if (prev != NULL) {
                    prePrev->next = curr;
                    delete prev;
                }
                cout << "Deleted node before " << targetData << ".\n";
                return;
            }
            prePrev = prev;
            prev = curr;
            curr = curr->next;
        } while (curr != head);

        cout << "Node with data " << targetData << " not found.\n";
    }

    // Delete after a particular node
    void deleteAfter(int targetData) {
        if (head == NULL || head->next == head) {
            cout << "Insufficient nodes to perform delete after.\n";
            return;
        }

        Node* curr = head;

        do {
            if (curr->data == targetData) {
                if (curr->next == head) { // Delete head (after last node)
                    deleteAtHead();
                } else {
                    Node* toDelete = curr->next;
                    curr->next = toDelete->next;
                    delete toDelete;
                }
                cout << "Deleted node after " << targetData << ".\n";
                return;
            }
            curr = curr->next;
        } while (curr != head);

        cout << "Node with data " << targetData << " not found.\n";
    }

    // Display the list
    void display() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)\n";
    }
};

int main() {
    CircularLinkedList list;

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
    list.deleteAfter(10);

    list.display();

    return 0;
}