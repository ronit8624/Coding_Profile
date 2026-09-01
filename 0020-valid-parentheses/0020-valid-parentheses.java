class Solution {
    boolean isOpenning(char curr) {
        return curr == '(' || curr == '{' || curr == '[';
    }

    boolean isMatched(char open, char close) {
        return (open == '(' && close == ')') ||
                (open == '{' && close == '}') ||
                (open == '[' && close == ']');
    }

    public boolean isValid(String s) {
        int n = s.length();
        
        if(n == 1) return false;

        Stack<Character> st = new Stack<>();

        for(int i=0;i<n;i++) {
            char curr = s.charAt(i);

            if(isOpenning(curr)) {
                st.add(curr);
            }
            else {
                if (st.isEmpty()) return false;

                char popped = st.pop();
                if(!isMatched(popped, curr)) return false;
            }
        }

        return st.isEmpty();
    }
}