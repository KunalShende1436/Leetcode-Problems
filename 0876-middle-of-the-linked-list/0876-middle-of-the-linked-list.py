# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:

        temp_var = head
        count = 0
        while temp_var:
            count += 1
            temp_var=temp_var.next
        mid_index = count // 2 
        
        temp_var = head
        for i in range(mid_index):
            temp_var=temp_var.next
        return temp_var