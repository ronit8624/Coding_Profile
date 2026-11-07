class Solution:
    def topoSort(self, adj, n):
        indegree = [0] * n

        for i in range(n):
            for it in adj[i]:
                indegree[it] += 1
        
        q = deque()

        for i in range(n):
            if indegree[i] == 0:
                q.append(i)
        
        ans = []

        while q:
            node = q.popleft()
            ans.append(node)

            for it in adj[node]:
                indegree[it] -= 1

                if indegree[it] == 0:
                    q.append(it)
        
        return ans

    def canFinish(self, numCourses: int, prerequisites: list[list[int]]) -> bool:
        n = numCourses
        adj = [[] for _ in range(n)]

        for course, prereq in prerequisites:
            adj[prereq].append(course)
        
        ans = self.topoSort(adj, n)

        if len(ans) != numCourses:
            return False

        return True