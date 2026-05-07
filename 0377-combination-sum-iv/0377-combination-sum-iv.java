class Solution {
    public int combinationSum4(int[] nums, int target) {
        final int[] dp = new int[target + 1];
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int k : nums) {
                if (i - k >= 0) {
                    dp[i] += dp[i - k];
                }
            }
        }
        return dp[target];
    }
}