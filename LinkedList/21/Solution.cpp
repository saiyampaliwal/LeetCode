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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1 == nullptr || l2 == nullptr) return l1==nullptr?l2:l1;
        
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        
        ListNode* c1 = l1;
        ListNode* c2 = l2;
        
        while(c1 != nullptr && c2 != nullptr){
            
            if(c1->val < c2->val){
                prev->next = c1;
                c1 = c1->next;
            }
            else{
                prev->next = c2;
                c2 = c2->next;
            }
            
            prev = prev->next;
        }
        
        if(c1==nullptr) prev->next = c2;
        else prev->next = c1;
        
        return dummy->next;
    }
};