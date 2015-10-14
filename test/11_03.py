

from heapq import *

def sortAlmostSorted(l, k):

  heap = []
  for i in range(len(l)):
    heappush(heap, l[i])
    print i, heap
    if len(heap) > k:
      l[i-k] = heappop(heap)

  i = len(l) - k
  while len(heap) > 0:
    print i, heap
    l[i] = heappop(heap)
    i += 1

x = [3, -1, 2, 6, 4, 5, 8]
sortAlmostSorted(x, 2)

print x
