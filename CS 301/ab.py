import itertools
import random
import time
def is_simple_cycle(graph, permutation):
    n = len(permutation)
    # Check if first and last nodes are connected
    if graph[permutation[0]][permutation[-1]] == 0:
        return False
    # Check if consecutive nodes are connected
    for i in range(1, n):
        if graph[permutation[i]][permutation[i-1]] == 0:
            return False
    return True

def longest_simple_cycle(graph):
    n = len(graph)
    longest_cycle = 0
    for k in range(3, n + 1):  # Simple cycles have at least 3 nodes
        for permutation in itertools.permutations(range(n), k):
            if is_simple_cycle(graph, permutation):
                longest_cycle = max(longest_cycle, k)
    return longest_cycle

def generate_random_graph(n, p):
    # Initialize an empty graph G(V,E) with n vertices.
    graph = [[0 for _ in range(n)] for _ in range(n)]
    # Iterate through all possible pairs of nodes (i, j), where i ≠ j.
    for i in range(n):
        for j in range(i + 1, n):
            # Generate a random number r in the range [0, 1].
            r = random.random()
            # If r <= p, add an edge between nodes i and j in the graph.
            if r <= p:
                graph[i][j] = 1
                graph[j][i] = 1
    print(graph)
    return graph

samples = [(7,0.5),(7,0.5),(7,0.5),(7,0.5),(7,0.5),(7,0.5)]

for i, (n, p) in enumerate(samples, 1):
    graph = generate_random_graph(n, p)
    start_time = time.time()
    longest_cycle = longest_simple_cycle(graph)
    end_time = time.time()
    running_time = end_time - start_time
    print(f"Sample {i}: n = {n}, p = {p}, Longest Simple Cycle = {longest_cycle}, Running Time = {running_time:.6f} seconds")


