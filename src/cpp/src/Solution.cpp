#include <unordered_set>

#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        if (n < 1) {
            return false;
        }
        else if (source == destination) {
            return true;
        }

        // build adjacency list
        unordered_map<int, vector<int>> graph;

        for (int i = 0; i < edges.size(); ++i)
        {
            vector<int> edge = edges[i];

            int a = edge[0];
            int b = edge[1];

            if (graph.find(a) == graph.end())
            {
                graph[a] = vector<int>();
            }

            if (graph.find(b) == graph.end())
            {
                graph[b] = vector<int>();
            }

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        // search for path
        queue<int> buffer;

        unordered_set<int> visited;

        buffer.emplace(source);

        while (buffer.size() > 0)
        {
            int node = buffer.front();
            buffer.pop();

            if (node == destination)
            {
                return true;
            }

            visited.emplace(node);

            vector<int> neighbors = graph[node];

            for (int i = 0; i < neighbors.size(); ++i)
            {
                int neighbor = neighbors[i];

                if (visited.find(neighbor) == visited.end())
                {
                    visited.emplace(neighbor);
                    buffer.emplace(neighbor);
                }
            }
        }

        return false;
    }
};