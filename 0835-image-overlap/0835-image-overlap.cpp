#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> ones1, ones2;

        // 1. Gather coordinates of all 1s
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (img1[r][c] == 1) ones1.push_back({r, c});
                if (img2[r][c] == 1) ones2.push_back({r, c});
            }
        }

        // 2. Count frequencies of translation vectors
        map<pair<int, int>, int> vector_counts;
        int max_overlap = 0;

        for (const auto& [r1, c1] : ones1) {
            for (const auto& [r2, c2] : ones2) {
                pair<int, int> shift = {r2 - r1, c2 - c1};
                max_overlap = max(max_overlap, ++vector_counts[shift]);
            }
        }

        return max_overlap;
    }
};