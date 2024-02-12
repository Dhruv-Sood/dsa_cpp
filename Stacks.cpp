#include <iostream>
#include <climits>
using namespace std;

template <class T>
class Stack{
    private:
    T *arr;
    int nextIndex = 0;
    int capacity;
    public:
    // push()
    void push(int data){
        if(nextIndex == capacity){
            T* newArr = new int[capacity*2];
            for(int i = 0 ; i<capacity ; i++){
                newArr[i] = arr[i];
            }
            delete [] arr;
            arr = newArr;
            capacity = capacity*2;
            
        }
        arr[nextIndex] = data;
        nextIndex++;
    }
    // pop()
    T pop(){
        if(nextIndex == 0){
            cout<<"[Returning dummy value as stack is empty]...."<<endl;
            return INT_MIN;
        }

        nextIndex--;
        return arr[nextIndex];

    }
    // top()
    T top(){
        if(nextIndex == 0){
            return 0;
        }
        return arr[nextIndex-1];
    }
    // size()
    int size(){
        return nextIndex;
    } 
    // isEmpty()
    bool isEmpty(){
        return nextIndex == 0;
    }

    Stack(){
        this -> capacity = 4;
        arr = new int[4];
    }
};

int main(){
    Stack <int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    cout<<s.pop()<<" "<<s.pop()<<endl;

    cout<<endl<<endl;
    return 0;
}