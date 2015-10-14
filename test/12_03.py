x = [-2, 0, 2, 3, 6, 7, 9]

def findMatchingIndex(x):
  l = 0
  r = len(x)-1
  while r >= l:
    mid = l + (r-l)/2
    val = x[mid] - mid
    if val == 0:
      return mid
    elif val > 0:
      r = mid - 1
    else:
      l = mid + 1
  return .1

print x
print findMatchingIndex(x)