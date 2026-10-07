#include<bits/stdc++.h>
using namespace std;

class Stack{
    private:
    int topInd;
    int *arr;
    int capacity;
    public:
    Stack(int size = 100){
        capacity = size;
        arr = new int[capacity];
        topInd = -1;
    }
    void push(int x){
        if(isFull()){
            cout << "Stack is already full" << endl;
            return;
        }
        topInd++;
        arr[topInd] = x;
    }
    int top(){
        if(isEmpty()) return -1;
        return arr[topInd];
    }
    int pop(){
        if(isEmpty()){
            cout << "Stack is already empty" << endl;
            return -1;
        }
        int popped = arr[topInd];
        topInd--;
        return popped;
    }
    bool isFull(){
        return topInd == capacity - 1;
    }
    bool isEmpty(){
        return topInd == -1;
    }
};
int main(){
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.top() << endl;
}