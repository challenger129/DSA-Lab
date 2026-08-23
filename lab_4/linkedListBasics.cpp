#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* next;
    int data;
    Node(int data): data(data), next(NULL){}
};
class Solution{
    public:
        void insertInStarting(Node*& head, int val){
            Node* newNode = new Node(val);
            newNode->next = head;
            head = newNode;
        }
        void insertAtEnd(Node*& head, int val){
            Node* newNode = new Node(val);
            Node* temp = head;
            if(!head) {
                head = newNode;
                return; 
            }
            while(temp->next){
                temp = temp->next;
            }
            temp->next = newNode;
        }
        void insertAtMiddle(Node*& head, int val, int posi){
            Node* newNode = new Node(val);
           if(posi == 1){
            insertInStarting(head, val);
           }
           Node* temp = head;
           int cnt = 2;
           while(temp && cnt < posi){
                temp = temp->next;
                cnt++;
           }
           if(temp){
                Node* next = temp->next;
                temp->next = newNode;
                newNode->next = next;
           }
        }
        void deleteHead(Node* &head){
            if(!head)return;
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        void deleteTail(Node* &head){
            if(!head)return;
            Node* temp = head;
            Node* prev;
            while(temp->next){
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL;
            delete temp;
        }
        void deleteAtMiddle(Node* &head, int posi){
            if(!head)return;
            if(posi == 1){
                deleteHead(head);
                return;
            }
            int cnt = 2;
            Node* temp = head;
            while(temp && cnt < posi){
                temp = temp->next;
                cnt++;
            }
            if(temp == NULL || temp->next == NULL){
                return;
            }
            Node* next = temp->next->next;
            delete temp->next;
            temp->next = next;        
        }
};
void printList(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
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
        temp = temp->next;
    }
    Solution s;
    printList(head);
    s.insertInStarting(head, 1);
    printList(head);
    s.insertAtEnd(head, 5);
    printList(head);
    s.insertAtMiddle(head, 4, 3);
    printList(head);
    s.deleteHead(head);
    printList(head);
    s.deleteTail(head);
    printList(head);
    s.deleteAtMiddle(head, 3);
    printList(head);
}