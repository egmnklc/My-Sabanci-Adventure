import random

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

# Example usage
n = 10  # Number of nodes
p = 0.5  # Probability of having an edge between any two nodes
random_graph = generate_random_graph(n, p)

print("Generated Random Graph (Adjacency Matrix):")
for row in random_graph:
    print(row)


