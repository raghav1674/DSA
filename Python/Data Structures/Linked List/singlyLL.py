#!/bin/bash
class Node:
    def __init__(self, value=None):
        self.value = value
        self.next = None

class singlyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def __iter__(self):
        node = self.head
        while node:
            yield node
            node = node.next
    
    def insertNode(self, value, location):
        newNode = Node(value)
        if self.head is None:
            self.head = newNode
            self.tail = newNode
        else:
            if location == 0:
                newNode.next = self.head
                self.head = newNode
            elif location == -1:
                newNode.next = None
                self.tail.next = newNode
                self.tail = newNode
            else:
                tempNode = self.head
                index = 0
                while index < location - 1:
                    tempNode = tempNode.next
                    index += 1
                nextNode = tempNode.next
                tempNode.next = newNode
                newNode.next = nextNode
                if tempNode == self.tail:
                    self.tail = newNode

    def traverseSLL(self):
            if self.head is None:
                print("Singly Linked List Is Empty!!")
            else:
                node = self.head
                while node is not None:
                    print(node.value, end=" ")
                    node = node.next

    def searchElement(self, nodeValue):
        if self.head is None:
            print("Singly Linked List Is Empty!!")
        else:
            node = self.head
            while node is not None:
                if node.value == nodeValue:
                    return str(node.value) + ": Value Found!!"
                node = node.next
        return "The value does not exist in the list!!"
    
    def deleteNode(self, nodeValue):
        if self.head.next is None:    # Or, if self.head == self.tail:
            self.head = None
            self.tail = None
        elif self.head.value == nodeValue:
            self.head = self.head.next
        else:
            tempNode = self.head
            while tempNode is not None:
                currentNode = tempNode
                tempNode = tempNode.next
                if tempNode.value == nodeValue:
                    currentNode.next = tempNode.next
                    return 


# #   1 2 3 4
# #   0 1 2 3
#     def deleteNode(self, location):
#         if self.head is None:
#             print("Singly Linked List Is Empty!!")
#         elif self.head.next is None:
#             self.head = None
#             self.tail = None
#         elif location == 0:
#             self.head = self.head.next
#         else:
#             tempNode = self.head
#             index = 0
#             while index < location - 1:
#                 tempNode = tempNode.next
#                 index += 1
#             nextNode = tempNode.next.next
#             tempNode.next = nextNode
    
            

SLinkedList = singlyLinkedList()
SLinkedList.insertNode(2,0)
SLinkedList.insertNode(3,1)
SLinkedList.insertNode(1,2)
SLinkedList.insertNode(7,3)
# SLinkedList.insertNode(5,4)
# SLinkedList.insertNode(6,5)
# SLinkedList.insertNode(7,6)
# SLinkedList.insertNode(8,7)
# SLinkedList.insertNode(9,8)
# SLinkedList.insertNode(10,9)
# SLinkedList.insertNode(11,10)
print("List Before Deleting: ", end=" ")
print([node.value for node in SLinkedList])


# SLinkedList.traverseSLL()
# print(SLinkedList.searchElement(6))
SLinkedList.deleteNode(2)
# SLinkedList.deleteNode(2)
# SLinkedList.deleteNode(4)
# SLinkedList.deleteNode(6)
# SLinkedList.deleteNode(8)
# SLinkedList.deleteNode(10)
print("List After Deleting: ", end=" ")
print([node.value for node in SLinkedList])