#ifndef BFS_DFS_H
#define BFS_DFS_H

#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include "adj_list.h"

class algo
{
private:
  
public:
  void BFS    (adj_list&, int);
  void DFS    (adj_list&, int);
  void kruskal(adj_list&);
  void prim   (adj_list&, int);
};

void algo::BFS(adj_list& matrix, int source)
{
  if(!matrix.valid_node(source))
  {
    std::cerr << "\nXXXXX   Invalid source  XXXXX\n";
    return;
  }
  else
  {
    int curr = 0;
    std::vector<int> visited;
    std::queue <int> priority;
    priority.push(source);
    while(!priority.empty())
    {
      curr = priority.front();
      std::cout << curr << std::endl;
      priority.pop();
      visited.push_back(curr);
      Edge* neighbors = matrix[curr].next;
      bool exist = false;
      while(neighbors != nullptr)
      {
        exist = false;
        for(int t:visited)
        {
          if(t == neighbors->data)
          {
            exist = true;
            break;
          }
        }
        if(exist)
        {
          neighbors = neighbors->next;
          continue;
        }
        priority.push(neighbors->data);
        neighbors = neighbors->next;
      }
    }
  }
}

void algo::DFS(adj_list& matrix, int source)
{
  if(!matrix.valid_node(source))
  {
    std::cerr << "\nXXXXX   Invalid source  XXXXX\n";
    return;
  }
  else
  {
    int curr = 0;
    std::vector<int> visited;
    std::stack <int> priority;
    priority.push(source);
    while(!priority.empty())
    {
      curr = priority.top();
      std::cout << curr << std::endl;
      priority.pop();
      visited.push_back(curr);
      Edge* neighbors = matrix[curr].next;
      bool exist = false;
      while(neighbors != nullptr)
      {
        exist = false;
        for(int t:visited)
        {
          if(t == neighbors->data)
          {
            exist = true;
            break;
          }
        }
        if(exist)
        {
          neighbors = neighbors->next;
          continue;
        }
        priority.push(neighbors->data);
        neighbors = neighbors->next;
      }
    }
  }
}

void algo::kruskal(adj_list& matrix)
{
  int   total = 0;
  bool  source_flag = false,
        dest_flag = true;
  
  std::vector<triplet> vec = matrix.get_list();
  std::vector<int>     visited;
  for(triplet itr:vec)
  {
    source_flag = false;
    dest_flag = false;
    for(int visit:visited)
    {
      if(itr.source == visit)
        source_flag = true;
      if(itr.dest == visit)
        dest_flag = true;
    }
    if(!source_flag && !dest_flag)
    {
      std::cout << itr.source << std::endl << itr.dest << std::endl;
      total = total + itr.weight;
      visited.push_back(itr.source);
      visited.push_back(itr.dest);
    }
    else if(!source_flag)
    {
      std::cout << itr.source << std::endl;
      total = total + itr.weight;
      visited.push_back(itr.source);
    }
    else if(!dest_flag)
    {
      std::cout << itr.dest << std::endl;
      total = total + itr.weight;
      visited.push_back(itr.dest);
    }
  }
  std::cout << "\nTotal weight: "<< total << std::endl;
}

void algo::prim(adj_list& matrix, int source)
{
  if(!matrix.valid_node(source))
  {
    std::cerr << "\nXXXXX   Invalid source  XXXXX\n";
    return;
  }
  else
  {
    int curr = 0,
        total = 0;
    std::vector<int> visited;
    std::queue <int> priority;
    priority.push(source);
    while(!priority.empty())
    {
      curr = priority.front();
      std::cout << curr << std::endl;
      priority.pop();
      visited.push_back(curr);
      Edge* neighbors = matrix[curr].next;
      bool exist = false;
      while(neighbors != nullptr)
      {
        exist = false;
        for(int t:visited)
        {
          if(t == neighbors->data)
          {
            exist = true;
            break;
          }
        }
        if(exist)
        {
          neighbors = neighbors->next;
          continue;
        }
        priority.push(neighbors->data);
        total = total + neighbors->weight;
        neighbors = neighbors->next;
      }
    }
    std::cout << "\nTotal weight: " << total << std::endl;
  }
}

#endif