import heapq
import sys
r = sys.stdin.readline

n = int(r())
m = int(r())

paths = [[] for _ in range(n)]

for _ in range(m):
    a, b, cost = map(int, r().split())
    paths[a-1].append((b, cost))

start, end = map(int, r().split())
cost = []

dist = [1e9 for _ in range(n)]
dist[start-1] = 0

hq = []

heapq.heappush(hq, (0, start))

while hq:
    prev_cost, curr = heapq.heappop(hq)
    for neighbor, cost in paths[curr-1]:
        if prev_cost + cost < dist[neighbor-1]:
            dist[neighbor-1] = prev_cost + cost
            heapq.heappush(hq, (dist[neighbor-1], neighbor))

print(dist[end - 1])