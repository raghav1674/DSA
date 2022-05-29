# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        temp = head
        if not head:
            return head
        if temp.next is None:
            return head
        # 1 -> 2 -> 3 -> 4
        while temp is not None:
            if temp == head:
                store = temp.next
                temp.next = temp.next.next
                store.next = temp
                head = store
            # 2 -> 1 -> 3 -> 4
            else:
                store = temp.next # 4
                if temp.next:
                    temp.next = temp.next.next # 3 -> None
                    store.next = temp  # 2 -> 1  4 -> 3
                    prev.next = store   # 2 -> 1 -> 4 -> 3
                
            prev = temp # 1            
            temp = temp.next # 3
             # 2 -> 1 -> 3 -> 4
            
            
        return head
            
        
        