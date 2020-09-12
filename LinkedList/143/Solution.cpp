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
    void reorderList(ListNode* head) {
        
        if(head == nullptr || head->next == nullptr) return;
        
        ListNode* mid = middleNode(head);
        ListNode* tHead = mid->next;
        mid->next = nullptr;
        
        tHead = reverseList(tHead);
        
        ListNode* currList1 = head;
        ListNode* nextList1 = nullptr;
        ListNode* currList2 = tHead;
        ListNode* nextList2 = nullptr;
        
        while(currList1 != nullptr && currList2 != nullptr){
            
            nextList1 = currList1->next;
            nextList2 = currList2->next;
            
            currList1->next = currList2;
            currList2->next = nextList1;
            
            currList1 = nextList1;
            currList2 = nextList2;
              
        }
        
        
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
    }};