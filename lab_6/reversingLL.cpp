#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int val) : val(val), next(NULL) {} 
};

class Solution{
    public:
    void reversingLL(Node* &head){
        Node* temp = head;
        Node* prev = NULL;
        if(!head->next) return;
        Node* next = head->next;
        while(temp->next){
            temp->next = prev;
            prev = temp;
            temp = next;
            next = next->next;
        }
        temp->next = prev;
        head = temp;
    }
};
void printLL(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    Node* head = new Node(10);
    Node* temp = head;
    int nums[5] = {3,7,9,6,2};
    for(int i=0; i<5; i++){
        temp->next = new Node(nums[i]);
        temp = temp->next;
    }
    Solution s;
    s.reversingLL(head);
    printLL(head);
}