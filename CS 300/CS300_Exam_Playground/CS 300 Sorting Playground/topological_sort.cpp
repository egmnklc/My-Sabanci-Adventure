/**
 * @file topological_sort.cpp
 * @author Egemen Kilic (egemenkilic@sabanciuniv.edu)
 * @brief 
 * @version 0.1
 * @date 2022-12-23
 * 
 * @copyright Copyright (c) 2022
 * 
 * 
 * ! Abdul Bari
 * *    For a Directed Acyclic Graph (DAG) is a linear ordering of vertices such that
 * * for every directed edge (u, v), vertex u comes before vertex v in the ordering.
 *  * - Assume there are two paths from A to B and C, and the rest is also in linked list structure.
 *  *   - There can be two possible paths starting from A, ending in E:
 *  *       - A->B->C->D->E
 *  *       - A->C->B->D->E
 * * - Examples of topological sorting:
 * *    - Advanced packaging tool (apt-get). Does topological sort for
 * *    a particular software program for install/remove purposes. 
 * *    - Pre requisite course issues.
 * ! About Topological Sort
 * * - Topological sort uses an empty stack, 
 * * We initially have all the vertices as univisited value
 * * 1) A for loop looks for an unvisited for loop.
 * * 2) TopologicalSort function will be called with Vertex A, visitedArray and an empty Stack.
 * * 3) This function will mark A as visited and make recursive call for its unvisited neighboring vertices.
 * ! NOTE: There's a rule set to decide which Vertex will be next, in the example rule is alphabetical.
 * * The process after this line will be done until you reach a Vertex with no neighboring Vertexes.
 * * 4) After you move according to a rule and using step 3, (!This part is recursive as stated in step 3)
 * * Insert the Vertex into the Stack and move back to Node B, (since H has no other neighboring Vertex),
 * * B has no other neighboring Vertex other than H, so push B into the Stack. Stach has B and H (top, bottom)
 * * 5) Now search for univisited Vertex of A, notice we have F, mark it as Visited, since it has no neighbor,
 * * push F into the stack.
 * * 6) Now all neighboring Vertexes of A are visited, so we push it into the Stack.
 * * 7) Now, we start from an unvisited node DEPENDING ON A PREDETERMINED RULE. In the example, C is chosen.
 * * 8) Since C has no neighbors, there isn't any direction going out from C (there is only going into C),
 * * so push C into the Stack.
 * * 9) We start again with D, and move to its unvisited neighbor E.
 * * 10) We visit Vertex I (it is unvisited), and since there's no unvisited Vertexes of I (C is visited),
 * * push I into Stack. 
 * * 11) Now move the previous Vertex, which is E. E has no unvisited neighboring Vertexes, push E into stack.
 * * 12) Move back from E. Now you're at D. D has no unvisited Vertexes, push D into Stack.
 * * 13) Now the example choses G and mark it as visited, since all of its neighboring Vertexes are visited,
 * * we push it into the stack.
 * * 14) We choose Vertex J and mark it as visited, since all of its neighboring Vertexes are visited,
 * * we push it into the stack.
 * *
 * * Order for pushing into the Stack is H->B->F->A->C->I->E->D->G->J (starting from bottom, ending at top)
 * *
 * * - Now that all of our Nodes are visited, we print the stack: J G D E I C A F B H.
 * *
 * ! Time Complexity: O(V+E), where V is the Vertexes and E is the Edges.
 * *
 * *
 * ! Cemal Yilmaz
 * ! Topological Sort
 * * - Topological sort is an ordering of Vertices in a Directed Acyclic Graph.
 * *    → If there is a path from vᵢ to vⱼ, then vⱼ appears after vᵢ in the ordering.
 * ? Note: 
 * ? - Directed Acyclic Graphs have no cycles.
 * ? - 1 or more Vertices with in-degree 0.
 * ? - 1 or more Vertices with out-degree 0.
 * * - Say we're given the courses in a university and the prerequisite relations between.
 * *    ⇒ It can be modeled as a Directed Acyclic Graph (DAG).
 * *    ⇒ Topological sort of the courses will give a valid sequence of courses (valid means, order with proper prerequisite order)
 * *
 * * Steps
 * * 1. Select Vertex with in-degree 0.
 * * 2. Print it out.
 * * 3. Remove the Vertex.
 * * 4. Repeat.
 * *
 * *    O(V2) running time is because of the linear search through the vertices.
 * * If the graph is sparse only a very small number vertices have 0 indegree.
 * * Only keep track of 0-indegree vertices
 * * At the beginning, put all such vertices in a separate place,
 * * When you decrease the indegrees, if the indegree of a node reaches 0, put that also there.
 * *
 * *
 * *
 * *
 * *
 */