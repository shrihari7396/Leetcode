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
    ListNode* sortList(ListNode* head) {
        ListNode* curr = head;
        vector<int> nums;
        while(curr) {
            nums.emplace_back(curr -> val);
            curr = curr -> next;
        }
        sort(nums.begin(), nums.end());
        curr = head;
        for(int i = 0; i < nums.size(); i++) {
            curr -> val = nums[i];
            curr = curr -> next;
        }
        return head;
    }
};