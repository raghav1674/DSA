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
                



SLinkedList = singlyLinkedList()
SLinkedList.insertNode(1,0)
SLinkedList.insertNode(2,1)
SLinkedList.insertNode(3,2)
SLinkedList.insertNode(4,3)
SLinkedList.insertNode(5,4)
SLinkedList.insertNode(6,4)

# SLinkedList.traverseSLL()
print(SLinkedList.searchElement(6))
# print([node.value for node in SLinkedList])