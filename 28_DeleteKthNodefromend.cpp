/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int k)
{
    int count=0;
    Node*n1= head;
    while(n1){
        count++;
        n1=n1->next;
    }
    if (k <= 0 || k > count) {
        return head;
    }
    // count has number of node present 
    n1= head;
    count = count-k;
    while(count>1){
        n1 = n1->next;
        count--;
    }
    if (count == 0) {
        return head->next;
    }

    n1->next= n1->next->next;
    return head;
}
