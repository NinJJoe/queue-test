
//queue doubly linked list 
#include <iostream>
using namespace std;
struct node
{
    int data;
    node* next;
    node* prev;
};
class DoublyIntegerLinkedList
{
private:
    node* head; 
    node* tail; 
    int counter;
public:
    DoublyIntegerLinkedList() 
    {
        counter = 0;
        head = tail = NULL;
    }
    void displaySize()
    {
        cout << "The current nodes in the list is: " << counter << endl;
    }
    void createNode(int value)
    {
        node* x = new node(); 
        x->data = value;
        x->next = NULL;
        x->prev = NULL;
        if (head == NULL) 
        {
            head = tail = x;
        }
        else 
        {  
            tail->next = x; 
            x->prev = tail;
            tail = x;
        }
        counter++;
    }
    void displayQueue()
    {
        cout << "Items in the list:\n";
        node* i = head;
        while (i != NULL)
        {
            cout << i->data << endl;
            i = i->next; 
        }
    }
    


    void enqueue(int value)
    {
        node* x = new node();
        x->data = value;
        x->next = NULL;
        x->prev = NULL;
        if (isEmpty())
        {
            head = tail = x;
        }
        else
        {
            x->prev = tail;
            tail->next = x;
            tail = x;
        }
        counter++;
    }

    void dequeue()
    {
        node* x = head;
        if (isEmpty())
        {
            return;
        }
        head = head->next;
        delete x;
        counter--;
    }
    
    int getSize()
    {
        return counter;
    }

    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        return false;
    }
   
};
int main() {

    DoublyIntegerLinkedList list;
    list.enqueue(23);
    list.enqueue(24);
    list.enqueue(25);
    list.dequeue();
    list.enqueue(26);
    list.enqueue(27);
    list.enqueue(28);
    list.displayQueue();
    cout << "list size: " << list.getSize() << endl;
    list.dequeue();
    list.displayQueue();
    cout << "list size: " << list.getSize() << endl;

    return 0;
}
   
