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
    public ListNode mergeNodes(ListNode head) {
        int sum = 0;
        ListNode ans, root = new ListNode();
        ans = root;
        while(head != null){
            if(head.val==0 && sum!=0){
                ans.next = new ListNode(sum);
                ans = ans.next;
                sum = 0;
            }
            sum+=head.val;
            head = head.next;
        }
        return root.next;
    }
}