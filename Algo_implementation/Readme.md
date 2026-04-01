#  Reflection on FLoyd Warshall

- Floyd-Warshall is a dynamic programming algorithm for computing shortest paths between all pairs in  (n^3) time.
- It handles negative edge weights if no negative cycle exists.
- The core idea is repeated relaxation using intermediate vertex k.
- Time complexity : O(n^3) 
- Space complexity : O(N^2)

```cmd
tadashi@tadashi:~/Desktop/CP_Praticals_SS26/Algo_implementation$ ./floyd_warshall < input2.txt
All pairs shortest path distances:
0 3 5 6 
5 0 2 3 
3 6 0 1 
2 5 7 0 
tadashi@tadashi:~/Desktop/CP_Praticals_SS26/Algo_implementation$ 
```
---

# Reflection on Johnson's Algorithm 

- Johnson's algorithm uses Bellman Ford to compute potential h(v) and reweight edges to non-negative.
- Then runs Dijkstra from each vertex to get efficient all-pairs shortest paths in sparse graphs.
- Good for graphs with negative weights but no negative cycles, and m << n^2.
- Time complexity : O(V * E + V^2 log V)
- Space complexity : O(V + E)

```cmd
tadashi@tadashi:~/Desktop/CP_Praticals_SS26/Algo_implementation$ ./johnson_algorithm < input1.txt
All-pairs shortest paths with Johnson's algorithm:
0 3 5 6 
5 0 2 3 
3 6 0 1 
2 5 7 0 
tadashi@tadashi:~/Desktop/CP_Praticals_SS26/Algo_implementation$ 
```
---

# Reflection on Boruvka Algorithm 

- Boruvka(Baruvka) repeatedly chooses the cheapest outgoing edge from each component and unions them.
- It is one of the earliest MST algorithms and runs in O(E log V) with union-find.
- Great for parallelization and for dense graphs as part of combined MST techniques.
- Time complexity : O(E log V)
- Space complexity : O(V + E)

```cmd 
tadashi@tadashi:~/Desktop/CP_Praticals_SS26/Algo_implementation$ ./boruvka_algorithm < input1.txt
Minimum spanning tree edges (u v w):
3 0 2
1 2 2
2 3 1
Total MST weight = 5
tadashi@tadashi:~/Desktop/CP_Praticals_SS26/Algo_implementation$ 
```
---