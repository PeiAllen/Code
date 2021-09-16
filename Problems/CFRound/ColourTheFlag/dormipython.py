t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    type=['.']*2
    poss=True
    for i in range(n):
        a=input()
        for j in range(m):
            if (a[j] != '.'):
                if (type[(i+j) % 2] == '.'):
                    type[(i+j) % 2]=a[j]
                else:
                    poss &= (type[(i+j) % 2] == a[j])
    if ((not poss) or (type[0] == type[1] and type[0] != '.')):
        print("no")
    else:
        print("yes")
        if (type[0] == '.'):
            if(type[1]=='R'):
                type[0]='W'
            else:
                type[0]='R'
        if (type[1] == '.'):
            if (type[0] == 'R'):
                type[1] = 'W'
            else:
                type[1] = 'R'
        for i in range(n):
            for j in range(m):
                print(type[(i+j) % 2],end="")
            print()