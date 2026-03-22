#include<bits/stdc++.h>
using namespace std;

long long Q[500][500];
int x[500];
int n, m;
long long score = 0;
long long max_score = -1;
int max_x[500];

void optimize() {
    bool stop = false;
    double T = 10000.0;
    while (T > 0.001) {
        stop = true;
        for (int i = 0; i < n; i++) {
            long long extended_score = Q[i][i];
            for (int j = 0; j < n; j++) {
                if (x[j] == 1 && j != i) {
                    extended_score += 2 * Q[i][j];
                }
            }
            long long E;
            if (x[i] == 0) {
                E = extended_score;
            } else if (x[i] == 1) {
                E = -extended_score;
            }
            if (E > 0) {
                x[i] = 1 - x[i];
                score = score + E;
                if (score > max_score) {
                    max_score = score;
                    for (int k = 0; k < n; k++) {
                        max_x[k] = x[k];
                    }
                }
                stop = false;
            } else {
                double p = exp((double)E/T);
                double r = (double)rand() / RAND_MAX;
                if (r < p) {
                    x[i] = 1 - x[i];
                    score = score + E;
                    if (score > max_score) {
                        max_score = score;
                        for (int k = 0; k < n; k++) {
                            max_x[k] = x[k];
                        }
                    }
                    stop = false;
                }
            }
        }
        T *= 0.99;
        if (stop == true) {
            break;
        }
    }
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < 500; i++) {
        for (int j = 0; j < 500; j++) {
            Q[i][j] = 0;
        }
    }
    cin >> n;
    cin >> m;
    for (int i = 0; i < n; i++) {
        x[i] = 0;
    }
    for (int k = 0; k < m; k++) {
        long long value;
        int u, v;
        cin >> u >> v >> value;
        Q[u][v] = value;
        Q[v][u] = value;
    }
    optimize();
    for (int i = 0; i < n; i++) {
        cout << max_x[i] << " ";
    }
}