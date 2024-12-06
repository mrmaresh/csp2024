from time import sleep

for i in range(4):
    print("hi")

for i in range(5):
    for j in range(3):
        print(f"{i} + {j} = {i + j}")


for i in range(4):
    print("?", end = "")
print()


i = 1
while True:
    print(i)
    sleep(1)
    i = i * 2
    if i > 100000:
        break
