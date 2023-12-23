#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Project {
    int start;
    int end;
    int reward;
};

bool compareProjects(Project& p1, Project& p2) {
    return p1.end < p2.end;
}

int main() {
    int vi;
    cin >> vi;

    vector<Project> projects(vi);
    for (int i = 0; i < vi; ++i) {
        cin >> projects[i].start >> projects[i].end >> projects[i].reward;
    }

    sort(projects.begin(), projects.end(), compareProjects);

    vector<long long> dp(vi + 1, 0);
    for (int i = 1; i <= vi; ++i) {
        int prev = lower_bound(projects.begin(), projects.end(), projects[i-1].start, 
            [](const Project& p, int val) { return p.end < val; }) - projects.begin();
        dp[i] = max((long long)projects[i-1].reward + dp[prev], dp[i-1]);
    }

    cout << dp[vi] << endl;

    return 0;
}
