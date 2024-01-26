/**
 * @file shortest_path.cpp
 * @author Egemen Kilic (egemenkilic@sabanciuniv.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-27
 * 
 * @copyright Copyright (c) 2022
 * 
 * 
 * 
 * ! Shortest Path Algorithms
 * * - It's about finding the shortest path in Weighted Graphs.
 * * - Input is a Weighted Graph: Associated with each edge (vᵢ, vⱼ) is a Cost c.
 * * - The Cost of a path v₁, v₂, v₃, ..., vₖ is called as the weighted path length 
 * *    → THe unweighted path length is just N-1.
 * ! Note: Shortest path is not defined if there's a negative cost cycle!
 * *
 * * Applications:
 * * - Find the shortest route  to fly from Istanbul to New York.
 * *    → Least time including waits at the airports
 * *    → Cheapest total flight (assuming flight cost is additive)
 * *
 * * - Least cost/time to transmit data through computer networks.
 * *    → Costs capture data rate, or TL/106 bytes, etc.
 * * 
 * * - Single-source shortest path problem
 * *    → Given as input a weighted graph G=(V,E), and a distinguished vertex s, 
 * *     find the shortest weighted path from s to every other vertex.
 * *    → Finding the shortest path to only ONE other vertex is not any easier, asymptotically.
 * *
 * * - Breadth first search traverses thorugh one's children first. Then moves to their children so on and so forth.
 * *    → Uses Queue.
 * *    → BFS is just like a level order on a binary tree.  
 * *    → You can begin with any index you want.
 * *    → Visit any adjacent vertex in any order you like.
 * !    RULE IS WHEN YOU SELECT A VERTEX, YOU MUST VISIT ALL OF ITS ADJACENT VERTEXES.
 * *    → Queue and exploration must be done.  
 * *
 * *
 * * - Depth first explores through a path until the very end leaf.
 * *    → Uses Stack.
 * *    → Begin with any Vertex.
 * *    → Start exploring its adjacents, once you visit a Vertex, start exploring it and repeat this process.
 * *    → DFS is just like a pre-order search.
 * *
 * * ↝ BFS and DFS traversals are different.
 * *
 * *
 * *
 */