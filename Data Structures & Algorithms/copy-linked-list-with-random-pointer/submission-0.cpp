/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL ;

        
       Node* curr = head ;
       while(curr != NULL){
        Node* newnode = new Node(curr->val) ;
        newnode->next = curr->next ;
        curr->next = newnode ;
        curr = newnode->next ;

       }
       
       curr = head ;

       while(curr != NULL){
        if(curr->random != NULL) {

        curr->next->random = curr->random->next ;
        
        }
              curr = curr->next->next ;
       }

       curr = head ;
       Node* newhead = head->next ;
       Node* newcurr = newhead ;

       while(curr != NULL){
        curr->next = newcurr->next ;
        curr = curr->next ;
     if(curr != NULL){
   
       newcurr->next = curr->next ;
        newcurr = newcurr->next ;
     }
        

       }
       return newhead ;
       
    }
};
