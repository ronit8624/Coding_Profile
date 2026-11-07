class Solution:
    def topoSort(self, adj, n):
        indeg = [0] * n

        for i in range(n):
            for it in adj[i]:
                indeg[it] += 1
        
        q = deque()

        for i in range(n):
            if indeg[i] == 0:
                q.append(i)
        
        ans = []

        while q:
            node = q.popleft()
            ans.append(node)

            for it in adj[node]:
                indeg[it] -= 1

                if indeg[it] == 0:
                    q.append(it)
        
        return ans

    def findOrder(self, numCourses: int, prerequisites: list[list[int]]) -> list[int]:
        n = numCourses
        adj = [[] for _ in range(n)]

        for course, prereq in prerequisites:
            adj[prereq].append(course)

        ans = self.topoSort(adj, n)
        
        if len(ans) != n:
            return []
        
        return ans