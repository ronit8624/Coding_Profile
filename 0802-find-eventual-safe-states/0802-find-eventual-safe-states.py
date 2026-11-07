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

    def eventualSafeNodes(self, graph: list[list[int]]) -> list[int]:
        n = len(graph)
        m = len(graph[0])

        adjRev = [[] for _ in range(n)]

        for i in range(n):
            for it in graph[i]:
                adjRev[it].append(i)

        ans = self.topoSort(adjRev, n)
        ans.sort()

        return ans