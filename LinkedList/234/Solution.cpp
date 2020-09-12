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
        
        if(head == nullptr || head->next == nullptr) return true;
        
        ListNode* mid = middleNode(head);
        ListNode* tHead = mid->next;
        
        tHead = reverseList(tHead);
        
        bool res = true;
        
        ListNode* c1 = head;
        ListNode* c2 = tHead;
        
        while(c1 != nullptr && c2 != nullptr){
            
            if(c1->val != c2->val){
                res = false;
                break;
            }
            
            c1 = c1->next;
            c2 = c2->next;
        }
        
        tHead = reverseList(tHead);
        mid->next = tHead;
        
        return res;
    }
    
    ListNode* middleNode(ListNode* head){
        
        if(head == nullptr || head->next == nullptr) return head;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
            
        }
        return slow;
    }
    
    ListNode* reverseList(ListNode* head){
        
        if(head == nullptr || head->next == nullptr) return head;
        
        ListNode* prev = nullptr;
        ListNode* curr = nullptr;
        ListNode* forw = head;
        
        while(forw !=  nullptr){
            curr = forw;
            forw = forw->next;
            
            curr->next = prev;
            prev = curr;
        }
        
        return prev;
    }
};