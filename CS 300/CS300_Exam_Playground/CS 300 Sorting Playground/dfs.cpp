/**
 * @file dfs.cpp
 * @author Egemen Kilic (egemenkilic@sabanciuniv.com)
 * @brief
 * @version 0.1
 * @date 2022-12-26
 *
 * @copyright Copyright (c) 2022
 *
 *
 *
 *
 *
 *
 * ! Not the very beginning.
 * ! Classification of Arcs (Directed Graphs)
 * * Forward Arcs
 * * - V is a proper descendant of u but not a child of u in the DFS tree, u->v.
 * * What is special about backward arcs?
 * * - Prescence of a backward arc indicates the prescence of a cycyle in the graph.
 * * - If I have an edge from u->v, then there's a path from u to v. If there's a backward arc, then there's a cycle.
 * * - See 2022-12-26-09-02-50.png.
 * * Cross Arcs:
 * * - Not a tree arc, not a forward/backward arc, then it is a cross arc.
 * * - See 2022-12-26-09-03-44.png.
 * * Pre-Order & Post-Order Numbers:
 * * - Right after we visit the vertex and before we visit its adjacents.
 * * - See 2022-12-26-09-04-47.png.
 * * - We increment the preorder number by 1 and assign it, so each vertex has a unique numbber.
 * * - For post order, see 2022-12-26-09-06-04.png/
 *
 * * Post-order number tree: 2022-12-26-09-06-24.png
 * * Preorder of a is 1 and for b is 2. A'
 * * Postorder numaranin atanmasi icin o vertexin adjacentlarininin visited olmasi gerekiyor.
 * *    Gidecek baska adjacent kalmadigi zaman post-order number assign ediyoruz.
 * * -> Pre-order->paranthesis, Post-order-> rectengles.
 *
 * * Characterization of Arcs (see 2022-12-26-09-09-53.png)
 * * We assigned the numbers during the DFS traversal, we'll now use them to identify arcs.
 * ! PON -> POST ORDER NUMBER.
 *
 * * DFS On Undirected Graphs
 * * - DFS Partitions the arcs of an undirected graph into Tree Arcs and Backward arcs.
 * * See 2022-12-26-09-12-40.png
 * * - If we end up having an edge that we didn't traverse, it means that the grpah has a cycle.
 * * If I have V vertices in a graph, condition to have a cycle-> If I have more than V-1 edges, then there's a backwards cycle.
 * *
 *
 * * Application of DFS
 * * - First, perform a DFS and check to see if we have a backward arc or not.
 * * - Then see 2022-12-26-09-15-03.png
 * *
 * * Topological Sorting
 * * - We push the Vertex in the stack after we assign a Post Order number.
 * * - When we're done with the stack, we'll have DFS with reverse order.
 * *
 * ! CONNECTED COMPONENTS
 * * We can use DFS to identift connected components.
 * * - See 2022-12-26-09-18-27.png and 2022-12-26-09-18-41.png.
 * 
 * * ```Graph Theory Ends```
 * 
 * * ```Algorithmic Paradigms Begins```
 *
 */