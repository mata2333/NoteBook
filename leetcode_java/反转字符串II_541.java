public class 反转字符串II_541 {

    public String reverseStr(String s, int k) {
        char[] ans = s.toCharArray();
        for (int i = 0; i < s.length(); i += 2 * k) {
            int left = i;
            int right = Math.min(i + k - 1, s.length() - 1);
            while (left < right) {
                char tmp = ans[left];
                ans[left] = ans[right];
                ans[right] = tmp;
                left++;
                right--;
            }
        }
        return new String(ans);
    }
}
