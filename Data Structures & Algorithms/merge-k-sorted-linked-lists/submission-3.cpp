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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head1 = list1 ;
        ListNode* head2 = list2 ;

        if(head1 == nullptr) return list2 ;
        if(head2 == nullptr) return list1 ;

        ListNode* head ;
        ListNode* tail ;

        if(head1->val <= head2->val){
                head = head1 ;
                tail = head ;
                head1 = head1->next ;

            }else{
                head = head2 ;
                tail = head ;
                head2 = head2->next ;
            }

        while(head1 != nullptr && head2 != nullptr) {

            if(head1->val <= head2->val){
                tail->next = head1 ;
                tail = head1 ;
                head1 = head1->next ;

            }else{
                tail->next = head2;
                tail = head2 ;
                head2 = head2->next ;
            }
        }

        if(head1 != nullptr){
            tail->next = head1 ;

        }else{
            tail->next = head2 ;

        }
        return head ;
    }



    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size() ;

      if (lists.empty()) return nullptr;

        for(int interval = 1; interval < k ; interval *= 2 ){
            for(int i = 0 ; i+ interval < k ; i += 2 * interval){
                lists[i] = mergeTwoLists(lists[i] , lists[i+interval]) ;
            }
        }

        return lists[0];    
    }
};