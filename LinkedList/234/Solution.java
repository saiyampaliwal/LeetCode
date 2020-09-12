/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        
        if(head == null || head.next == null) return true;
        
        ListNode mid = middleNode(head);
        ListNode tHead = mid.next;
        
        tHead = reverseList(tHead);
        
        boolean res = true;
        
        ListNode c1 = head;
        ListNode c2 = tHead;
        
        while(c1 != null && c2 != null){
            
            if(c1.val != c2.val){
                res = false;
                break; 
            }
            
            c1 = c1.next;
            c2 = c2.next;
        }
        
        tHead = reverseList(tHead);
        mid.next = tHead;
        
        return res;
    }
    
    public ListNode middleNode(ListNode head){
        
        if(head == null || head.next == null) return head;
        
        ListNode slow = head;
        ListNode fast = head;
        
        while(fast.next != null && fast.next.next != null){
            fast = fast.next.next;
            slow = slow.next;
            
        }
        return slow;
    }
    
    public ListNode reverseList(ListNode head){
        
        if(head == null || head.next == null) return head;
        
        ListNode prev = null;
        ListNode curr = null;
        ListNode forw = head;
        
        while(forw !=  null){
            curr = forw;
            forw = forw.next;
            
            curr.next = prev;
            prev = curr;
        }
        
        return prev;
    }
}