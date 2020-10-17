class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return head;
        // copy list node and insert it between this node and next node.
        Node* nhead = head;
        while(nhead) {
            Node* tmp = new Node(nhead->val);
            tmp->next = nhead->next;
            nhead->next = tmp;
            nhead = nhead->next->next;
        }
        // copy all the random links to the new nodes.
        nhead = head;
        Node* newhead = nhead->next;
        while(nhead) {
            newhead->random = nhead->random == NULL ? NULL : nhead->random->next;
            nhead = newhead->next;
            if(nhead == NULL)
                break;
            newhead = nhead->next;
        }
        
        // decouple the new nodes and old nodes
        nhead = head;
        newhead = nhead->next;
        Node* ans = nhead->next;
        while(nhead) {
            Node * tmp = newhead->next;
            nhead->next = newhead->next;
            nhead = newhead->next;
            if(nhead == NULL)
                break;
            newhead->next = nhead->next;
            newhead = nhead->next;
        }
        return ans;
    }
};
