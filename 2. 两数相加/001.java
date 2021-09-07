/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

public class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}
    class Solution {
        public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
            boolean overflow = false;
            int value;
            ListNode head=null;
            ListNode tail=null;
            while(l1!=null || l2!=null || overflow){
                value = (l1==null?0:l1.val) + (l2==null?0:l2.val) + (overflow?1:0);
                if(head==null){
                    head = new ListNode(value%10);
                    tail = head;
                }
                else{
                    tail.next = new ListNode(value%10);
                    tail = tail.next;
                }
                overflow = value>=10;
                l1 = l1==null?null:l1.next;
                l2 = l2==null?null:l2.next;
            }
            return(head);
        }
    }