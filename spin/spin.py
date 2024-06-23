"""
ID: anant901
LANG: PYTHON3
TASK: spin
"""

fin = open("spin.in", "r")
fout = open("spin.out", "w")

speeds = []
wedges = []

for i in range(5):
    data = list(map(int, fin.readline().split()))
    speed, num = data[0], data[1]
    speeds.append(speed)
    w = []
    for j in range(num):
        start, extent = data[2 + 2 * j], data[3 + 2 * j]
        w.append((start, start + extent))
    wedges.append(w)

for time in range(360):
    # initialize a list of status of every degree
    status = [0] * 360
    for i in range(5):
        speed = speeds[i]
        for w in wedges[i]:
            start, end = w
            current_start = (start + speed * time) % 360
            current_end = (end + speed * time) % 360
            if current_start <= current_end:
                for j in range(current_start, current_end + 1):
                    status[j] += 1
            else:
                for j in range(current_start, 360):
                    status[j] += 1
                for j in range(0, current_end + 1):
                    status[j] += 1
        for j in range(360):
            if status[j] == 5:
                fout.write(str(time) + "\n")
                fout.close()
                exit()

if time == 359:
    fout.write("none\n")
fout.close()
