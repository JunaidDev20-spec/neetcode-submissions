/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return head ;

        }

        
        int totalnodes =0 ;
        ListNode* more = head ;
        while(more != nullptr){
            totalnodes++;
            more = more->next ;
        }

        if(n == totalnodes){
    ListNode* temp = head;
    head = head->next;
    delete temp;
    return head;
}
        
        int count = 0 ;
        ListNode* prev = NULL ;
        ListNode* temp = head ;



        while(temp != NULL){
        count++;
        if(count == totalnodes -n + 1){
            prev->next = temp->next ;
            delete temp ;

            break;
        }
        prev = temp ;
        temp = temp->next ;

        }
        
        return head;

    }
};
