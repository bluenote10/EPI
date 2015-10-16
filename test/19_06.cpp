#include "convenience.hpp"

struct Vertex {
  int label;
  vector<Vertex*> edges;
};


void traverse(Vertex* v, unordered_map<Vertex*, Vertex*>& translate){
  Vertex* u = new Vertex{0};
  cout << v << " " << u << endl;
  translate[v] = u;
  v->label = 1;

  for (Vertex*& n : v->edges) {
    if (n->label == 0) {
      traverse(n, translate);
    }
    Vertex* n_trans = translate[n];
    u->edges.push_back(n_trans);
  }
}

Vertex* clone(Vertex *v) {
  unordered_map<Vertex*, Vertex*> translate;
  traverse(v, translate);
  cout << translate << endl;
  return translate[v];
}

int main(int argc, char** args) {
  Vertex vA{0};
  Vertex vB{0};
  Vertex vC{0};
  vA.edges.push_back(&vB);
  vA.edges.push_back(&vC);
  vB.edges.push_back(&vA);
  vB.edges.push_back(&vC);
  vC.edges.push_back(&vA);
  vC.edges.push_back(&vB);
  vector<Vertex*> vertices{&vA, &vB, &vC};

  auto c = clone(&vA);
  cout << c->edges << endl;

  return 0;
}