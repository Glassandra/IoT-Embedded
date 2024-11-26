#include <iostream>
#include <stdexcept>
#include <cassert>
#include <string>

/*
Jag har valt att implementera detta som en enkel länkad lista. Eftersom vi bara vill göra operationer på ändarna,
    så  behöver vi bara ha ett sätt att länka noderna, vilket jag tyckte en enkel länkad lista uppfyllde.
    För att hålla all data så har vi en struct Node, som innehåller själva datan, och en pekare till nästa Node. 
*/

template <class T> class Queue {
    private:
        struct Node {
            T data;
            Node* next;
            Node(T value) : data(value), next(nullptr) {};
        };
        Node* front; // Noderna behöver bara nästa, men Queue behöver front och ände.
        Node* rear;
        int count = 0; // enkel int för att räkna antalet aktiva noder

    public:
        Queue () : front(nullptr), rear(nullptr) {};

        ~Queue() { // tömma kön från front till bak när vi slutar använda den
            while(front != nullptr) {
                Node* temp = front;
                front = front->next;
                delete temp;
            }

        }

        void enqueue(T value) {
            Node* newNode = new Node(value);
            if (rear == nullptr) {
                front = rear = newNode; // om värdet är första värdet så blir den både front och bak
            }
            else {
                rear->next = newNode; // annars ger du pekaren till den sista noden och ändrar köns pekare
                rear = newNode;
            }
            count++;
        }

        void dequeue() {
            if (front == nullptr) { // kan inte ta bor en nod om det inte finns några
                throw std::runtime_error("Queue is empty");
            }
            Node* temp = front;
            front = front->next;
            if (front == nullptr) {
                rear = nullptr; // om vi tar bort sista noden så säkerställer vi att både front och bak är nullpointers
            }            
            delete temp;
            count--;
        }

        T& peek() {
            if (front == nullptr) {
                throw std::runtime_error("Queue is empty");
            }
            return front->data; // enkel returnering av första nodens data om den inte är tom
        }

        bool isEmpty() const {
            return front == nullptr; // om allt fungerar som det ska så måste en nullpointer i front betyda tom kö
        }

        int size() {
            return count;
        }

        void display() const { // en funktion till att visa alla värden mest bara för testfall
            Node* temp = front;
            while (temp != nullptr) {
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << std::endl;
        }
};

int main() {
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    std::cout << "Peek: " << q.peek() << std::endl;
    assert(q.size() == 3); // assert så att errors inte stänger programmet
    q.dequeue();
    std::cout << "Peek: " << q.peek() << std::endl;
    assert(q.size() == 2);
    q.dequeue();    
    std::cout << "Peek: " << q.peek() << std::endl;
    q.dequeue();
    assert(q.isEmpty() == true);

    
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();
    //std::cout << "\nPeek: " << q.peek() << std::endl;

    Queue<std::string> s;
    s.enqueue("hello");
    std::cout << "Peek: " << s.peek() << std::endl;


    

}