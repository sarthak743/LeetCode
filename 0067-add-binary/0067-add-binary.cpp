using namespace std;

class Solution {
public:
    // Pass to_add and carry by reference (&) to modify them in-place
    void processSum(int sum, int &to_add, int &carry) {
        to_add = sum % 2;  // 0 or 1
        carry = sum / 2;   // 0 or 1
    }

    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string result = "";

        // Run until both strings are fully processed AND carry is zero
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;

            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';

            int to_add = 0;
            processSum(sum, to_add, carry);

            result += (to_add + '0'); // Append character directly instead of to_string
        }

        reverse(result.begin(), result.end());
        return result;
    }
};