#include <iostream>
#include <climits>
using namespace std;

template <class T>
class Node{
    public:
    T data;
    Node<T>* next;
    Node(int data){
        this -> data = data;
        next = NULL;
    }
};


template <class T>
class Stack{
    Node <T>* head;
    int size;

    public:
    Stack(){
        head = NULL;
        size = 0;
    }

    // push()
    void push(T data){
        Node<T>* newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
        size++;
    }
    // pop()
    T pop(){
        if(!size){
            return INT_MIN;
        }
        T val = head->data;
        Node <T>*temp = head->next;
        delete head;
        head = temp;
        size--;
        return val;
    }
    // isEmpty()
    bool isEmpty(){
        return size==0;
    }
    // top()
    T top(){
        if(size==0){
            return INT_MIN;
        }
        return head->data;
    }
    // getSize()
    int getSize(){
        return size;
    }

};

int main(){
    Stack<char> s;

    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);

    cout<<s.pop()<<s.pop()<<s.pop()<<s.pop()<<s.pop();

    cout<<endl<<endl;
}