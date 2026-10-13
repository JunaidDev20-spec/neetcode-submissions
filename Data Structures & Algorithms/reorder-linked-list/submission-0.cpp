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
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next== nullptr) {
            return ;

        }

        ListNode* slow = head ;
        ListNode* fast = head ;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

        }

        ListNode* second = slow->next ;
        slow->next = nullptr ;
        ListNode* prev = nullptr ;
        ListNode*  curr = second ;


        while(curr != NULL){
            ListNode* nextnode = curr->next ;
            curr->next = prev ;
            prev = curr ;
            curr = nextnode ;

        }
        
        second = prev ;
        ListNode* first = head ;

        while(second != nullptr){

        ListNode* temp1 = first->next ;
        ListNode* temp2 = second->next;

        first->next = second ;
        second->next = temp1 ;

        first = temp1 ;
        second = temp2 ;
        }

    }
};
