#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int val) : val(val), next(NULL) {}
};

class Solution{
    public:
    void reversingCLL(Node* &head){
        Node* temp = head;
        if(head->next == head) return;
        Node* prev = head->next;
        while(prev->next != head) prev = prev->next;
        Node* next = head->next;
        while(next != head){
            temp->next = prev;
            prev = temp;
            temp = next;
            next = next->next;
        }
        temp->next = prev;
        head = temp;
    }
};

void printCircularLL(Node* &head){
    if(head == NULL){
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    while(temp->next != head){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << temp->val << " ";
    cout << endl;
}
int main(){
    Node* head = new Node(10);
    Node* temp = head;
    int nums[5] = {3,7,9,6,2};
    for(int i = 0; i < 5; i++){
        Node* newNode = new Node(nums[i]);
        temp->next = newNode;
        temp = temp->next;
    }
    temp->next = head;
    Solution s;
    cout << "Original Circular Linked List: ";
    printCircularLL(head);
    s.reversingCLL(head);
    cout << "Reversed Circular Linked List: ";
    printCircularLL(head);
}