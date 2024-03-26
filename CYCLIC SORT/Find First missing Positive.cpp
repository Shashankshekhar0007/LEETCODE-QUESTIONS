int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int ans = n + 1;
        int i = 0;
        while (i < n) {
            int correct;
            if (nums[i] == INT_MIN) {
                correct = 0;
            } else {
                correct = nums[i] - 1;
            }
            if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[correct]) {
                swap(nums[i], nums[correct]);
            } else
                i++;
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return ans;
    }