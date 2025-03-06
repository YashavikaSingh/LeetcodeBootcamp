#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;



class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int n = nums.size();
            vector<int> ans(n, 1);  // Initialize ans vector of size n with 1s
    
            int beforep = 1;
            // First pass: calculate prefix product
            for (int i = 0; i < n; i++) {
                if (i > 0) {
                    beforep *= nums[i - 1];
                }
                ans[i] *= beforep;
            }
    
            int p = 1;
            // Second pass: calculate suffix product and multiply with previous result
            for (int i = n - 1; i >= 0; i--) {
                ans[i] *= p;
                p *= nums[i];
            }
    
            return ans;
        }
    };