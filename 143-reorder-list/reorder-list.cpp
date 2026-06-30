class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL){
            return;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next){ //finding middle
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* second = slow->next; //reversing the second LL
        slow->next = nullptr;

        ListNode* prev = nullptr;
        while (second) {
            ListNode* nextNode = second->next;
            second->next = prev;
            prev = second;
            second = nextNode;
        }

        ListNode* first = head; //merging both
        second = prev;

        while (second) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};