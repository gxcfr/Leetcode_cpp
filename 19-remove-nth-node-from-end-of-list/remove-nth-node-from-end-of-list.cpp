class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* front = dummy;
        ListNode* back = dummy;

        // Move front n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            front = front->next;
        }

        while (front) {
            front = front->next;
            back = back->next;
        }

        back->next = back->next->next;

        ListNode* ans = dummy->next;
        delete dummy;   // Prevent memory leak

        return ans;
    }
};