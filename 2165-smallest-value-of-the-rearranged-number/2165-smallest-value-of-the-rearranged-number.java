class Solution {
    public long smallestNumber(long num) {
        if (num == 0) return 0;
        long n = Math.abs(num);
        List<Integer> arr = new ArrayList<>();

        while (n > 0) {
            arr.add((int)(n % 10));
            n = n / 10;
        }

        if (num > 0) {
            Collections.sort(arr);

            for (int i = 0; i < arr.size(); i++) {
                if (arr.get(i) != 0) {
                    Collections.swap(arr, 0, i);
                    break;
                }
            }
        } 
        else {
            Collections.sort(arr, Collections.reverseOrder());
        }

        long ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            ans = ans * 10 + arr.get(i);
        }

        return num > 0 ? ans : -ans;
    }
}