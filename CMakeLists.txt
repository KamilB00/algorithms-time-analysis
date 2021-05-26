cmake_minimum_required(VERSION 3.17)
project(algorithms_time_analysis)

set(CMAKE_CXX_STANDARD 14)

add_executable(algorithms_time_analysis main.cpp "Data Structures/LinkedList/Element.cpp" "Data Structures/LinkedList/Element.h" "Data Structures/LinkedList/List.cpp" "Data Structures/LinkedList/List.h" "Data Structures/mystl.h" "Data Structures/ArrayList/ArrayList.cpp" "Data Structures/ArrayList/ArrayList.h" Graph/Vertex.cpp Graph/Vertex.h Graph/Edge.cpp Graph/Edge.h Graph/Graph.cpp Graph/Graph.h Algorithms/Prime.cpp Algorithms/Prime.h Algorithms/Kruskal.cpp Algorithms/Kruskal.h Algorithms/BellmanFord.cpp Algorithms/BellmanFord.h Algorithms/Djikstra.cpp Algorithms/Djikstra.h "Graph Representation/Representation.cpp" "Graph Representation/Representation.h" "Menu /Menu.cpp" "Menu /Menu.h" "Graph Generator/Generator.cpp" "Graph Generator/Generator.h" "File Loader/File.cpp" "File Loader/File.h" Timer/Timer.cpp Timer/Timer.h)