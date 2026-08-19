class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.length;

        int totalGas = 0, totalCost = 0;
        for(int i=0;i<n;i++) {
            totalGas += gas[i];
            totalCost += cost[i];
        }

        if(totalGas < totalCost) return -1;

        int total = 0, ans = 0;
        for(int i=0;i<n;i++) {
            total += gas[i] - cost[i];

            if(total < 0) {
                ans = i + 1;
                total = 0;
            }
        }

        return ans;
    }
}