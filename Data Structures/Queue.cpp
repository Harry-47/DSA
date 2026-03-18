#include<iostream>

class Queue
{
    private:
    int front;
    int rear;
    int Array[5];
    public:
    Queue(): front(-1), rear(-1)
    {
        for(int i = 0; i < 5; i++)
        {
            Array[i] = 0;
        }
    }

    void Enqueue(int data)
    {
        if(rear >= 4)
        std::cout << "Queue is full" << std::endl;

        else if (rear == -1 && front == -1)
        rear = front = 0;
      
        Array[rear] = data;
        rear++;
    }
    
    void Dequeue()
    {
        if(front == -1 && rear == -1)
        std::cout << "Queue is already empty" << std::endl;
        
        else if(front == rear)
        front = rear = -1;

        else
        {   
            return Array[front];
            front++;
        }
    }
    
    void Display()
    {
      for(int i = 0; i < 5; i++)
      std::cout << Array[i] << " ";
    }

     bool isFull()
     {
        return rear == 5;
     }

     bool isEmpty()
     {
        return front == -1 && rear == -1;
     }
     
     void insert(int index, int value)
     {
         if(rear == 5)
         {
          Array[index] = value;
          return;
         }

         else if (rear == -1 && front == -1)
         rear = front = 0;

         else if (index >=5 || index < 0)
         std::cout << "Index out of Bounds! " << std::endl;

         else 

         {
            for(int i = rear; i>=index; i--)
                 Array[i+1] = Array[i];
         }
        Array[index] = value;
        rear++;
     }
};


int main()
{
    Queue q;
    int choice;

    do
    {
        system("pause");
        system("cls");

      std::cout << " -------Queue Implementation------- " << std::endl;
      std::cout << "1. Enqueue" << std::endl;
      std::cout << "2. Dequeue" << std::endl;
      std::cout << "3. Display" << std::endl;
      std::cout << "4. Insert" << std::endl;
      std::cout << "5. Check Full " << std::endl;
      std::cout << "6. Check Empty " << std::endl;
      std::cout << "7. Exit" << std::endl;
      std::cout << "Enter your choice: ";
      std::cin >> choice;

    switch(choice)
    {
    case 1:
    int data;
    std::cout << "Enter Value: ";
    std::cin >> data;
    
    q.Enqueue(data);
    break;
    
    case 2:
    q.Dequeue();
    break;

    case 3:
    q.Display();
    break;

    case 4:
    int Index, Value;
    std::cout << "Enter Index: ";
    std::cin >> Index;
   
    std::cout << "Enter Value:";
    std::cin >> Value;
    
    q.insert(Index, Value);
    break;

    case 5:
    if(q.isFull())
    std::cout << "Queue is Full" << std::endl;
    else
    std::cout << "Queue is not Full" << std::endl;
    break;

    case 6:
    if(q.isEmpty())
    std::cout << "Queue is Empty" << std::endl;
    else
    std::cout << "Queue is not Empty" << std::endl;
    break;
    
    case 7:
    break;
    
    default:
    std::cout << "Invalid Choice" << std::endl;
    }

    }while(choice !=7);

    return 0;
}