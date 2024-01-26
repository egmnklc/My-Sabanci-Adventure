/**
 * @file graphs.cpp
 * @author Egemen Kilic (egemenkilic@sabanciuniv.edu)
 * @brief
 * @version 0.1
 * @date 2022-12-23
 *
 * @copyright Copyright (c) 2022
 * ! Abdul Bari Graphs
 * ! Graph (see 2022-12-23-21-46-10.png)
 * * Directed Graph: Have pair of ordered vertices (u, v), there's an arrow
 * * Un-Directed Graph: There isn't an arrow between vertices
 * * - Graph applications:
 * *    - Social Networks, City-Road Network, Precedence Constraints
 * * - Weighted oldugu zaman edgelerin uzerinde sayi yaziyor, adjacency matrixte de 1 yerine o
 * * sayiyi yaziyorsun.
 *
 *
 * ! Graph Representations
 * * Adjacency Matrix: (see 2022-12-23-21-49-58.png)
 * * - 2d matrix of size VxV , V is # of nodes, Aij = 1 means i and j are connected
 * * For pros, see 2022-12-23-21-51-59.png
 * * For cons, see 2022-12-23-21-52-22.png
 * ! IT DOESN'T HAVE TO BE A SYMMETRIC MATRIX
 * * Adjacency List (see 2022-12-23-21-54-14.png):
 * * - An array of linked lists is used. Size of the array is equal to the # of Vertices
 * * and each entry of array corresponds to a linked list of vertices adjacent to this index.
 * * For pros AND cons, see 2022-12-23-21-54-44.png
 * * - It consumes less space because we store only the connected vertices.
 * * - Max space is required when each Vertice is connected to all other vertices.
 * *
 * *
 * *
 * longrightarrow	⟶
 * circ	vysmwhtcircle	∘
 * Rightarrow	⇒
 * rightwavearrow	↝
 * in	∈
 * implies	Longrightarrow	⟹
 * --> longrightarrow	⟶
 * ! Cemal Yilmaz Graphs;
 * * - A Graph G = (V,E) consists of:
 * *    → A set of Vertices, V
 * *    → A set of Edges, E
 * *        ⇒ Each edge is a pair shown by vertices v and w:  (v, w)
 * *        ⇒ Edges are sometimes referred to as arcs.
 * *
 * ! Graph Definitions
 * * - Directed Graph: If the pair of edges are ordered, then the graph is a directed graph.
 * *    ⇒ See 2022-12-27-11-52-28.png for Directed Graph example.
 * *    ⇒ Strongly Connected Directed Graph: A Directed Graph is Strongly Connected if there is a path from every Vertex to every other Vertex.
 * *    ⇒ Cycle: A Cycle in a Directed Graph is a Path of at least 1 length such that w₁ = wₙ.
 * *    ⇒ In-degree of a Vertex (Directed Graph): Number of Edges coming in to a Vertex.
 * *    ⇒ For Directed Graphs, there can be at most M = |V| × (|V| - 1) Edges.
 * *
 * * - Adjacent: Vertex v is adjacent to w ⟺ (v, w) ∈ E
 * *
 * * - Undirected Graph: If in an Edge (v, w), v is adjacent to w and w is adjacent to w.
 * *    ⇒ See 2022-12-27-11-51-52.png for Undirected Graph example.
 * *    ⇒ A Cycle in an Undirected Graph has distinct Edges.
 * *    ⇒ Connected Undirected Graph: An Undirected Graph is Connected if there is a path from every Vertex to every other Vertex.
 * *    ⇒ Degree of a Vertex Undirected Graph: Number of Edges on the Vertex.
 * *    ⇒ Out-Degree of a Vertex undirected Graph: Number of Edges going out from a Vertex.
 * *    ⇒ For Undirected Graphs, there can be at most M = |V| × (|V|-1)/2 Edges. (We divide it by 2 because Undirected Graph has no directions)
 * *
 * * - Weight: Sometimes the edge has a third component named weight, (v, w, weight).
 * *    ⇒ See 2022-12-27-11-52-44.png for Undirected Graph with Weighted Edges.
 * *
 * * - Path: Path in a graph is a sequence of vertices w₁, w₂, w₃, ..., wₙ such that (wᵢ, wᵢ₊₁) ∈ E.
 * *    ⇒ Length of a Path: The length of a Path is the number of Edges on the Path. If N is the number of Vertices, Path length is n - 1.
 * *    ⇒ Simple path: A Simple Path is a path such that all Vertices are distinct.
 * !        ⟶ Except that first and last Vertice could be the same (a cycle).
 * * - Directed Acyclic Graph (DAG): A Directed Graph with No Cycles is called a Directed Acyclic Graph (DAG).
 * * - Complete Graph: Complete Graph is a graph with Edges between all pairs of Vertices. (All Vertices are connected.)
 * *
 * * - Density of a Graph (D)
 * *    → |E| =  Number of Edges
 * *    → M =  Maximum number of possible Edges in Graph (G).
 * *    → D = |E| / M
 * *    → Dense (Yogun) Graph: If D is close to 1, that is, |E| = Θ(|V|²), we call the Graph a Dense Graph.
 * *    → Sparse (Seyrek) Graph: If D isn't close to 1, that is, |E| = Ο(|V|), wall the Graph a Sparse Graph. 
 * *
 * ! Graphs & Uses
 * * - Land transportation system
 * *    → Vertices represent towns
 * *    → Edges represent roads
 * *    → Weights represent distances
 * * - Problems
 * *    → Is there a path between two towns?
 * *    → What is the shortest path between two towns?
 * *
 * *
 * * - University Courses Structure
 * *    → Vertices represent courses
 * *    → Directed Edges represent Prerequisite relations
 * !    This is a Directed Acyclic Graph!
 * *- Problems
 * *    → What course(s) should I take before a given course?
 * *    → Is there a set of courses that is a prerequisite for all other courses?
 * *
 * * ↝ So on and so forth.
 * *
 * ! Graph Representations
 * * - Adjacency Matrix Representation
 * *    → We use a 2 dimensional array of boolean values.
 * *    → A[i][j] = true ⟶ (i, j) ∈ E (Edge of A), false otherwise. We can use infinity instead of using 0 for representing false.
 * *    → Adjacency Matrix Representation uses O(|V|²) space.
 * *        ⇒ We can check existwnce of an Edge in Ο(1) time.
 * *    → If the Graph is Sparse, the matrix will have a large number of 0 elements, which indicates there're too many unconnected Vertices. 
 * *        → Adjaceny Matrix wastes too much space if the Graph is Sparse, because we're allocating memory to show data does not exist.
 * *        → Adjaceny Matrix representation is good for Dense Graphs.
 * *        → If the Graph is Sparse, better to use Adjaceny List Representation.
 * *
 * * - Adjacency List Representation
 * *    - Adjacency list representation is exactly the same data structure we used for hash tables with separate chaining.
 * *    → If the Graph is Sparse,  Adjacency List Representation is a better representation.
 * *        ⇒ For each Vertex, we keep a list of the Edges coming out from that Vertex.
 * *            ↝ For Undirected Graphs, we only need to keep the Edge Once (since direction is not important).
 * *    → It is represented by using Linked List structure.
 * *        ⇒ Total memory for Adjaceny Lists is Ο(|E|) (For representing which Vertexes a Vertex is connected to).
 * *        ⇒ Total memory for Array of Pointers is Ο(|V|) (For reprsenting number of Vertexes).
 * *        ⇒ By adding an additional property to the Node, we can store Edge Weight.
 * *   → Total memory for adjaceny list representation is Ο(|V| + |E|), which is linear.
 * *   → Verices may have labels that are not integers.
 * *        ⇒ If that's the case, use a hash table to assign integer values non-integer values.
 * *        ⇒ Then use these integer values to access the adjaceny list vector.
 * *        ⇒ Here, the iₜₕ integer index is an Edge Object that keeps Vertex, Weight, and Element data.
 * *   → For Undirected Graphs, we only keep the Edges (v, w) where v < w. !!
 * *        ⇒ To check if Edge (v, w) exists where v > w, we check if (w, v) exists.
 * * 
 * *
 * *
 *
 */