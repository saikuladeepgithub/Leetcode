class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int one = (coordinate1[0] - 'a') + (coordinate1[1] - '0');
        int two = (coordinate2[0] - 'a') + (coordinate2[1]-'0');
        return one % 2 == two % 2;

        // Each square's position can be translated into a unique numeric value:
// The column (a-h) can be mapped to integers 0-7.
// The row (1-8) can be directly used as integers.
// The color of a square can be determined by summing its column and row indices:
// If the sum is even, the square is black.
// If the sum is odd, the square is white
    }
};