class Solution {
    public int[] replaceElements(int[] arr) {
        int n = arr.length;
        int[] ans = new int[n];
        int maxi = arr[n-1];
        ans[n-1] = -1;

        for(int i=n-2;i>=0;i--) {
            int temp = arr[i];
            ans[i] = maxi;
            maxi = Math.max(maxi, temp);
        }

        return ans;
    }
}