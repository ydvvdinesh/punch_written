class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int dup = x;
        int revnum = 0;
        int INT_MAX = 2147483647;
        while (x > 0) {
            int ld = x % 10;

            // 🔴 overflow guard (minimum required)
            if (revnum > INT_MAX= / 10)
                return false;

            revnum = revnum * 10 + ld;
            x /= 10;
        }

        return revnum == dup;
    }
};
