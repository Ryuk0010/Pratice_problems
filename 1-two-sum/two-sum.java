class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> mpp = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            int need = target - nums[i];

            if (mpp.containsKey(need)) {
                int storedIndex = mpp.get(need);
                return new int[]{storedIndex, i};
            }

            mpp.put(nums[i], i);
        }

        return new int[]{-1, -1};
    }
}
