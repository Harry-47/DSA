#include <iostream>
using namespace std;

const int MAX = 1000; // Maximum size of Stack

class Stack {
private:
    int top;
    int arr[MAX]; // Array to store stack elements

public:
    Stack() :top(-1){} // Constructor to initialize top

    void push(int x) 
    {
        if (top >= (MAX - 1)) {
            cout << "Stack Overflow" << endl;
        }
        arr[++top] = x;
    }

    int pop() 
    {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
            return 0;
        }
        int x = arr[top];
        top--;
        return x;
    }

    bool isEmpty() 
    {
        return (top < 0);
    }
    bool isFull() 
    {
        return (top >= (MAX - 1));
    }
    
    void display()
    {
        if (top < 0) {
            cout << "Stack is Empty" << endl;
            return;
        }
        for (int i = top; i >= 0; i--)
        {
            cout << '|' << arr[i] << '|' << endl;
            cout << "---" << endl;
        }
        cout << endl;
    }
//Miscellaneous functions
    int peek() 
    {
        if (top < 0) 
        {
            cout << "Stack is Empty" << endl;
            return 0;
        }
        return arr[top];
    }

    int size()
    { 
    return (top + 1);
    }
};

int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    stack.display();

    cout << "Top Value deleted: " << stack.pop() << endl;   
       // Output: 3
    cout << "Top Value is: " << stack.peek() << endl; 
        // Output: 2

    if(stack.isEmpty()) cout << "Stack is Empty" << endl;
    else cout << "Stack is not Empty" << endl; 
     // Output: 0 (false)
    cout << "Current Stack Size: " << stack.size() << endl;
         // Output: 2
    stack.display();  

    stack.push(4);
    stack.push(5);
    stack.display();  

    stack.pop();
    stack.pop();
    stack.display();  

    stack.push(6);
    stack.push(7);
    stack.display(); 

    stack.pop();
    stack.pop();
    stack.pop();
    stack.display();


    return 0;
}
