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

Node *findMiddle(Node *head) {
    Node* move1, *prec;
    move1=head;
    prec=head;
    if(!move1->next){
        return head;
    }
    while(move1){
        if(!move1->next)
            return prec;
        if(move1->next->next){
            prec=prec->next;
        }
        if(move1->next && !move1->next->next)
            return prec->next;

        if(!move1->next)
            return prec->next;
        move1= move1->next->next;
    }
    
}

