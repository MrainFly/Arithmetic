class Solution(object):
    def largeGroupPositions(self, s):
        """
        :type s: str
        :rtype: List[List[int]]
        """
        start = 0
        end = 0
        rlist = []
        if len(s) < 3:
            return rlist
        for end in range(len(s)):
            if s[end] == s[start]:
                pass
            else:
                if end - start < 3:
                    start = end
                else:
                    rlist.append([start, end - 1])
                    start = end

        if end - start + 1 < 3:
            pass
        else:
            rlist.append([start, end])

        return rlist


if __name__ == "__main__":
    s = Solution()
    input_string = "aaa"
    l = s.largeGroupPositions(input_string)
    while True:
        pass