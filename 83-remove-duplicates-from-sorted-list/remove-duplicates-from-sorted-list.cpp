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
    ListNode* deleteDuplicates(ListNode* head) {
        int prev = INT_MIN;
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while(head && head -> next) {
            if(prev != head -> val) {
                ListNode* newNode = new ListNode(head -> val);
                curr -> next = newNode;
                curr = curr -> next;
                prev = head -> val;
            }
            head = head -> next;
        }
        if(head && prev != head -> val) {
            curr -> next = new ListNode(head->val);
        }
        return dummy -> next;
    }
};