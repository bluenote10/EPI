

def testLetter1(letter, mag):
  counts = {}
  for c in mag:
    c = c.upper()
    if c != ' ':
      counts[c] = (counts.get(c) or 0) + 1
  print counts
  for c in letter:
    c = c.upper()
    if c != ' ':
      count = counts.get(c)
      if count is not None:
        counts[c] -= 1
        if counts[c] < 0:
          print 'letter has too low frequency:', c
          return False
      else:
        print 'letter does not exist:', c
        return False
  print counts
  return True

def testLetter2(letter, mag):
  counts = {}
  for c in letter:
    c = c.upper()
    if c != ' ':
      counts[c] = (counts.get(c) or 0) + 1
  print counts
  for c in mag:
    c = c.upper()
    if c != ' ':
      count = counts.get(c)
      if count is not None:
        counts[c] -= 1
        if counts[c] == 0:
          del counts[c]
      if len(counts) == 0:
        return True

  print 'There are remaining characters:', counts
  return False

letter = "Is this printable"

mag = "Hello World Magazine with really few, stupid words" # . But enough."

print testLetter2(letter, mag)






