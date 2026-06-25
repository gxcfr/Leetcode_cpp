class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL){
            return NULL;
        }

        unordered_map<Node*, Node*>m;
        Node* newHead = new Node (head->val);
        Node* oldtemp = head->next;
        Node* newtemp =  newHead;
        m[head] = newHead;

        while (oldtemp != NULL){ // plain copy
            Node* copyNode = new Node(oldtemp->val);
            m[oldtemp]= copyNode;
            newtemp->next = copyNode;

            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }   

        oldtemp  = head;
        newtemp = newHead;

        while (oldtemp){ //copying random links
            newtemp->random = m[oldtemp->random];
            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }

        return newHead;
    }
};