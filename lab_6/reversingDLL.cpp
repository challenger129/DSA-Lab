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
    void reversingDLL(Node* &head){
        Node* temp = head;
        if(!head->next)return;
        Node* next = head->next;
        Node* prev = NULL;
        while(temp->next){
            temp->next = prev;
            temp->prev = next;
            prev = temp;
            temp = next;
            next = next->next;
        }
        temp->next = prev;
        head = temp;
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
    Solution s;
    cout << "Original Doubly Linked List: ";
    printDoublyLL(head);
    s.reversingDLL(head);
    cout << "Reversed Doubly Linked List: ";    
    printDoublyLL(head);
}