#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>

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

void reverseString(std::vector<char>& s) {

    if  (s.size() < 2)
    {
        return;
    }

    int length = s.size();

    for (int i = 0; i < (length / 2); ++i)
    {
        int char1 = s[i];
        int char2 = s[length - 1 - i];

        s[i] = char2;
        s[length - 1 - i] = char1;
    }
}

void _removeLastToken(std::stack<char>& path) {

    // NOTE: this function shouldn't remove first '/' in path!
    while (path.size() > 1)
    {
        char value = path.top();

        path.pop();

        if (value == '/')
        {
            return;
        }
    }
}

std::string simplifyPath(std::string path) {
    
    std::stack<char> newPath;

    newPath.push('/');

    bool oneDot = false;
    bool twoDots = false;
    bool hasCharacter = false;

    // process path onto stack
    for (int i = 0; i < path.size(); ++i)
    {
        if (path[i] == '/')
        {
            // current token has ended
            if (oneDot)
            {
                _removeLastToken(newPath);
            }
            else if (twoDots)
            {
                _removeLastToken(newPath);
                _removeLastToken(newPath);
            }
            
            if (newPath.top() != '/' && (i != path.size() - 1))
            {
                newPath.push('/');
            }

            // reset state for next token
            oneDot = false;
            twoDots = false;
            hasCharacter = false;
        }        
        else if (path[i] == '.' && !hasCharacter)
        {
            if (oneDot)
            {
                twoDots = true;
                oneDot = false;
            }            
            else if (twoDots)
            {
                oneDot = false;
                twoDots = false;
                hasCharacter = true;
            }
            else
            {
                oneDot = true;
            }

            newPath.push(path[i]);
        }
        else
        {
            oneDot = false;
            twoDots = false;
            hasCharacter = true;

            newPath.push(path[i]);
        }
    }

    // current token has ended
    if (oneDot)
    {
        _removeLastToken(newPath);
    }
    else if (twoDots)
    {
        _removeLastToken(newPath);
        _removeLastToken(newPath);
    }

    if (newPath.size() > 1 && newPath.top() == '/')
    {
        newPath.pop();
    }

    // generate new string from path
    int resultLength = newPath.size();
    std::string result(resultLength, '0');

    for (int i = resultLength - 1; i >= 0; --i)
    {
        result[i] = newPath.top();
        newPath.pop();
    }

    return result;
}

void SimplifyPathTest()
{
    std::cout << "simplifyPath('/home/') = " << simplifyPath("/home/") << std::endl;
    std::cout << "simplifyPath('/home//foo/') = " << simplifyPath("/home//foo/") << std::endl;
    std::cout << "simplifyPath('/home/user/Documents/../Pictures') = " << simplifyPath("/home/user/Documents/../Pictures") << std::endl;
    std::cout << "simplifyPath('/../') = " << simplifyPath("/../") << std::endl;
    std::cout << "simplifyPath('/.../a/../b/c/../d/./') = " << simplifyPath("/.../a/../b/c/../d/./") << std::endl;
}
