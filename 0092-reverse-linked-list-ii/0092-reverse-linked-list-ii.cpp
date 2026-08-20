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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        dummy->next = head;
        for(int i =1;i<left;i++)
        {
            prev = prev->next;
        }
        ListNode* curr = prev->next;//left

        for(int i =0;i<right-left;i++)
        {
            ListNode* front = curr->next;
            curr->next = front->next;
            front->next = prev->next;
            prev->next = front;
        }
        return dummy->next;

    }
};