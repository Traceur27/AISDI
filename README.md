# Kosaraju's algorithm
Implementation of Kosaraju's algorithm(finding all strongly connected components of directed graph in C++.

## Usage
Program takes one parameter(name of txt file with definitions of edges and vertices).
The result txt file contains numbers of vertices that belong to strongly connected components.

Run example:
```bash
git clone https://github.com/kczarnota/Kosaraju
cd Kosaraju
make
./graph input.txt
```
Input file format:
* First provide n lines with vertices(2 numbers - positions of vertices)
* Then provide q lines with edges(3 numbers - start and end vertex indices for edge and its weight)




