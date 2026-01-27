class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        int[] arr1 = Arrays.copyOf(arr, arr.length);
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(arr1);
        int minDiff = Integer.MAX_VALUE;
        for(int i = 1; i < arr1.length; i++){
            if(Math.abs(arr1[i-1] - arr1[i]) <= minDiff){
                minDiff = Math.abs(arr1[i-1] - arr1[i]);
            }
        }
        for(int i = 1; i < arr1.length; i++){
            if(Math.abs(arr1[i-1] - arr1[i]) <= minDiff){
                ans.add(Arrays.asList(arr1[i-1], arr1[i]));
            }
        }
        return ans;
    }
}