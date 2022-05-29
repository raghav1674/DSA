# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
    # Method - 1
        i = head
        j = head
        
        for node in range(n):
            j = j.next
        
        if j is None:
            return head.next
        
        while j.next is not None:
            i = i.next
            j = j.next
        i.next = i.next.next
        
        return head
        

# Method - 2    
        
#         length = 0
#         node = head
#         while node:
#             node = node.next
#             length += 1 
        
#         if length == 1:
#             head = None
#             return head
        
#         index = 1
#         tempNode = head
#         while index < length - n:
#             tempNode = tempNode.next
#             index += 1
#         if length == n:
#             head = tempNode.next
#         else:
#             tempNode.next = tempNode.next.next
        
#         return head

        
            
        
        
        