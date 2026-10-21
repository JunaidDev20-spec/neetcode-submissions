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
        ListNode* prev = nullptr;
        ListNode* temp = head;

        while (temp != nullptr) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
     
     if (head == nullptr || left == right) {
            return head;
        }

        
        ListNode* temp = head;
        ListNode* prev = nullptr;
        int count = 1;

        while (count < left) {
            count++;
            prev = temp;
            temp = temp->next;
        }

        ListNode* before = prev ;

        ListNode* newHead = temp;
        ListNode* subTail = newHead;
        

        while (count != right) {
            temp = temp->next;
            
            count++;
        }
        ListNode* subright = temp->next ;

        temp->next = nullptr;

        newHead = reverseList(newHead);

        if (before != nullptr) {
            before->next = newHead;
        } else {
            head = newHead;
        }

        subTail->next = subright;

        return head;
    }
};