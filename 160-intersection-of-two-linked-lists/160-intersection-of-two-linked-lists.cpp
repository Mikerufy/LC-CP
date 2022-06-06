/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int count_a = 0, count_b = 0 , diff =0;
        ListNode* trackerA = headA;
        ListNode* trackerB = headB;
        while(trackerA)
        {
            trackerA=trackerA->next;
            count_a++;
        }
        while(trackerB)
        {
            trackerB=trackerB->next;
            count_b++;
        }
        trackerA = headA;
        trackerB = headB;
        if(count_a>count_b)
        {
            diff = (count_a-count_b);
            while(diff--)
                trackerA=trackerA->next;
        }
        else
        {
            diff = (count_b-count_a);
            while(diff--)
                trackerB=trackerB->next;
        }
        
        while(trackerA!=trackerB)
        {
            trackerA=trackerA->next;
            trackerB=trackerB->next;
        }
        return trackerA;
    }
};