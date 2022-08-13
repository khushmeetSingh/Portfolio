#include <iostream>

// Define the default capacity of the queue
#define SIZE 10

// A class to represent a queue
template <class X>
class queue
{
    X *arr;       // array to store queue elements
    int capacity; // maximum capacity of the queue
    int front;    // front points to the front element in the queue (if any)
    int rear;     // rear points to the last element in the queue
    int count;    // current size of the queue

public:
    queue(int size = SIZE);    // constructor
    ~queue() { delete[] arr; } //destructor

    void dequeue();
    void enqueue(X x);
    X peek();
    int size();
    bool isEmpty();
    bool isFull();
    void display();
};

// Constructor to initialize a queue
template <class X>
queue<X>::queue(int size)
{
    arr = new X[size];
    capacity = size;
    front = -1;
    rear = -1;
    count = 0;
}

// Utility function to dequeue the front element
template <class X>
void queue<X>::dequeue()
{
    // check for queue underflow
    if (isEmpty())
    {
        std::cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    std::cout << "Removing " << arr[front] << std::endl;

    front = (front + 1) % capacity;
    count--;
}

// Template function to add an item to the queue
template <class X>
void queue<X>::enqueue(X item)
{
    // check for queue overflow
    if (isFull())
    {
        std::cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    std::cout << "Inserting " << item << std::endl;

    if (rear == -1)
        front = 0;

    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}

// Template function to return the front element of the queue
template <class X>
X queue<X>::peek()
{
    if (isEmpty())
    {
        std::cout << "UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}

// Template function to return the size of the queue
template <class X>
int queue<X>::size()
{
    return count;
}

// Template function to check if the queue is empty or not
template <class X>
bool queue<X>::isEmpty()
{
    return (size() == 0);
}

// Template function to check if the queue is full or not
template <class X>
bool queue<X>::isFull()
{
    return (size() == capacity);
}

// Template function to display the queue
template <class X>
void queue<X>::display()
{
    std::cout << "Elements in the queue : ";
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            std::cout << arr[i] << " ";
    }
    else
    {
        for (int i = front; i < capacity; i++)
            std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

//driver code
int main()
{
    std::cout << "\n|***|Program Started|***|" << std::endl;
    // create a queue of capacity 4
    queue<char> q(4);

    std::cout << "\n Operations on a queue of size 4...\n";

    q.enqueue('a');
    q.enqueue('b');
    q.enqueue('c');
    q.display();

    std::cout << "The front element is " << q.peek() << std::endl;
    q.dequeue();

    q.enqueue('d');
    q.enqueue('e');

    std::cout << "The queue size is " << q.size() << std::endl;
    q.display();

    if (q.isFull())
    {
        std::cout << "The queue is full\n";
    }
    else
    {
        std::cout << "The queue is not full\n";
    }

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    if (q.isEmpty())
    {
        std::cout << "The queue is empty\n";
    }
    else
    {
        std::cout << "The queue is not empty\n";
    }

    std::cout << "\n|***|Program Ended|***|" << std::endl;

    return 0;
}