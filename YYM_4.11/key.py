for n in range(1, 201): #前闭后开区间
    p = 1
    s = '1'
    while int(s) % n != 0: #二进制枚举
        s = bin(p)
        s = s[2:len(s)]
        p += 1
    print(s,end=',')