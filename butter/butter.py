"""
ID: anant901
LANG: PYTHON3
TASK: butter
"""

fin = open("butter.in", "r")
fout = open("butter.out", "w")


def flatten(xss):
    return [x for xs in xss for x in xs]


N, P, C = map(int, fin.readline().split())
cows = flatten([list(map(int, fin.readline().split())) for _ in range(N)])
edges = [list(map(int, fin.readline().split())) for _ in range(C)]

# Floyd-Warshall algorithm
distances = [[float("inf") for _ in range(P)] for _ in range(P)]
for i in range(P):
    distances[i][i] = 0

for edge in edges:
    distances[edge[0] - 1][edge[1] - 1] = edge[2]
    distances[edge[1] - 1][edge[0] - 1] = edge[2]

for k in range(P):
    for i in range(P):
        for j in range(P):
            distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j])

# 2. Calculate the sum of distances from each cow to each pasture
min_distance = float("inf")
for i in range(P):
    distance = 0
    for cow in cows:
        distance += distances[cow - 1][i]
    min_distance = min(min_distance, distance)

fout.write(f"{min_distance}\n")
fout.close()
