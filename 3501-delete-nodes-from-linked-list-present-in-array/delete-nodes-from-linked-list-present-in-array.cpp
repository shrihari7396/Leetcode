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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy, *curr = head;
        unordered_set<int> hash(nums.begin(), nums.end());
        
        while(curr) {
            if(hash.find(curr -> val) == hash.end()) {
                prev -> next = curr;
                prev = prev -> next;
            }
            curr = curr -> next;
        }

        prev -> next = nullptr;
        return dummy -> next;
    }
};