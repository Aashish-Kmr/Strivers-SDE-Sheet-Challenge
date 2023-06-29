/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)

{   Node*ans=new Node();
    Node *h = ans;
    int carry=0;
    while(num1 && num2){
        int val= num1->data+ num2->data;
        h->next =new Node((val+carry)%10);
        carry = (val+carry)/10;
        num1= num1->next; 
        num2= num2->next;
        h = h->next;
    }
    while(num1){
        int val=num1->data;
        h->next=new Node((carry+val)%10);
        num1= num1->next;
        h=h->next;
        carry=(carry+val)/10;
    }
    while(num2){
     int val=num2->data;
        h->next=new Node((carry+val)%10);
        num2= num2->next;
        h=h->next;
        carry=(carry+val)/10;
    }
    if(carry>0)
        h->next=new Node(1);

    return ans->next;
}
