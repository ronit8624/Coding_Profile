class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        int n = arr.length;
        List<List<Integer>> ans = new ArrayList<>();
        int mini = Integer.MAX_VALUE;

        Arrays.sort(arr);

        for(int i = 1; i < n; i++) {
            int diff = arr[i] - arr[i - 1];

            if(diff < mini) {
                mini = diff;
                ans.clear();
                ans.add(Arrays.asList(arr[i - 1], arr[i]));
            }
            else if(diff == mini) {
                ans.add(Arrays.asList(arr[i - 1], arr[i]));
            }
        }

        return ans;
    }
}