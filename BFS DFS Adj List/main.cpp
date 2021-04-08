#include <iostream>
#include "algo.h"
using namespace std;

int main()
{
  int choice = 0,
      number_of_verticies = 0,
      vert = 0,
      edg = 0,
      wt = 0;
  adj_list object;
  algo test_algo;
  while(true)
  {
    cout << "*****MENU*****\n";
    cout << "1. Insert number of verticies\n";
    cout << "2. Insert edge\n";
    cout << "3. Breadth First Traversal\n";
    cout << "4. Depth First Traversal\n";
    cout << "5. Find MST using Kruskal's algorithm and print the edges and total weight of the tree\n";
    cout << "6. Find MST using Prim's algorithm and print the edges and total weight of the tree\n";
    cout << "7. EXIT\n\nEnter you choice (Value between 1-7): ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      cout << "\nEnter number of verticies: ";
      cin >> number_of_verticies;
      object.set_size(number_of_verticies);
      break;
    case 2:
      cout << "Enter vertex, edge and weight eg:(1 4 20): ";
      cin >> vert;
      cin >> edg;
      cin >> wt;
      object.add_edge(vert, edg, wt);
      break;
    case 3:
      cout << "\nEnter source vertex: ";
      cin >> vert;
      test_algo.BFS(object, vert);
      break;
    case 4:
      cout << "\nEnter source vertex: ";
      cin >> vert;
      test_algo.DFS(object, vert);
      break;
    case 5:
      test_algo.kruskal(object);
      break;
    case 6:
      cout << "\nEnter source vertex: ";
      cin >> vert;
      test_algo.prim(object, vert);
      break;
    case 7:
      cout << "\nExiting...\n";
      return 0;
      break;
    default:
      cout << "\nInvalid choice\n";
      break;
    }
  }
  return 0;
}