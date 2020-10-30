#include <iostream>
#include <array>
using namespace std;

template <int size>
struct DisjointSet
{
    array<int, size> parent;
    array<bool, 101> isAdded; // array of bool to check whether x is in the set or not
    int cardinality; // number of elements in disjoint set
    void init() {
        cardinality = 0;
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
        for(int i = 0; i < 101; i++)
            isAdded[i] = false;
    }

    int  find(int x) {
        if (parent[x] == x)
            return x;
        else
            return find(parent[x]);
    }

    void unions(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if(!isAdded[x])
            this->cardinality += 1;
        if(!isAdded[y])
            this->cardinality += 1;

        isAdded[x]= true;
        isAdded[y] = true;

        parent[rootX] = rootY;
    }

    bool check(int x, int y) {
        return find(x) == find(y);
    }

    int getCardinality() {
        return this->cardinality;
    }
};

int solve(int cards[], int n, int k, DisjointSet<105> ds) {
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++) {
            if((cards[i] + cards[j]) % k != 0) {
                ds.unions(cards[i], cards[j]);
            }
        }
    return ds.getCardinality();
}

int main()
{
    DisjointSet<105> disjointSet; //disjoint set to store the set of cards' value that satisfy the requirements
    int cards[105], n, k; //array to store the cards' value and variables to store input, respectively
    cin >> n >> k; //get n and k
    for(int i = 0; i < n; i++) { //get cards' value
        cin >> cards[i];
    }

    disjointSet.init(); //initialize disjoint set

    cout << solve(cards, n, k, disjointSet) << endl; //output result
}
