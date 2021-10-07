class MaxHeap:
    def __init__(self):
        self.heap = []

    def getParentPosition(self, i):
        return int((i-1)/2)

    def getLeftChildPosition(self, i):
        return 2*i+1

    def getRightChildPosition(self, i):
        return 2*i+2

    def hasParent(self, i):
        return self.getParentPosition(i) < len(self.heap)

    def hasLeftChild(self, i):
        return self.getLeftChildPosition(i) < len(self.heap)

    def hasRightChild(self, i):
        return self.getRightChildPosition(i) < len(self.heap)

    def insert(self, key):
        self.heap.append(key)
        self.heapify(len(self.heap) - 1)

    def getMax(self):
        return self.heap[0]

    def heapify(self, i):
        while(self.hasParent(i) and self.heap[i] > self.heap[self.getParentPosition(i)]): 
            self.heap[i], self.heap[self.getParentPosition(i)] = self.heap[self.getParentPosition(i)], self.heap[i]
            i = self.getParentPosition(i)

    def printHeap(self):
        print(self.heap)