class Solution {
    public String decodeString(String s) {
        Stack<Integer> numStack = new Stack<>();
        Stack<String>  strStack = new Stack<>();
        String current = "";
        int num = 0;

        for(char ch : s.toCharArray()) {
            if(Character.isDigit(ch)) {
                num = num * 10 + (ch - '0');
            }
            else if(ch == '[') {
                numStack.push(num);
                strStack.push(current);
                num = 0;
                current = "";
            }
            else if(ch == ']') {
                int repeat = numStack.pop();
                String prev = strStack.pop();

                StringBuilder sb = new StringBuilder(prev);
                for(int i=0;i<repeat;i++) {
                    sb.append(current);
                }

                current = sb.toString();
            }
            else {
                current += ch;
            }
        }

        return current;
    }
}