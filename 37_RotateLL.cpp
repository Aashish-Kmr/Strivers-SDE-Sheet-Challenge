/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */
Node* rotate(Node* head, int k) {
    if (head == nullptr || head->next == nullptr || k == 0) {
        return head;
    }
    // Find the length of the linked list
    int length = 1;
    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
        length++;
    }
    k = k%length; 
    k  = length - k ;
    tail->next= head; 
    while(k--){
         tail= tail->next; 
    }
    head= tail->next; 
    tail->next= NULL;

    return head; 
}