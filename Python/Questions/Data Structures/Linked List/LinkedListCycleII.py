# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        map_ = {}
        temp = head
        index = 0
        while temp:
            if temp in map_:
                return temp
            map_[temp] = index
            index += 1
            temp = temp.next
        return None

