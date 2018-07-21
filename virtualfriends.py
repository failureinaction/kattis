#Virtual friends using disjoint set datastructure. Runtime 0.39s according to kattis.
from sys import stdin

class DisjointSet:
    def __init__(self):
        self.root = {}
        self.sets = {}

    def addSet(self, x):
        self.root[x] = x
        self.sets[x] = [x]

    def find(self, x):
        if self.root[x] == x:
            return x
        self.root[x] = self.find(self.root[x])
        return self.root[x]

    def unite(self, x, y):
        if self.root[x] == self.root[y]:
            return
        xparent = self.find(x)
        yparent = self.find(y)
        if len(self.sets[xparent]) >= len(self.sets[yparent]):
            for item in self.sets[yparent]:
                self.sets[xparent].append(item)
                self.root[item] = xparent
            self.sets[yparent] = [yparent]
        else:
            for item in self.sets[xparent]:
                self.sets[yparent].append(item)
                self.root[item] = yparent
            self.sets[xparent] = [xparent]

def main():
    cases = int(stdin.readline())
    for _ in range(cases):
        ds = DisjointSet()
        friendships = int(stdin.readline())
        for _ in range(friendships):
            friends = stdin.readline().split()
            a, b = friends[0], friends[1]
            try:
                ds.find(a)
            except KeyError:
                ds.addSet(a)
            try:
                ds.find(b)
            except:
                ds.addSet(b)
            ds.unite(a, b)
            print(len(ds.sets[ds.find(a)]))

if __name__ == "__main__":
    main()
