class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return NULL;

        // ListNode* dummy = new ListNode(-1);
        // dummy->next = head;
        // ListNode* cur = dummy;

        // while(cur != NULL && cur->next != NULL) {
        //     if(cur->next->val == val) {
        //         ListNode* temp = cur->next;
        //         cur->next = cur->next->next;
        //         delete temp;
        //     }
        //     else {
        //         cur = cur->next;
        //     }
        // }
        // return dummy->next;

        // Recursion
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};