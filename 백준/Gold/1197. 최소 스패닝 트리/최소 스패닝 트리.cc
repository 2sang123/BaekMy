#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int v, e;

// 간선을 표현하는 구조체
struct Edge {
    int u, v, w; // 정점 u와 v를 잇는 간선, 가중치 w

    // 가중치 기준으로 정렬하기 위한 연산자 오버로딩
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

// 부모 노드를 찾는 함수 (Find 연산)
int find(int x, vector<int>& parent) {
    if (x == parent[x]) return x; // 자기 자신이 부모면 반환
    return parent[x] = find(parent[x], parent); // 경로 압축 (재귀적으로 최상위 부모로 갱신)
}

// 두 노드를 하나의 집합으로 합치는 함수 (Union 연산)
bool merge(int a, int b, vector<int>& parent) {
    a = find(a, parent); // a의 대표 부모 찾기
    b = find(b, parent); // b의 대표 부모 찾기
    if (a == b) return false; // 이미 같은 집합이면 사이클이 생기므로 합치지 않음
    parent[b] = a; // b의 부모를 a로 설정하여 두 집합을 합침
    return true; // 합치기에 성공했음을 반환
}

// 크루스칼 알고리즘 본체
int kruskal(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end()); // 간선을 가중치 기준으로 오름차순 정렬

    // 유니온-파인드용 부모 배열 초기화
    vector<int> parent(V + 1); // 1번부터 V번 정점까지 사용
    for (int i = 1; i <= V; i++) parent[i] = i; // 처음엔 자기 자신이 부모

    int totalCost = 0; // 최소 신장 트리의 전체 비용

    // 정렬된 간선을 하나씩 확인
    for (Edge e : edges) {
        // 사이클이 생기지 않으면 간선을 선택하고 비용 추가
        if (merge(e.u, e.v, parent)) {
            totalCost += e.w;
        }
    }

    return totalCost; // MST의 총 가중치 반환
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> v >> e;
	vector<Edge> edges;
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		Edge d = { a, b, c };
		edges.push_back(d);
	}
    cout << kruskal(v, edges);
}
