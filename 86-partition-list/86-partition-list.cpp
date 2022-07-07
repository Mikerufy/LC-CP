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
    ListNode* partition(ListNode* head, int x) {
        ListNode *left = new ListNode(0),*right= new ListNode(0),*tmp=head;
        ListNode *a = left,*b = right;
        while(tmp){
            if(tmp->val < x){
                left->next = tmp;
                tmp=tmp->next;
                left=left->next;
            }else if(tmp->val >=x){
                right->next = tmp;
                tmp=tmp->next;
                right=right->next;
            }
        }
        right->next = NULL;
        left->next = b->next;
        ListNode *ans = a->next;
        return ans;
    }
};