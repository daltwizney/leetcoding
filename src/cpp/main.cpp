#include <algorithm>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>

#include <unordered_set>

#include <unordered_map>

int largestUniqueNumber(std::vector<int>& nums) {
    
    std::unordered_map<int, int> valueCount;

    for (int i = 0; i < nums.size(); ++i)
    {
        int value = nums[i];

        if (valueCount.find(value) == valueCount.end())
        {
            valueCount.emplace(value, 1);
        }
        else
        {
            valueCount[value]++;
        }
    }

    int max = INT_MIN;

    for (int i = 0; i < nums.size(); ++i)
    {
        int value = nums[i];

        if (valueCount[value] == 1 && value > max)
        {
            max = value;
        }
    }

    if (max == INT_MIN)
    {
        return -1;
    }

    return max;
}

// TODO: this is too slow, how can we optimize it further?
bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination) {

    if (n >= 1 && (source == destination))
    {
        return true;
    }

    if (edges.size() == 0)
    {
        return false;
    }

    // build adjacency list for graph representation
    std::unordered_map<int, std::unordered_set<int>> graph;

    for (int i = 0; i < edges.size(); ++i)
    {
        int node1 = edges[i][0];
        int node2 = edges[i][1];

        if ((node1 == source && node2 == destination) ||
            (node2 == source && node1 == destination))
        {
            return true;
        }

        if (graph.find(node1) == graph.end())
        {
            graph.emplace(node1, std::unordered_set<int>());
        }

        if (graph.find(node2) == graph.end())
        {
            graph.emplace(node2, std::unordered_set<int>());
        }

        graph[node1].emplace(node2);
        graph[node2].emplace(node1);
    }

    // BFS on graph to see if source is connected to destination
    std::stack<int> nodeQueue;

    std::unordered_set<int> visitedNodes;

    nodeQueue.push(source);

    while (nodeQueue.size() > 0)
    {
        int node = nodeQueue.top();
        nodeQueue.pop();

        if (node == destination)
        {
            return true;
        }

        visitedNodes.emplace(node);

        auto edges = graph[node];

        for (auto iter = edges.begin(); iter != edges.end(); ++iter)
        {
            int sibling = *iter;

            if (visitedNodes.find(sibling) == visitedNodes.end())
            {
                nodeQueue.push(sibling);
            }
        }
    }

    return false;
}

int main() {

  printf("hello wasm!\n");
  
  return 0;
}