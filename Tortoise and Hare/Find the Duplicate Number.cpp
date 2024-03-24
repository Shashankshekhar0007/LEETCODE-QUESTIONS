int findDuplicate(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];

    // Phase 1: Detect if there's a cycle
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // Phase 2: Find the entrance of the cycle
    fast = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

  int findDuplicate(vector<int>& nums) {
   int slow = nums[nums[0]];
    int fast = nums[nums[nums[0]]];

    while (slow != fast) {
      slow = nums[slow];
      fast = nums[nums[fast]];
    }

    slow = nums[0];

    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }
    return slow;
    }