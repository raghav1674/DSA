# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        i = head
        j = head
        for node in range(k):
            if node == k-1:
                 temp = j
            if j.next is None:
                temp = j
            j = j.next
            
        if j is None:
            i.val, temp.val = temp.val, i.val
            return head
        
        while j.next is not None:
            i = i.next
            j = j.next
        temp.val , i.next.val = i.next.val, temp.val
        return head
        
        
        