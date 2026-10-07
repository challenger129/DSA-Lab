#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int val) : val(val), next(NULL) {}
};

class Stack{
    private:
    Node* head;
    public:
    Stack(){
        head = NULL;
    }
    void push(int x){
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }
    int top(){
        if(isEmpty()) return -1;
        return head->val;
    }
    int pop(){
        if(isEmpty()){
            cout << "Stack is empty" << endl;
            return -1;
        }
        int popped = head->val;
        Node* deletedNode = head;
        head = head->next;
        deletedNode->next = NULL;
        delete deletedNode;
        return popped;
    }
    bool isEmpty(){
        return head == NULL;
    }
};
int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
}