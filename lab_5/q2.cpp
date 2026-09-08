#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node* prev;
    Node(int val) : val(val), next(NULL), prev(NULL) {}
};

class Solution{
    public:
    void insertAtStartOfDoublyLL(Node* &head, int x){
        Node* newNode = new Node(x);
        if(head == NULL){
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    void insertAtTheMiddleOfDoublyLL(Node* &head, int x, int posi){
        if(posi < 1){
            cout << "Position must be positive" << endl;
            return;
        }
        if(posi == 1){
            insertAtStartOfDoublyLL(head,x);
            return;
        }
        int cnt = 1;
        Node* temp = head;
        while(temp && cnt < posi - 1){
            temp = temp->next;
            cnt++;
        }
        if(!temp){
            cout << "This position doesn't exist in the curr doubly linked list" << endl;
            return;
        }
        Node* newNode = new Node(x);
        Node* next = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = next;
        if(next) next->prev = newNode;
    }
    void insertAtTheEndOfDoublyLL(Node* &head, int x){
        Node* newNode = new Node(x);
        if(head == NULL){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    void deleteHeadOfDoublyLL(Node* &head){
        if(head == NULL)return;
        Node* deletedNode = head;
        head = head->next;
        if(head) head->prev = NULL;
        delete deletedNode;
    }
    void deleteTailOfDoublyLL(Node* &head){
        if(head == NULL)return;
        if(head->next == NULL){
            Node* deletedNode = head;
            head = NULL;
            delete deletedNode;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        Node* prev = temp->prev;
        prev->next = NULL;
        temp->prev = NULL;
        delete temp;
    }
    void deleteInMiddleOfDoublyLL(Node* &head, int posi){
        if(head == NULL || posi < 1){
            cout << "This position doesn't exist in the curr doubly Linked list" << endl;
            return;
        }
        if(posi == 1){
            deleteHeadOfDoublyLL(head);
            return;
        }
        int cnt = 1;
        Node* temp = head;
        while(temp && cnt < posi){
            temp = temp->next;
            cnt++;
        }
        if(!temp){
            cout << "This position doesn't exist in the curr doubly Linked list" << endl;
            return;
        }
        if(temp->prev) temp->prev->next = temp->next;
        if(temp->next) temp->next->prev = temp->prev;
        if(temp == head) head = temp->next;
        delete temp;
    }
};
void printDoublyLL(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    Node* head = new Node(10);
    Node* temp = head;
    int nums[5] = {3,7,9,6,2};
    for(int i = 0; i < 5; i++){
        Node* newNode = new Node(nums[i]);
        temp->next = newNode;
        newNode->prev = temp;
        temp = temp->next;
    }
    cout << "Initial Doubly Linked List: ";
    printDoublyLL(head);
    Solution s;
    cout << "After deleting head of doubly linked list: ";
    s.deleteHeadOfDoublyLL(head);
    printDoublyLL(head);
    cout << "After deleting tail of doubly linked list: ";
    s.deleteTailOfDoublyLL(head);
    printDoublyLL(head);
    cout << "After deleting node at position 3: ";
    s.deleteInMiddleOfDoublyLL(head, 3);
    printDoublyLL(head);
    cout << "After inserting at the start: ";
    s.insertAtStartOfDoublyLL(head, 7);
    printDoublyLL(head);
    cout << "After inserting at the end: ";
    s.insertAtTheEndOfDoublyLL(head, 19);
    printDoublyLL(head);
    cout << "After inserting at the middle: ";
    s.insertAtTheMiddleOfDoublyLL(head, 9, 3);
    printDoublyLL(head);
}