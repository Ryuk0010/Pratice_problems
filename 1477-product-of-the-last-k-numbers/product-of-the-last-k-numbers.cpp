class ProductOfNumbers {
public:
    vector<int> ans;
    int prod = 1;
    ProductOfNumbers() {

    }
    
    void add(int num) {
        if(num == 0){
            ans = vector<int> ();
            prod = 1;
        }
        else{
            prod *= num;
            ans.push_back(prod);
        }
    }
    
    int getProduct(int k) {
        int n = ans.size();
        if(k > n) return 0;
        else if(k == n) return ans[n-1];
        return ans[n-1] / ans[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */