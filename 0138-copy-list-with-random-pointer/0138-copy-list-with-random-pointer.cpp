class Solution {
public:

    Node* copyRandomList(Node* head) {

        if(head == NULL)
            return NULL;

        unordered_map<Node*, Node*> mp;

        // Create first node
        Node* newHead = new Node(head->val);

        mp[head] = newHead;

        Node* oldtemp = head->next;
        Node* newtemp = newHead;

        // First pass: copy all nodes
        while(oldtemp != NULL)
        {
            Node* copyNode = new Node(oldtemp->val);

            mp[oldtemp] = copyNode;

            newtemp->next = copyNode;

            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }

        // Second pass: copy random pointers
        oldtemp = head;
        newtemp = newHead;

        while(oldtemp != NULL)
        {
            if(oldtemp->random != NULL)
                newtemp->random = mp[oldtemp->random];

            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }

        return newHead;
    }
};