def current(Na, Ma, cin):
    A1 = list(map(float, cin.readline().split()))
    A = []
    l = 0
    r = Ma
    for i in range(Na):
        A.append([])
        for p in range(l, r):
            A[i].append(A1[p])
        l = l + Ma
        r = r + Ma
    return A


def sum(a, b, na, ma, nb, mb):
    if na != nb or ma != mb:
        return 0
    c = []
    for i in range(na):
        c.append([])
        for j in range(ma):
            c[i].append(a[i][j] + b[i][j])
    return c


def dif(a, b, na, ma, nb, mb):
    if na != nb or ma != mb:
        return 0
    c = []
    for i in range(na):
        c.append([])
        for j in range(ma):
            c[i].append(a[i][j] - b[i][j])
    return c


def transpose(a, n, m):
    c = []
    for i in range(m):
        c.append([])
        for j in range(n):
            c[i].append(a[j][i])
    return c


def multiNum(a, n, m, k):
    c = []
    for i in range(n):
        c.append([])
        for j in range(m):
            c[i].append(a[i][j] * k)
    return c


def mmult(a, b, na, ma, nb, mb):
    if nb != ma:
        return 0
    c = []
    s = 0
    for i in range(na):
        c.append([])
        for k in range(mb):
            for j in range(ma):
                s += a[i][j] * b[j][k]
            c[i].append(s)
            s = 0
    return c


def func(a, b, c, d, f, k, r, na, ma, nb, mb, nc, mc, nd, md, nf, mf, out):
    aA = multiNum(a, na, ma, k)
    BT = transpose(b, nb, mb)
    bBT = multiNum(BT, nb, mb, r)
    SUM = sum(aA, bBT, na, ma, nb, mb)
    if SUM == 0:
        out.write(str(0))
        return 0
    Tsum = transpose(SUM, na, ma)
    MULTI = mmult(c, Tsum, nc, mc, na, ma)
    if MULTI == 0:
        out.write(str(0))
        return 0
    multi = mmult(MULTI, d, nc, ma, nd, md)
    if multi == 0:
        out.write(str(0))
        return 0
    XX = dif(multi, f, nc, md, nf, mf)
    if XX == 0:
        out.write(str(0))
        return 0
    out.write(str(1))
    out.write('\n')
    out.write(str(nf) + " " + str(mf) + '\n')
    for i in range(nf):
        for j in range(mf):
            out.write(str(XX[i][j]) + " ")
        out.write('\n')
    out.close()
    return 0


cin = open("input.txt", "r")
out = open("output.txt", "w")
k, r = map(float, cin.readline().split())
na, ma = map(int, cin.readline().split())
a = current(na, ma, cin)
nb, mb = map(int, cin.readline().split())
b = current(nb, mb, cin)
nc, mc = map(int, cin.readline().split())
c = current(nc, mc, cin)
nd, md = map(int, cin.readline().split())
d = current(nd, md, cin)
nf, mf = map(int, cin.readline().split())
f = current(nf, mf, cin)
func(a, b, c, d, f, k, r, na, ma, nb, mb, nc, mc, nd, md, nf, mf, out)
cin.close()
out.close()
