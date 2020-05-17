/*
 * Leetcode: 210. 课程表 II
 * tag: DFS
 * language: CPP
 * data: 2020/5/17
 */

class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    vector<int> stack;
    bool loop = false;
public:
    void dfs(int v) {
        visited[v] = 1;
        for(int u : edges[v]) {
            if(visited[u] == 0) {
                dfs(u);
                if(loop) {
                    return;
                }
            } else if (visited[u] == 1) {
                loop = true;
                return;
            }
        }
        visited[v] = 2;
        stack.push_back(v);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for(const auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
        }
        for (int i = 0; i < numCourses && !loop; i++) {
            if (visited[i] == 0) {
                dfs(i);
            }
        }
        if (loop) {
            return {};
        }
        reverse(stack.begin(), stack.end());
        return stack;
    }
};