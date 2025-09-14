class Solution {
public:
    void buildSegmentTree(int i, int l, int r, int segmentTree[], vector<int>& heights) {
        if (l == r) {
            segmentTree[i] = l;
            return;
        }
        int mid = l + (r - l) / 2;
        buildSegmentTree(2 * i + 1, l, mid, segmentTree, heights);
        buildSegmentTree(2 * i + 2, mid + 1, r, segmentTree, heights);
        
        segmentTree[i] = (heights[segmentTree[2 * i + 1]] >= heights[segmentTree[2 * i + 2]]) ?
                        segmentTree[2 * i + 1] : segmentTree[2 * i + 2];
    }

    int* constructST(vector<int>& heights, int n) {
        int* segmentTree = new int[4 * n];
        buildSegmentTree(0, 0, n - 1, segmentTree, heights);
        return segmentTree;
    }

    int querySegmentTree(int start, int end, int i, int l, int r, int segmentTree[], vector<int>& heights) {
        if (l > end || r < start) {
            return -1;
        }
        
        if (l >= start && r <= end) {
            return segmentTree[i];
        }
        
        int mid = l + (r - l) / 2;
        int leftIndex = querySegmentTree(start, end, 2 * i + 1, l, mid, segmentTree, heights);
        int rightIndex = querySegmentTree(start, end, 2 * i + 2, mid + 1, r, segmentTree, heights);

        if (leftIndex == -1)
            return rightIndex;
        if (rightIndex == -1)
            return leftIndex;

        return (heights[leftIndex] >= heights[rightIndex]) ? leftIndex : rightIndex;
    }

    // int RMIQ(int st[], vector<int>& heights, int n, int a, int b) {
    //     return querySegmentTree(a, b, 0, 0, n - 1, st, heights);
    // }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int* segmentTree = constructST(heights, n);

        vector<int> result;
        for(auto& query: queries){
            int alice = min(query[0],query[1]);
            int bob   = max(query[0],query[1]);

            if(alice == bob || heights[bob] > heights[alice]){
                result.push_back(bob);
                continue;
            }

            int l = bob+1;
            int r = n - 1;
            int result_idx = INT_MAX;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                int idx = querySegmentTree(l, mid, 0, 0, n-1, segmentTree, heights);

                if (heights[idx] > max(heights[alice], heights[bob])) {
                    r = mid - 1;
                    result_idx = idx;
                } else {
                    l = mid + 1;
                }
            }

            if(result_idx == INT_MAX) {
                result.push_back(-1);
            } else {
                result.push_back(result_idx);
            }
        }
        return result;
    }
};