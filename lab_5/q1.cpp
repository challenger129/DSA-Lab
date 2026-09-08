#include<bits/stdc++.h>
using namespace std;

int size = 0;
struct node{
    int val;
    node* next;
    node(int val) : val(val), next(NULL){}
};

class Solution{
    public:
    void insertAtTheEndOfCircularLL(node* &head, int x){
        node* newNode = new node(x);
        size++;
        if(head == NULL){
            head = newNode;
            newNode->next = head;
            return;
        }
        node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        node* next = temp->next;
        temp->next = newNode;
        newNode->next = next;
    }
    void insertAtMiddleOfCircularLL(node* &head, int x, int posi){
        if(posi > size){
            posi = posi % size;
        }
        if(head == NULL){
            if(posi == 1){
                head = new node(x);
                head->next = head;
                size++;
            }
            else{
                cout << "Insertion not possible" << endl;
            }
            return;
        }
        node* temp = head;
        int cnt = 2;
        while(cnt < posi){
            temp = temp->next;
            cnt++;
        }
        node* newNode = new node(x);
        node* next = temp->next;
        temp->next = newNode;
        newNode->next = next;
        size++;
    }
    void deleteEndOfTheCircularLL(node* &head){
        if(head == NULL){
            cout << "List is empty" << endl;
            return;
        }
        if(head->next == NULL){
            node* deletedNode = head;
            head = NULL;
            delete deletedNode;
            size--;
            return;
        }
        node* temp = head;
        while(temp->next->next != head){
            temp = temp->next;
        }
        node* deletedNode = temp->next;
        temp->next = head;
        deletedNode->next = NULL;
        delete deletedNode;
        size--;
    }
    void deleteAtSomePositionInCircularLL(node* &head, int posi){
        if(head == NULL){
            cout << "List is empty" << endl;
            return;
        }
        if(posi > size){
            posi = posi % size;
        }
        int cnt = 2;
        node* temp = head;
        while(cnt < posi){
            temp = temp->next;
            cnt++;
        }
        node* deletedNode = temp->next;
        temp->next = temp->next->next;
        deletedNode->next = NULL;
        delete deletedNode;
        size--;
    }
};

void printCircularLL(node* &head){
    if(head == NULL){
        cout << "List is empty" << endl;
        return;
    }
    node* temp = head;
    while(temp->next != head){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << temp->val << " ";
    cout << endl;
}

int main(){
    node* head = new node(10);
    node* temp = head;
    int nums[5] = {3,7,9,6,2};
    for(int i = 0; i < 5; i++){
        node* newNode = new node(nums[i]);
        temp->next = newNode;
        temp = temp->next;
    }
    size = 6;
    temp->next = head;
    Solution s;
    cout << "Initial Circular Linked List: ";
    printCircularLL(head);
    s.deleteAtSomePositionInCircularLL(head, 3);
    cout << "After deletion at position 3: ";
    printCircularLL(head);
    s.deleteEndOfTheCircularLL(head);
    cout << "After deletion at the end: ";
    printCircularLL(head);
    s.insertAtMiddleOfCircularLL(head, 15, 3);
    cout << "After insertion at position 3: ";
    printCircularLL(head);
    s.insertAtTheEndOfCircularLL(head, 20);
    cout << "After insertion at the end: ";
    printCircularLL(head);
}