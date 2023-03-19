class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = NULL;
        while(head != NULL){
            ListNode* next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }
        return newHead;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        head = reverseList(head);
        ListNode* cur = head;
        int maxi = head->val;

        ListNode* prev = head;
        head = head->next;

        while(head) {
            if(head->val >= maxi) {
                maxi = head->val;
                prev = head;
                head = head->next;
            }
            else {
                prev->next = head->next;
                head = prev->next;
            }
        }

        head = reverseList(cur);
        return head;
    }
};