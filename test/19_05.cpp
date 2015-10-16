
#include "convenience.hpp"


struct Vertex {
  int color;
  vector<Vertex*> edges;
};

bool traverse(Vertex* v, Vertex* previous) {
  v->color = 1;
  cout << v << endl;
  for (Vertex* neighbor : v->edges) {
    cout << neighbor << " " << neighbor->color << endl;
    if (neighbor->color == 0) {
      traverse(neighbor, v);
    } else if (neighbor->color == 1 && neighbor != previous) {
      return false;
    }
  }
  return true;
}

bool test_minimal_connected(vector<Vertex*> vertices) {
  if (vertices.size() <= 0) {
    return true;
  }
  return traverse(vertices[0], nullptr);
}

int main(int argc, char** args) {
  Vertex vA{0};
  Vertex vB{0};
  Vertex vC{0};
  vA.edges.push_back(&vB);
  //vA.edges.push_back(&vC);
  vB.edges.push_back(&vA);
  vB.edges.push_back(&vC);
  //vC.edges.push_back(&vA);
  vC.edges.push_back(&vB);
  vector<Vertex*> vertices{&vA, &vB, &vC};

  cout << test_minimal_connected(vertices) << endl;

  return 0;
}