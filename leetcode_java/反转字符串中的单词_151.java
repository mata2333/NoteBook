import java.util.Stack;

public class 反转字符串中的单词_151 {
    public String reverseWords(String s) {
        s = s.trim();
        StringBuilder ans = new StringBuilder();
        Stack<String> stack = new Stack<>();
        int start = 0;
        int end = 0;
        for (; end < s.length(); end++) {
            if ((end == 0 && s.charAt(end) == ' ') || (end > 0 && s.charAt(end - 1) == ' ' && s.charAt(end) == ' ')) {
                start = end + 1;
                continue;
            }
            if (s.charAt(end) == ' ') {
                stack.push(s.substring(start, end).trim());
                start = end + 1;
            }
        }
        if (end == s.length()) {
            stack.push(s.substring(start, end).trim());
        }
        ans.append(stack.pop());
        while (!stack.isEmpty()) {
            ans.append(' ');
            ans.append(stack.pop());
        }
        return ans.toString();
    }
}
