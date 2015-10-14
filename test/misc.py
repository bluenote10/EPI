

def fibLoop(n):
  if n == 1: return 1
  elif n == 2: return 1
  else:
    a = 1
    b = 1
    for _ in range(0, n-2):
      fib = a + b
      b = a
      a = fib
    return fib


# tail recursive fibo
def fibrec(steps, fibA, fibB):
  print steps, fibA, fibB
  if steps == 0: # we could also terminate on steps == 1 and return fibA + fibB
    return fibA
  else:
    return fibrec(steps-1, fibA+fibB, fibA)

def fib(n):
  res = {1: 1, 2: 1}.get(n)
  return res or fibrec(n-2, 1, 1)

for i in range(1,6):
  print "recursive:", i, fib(i)
  print "loop:     ", i, fibLoop(i)






import random
def mcrun(k, p = 0.5):
  i = 0
  while k > 0:
    toss = random.random() < p
    if toss:
      k -= 1
    i += 1
  return i

trials = []
for i in range(0, 1000):
  trial = mcrun(2, 0.1)
  #print trial
  trials.append(trial)

print 1.0 * sum(trials) / len(trials)

