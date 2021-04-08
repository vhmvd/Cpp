#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <iterator>

using namespace std;

//repl byun code

string read_graph( map<string, vector<string> > &g, vector<string> &cities, int &hop)
{
    int num_of_vertices=0;
    cin >> num_of_vertices;
    string city;
    for(int i = 0; i < num_of_vertices; i++)
    {
        cin >> city;
        cities.push_back(city);
        city.clear();
    }
    
    int num_of_edges=0;
    cin >> num_of_edges;
    string from;
    string to;
    for (int i = 0; i < num_of_edges; i++) 
    {
        cin >> from;
        cin >> to;
        g[from].push_back(to);
        from.clear();
        to.clear();
    }
    
    string startingCity;
    cin >> startingCity;
    cin >> hop;
    return startingCity;
}

//more repl byun code with some tweaks
void bfs(map<string, vector<string>>& g, map<string,int>& gNum, string startingCity, int hop) 
{
    queue<string> q;
    queue<int> jump;
    int count = 0;
    q.push(startingCity);
    vector<string> visited;
    visited.push_back(startingCity);
    string currentCity;
    vector<string> edges;
    bool visit;
    gNum[startingCity] = count;
    jump.push(count);

    while(!q.empty())
    {
        currentCity = q.front();
        count = jump.front();
        count += 1;
        jump.pop();
        q.pop();
        edges = g[currentCity];
        for(long unsigned int i=0; i<edges.size(); i++)
        {
            visit = false;
            for(long unsigned int j=0; j<visited.size(); j++)
            {
                if(edges[i] == visited[j])
                {
                    visit = true;
                    break;
                }
            }
            if(visit)
            {
                break;
            }
            else
            {
                jump.push(count);
                q.push(edges[i]);
                visited.push_back(edges[i]);
                gNum[edges[i]] = count;
            }
        }
        edges.clear();
    }
    //for()
    //https://thispointer.com/how-to-iterate-over-a-map-in-c/
    //source for how to iterate map
    map<string, int>::iterator itr = gNum.begin();
    while(itr != gNum.end()){
        if(itr->second > hop) { 
            itr++; 
            }
        else
        {
            cout << itr->first << ":" << itr->second << endl;
            itr++;
        }
    }
    
    return;
    
}

int main()
{
    map<string, vector<string>> g;
    map<string, int> gNum;
    int hop = 0;
    vector<string> cities;

    string startingCity = read_graph(g, cities, hop);

    bfs(g, gNum, startingCity, hop);
 
}

