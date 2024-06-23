"""
ID: anant901
LANG: PYTHON3
TASK: msquare
"""

fin = open("msquare.in", "r")
fout = open("msquare.out", "w")

target = list(map(int, fin.readline().split()))


def A(state):
    return state[::-1]  # reverse


def B(state):
    return [
        state[3],
        state[0],
        state[1],
        state[2],
        state[5],
        state[6],
        state[7],
        state[4],
    ]


def C(state):
    return [
        state[0],
        state[6],
        state[1],
        state[3],
        state[4],
        state[2],
        state[5],
        state[7],
    ]


def to_string(state):
    return "".join(map(str, state))


def from_string(string):
    return list(map(int, string))


def bfs():
    queue = [(from_string("12345678"), [])]
    visited = set()
    while queue:
        state, moves = queue.pop(0)
        if state == target:
            return moves
        if to_string(state) in visited:
            continue
        visited.add(to_string(state))
        queue.append((A(state), moves + ["A"]))
        queue.append((B(state), moves + ["B"]))
        queue.append((C(state), moves + ["C"]))


moves = bfs()
fout.write(str(len(moves)) + "\n")
if len(moves) == 0:
    fout.write("\n")
for i in range(0, len(moves), 60):
    fout.write("".join(moves[i : i + 60]) + "\n")

fout.close()
