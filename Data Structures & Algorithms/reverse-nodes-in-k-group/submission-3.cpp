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
   ListNode* reverseList(ListNode* head) {
    ListNode* temp = head ;
    ListNode* prev = nullptr ;

    while(temp != nullptr ){
        ListNode* front = temp->next ;
        temp ->next = prev ;
        
        prev = temp ;
        temp = front ;

        
    }
    return temp ;

   }

   ListNode* getKthNode(ListNode* temp , int k){
    k -= 1 ;
    while(temp != nullptr && k>0){
        k-- ;

        temp = temp->next ;

    }
    return temp ;
   }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head ;
        ListNode* prevLast = nullptr ;

        while(temp != nullptr){
            ListNode* kthNode = getKthNode(temp , k) ;
            if(kthNode == nullptr){
                if(prevLast != nullptr){
                    prevLast->next = temp ;

                }
                break ;

            }

            ListNode* nextN = kthNode->next ;

            kthNode->next = nullptr ;

            reverseList(temp) ;
            
            if(head == temp){
                head = kthNode ;

            }else{
                prevLast->next = kthNode ;

            }

             prevLast = temp ;
             temp = nextN ;

            
            

        }
        return head ;

    }
};
