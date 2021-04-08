#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H

#include <iostream>
#include <vector>
#include <algorithm>

struct Edge
{
  int   data,
        weight;
  Edge* next;
  Edge()             : data(0), weight(0), next(nullptr) {}
  Edge(int d, int w) : data(d), weight(w), next(nullptr) {}
};

struct Vertex
{
  int   index;
  Edge* next;
  Vertex() : index(0), next(nullptr) {}
};

struct triplet
{
  int weight,
      source,
      dest;
  triplet()                    : weight(0), source(0), dest(0) {}
  triplet(int a, int b, int c) : weight(a), source(b), dest(c) {}
};

struct weight_sort
{
  bool operator ()( const triplet &a, const triplet &b ) const
  {
    return a.weight < b.weight;
  }
};

class adj_list
{
private:
  int                  size;
  Vertex*              verticies;
  std::vector<triplet> vec;
public:
  ~adj_list      ();
  adj_list       ();
  adj_list       (int);
  void add_edge  (int, int, int);
  void undirected(int, int, int);
  void set_size  (int);
  void clear     (Edge*);

  const std::vector<triplet>& get_list() const {return vec;}
  bool valid_node(int node)              const {return (node < 1 || node > size) ? false : true;}
  Vertex& operator[](int ind)            const {return verticies[ind-1];}
};

adj_list::adj_list() : size(0), verticies(nullptr), vec() {}

adj_list::adj_list(int sz) : size(sz), verticies(nullptr), vec()
{
  verticies = new Vertex[size];
  for(int i=0; i<size; i++)
    verticies[i].index = i+1;
}

void adj_list::set_size(int sz)
{
  this->vec.clear();
  if(verticies)
  {
    for(int i=0; i<size; i++)
      clear(verticies[i].next);
    delete[] verticies;
    verticies = nullptr;
  }
  this->size = sz;
  verticies = new Vertex[size];
  for(int i=0; i<size; i++)
    verticies[i].index = i+1;
}

void adj_list::add_edge(int id, int edge, int weight)
{
  undirected(edge, id, weight);
  if(id > size || id < 1)
  {
    std::cerr << "\nInvalid Vertex provided\n";
    return;
  }
  else if(edge > size || id < 1)
  {
    std::cerr << "\nInvalid Edge provided\n";
    return;
  }
  else
  {
    if(verticies[id-1].next == nullptr)
    {
      verticies[id-1].next = new Edge(edge, weight);
      std::cout << "\nSuccessfully added an edge\n";
      vec.push_back({weight, id, edge});
      std::sort(vec.begin(), vec.end(), weight_sort());
      return;
    }
    else
    {
      Edge* temp = verticies[id-1].next;
      while (temp != nullptr)
      {
        if(temp->data == edge)
        {
          std::cout << "\nSpecified Edge already present\n";
          return;
        }
        if(temp->next == nullptr)
        {
          temp->next = new Edge(edge, weight);
          std::cout << "\nSuccessfully added an edge\n";
          vec.push_back({weight, id, edge});
          std::sort(vec.begin(), vec.end(), weight_sort());
          return;
        }
        temp = temp->next;
      }
      return;
    }
  }
}

void adj_list::undirected(int id, int edge, int weight)
{
  if(id > size || id < 1)
    return;
  else if(edge > size || id < 1)
    return;
  else
  {
    if(verticies[id-1].next == nullptr)
    {
      verticies[id-1].next = new Edge(edge, weight);
      return;
    }
    else
    {
      Edge* temp = verticies[id-1].next;
      while (temp != nullptr)
      {
        if(temp->data == edge)
          return;
        if(temp->next == nullptr)
        {
          temp->next = new Edge(edge, weight);
          return;
        }
        temp = temp->next;
      }
      return;
    }
  }
}

void adj_list::clear(Edge* node)
{
  if(node == nullptr)
    return;
  clear(node->next);
  delete node;
}

adj_list::~adj_list()
{
  for(int i=0; i<size; i++)
    clear(verticies[i].next);

  delete[] verticies;
}

#endif // ADJACENCY_LIST
