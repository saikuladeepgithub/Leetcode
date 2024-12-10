class Solution:
    def maximumLength(self, s: str) -> int:
        n = len(s)
        subarrays = []

        # Generate all substrings with the same character
        for i in range(n):
            j = i
            cur = ""
            while j < n and s[i] == s[j]:
                cur += s[j]
                subarrays.append(cur)
                j += 1

        # Count the frequency of each substring
        counter = Counter(subarrays)

        # Find the maximum length of substrings with frequency >= 3
        res = -1
        for substring, freq in counter.items():
            if freq >= 3 and len(substring) > res:
                res = len(substring)

        return res