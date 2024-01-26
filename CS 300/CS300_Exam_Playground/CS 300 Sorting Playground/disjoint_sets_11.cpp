/**
 * @file disjoint_sets.cpp
 * @author Egemen Kilic (egemenkilic@sabanciuniv.edu)
 * @brief 
 * @version 0.1
 * @date 2022-12-26
 * 
 * @copyright Copyright (c) 2022
 * 
 * revemptyset ⦰
 * bigcap ⋂ 
 * bigcup ⋃
 * rightwavearrow ↝
 * upTheta Θ
 * upOmicron Ο
 * 
 * ! Disjoint Sets
 * * 1. Disjoint sets & operations
 * * 2. Detecting a cycle
 * * 3. Graphical Representation
 * * 4. Array Representation
 * * 5. Weighted Union & Collapsing Find
 * * - Disjoing sets are useful for algorithms.
 * *
 * * 1. Find: Find operation is to find out any Vertex belongs to which set. (Set membership operation)
 * * 2. Union: S1 ⋃ S2 = {1,2,3,4,5,6,7,8} ↝ This is the union operation.
 * 
 * * S1 = {1,2,3,4} => 1-2-3-4 (Numbers are vertices of s1)
 * * S2 = {5,6,7,8} => 5-6-7-8 (Numbers are vertices of s2)
 * 
 * * S1 ⋂ S2 = ⦰
 * * - When Find 5 operation is applied, you get S2.
 * *
 * * Now say you've added an edge between 4 and 8 ⇒ 1-2-3-4-8-7-6-5, it means we connected (4, 8)
 * *    Find 4 ⇒ Belongs to S1
 * *    Find 8 ⇒ Belongs to S2
 * * Say (4, 8) = (u, v), and we add an edge (1, 5)
 * * Now we have S3 which is = S1 ⋃ S2 = {1,2,3,4,5,6,7,8} 
 * *    - Find 1 → It is in S3, Find  5 → It is in S3.
 * *       - They both belong to the same set, then it means:
 * !           - THERE IS A CYCYLE, this is how we find out if there's a cycle.
 * ! ↦ If you take any edge and both Vertices belong to the same set, then there's a cycle in the graph.
 * * See 2022-12-26-11-50-17.png.
 * ? Note: Say there's an edge with number 3. It connects 5 and 6. So looks like 5 (3) 6.
 * ?    When we say edge 3, we mean (5,6). Starting from 1st edge, move to the last. See 
 * *
 * ! When two points are on different sets, perform union operation. 
 * ! See 2022-12-26-11-56-43.png 
 * * If both vertices belong to the same set, don't union the sets so you always have disjoint sets.
 * *
 * *
 * *
 * ! Cemal Yilmaz Style 
 * * Disjoint Sets
 * * - We'd like to implement the following set of operations on disjoint sets:
 * *    - Given an element X, find the set that it belongs to (Find Operation)
 * *    - Given two sets, replace them by their union. (Union Operation) 
 * * Equivalance Relations
 * * - Disjoint sets are used for computing *Equivalance Relations*.
 * *    - Given a set 'S' and a relation 'R', a R b, indicates that a is related to b with relation R.
 * * Some relations:
 * * 1. Father-of
 * *    - Not reflexive, Not symmetric, Not Transitive.
 * *    - Not an equivalance relation.
 * * 2. Are-connected-by-wire
 * *    - Reflexive, Symmetric, Transitive.
 * *    - An equivalance Relation.
 * * 3. Less-than-or-equal-to
 * *    - Reflexive, NOT SYMMETRIC, Transitive.
 * *    - Not an equivalance relation.
 * * 4. Are-in-the-same-country
 * * - Equivalance Relations satisft the following conditions: 
 * *    1. Reflexivity
 * *    → (a R a) ∀a ∈ S. 
 * *    2. Symmetric
 * *    → (a R b) ⟺ (b R a).
 * *    3. Transivity
 * *    → (a R b) ∧ (b R c) ⇒ (a R c).
 * * 
 * *
 * * - Equivalance Classes are disjoint. See 2022-12-26-15-49-06.png.
 * *
 * ! Computing Equivalance Classes
 * * - Graph Theory
 * *    - Finding connected components of graphs.
 * * - Finite State Machines
 * *    - Minimizing finite state machines.
 * *   
 * ! Operations   
 * * - We start with N sets each containing one element.
 * * - We have 2 permissable (izin verilebilir) 
 * *   - Find (Find the belonging set of an element)
 * *   - Union ⋃, (Taking union of two sets)  
 * *        - Union ⋃ Takes θ(N) time. A sequence of N-1 elements' union takes θ(N²) time.   
 * *
 * ! Smart Union Algorithms    
 * * - Union By Size
 * *   - Make the smaller a subtree of the larger tree. 
 * *   - The depth of any node is never more than log(N).
 * *   - The depth can be increased at most log(N) times.
 * *   - Initially the depth of a node is 0. 
 * *   - Time complexity of Find takes Ο(logN) time.
 * *   - A sequence of M operations will take Ο(M*logN) time.
 * *  
 * * - Union By Height
 * *   - Make the shallower tree a subtree of the deeper tree.
 * *   - The height of the tree increases by 1 when equally deep trees are unioned.
 * *        - This can only happen logN times.
 * *  
 * * - Once we locate the sets, Union ⋃ takes Ο(1) time.
 * *   
 * ! Path Compression  
 * *   - Path Compression is a technique for dynamically changing the data structure during a find oprtn. 
 * *   - When we perform Find(x), the parent of every Node from X to the root is changed to Root.
 * *     - So that find operations run faster.   
 * *     - Abdul Bari explains this as Element Compression.
 * *   
 * * Applications of Disjoint Sets
 * * - Creating Mazes, 
 * * - Electric Circuit Analysis,
 * *    - Perform circuit extraction from layout.
 * *    - Check if the right places are connected.
 * * - Find minimal finite state machines
 * *    - Find the minimal machine so that it runs faster and uses less memory.
 * *   
 * *   
 */