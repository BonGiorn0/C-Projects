import random

random.seed()
a = random.sample(range(10, 100), 40)
a = str(a)
with open("random.txt", "w") as f:
    f.write(a[1:len(a) - 1])
    f.write(' s')
