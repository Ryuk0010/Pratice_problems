class NumArray {
public:
    int n;
    vector<int> segTree;
    void buildSegTree(int i, int l, int r, vector<int>& nums){
        if(l == r){
            segTree[i] = nums[l];
            return;
        }
        int mid = l + (r - l)/2;
        buildSegTree(2*i+1, l, mid, nums);
        buildSegTree(2*i+2, mid+1, r, nums);
        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }

    void updateSegTree(int i, int l, int r, int ind, int val){
        if(l == r){
            segTree[i] = val;
            return;
        }
        int mid = l + (r - l)/2;
        if(ind <= mid) updateSegTree(i*2+1, l, mid, ind, val);
        else updateSegTree(i*2+2, mid+1, r, ind, val);

        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }

    int querySegTree(int i, int l, int r, int left, int right){
        if(l >= left && r <= right) return segTree[i];
        else if(r < left || l > right) return 0;
        int mid = l + (r - l)/2;
        return querySegTree(2*i+1, l, mid, left, right) + querySegTree(2*i+2, mid+1, r, left, right);
        
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.resize(4*n);
        buildSegTree(0, 0, n-1, nums);
    }
    
    void update(int index, int val) {
        return updateSegTree(0, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return querySegTree(0, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */