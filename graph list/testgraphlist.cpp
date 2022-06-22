#include "graph.h"

int main() {
    Graph<int> g;

    g.addVertex(123);
    g.addVertex(13);
    g.addVertex(1333);
    g.addVertex(122133);
    g.addVertex(3);

    g.addEdge(3,13);
    g.addEdge(13,1333);
    g.addEdge(123,13);
    g.addEdge(13,3);

    cout << g << endl;
}