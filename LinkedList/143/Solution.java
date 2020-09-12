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
    public void reorderList(ListNode head) {
        
        if(head == null || head.next == null) return;
        
        ListNode mid = middleNode(head);
        ListNode tHead = mid.next;
        mid.next = null;
        
        tHead = reverseList(tHead);
        
        ListNode currList1 = head;
        ListNode nextList1 = null;
        ListNode currList2 = tHead;
        ListNode nextList2 = null;
        
        while(currList1 != null && currList2 != null){
            
            nextList1 = currList1.next;
            nextList2 = currList2.next;
            
            currList1.next = currList2;
            currList2.next = nextList1;
            
            currList1 = nextList1;
            currList2 = nextList2;
              
        }
        
        
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