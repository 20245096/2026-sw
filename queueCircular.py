class CircularQueue :
    def __init__( self, maxSize=20 ) :
        self.front = 0
        self.rear = 0
        self.MaxSize = maxSize
        self.items = []
        for i in range( self.MaxSize ) :
            self.items.append(0)
        
    def isEmpty( self ) :
       return self.front == self.rear

    def isFull( self ) :
       return self.front == (self.rear+1)%self.MaxSize

    def __len__( self ) :
       return (self.rear - self.front + self.MaxSize) % self.MaxSize

    def enqueue( self, item ):
        if not self.isFull():
            self.rear = (self.rear + 1) % self.MaxSize
            self.items[self.rear] = item

    def dequeue( self ):
        if not self.isEmpty():
            self.front = (self.front + 1) % self.MaxSize
            return self.items[self.front]

    def peek( self ):
        if not self.isEmpty():
            return self.items[(self.front + 1) % self.MaxSize]

    def print( self ):
        list = []
        if self.front < self.rear :
            list = self.items[self.front+1:self.rear+1]
        else:
            list1 = self.items[self.front+1:self.MaxSize]
            list2 = self.items[0:self.rear+1]
            list = list1 + list2
        print(list)
