#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Point {
    int x, y;
};

long long get_dist_sq(Point p1, Point p2) {
    long long dx = p1.x - p2.x;
    long long dy = p1.y - p2.y;
    return dx * dx + dy * dy;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    // 편의시설 좌표 저장
    std::vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> points[i].x >> points[i].y;
    }

    long long min_max_dist_sq = -1;
    Point best_point;

    // 각 편의시설을 집 위치 후보로 순회
    for (int i = 0; i < n; ++i) {
        long long current_max_dist_sq = 0;

        // 현재 집 위치(points[i])에서 가장 먼 편의시설 찾기
        for (int j = 0; j < n; ++j) {
            long long dist_sq = get_dist_sq(points[i], points[j]);
            if (dist_sq > current_max_dist_sq) {
                current_max_dist_sq = dist_sq;
            }
        }

        // 현재 찾은 '최대 거리'가 이전에 찾은 '최소 최대 거리'보다 작으면 갱신
        if (min_max_dist_sq == -1 || current_max_dist_sq < min_max_dist_sq) {
            min_max_dist_sq = current_max_dist_sq;
            best_point = points[i];
        }
    }

    // 결과 출력
    std::cout << best_point.x << " " << best_point.y << std::endl;

    return 0;
}