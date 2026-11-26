class Solution:
    def getKey(self, s):
        key = sorted(s)
        return ''.join(key)

    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        result = []
        groups = defaultdict(list)
        
        for s in strs:
            key = self.getKey(s)
            groups[key].append(s)

        for value in groups.values():
            result.append(value)

        return result