#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
    bool operator==(const Point& o) const { return x == o.x && y == o.y; }
    bool operator<(const Point& o) const { return (x == o.x) ? y < o.y : x < o.x; }
};

int heuristic(const Point& a, const Point& b) {
    return -(abs(a.x - b.x) + abs(a.y - b.y));
}

vector<Point> hillClimb(int n, Point start, Point goal) {
    vector<Point> path{start};
    Point cur = start, prev = {-1, -1};

    while (true) {
        vector<Point> nbrs;
        int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

        for (int i = 0; i < 4; i++) {
            Point p = {cur.x + dx[i], cur.y + dy[i]};
            if (p.x >= 0 && p.x < n && p.y >= 0 && p.y < n && !(p == prev))
                nbrs.push_back(p);
        }
        if (nbrs.empty()) break;

        sort(nbrs.begin(), nbrs.end());
        Point best = nbrs[0];
        int bestH = heuristic(best, goal);
        for (auto &p : nbrs)
            if (heuristic(p, goal) > bestH)
                best = p, bestH = heuristic(p, goal);

        if (bestH <= heuristic(cur, goal)) {
            cout << "\nLocal max reached.\n";
            break;
        }
        prev = cur;
        cur = best;
        path.push_back(cur);

        if (cur == goal) {
            cout << "\nGoal reached!\n";
            break;
        }
    }
    return path;
}

int main() {
    int n = 10;
    Point start = {1, 1}, goal = {8, 7};

    cout << "Hill Climbing from (" << start.x << "," << start.y << ") to ("
         << goal.x << "," << goal.y << ")\n";

    auto path = hillClimb(n, start, goal);

    cout << "\nPath: ";
    for (size_t i = 0; i < path.size(); i++) {
        cout << "(" << path[i].x << "," << path[i].y << ")";
        if (i < path.size() - 1) cout << " ";
    }
    cout << "\nFinal: (" << path.back().x << "," << path.back().y << ")";
    cout << "\nHeuristic: " << heuristic(path.back(), goal) << "\n";
}
