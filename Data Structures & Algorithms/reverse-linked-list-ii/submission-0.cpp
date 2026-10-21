class Solution {
public:

    // Standard reverse linked list function
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

        // 1. Reach the node at position left
        while (count < left) {
            prev = temp;
            temp = temp->next;
            count++;
        }

        // Preserve the connection before the sublist
        ListNode* before = prev;

        // Preserve the original first node of the sublist
        ListNode* subHead = temp;

        // 2. Reach the node at position right
        while (count < right) {
            temp = temp->next;
            count++;
        }

        // 3. Preserve the remaining list
        ListNode* after = temp->next;

        // 4. Isolate the sublist
        temp->next = nullptr;

        // 5. Reverse the isolated sublist
        ListNode* newHead = reverseList(subHead);

        // 6. Reconnect the reversed sublist to the remaining list
        if (before != nullptr) {
            before->next = newHead;
        } else {
            head = newHead;
        }

        // The original sublist head is now its tail
        subHead->next = after;

        return head;
    }
};