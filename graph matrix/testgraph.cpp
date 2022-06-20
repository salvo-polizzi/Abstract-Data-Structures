#include "graph.h"

int main() {
    Graph<int> g(10);

    g.insertNode(324);
    g.insertNode(4);
    g.insertNode(34);
    g.insertNode(32324);
    g.insertNode(21);

    g.addEdge(4, 32324, false);
    g.addEdge(4, 4);
    g.addEdge(21, 34);

    cout << g << endl;
}