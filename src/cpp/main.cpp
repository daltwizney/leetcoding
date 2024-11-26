#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>

#include <cstdint>

#include <unordered_set>

#include <unordered_map>

using namespace std;


struct GridCell
{
    int i;
    int j;

    GridCell(int i, int j) : i(i), j(j) {}

    int getHash() {

        return i + (j << 24);
    }
};

int computeArea(vector<vector<int>>& grid, GridCell root, unordered_set<int>& visitedNodes) {

    int m = grid.size();
    int n = grid[0].size();

    int area = 0;

    stack<GridCell> cells;

    cells.push(root);

    while (cells.size() > 0)
    {
        GridCell cell = cells.top();
        cells.pop();

        int cellValue = grid[cell.i][cell.j];

        if (cellValue == 1 && (visitedNodes.find(cell.getHash()) == visitedNodes.end()))
        {
            area++;
        }

        visitedNodes.emplace(cell.getHash());

        GridCell leftChild(cell.i, cell.j - 1);
        GridCell rightChild(cell.i, cell.j + 1);
        GridCell topChild(cell.i - 1, cell.j);
        GridCell bottomChild(cell.i + 1, cell.j);

        if (leftChild.j >= 0 && (visitedNodes.find(leftChild.getHash()) == visitedNodes.end()))
        {
            if (grid[leftChild.i][leftChild.j] == 1)
            {
                cells.push(leftChild);
            }
            else
            {
                visitedNodes.emplace(leftChild.getHash());
            }
        }

        if (rightChild.j < n && (visitedNodes.find(rightChild.getHash()) == visitedNodes.end()))
        {
            if (grid[rightChild.i][rightChild.j] == 1)
            {
                cells.push(rightChild);
            }
            else
            {
                visitedNodes.emplace(rightChild.getHash());
            }
        }

        if (topChild.i >= 0 && (visitedNodes.find(topChild.getHash()) == visitedNodes.end()))
        {
            if (grid[topChild.i][topChild.j] == 1)
            {
                cells.push(topChild);
            }
            else
            {
                visitedNodes.emplace(topChild.getHash());
            }
        }

        if (bottomChild.i < m && (visitedNodes.find(bottomChild.getHash()) == visitedNodes.end()))
        {
            if (grid[bottomChild.i][bottomChild.j] == 1)
            {
                cells.push(bottomChild);
            }
            else
            {
                visitedNodes.emplace(bottomChild.getHash());
            }
        }
    }

    return area;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {

    if (grid.size() == 0 || grid[0].size() == 0)
    {
        return 0;
    }

    int m = grid.size();
    int n = grid[0].size();

    unordered_set<int> visitedNodes;

    int maxArea = 0;

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            GridCell cell(i, j);
            int nodeHash = cell.getHash();

            if (visitedNodes.find(nodeHash) == visitedNodes.end())
            {
                if (grid[i][j] == 1)
                {
                    int area = computeArea(grid, cell, visitedNodes);

                    if (area > maxArea)
                    {
                        maxArea = area;
                    }
                }
                else
                {
                    visitedNodes.emplace(nodeHash);
                }
            }
        }
    }

    return maxArea;
}

int main() {

  return 0;
}