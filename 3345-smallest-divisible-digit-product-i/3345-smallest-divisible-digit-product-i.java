class Solution {
    private int getDigitProduct(int n) {
        long prod = 1;

        while(n != 0) {
            int lastDigit = n % 10;
            prod *= lastDigit;
            n = n / 10;
        }

        return (int) prod;
    }

    public int smallestNumber(int n, int t) {
        int digitProd = getDigitProduct(n);

        if(digitProd % t == 0) {
            return n;
        }

        n = n + 1;

        while(true) {
            int prod = getDigitProduct(n);

            if(prod % t == 0) {
                return n;
            }

            n++;
        }
    }
}