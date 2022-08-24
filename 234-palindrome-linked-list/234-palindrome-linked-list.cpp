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
    bool isPalindrome(ListNode* head) {
        int sum1 =0,sum2 =0;
        ListNode* tortoise = nullptr;
        ListNode* hare = head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        if(!head)
            return false;
        if(!head->next)
            return true;
        while(hare && hare->next)
        {
            hare = hare->next->next;
            tortoise = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tortoise;
        }
        if(hare== NULL)
            tortoise = tortoise;
        else
            tortoise = tortoise->next;
        hare = prev;
        while(tortoise)
        {
            if(tortoise->val!=hare->val)
                return false;
            tortoise = tortoise->next;
            hare=hare->next;
        }
        return true;
        
    }
};