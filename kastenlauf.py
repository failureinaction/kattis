#Kastenlauf using dfs
from sys import stdin

class Node:
    def __init__(self, item):
        self.value = item
        self.next = None

class Stack:
    def __init__(self):
        self.first = None

    def push(self, item):
        node = Node(item)
        if self.first != None:
            node.next = self.first
        self.first = node

    def pop(self):
        if self.first == None:
            return None
        returnnode = self.first
        self.first = self.first.next
        return returnnode.value

    def isEmpty(self):
        return self.first == None

t = int(stdin.readline())

for _ in range(t):
    n = int(stdin.readline())
    grid = {}
    locations = []
    
    for i in range(n + 2):
        line = stdin.readline().split()
        x, y = int(line[0]), int(line[1])
        locations.append((x, y))
        grid[(x, y)] = []
        for c in locations:
            if abs(c[0] - x) + abs(c[1] - y) <= 1000:
                grid[(x, y)].append((c[0], c[1]))
                grid[(c[0], c[1])].append((x, y))
    start = locations[0]
    end = locations[-1]
    s = Stack()
    visited = []
    s.push(start)
    happy = False
    while not s.isEmpty():
        current = s.pop()
        if current == end:
            happy = True
            break
        if current not in visited:
            visited.append(current)
            for item in grid[current]:
                if item not in visited:
                    s.push(item)
            
    if happy:
        print("happy")
    else:
        print("sad")
