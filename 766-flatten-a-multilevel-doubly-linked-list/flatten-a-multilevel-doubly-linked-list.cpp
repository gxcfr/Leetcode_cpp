class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL){
            return head;
        }        

        Node* curr = head;

        while (curr){
            if (curr->child != NULL){
                Node* next = curr->next; //flatten
                curr->next = flatten(curr->child);

                curr->next->prev = curr;
                curr->child = NULL;

                //find tail
                while (curr->next){
                    curr= curr->next;
                }

                //attach tail to next ptr
                if (next){
                    curr->next = next;
                    next->prev = curr;
                }

            }

            curr = curr->next;
        }
        return head;
    }
};