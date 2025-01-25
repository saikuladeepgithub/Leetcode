#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    // Find function for Union-Find
    int find(int x, vector<int>& parent) {
        if (parent[x] != x) {
            parent[x] = find(parent[x], parent); // Path compression
        }
        return parent[x];
    }

    // Union function for Union-Find
    void unionSets(int x, int y, vector<int>& parent, vector<int>& rank) {
        int rootX = find(x, parent);
        int rootY = find(y, parent);
        
        if (rootX != rootY) {
            // Union by rank
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        // Initialize Union-Find structures
        vector<int> parent(n), rank(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        
        // Pair the elements in the sorted order
        vector<pair<int, int>> sorted_nums;
        for (int i = 0; i < n; ++i) {
            sorted_nums.push_back({nums[i], i});
        }
        
        // Sort by value to allow processing adjacent pairs
        sort(sorted_nums.begin(), sorted_nums.end());

        // Use Union-Find to group elements that can be swapped
        for (int i = 1; i < n; ++i) {
            // Compare adjacent elements in the sorted array
            if (abs(sorted_nums[i].first - sorted_nums[i - 1].first) <= limit) {
                unionSets(sorted_nums[i].second, sorted_nums[i - 1].second, parent, rank);
            }
        }
        
        // Group elements by their root parent
        vector<vector<int>> groups(n);
        for (int i = 0; i < n; ++i) {
            int root = find(i, parent);
            groups[root].push_back(i);
        }

        // Sort each group and place the smallest elements in the original array
        for (auto& group : groups) {
            if (!group.empty()) {
                vector<int> values;
                for (int index : group) {
                    values.push_back(nums[index]);
                }
                sort(values.begin(), values.end());

                // Assign the sorted values back to the corresponding positions
                int idx = 0;
                for (int index : group) {
                    nums[index] = values[idx++];
                }
            }
        }

        return nums;
    }
};
