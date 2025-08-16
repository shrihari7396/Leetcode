class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode* curr = head;
        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                // skip duplicate node
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }
        return head;
    }
};
