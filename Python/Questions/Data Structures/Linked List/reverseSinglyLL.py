import json
from re import template

class NodeJSONEncoder(json.JSONEncoder):
    def default(self, obj):
        return str(obj)

class Node:
    def __init__(self, value=None) -> None:
        self.value = value
        self.next = None
        self.id = str(hex(id(self)))
    
    def __str__(self):
        return str(hex(id(self)))

    def __repr__(self):
        return "[" + str(hex(id(self))) + "], " + str(self.value)
    
class singlyLL:
    def __init__(self):
        self.head = None
        self.tail = None
    
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
                    # print(tempNode.value)
                nextNode = tempNode.next
                tempNode.next = newNode
                newNode.next = nextNode
                if tempNode == self.tail:
                    self.tail = newNode
    
    def __iter__(self):
        node = self.head
        while node:
            yield node
            node = node.next

    def iterativeReverseSinglyLL(self): # iterative
        prev = None
        current = self.head
        while current:
            tempNode = current.next
            current.next = prev
            prev = current
            current = tempNode
        self.head = prev
    

    def recursiveReverseSinglyLL(self):
        head = self.head
        new_head = self.recursiveReverseSinglyLLHelper(head)
        self.head = new_head


    def recursiveReverseSinglyLLHelper(self, head):
        print(head)
        if head is None or head.next is None:
            return head
        else:
            new_head = self.recursiveReverseSinglyLLHelper(head.next)
            head.next.next = head
            head.next = None
        return new_head



        



         
        
    

SLinkedList = singlyLL()
SLinkedList.insertNode(0,0)
SLinkedList.insertNode(1,1)
SLinkedList.insertNode(2,2)
SLinkedList.insertNode(3,3)
SLinkedList.insertNode(4,4)
SLinkedList.recursiveReverseSinglyLL()


data = [node.__dict__ for node in SLinkedList]
#result = NodeJSONEncoder().encode(data)
result = json.dumps(json.loads(NodeJSONEncoder().encode(data)),indent=4)
print(result)