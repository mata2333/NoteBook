import java.lang.reflect.Array;

public class 重复的子字符串_459 {

    public static int[] getNext(String s) {
        int[] next = new int[s.length()];
        char[] charArray = s.toCharArray();
        int left = 0, right = 1, len = 0;
        next[left] = 0;
        while (right < charArray.length) {
            if (charArray[right] == charArray[left]) {
                len++;
                next[right] = len;
                right++;
                left++;
            } else {
                if (left > 0) {
                    left = next[left - 1];
                } else {
                    next[right] = len;
                    right++;
                }
                len = left;
            }
        }

        return next;
    }

    public boolean repeatedSubstringPattern(String s) {
        if (s.length() <= 1)
            return false;
        int[] next = getNext(s);
        return (s.length() % (s.length() - next[s.length() - 1]) == 0) && (next[s.length() - 1] != 0);
    }
}
