#include<iostream>
#include<string>
using namespace std;

struct customer {
    int id;
    string stt;
 
};

class CSR {
public:
    int size = 5;
    customer* c1 = new customer[size];
    int front = -1;
    int rear = -1;
    int noElements = 0;

    void enqueue(int id, string stt) {
        if(!isFull() && noElements==0){
            front=(front+1)%size;
            rear=(rear+1)%size;
            c1[front].id=id;
            c1[front].stt=stt;
            noElements++;
        
        }
        else if(noElements==size){
            return;
        }
       else if (!isFull()) {
            rear = (rear + 1) % size;
            c1[rear].id = id;
            c1[rear].stt = stt;
            noElements++;
        }
        else {
            cout << "----Queue is Full------" << endl;
        }
    }

    bool isFull() {
        
        if (noElements == size) {
            return true;
        }
        else {
            return false;
        }
    }

    bool isEmpty() {
        if (noElements == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    customer dequeue() {
          customer x;
        if(noElements==0){
            cout<<"--Empty"<<endl;
            return x;
        }
        if (!isEmpty()) {
            front = (front + 1) % size;
            x.id = c1[front].id;
            x.stt = c1[front].stt;
            noElements--;
        }
        else {
            cout << "----Queue is empty------" << endl;
        }
        return x;
    }

    void display(){
        //int temp=front;
        for (int i = front; i<=rear; i = (i+1))
        {
            cout<<c1[i].id<<" "<<c1[i].stt<<endl;
           

            
        }


    }
};

int main() {
    CSR c1; // allocate memory for CSR object
     

    c1.enqueue(1, "Hello");
    c1.enqueue(2, "World");
    c1.enqueue(3, "How");
    c1.enqueue(4, "Are");
   c1.enqueue(5, "You");
  
  c1.dequeue();
 
         c1.display();


    
    return 0;
}
