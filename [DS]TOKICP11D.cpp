#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

typedef pair<int, int> pii;

/* kelas ini merepresentasikan directed weighted graph menggunakan
adjacency list*/
class Graph {
	int V;              // jumlah vertex dalam graph
public:
    vector<pii> *adj;   // adjacency list untuk menyimpan data ruas jalan dan waktu tempuh ruas jalan
    Graph(int V);       // constructor
	void addEdge(int u, int v, int w);      // fungsi untuk menambahkan edge (data ruas jalan) pada graph
	int shortestPath(int src, int dest);    // fungsi untuk mengetahui waktu perpindahan terkecil antara vertex "src" dan "dest"
};

// alokasi memori untuk adjacency list
Graph::Graph(int V) {
	this->V = V;
	adj = new vector<pii>[V];
}

// membuat edge dua arah yaitu (u, v) dan (v, u) dengan masing-masing edge memiliki weight yang sama yaitu w
void Graph::addEdge(int u, int v, int w) {
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

// fungsi untuk mencari waktu tempuh terkecil antara perumahan "src" dan "dest"
int Graph::shortestPath(int src, int dest) {
    // priority queue sebagai min heap yang menyimpan vertex yang akan diproses
	priority_queue<pii, vector <pii>, greater<pii>> pq;
	// vector untuk menyimpan waktu tempuh dari vertex "src" ke semua vertex lainnya
	// dan inisialisasi semua waktu tempuh dengan infinite (INF)
	vector<int> dist(V, INF);

	// masukkan vertex "src" ke priority queue dan inisialisasi waktu tempuh ke "src" dengan nilai 0
	pq.push(make_pair(0, src));
	dist[src] = 0;

	// perulangan sampai priority queue menjadi kosong atau tidak semua vertex terfinalisasi
	while (!pq.empty()) {
        // bagian pertama pada pair dalam pq adalah waktu tempuh vertex
        // bagian kedua pada pair dalam pq adalah label vertex
        // hal ini bertujuan untuk memudahkan pengurutan waktu tempuh ke vertex lainnya
		int u = pq.top().second;
		pq.pop();

		// lakukan breadth-first search (BFS) untuk mendapatkan vertex tetangga dari vertex u
		for (vector<pii>::iterator i = adj[u].begin(); i != adj[u].end(); i++) {
			int v = (*i).first;         // ambil label vertex
			int weight = (*i).second;   // ambil waktu tempuh vertex

			// jika ada waktu tempuh yang lebih kecil ke vertex v dari vertex u, maka perbarui waktu tempuh
			if (dist[v] > dist[u] + weight) { // relaxation
                // perbarui waktu tempuh
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
    return dist[dest]; // kembalikan nilai dari waktu tempuh terkecil antara vertex "src" ke vertex "dest"
}

int main() {
    int n, m, q;

    cin >> n >> m >> q; // input

    vector<int> house(q); // vector untuk menyimpan urutan perumahan yang harus dikunjungi
	Graph g(n);

	for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;         // input data ruas jalan dan waktu tempuh
        g.addEdge(u - 1, v - 1, w); // masukan edge pada graph
	}

	for(int i = 0; i < q; i++) {
        cin >> house[i];            // input urutan perumahan yang harus dikunjungi
	}

	int min_path = 0;   // inisialisasi total waktu perpindahan antar
                        // perumahan terkecil yang mungkin dengan nilai0 0
	for(int i = 1; i < q; i++) { // perulangan untuk mencari total waktu perpindahan antar perumahan terkecil
        min_path += g.shortestPath(house[i - 1] - 1, house[i] - 1);
	}

	cout << min_path << endl;   // total waktu perpindahan antar perumahan terkecil yang mungkin

	return 0;
}
