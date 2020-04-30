import math;


def multiVector(ax, ay, az, bx, by, bz):
    cx = ay * bz - az * by
    cy = (-1) * (ax * bz - az * bx)
    cz = ax * by - ay * bx
    return cx, cy, cz;


def checker(ax, ay, az, bx, by, bz):
    return (ax * bx + ay * by + az * bz) / (
            math.sqrt(ax * ax + ay * ay + az * az) * math.sqrt(bx * bx + by * by + bz * bz));


def ro(vx, vy, vz, wx, wy, wz):
    bx = wx - vx
    by = wy - vy
    bz = wz - vz
    return bx, by, bz;


cin = open("input.txt", "r")
cout = open("output.txt", "w")
vx, vy, vz = map(float, cin.readline().split())
ax, ay, az = map(float, cin.readline().split())
mx, my, mz = map(float, cin.readline().split())
wx, wy, wz = map(float, cin.readline().split())
bx, by, bz = ro(vx, vy, vz, wx, wy, wz)
rgx, rgy, rgz = multiVector(ax, ay, az, 0, 0, 1)
lgx, lgy, lgz = multiVector(0, 0, 1, ax, ay, az)

if math.fabs(checker(mx, my, mz, 0, 0, 1)) <= 0.5:
    cout.write(str(0))
    cout.write('\n')
    cin.close()
    cout.close()
    exit(0)

if math.fabs(checker(bx, by, bz, ax, ay, az)) >= math.sqrt(3) / 2:
    cout.write(str(0))
    cout.write('\n')
    cin.close()
    cout.close()
    exit(0)

if checker(lgx, lgy, lgz, bx, by, bz) >= 0.5:
    if checker(bx, by, bz, ax, ay, az) < 0:
        sign = -1
    else:
        sign = 1
    cout.write(str(1))
    cout.write('\n')
    cout.write(str(sign * math.degrees(math.acos(math.fabs(checker(lgx, lgy, lgz, bx, by, bz))))))
else:
    if checker(rgx, rgy, rgz, bx, by, bz) >= 0.5:
        if checker(bx, by, bz, ax, ay, az) < 0:
            sign = -1
        else:
            sign = 1
        cout.write(str(-1))
        cout.write('\n')
        cout.write(str(sign * math.degrees(math.acos(math.fabs(checker(rgx, rgy, rgz, bx, by, bz))))))
cout.write('\n')
cout.write(str(sign * math.degrees(math.acos(math.fabs(checker(mx, my, mz, 0, 0, 1))))))
cout.write('\n')
cout.write("Bye")
cin.close()
cout.close()
