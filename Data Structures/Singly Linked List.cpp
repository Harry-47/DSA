#include<iostream>
using namespace std;
//Note: Dont Delete A node because it will cause a memory leak in this program
// Node class definition
class Node {
public:
    int key;
    int data;
    Node *next;

    // Default constructor
    Node() : key(0), data(0), next(NULL) {}

    // Parameterized constructor
    Node(int key, int data) : key(key), data(data), next(NULL) {}
};

// Singly linked list class definition
class SinglyLinkedList {
public:
    Node *head;

    // Default constructor
    SinglyLinkedList() : head(NULL) {}

    // Parameterized constructor
    SinglyLinkedList(Node *node) : head(node) {}

    // Function to check if a node with a given key exists in the list
    Node *nodeExists(int k) {
        Node *temp = head;
        while (temp != NULL) {
            if (temp->key == k)
                return temp;

            temp = temp->next;
        }
        return NULL;
    }

    // Function to append a node to the end of the list
    void appendNode(Node *n) {
        if (nodeExists(n->key) != NULL)
            std::cout << "Node with the given key already exists" << std::endl;
        else {
            if (head == NULL) {
                head = n;
                std::cout << "Node appended!" << std::endl;
            } else {
                Node *temp = head;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = n;
                std::cout << "Node appended!" << std::endl;
            }
        }
    }

    // Function to prepend a node to the beginning of the list
    void prependNode(Node *n) {
        if (nodeExists(n->key) != NULL)
            std::cout << "Node with the given key already exists" << std::endl;
        else {
            if (head == NULL)
                head = n;
            else {
                n->next = head;
                head = n;
                std::cout << "Node prepended!" << std::endl;
            }
        }
    }

    // Function to remove a node with a given key from the list
    void removeNode(int k) {
        if (nodeExists(k) == NULL)
            std::cout << "Node with the given key does not exist" << std::endl;
        else {
            if (head->key == k) {
                head = head->next;
                std::cout << "Node removed!" << std::endl;
            } 
            else if (head == NULL)
                std::cout << "Warning: List is Empty! " << std::endl;

            else {
                Node *temp = head;
                while (temp->next != NULL) {
                    if (temp->next->key == k) {
                        temp->next = temp->next->next;
                        std::cout << "Node removed!" << std::endl;
                        break;
                    }
                    temp = temp->next;
                }
            }
        }
    }

    // Function to update the data of a node with a given key
    void updateNode(int k, int data) {
        Node *temp = nodeExists(k);
        if (temp == NULL)
            std::cout << "Node with the given key does not exist" << std::endl;
        else {
            temp->data = data;
            std::cout << "Node updated!" << std::endl;
        }
    }

    // Function to display all nodes in the list
    void displayNodes() {
        Node *temp = head;
        while (temp != NULL) {
            std::cout << "(" << temp->key << ", " << temp->data << ")-->";
            temp = temp->next;
        }
    }

    // Function to count the number of nodes in the list
    void countNodes() 
    {
        Node *temp = head;
        int count = 0;
        while (temp != NULL) 
        {
            count++;
            temp = temp->next;
        }
        std::cout << count << std::endl;
    }

    // Function to insert a node after a node with a given key
    void insertNode(Node *node, int k) {
        if (nodeExists(node->key) != NULL)
            std::cout << "Node with the given key already exists" << std::endl;
        else {
            if (head == NULL) 
            {
                std::cout << "Warning: List is Empty! " << std::endl;
                head = node;
                std::cout << "Node Appended" << std::endl;
            } 
            else if (nodeExists(k) == NULL)
            {
                std::cout << "Node Does Not Exist" << std::endl;
                return;
            } 
            else if (head->key == k) 
            {
                node->next = head->next;
                head->next = node;
                std::cout << "Node Inserted" << std::endl;
            } 

            else {
                Node *curr = head->next;
                while (curr != NULL) {
                    if (curr->key == k) {
                        node->next = curr->next;
                        curr->next = node;
                        std::cout << "Node Inserted" << std::endl;
                        return;
                    }
                    curr = curr->next;
                }
            }
        }
    }
};
int main() {
    SinglyLinkedList List;
    int choice, key, data;
    Node *node;

    while (true)
     {
        std::cout << "\nSingly Linked List Operations:\n";
        std::cout << "1. Append\n";
        std::cout << "2. Prepend\n";
        std::cout << "3. Delete\n";
        std::cout << "4. Insert\n";
        std::cout << "5. Update\n";
        std::cout << "6. Count\n";
        std::cout << "7. Display\n";
        std::cout << "8. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter key and data: ";
                std::cin >> key >> data;
                node = new Node(key, data);
                List.appendNode(node);
                break;
            case 2:
                std::cout << "Enter key and data: ";
                std::cin >> key >> data;
                node = new Node(key, data);
                List.prependNode(node);
                break;
            case 3:
                std::cout << "Enter key to delete: ";
                std::cin >> key;
                List.removeNode(key);
                break;
            case 4:
                std::cout << "Enter key and data for new node: ";
                std::cin >> key >> data;
                node = new Node(key, data);
                std::cout << "Enter key after which to insert: ";
                std::cin >> key;
                List.insertNode(node, key);
                break;
            case 5:
                std::cout << "Enter key and new data: ";
                std::cin >> key >> data;
                List.updateNode(key, data);
                break;
            case 6:
                List.countNodes();
                break;
            case 7:
                List.displayNodes();
                break;
            case 8:
                // Deallocate memory
                while (List.head != NULL) {
                    node = List.head;
                    List.head = List.head->next;
                    delete node;
                }
                return 0;
            default:
                std::cout << "Invalid choice!\n";
        }
    }
        while (List.head != NULL) {
                    node = List.head;
                    List.head = List.head->next;
                    delete node;
                }

    return 0;
}
