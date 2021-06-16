# Algorithms time analysis

Program analyses performance time of algorithms such as:

* Prime algorithm
* Kruskal's algorithm 
* Djikstra algorithm
* Bellman-Ford algorithm

### Graph representation
Each algorithm was implemented using **adjacency list** and **incidence matrix**.
The program was created to determine a performance difference between both representations and
access which representation suits better to particular problem. 

### Data structures 
Problem involved using self implemented data structures such as:
* Array List (**Generic**)
* Linked List (**Generic**)
* Priority Queue 
* Union Find

### Usage
You can simply clone repository and run code on your device.
Program allows using already prepared **.txt** files which represent graph or generate your own graph using already embedded graph generator.

> For shortest path problems (Djikstra, Bellman-Ford) choose at console menu  **directed** graph type

> For MST problems (Prime, Kruskal) choose at console menu **undirected** graph type

Switching graphs in already running program requires **deleting** older one 

You can view loaded graph in both representations by choosing:
* _Display Graph as Adjacency List_
* _Display Graph as Incidence Matrix_

Time measurement is only available in **experimental mode** 
### File structure _(.txt)_

Exemplary file describes following graph
```bash
10 7
0 1 4
0 3 8
1 2 8
1 3 11
2 4 2
2 5 4
3 4 7
3 6 1
4 6 6
5 6 2
```
<img src="https://user-images.githubusercontent.com/57325544/122285794-6c098180-ceef-11eb-883f-4b636c1db90a.png" width="500" height="500">

First line represents number of edges and vertexes. Other lines represents **starting vertex**, **end vertex** and
**edge weight** separated with _space_

_Each vertex is enumerated starting from 0 and edge weights can not be equal to zero_ 





  




