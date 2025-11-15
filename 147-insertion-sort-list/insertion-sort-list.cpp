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
    ListNode* insertionSortList(ListNode* head) {
        vector<ListNode*> ans;
        while(head) {
            ans.emplace_back(head);
            head = head -> next;
        }

        sort(ans.begin(), ans.end(), [&](ListNode* first, ListNode* second) {
            if(first->val <= second -> val) return true;
            return false;
        });

        head = nullptr;
        ListNode* finalAns = nullptr;
        for(int i = 0; i < ans.size(); i++) {
            if(i == 0) {
                head = ans[i];
                finalAns = head;
            } else {
                head -> next = ans[i];
                head = head -> next;
            }
        }
        head -> next = nullptr;
        return finalAns;
    }
};