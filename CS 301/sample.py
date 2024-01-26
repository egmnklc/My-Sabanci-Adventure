import random
import time


# Random graph generator, it represents the graph
# in adjacency matrix form
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

    return graph


# The graph parameter represents the input graph in the
# form of an array, where each element is an edge represented as a pair (source, target).
def adjacency_matrix_generator(n, graph):
    # Creating an empty nxn matrix O(|V|^2)
    adjacency_matrix = [[0 for _ in range(n)] for _ in range(n)]

    # It is a simple graph, so, no cyclic edge for a node.
    i = 0
    for i in range(n):
        adjacency_matrix[i][i] = 0

    # O(|E|), since it's undirected, and unweighted; this operation can be done.
    for edge in graph:
        source, target = edge
        adjacency_matrix[source][target] = 1
        adjacency_matrix[target][source] = 1

    return adjacency_matrix

# Finding the vertex with the highest degree to put it in the root of the tree.


def highestDegreeVertex(adjacency_matrix):
    # Find the vertex with the highest degree in the graph
    max_degree = 0
    vertex_with_max_degree = 0

    for i in range(len(adjacency_matrix)):
        degree = sum(adjacency_matrix[i])
        if degree > max_degree:
            max_degree = degree
            vertex_with_max_degree = i

    return vertex_with_max_degree

# Recursive depth-first search for finding cycles starting from vertex u


def LCL_DFS(u, parent, visited, level, levels, adjacency_matrix):
    visited[u] = True
    levels[u] = level

    max_cycle_length = 0

    for v in range(len(adjacency_matrix)):
        if adjacency_matrix[u][v] == 1:
            if not visited[v]:
                max_cycle_length = max(max_cycle_length, LCL_DFS(v, u, visited, level+1, levels, adjacency_matrix))
            elif v != parent:
                # If an adjacent vertex is visited and it's not the parent
                # of the current vertex, then there is a cycle.
                max_cycle_length = max(max_cycle_length, level - levels[v] + 1)

    return max_cycle_length

def LCL(adjacency_matrix):
    n = len(adjacency_matrix)
    visited = [False] * n
    levels = [0] * n

    max_length = 0
    for i in range(n):
        if not visited[i]:
            max_length = max(max_length, LCL_DFS(i, -1, visited, 1, levels, adjacency_matrix))

    return max_length

# Sample testing
def perform_LCL(adjacency_matrix):
    start_time = time.perf_counter()
    max_length = LCL(adjacency_matrix)
    execution_time = time.perf_counter() - start_time
    return max_length, execution_time


# Node sizes to test
node_sizes = [10, 15, 20, 25, 30, 35]
g1 = [[0, 0, 0, 1, 0], [0, 0, 1, 0, 1], [0, 1, 0, 0, 0], [1, 0, 0, 0, 0], [0, 1, 0, 0, 0]] #5
g2 = [[0, 1, 0, 0, 0, 0], [1, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 1], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 1, 0, 0, 0]] #6
g3 = [[0, 0, 1, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 1], [1, 0, 0, 1, 0, 0, 1], [0, 0, 1, 0, 0, 0, 0], [0, 0, 0, 0, 0, 1, 0], [0, 0, 0, 0, 1, 0, 0], [0, 1, 1, 0, 0, 0, 0]] #7
g4 = [[0, 1, 1, 1, 1, 1, 1, 1], [1, 0, 1, 1, 1, 1, 1, 1], [1, 1, 0, 1, 1, 1, 1, 1], [1, 1, 1, 0, 1, 1, 1, 1], [1, 1, 1, 1, 0, 1, 1, 1], [1, 1, 1, 1, 1, 0, 1, 1], [1, 1, 1, 1, 1, 1, 0, 1], [1, 1, 1, 1, 1, 1, 1, 0]] #8
g5 = [[0, 1, 1, 1, 1], [1, 0, 1, 1, 1], [1, 1, 0, 1, 1], [1, 1, 1, 0, 1], [1, 1, 1, 1, 0]]
g6 = [[0, 1, 0, 1, 1, 1, 1, 1, 0], [1, 0, 0, 0, 0, 1, 0, 1, 1], [0, 0, 0, 0, 1, 1, 0, 1, 1], [1, 0, 0, 0, 1, 0, 1, 1, 0], [1, 0, 1, 1, 0, 0, 1, 0, 1], [1, 1, 1, 0, 0, 0, 1, 1, 0], [1, 0, 0, 1, 1, 1, 0, 1, 1], [1, 1, 1, 1, 0, 1, 1, 0, 0], [0, 1, 1, 0, 1, 0, 1, 0, 0]] #9

g7 = [[0, 1, 0, 1, 1, 0, 0, 0, 1, 0], [1, 0, 1, 0, 1, 0, 1, 0, 1, 1], [0, 1, 0, 1, 1, 0, 0, 0, 0, 0], [1, 0, 1, 0, 1, 0, 1, 1, 1, 1], [1, 1, 1, 1, 0, 1, 1, 0, 0, 1], [0, 0, 0, 0, 1, 0, 1, 1, 0, 0], [0, 1, 0, 1, 1, 1, 0, 0, 1, 1], [0, 0, 0, 1, 0, 1, 0, 0, 1, 0], [1, 1, 0, 1, 0, 0, 1, 1, 0, 0], [0, 1, 0, 1, 1, 0, 1, 0, 0, 0]] #10
g8 =[[0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1], [1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0], [0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0], [0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0], [0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0], [0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0], [0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0], [0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0], [0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0]] #11
g9 = [[0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1], [0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1], [1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1], [0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0], [1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0], [0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0], [0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0], [1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1], [1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1], [1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1], [1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0], [1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0]] #12

g10 = [[0, 1, 1, 1, 1, 1], [1, 0, 1, 1, 1, 1], [1, 1, 0, 1, 1, 1], [1, 1, 1, 0, 1, 1], [1, 1, 1, 1, 0, 1], [1, 1, 1, 1, 1, 0]]#6
g11 = [[0, 1, 1, 1, 1, 1, 1], [1, 0, 1, 1, 1, 1, 1], [1, 1, 0, 1, 1, 1, 1], [1, 1, 1, 0, 1, 1, 1], [1, 1, 1, 1, 0, 1, 1], [1, 1, 1, 1, 1, 0, 1], [1, 1, 1, 1, 1, 1, 0]]#7
g12 = [[0, 1, 1, 1, 1, 1, 1, 1], [1, 0, 1, 1, 1, 1, 1, 1], [1, 1, 0, 1, 1, 1, 1, 1], [1, 1, 1, 0, 1, 1, 1, 1], [1, 1, 1, 1, 0, 1, 1, 1], [1, 1, 1, 1, 1, 0, 1, 1], [1, 1, 1, 1, 1, 1, 0, 1], [1, 1, 1, 1, 1, 1, 1, 0]] #8
g13 = [[0, 1, 1, 1, 1, 1, 1, 1, 1], [1, 0, 1, 1, 1, 1, 1, 1, 1], [1, 1, 0, 1, 1, 1, 1, 1, 1], [1, 1, 1, 0, 1, 1, 1, 1, 1], [1, 1, 1, 1, 0, 1, 1, 1, 1], [1, 1, 1, 1, 1, 0, 1, 1, 1], [1, 1, 1, 1, 1, 1, 0, 1, 1], [1, 1, 1, 1, 1, 1, 1, 0, 1], [1, 1, 1, 1, 1, 1, 1, 1, 0]] #9
g14 = [[0, 1, 1, 1, 1, 1, 1, 1, 1, 1], [1, 0, 1, 1, 1, 1, 1, 1, 1, 1], [1, 1, 0, 1, 1, 1, 1, 1, 1, 1], [1, 1, 1, 0, 1, 1, 1, 1, 1, 1], [1, 1, 1, 1, 0, 1, 1, 1, 1, 1], [1, 1, 1, 1, 1, 0, 1, 1, 1, 1], [1, 1, 1, 1, 1, 1, 0, 1, 1, 1], [1, 1, 1, 1, 1, 1, 1, 0, 1, 1], [1, 1, 1, 1, 1, 1, 1, 1, 0, 1], [1, 1, 1, 1, 1, 1, 1, 1, 1, 0]] #10
g15 = [[0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1], [1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1], [1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1], [1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1], [1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1], [1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1], [1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1], [1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1], [1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1], [1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1], [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0]] #11
g16 = [[0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1], [1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1], [1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1], [1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1], [1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1], [1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1], [1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1], [1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1], [1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1], [1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1], [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1], [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0]] #12

graphs = [
        g1,
        g2,
        g3,
        g4,
        g5,
        g6,
        g7,
        g8,
        g9,
        g10,
        g11,
        g12,
        g13,
        g14,
        g15,
        g16]
# Parameters for random graph generation
# Edge probability
max_lengths = []       # List to store maximum lengths
execution_times = []   # List to store execution times
current_P = []
actuals = [0, 0, 0, 8, 9, 10, 5, 12, 5, 6, 7, 8, 9, 10, 11, 12]
for g in graphs:
    print(f"Node Size:  {len(g)} \n")
    max_length, execution_time = perform_LCL(g)
    print(f"Max Length: {max_length}")
    print(f"Execution Time: {execution_time:.6f} seconds")
    print()
    max_lengths.append(max_length)
    execution_times.append(execution_time)
    # current_P.append(p)

maxs = []
graphs = [g1, g2, g3, g4, g5, g6, g7, g8, g9, g10, g11, g12, g13, g14, g15, g16]
for i, g in enumerate(graphs):
    max_length, execution_time = perform_LCL(g)
    maxs.append(max_length)
    print(f"Graph g{i+1} - Max length: {max_length}, Execution time: {execution_time}s")
# for n in node_sizes:
#     print(f"Node Size: {n}\n")

#     for sample in range(1, 5):
#         print(f"Sample {sample}:")

#         # Generate a random edge probability between 0.5, 0.6, and 0.8
#         p = random.choice([0.3, 0.5, 0.7])
#         # Generate a random graph
#         graph = generate_random_graph(n, p)

#         # Print the adjacency matrix
#         print("Adjacency Matrix: ", graph)
#         print("p: ", p)

#         # Perform LCL and measure execution time
#         max_length, execution_time = perform_LCL(graph)

#         # Print the maximum length and execution time
#         print(f"Max Length: {max_length}")
#         print(f"Execution Time: {execution_time:.6f} seconds")
#         print()

#         # Store maximum length and execution time
#         max_lengths.append(max_length)
#         execution_times.append(execution_time)
#         current_P.append(p)


# print the maximum lengths and execution times for all samples
print("Maximum Lengths:", max_lengths)
print("Actual values:", actuals)
print("Maxs", maxs)
print("Execution Times:", execution_times)
# print("Probabilites of edges between vertices:", current_P)
# length, extime = perform_LCL([[0, 1, 1, 0, 1, 0, 1], [1, 0, 0, 0, 1, 0, 1], [1, 0, 0, 1, 0, 1, 0], [
                            #  0, 0, 1, 0, 0, 1, 0], [1, 1, 0, 0, 0, 0, 0], [0, 0, 1, 1, 0, 0, 1], [1, 1, 0, 0, 0, 1, 0]])
# print(length)
