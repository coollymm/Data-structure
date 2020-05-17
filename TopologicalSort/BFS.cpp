/*
 * Leetcode: 210. 课程表 II
 * tag: BFS
 * language: CPP
 * data: 2020/5/13
 */

class Solution {
private:
    vector<vector<int>> edges;
    vector<int> indeg;
    vector<int> result;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for(const auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
            indeg[info[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if(indeg[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int v = q.front();
            q.pop();
            result.push_back(v);
            for (auto u: edges[v]) {
                indeg[u]--;
                if(indeg[u] == 0) {
                    q.push(u);
                }
            }
        }

        if(result.size() != numCourses) {
            return {};
        }
        return result;
    }
};