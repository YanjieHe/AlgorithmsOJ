#ifndef CLONEGRAPH_HPP
#define CLONEGRAPH_HPP
#include "common_header_files.hpp"
class UndirectedGraphNode
{
public:
    int label;
    vector<UndirectedGraphNode*> neighbors;
    UndirectedGraphNode(int x)
        : label{x}
    {
    }
};

class Solution
{
public:
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node)
    {
        unordered_map<int, UndirectedGraphNode*> map;
        return clone(node, map);
    }
    UndirectedGraphNode* clone(UndirectedGraphNode* node,
                               unordered_map<int, UndirectedGraphNode*>& map)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        else
        {
            if (map.find(node->label) != map.end())
            {
                return map[node->label];
            }
            else
            {
                UndirectedGraphNode* newNode =
                    new UndirectedGraphNode(node->label);
                map.insert({node->label, newNode});
                for (auto neighbor : node->neighbors)
                {
                    newNode->neighbors.push_back(clone(neighbor, map));
                }
                return newNode;
            }
        }
    }
};

#endif // CLONEGRAPH_HPP
