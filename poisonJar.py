import random

def find(n):
    print("\n<<< 술단지", n, "개 >>>")

    k = 0
    while 2**k < n:
        k += 1
    print("필요한 최소 신하 수:", k, "명")

    poison = random.randint(0, n-1)
    print("실제 독단지:", poison, "번")

    servant = {i: [] for i in range(k)}

    print("\n술단지 번호와 이진수:")
    for jar in range(n):  
        b = bin(jar)[2:]         
        b = '0'*(k - len(b)) + b 
        print(jar,"번", "->", b)
        for i in range(k):
            if b[-1-i] == '1':
                servant[i].append(jar)

    print("\n신하별 마시는 술:")
    for s, jars in servant.items():
        print("신하", s, ":", jars,"번")

    dead = []
    b = bin(poison)[2:]
    b = '0'*(k - len(b)) + b
    for i in range(k):
        if b[-1-i] == '1':
            dead.append(i)
    print("\n죽은 신하:", "신하", dead)

    found = sum(2**i for i in dead)
    print("찾아낸 독단지:", found, "번")

find(4)
find(6)
find(10)