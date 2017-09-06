#include <bits/stdc++.h>
using namespace std;

typedef vector<double> Vector;
typedef vector<Vector> Matriz;

const double ERROR = 1e-9;

bool EsCero(double a) {
    return fabs(a) < ERROR;
}

// En caso de no permitir el pivoteo (eg. cuando
// requieran sacar una matriz inversa) simplemente
// comenten o borren la seccion <comment>.
void EliminacionGaussiana(Matriz& m) {
    for (int i = 0; i < m.size(); ++i) {
    	// <comment>
        int fila_mayor = i;
        for (int j = i + 1; j < m.size(); ++j)
            if (fabs(m[fila_mayor][i]) < fabs(m[j][i])) 
            	fila_mayor = j;
        swap(m[i], m[fila_mayor]);
        // </comment>

        if (EsCero(m[i][i])) continue; //No invertible (Singular)
        for (int j = m[i].size() - 1; j >= i; --j)
            m[i][j] = m[i][j] / m[i][i];
        for (int j = 0; j < m.size(); ++j) {
            if (i == j || EsCero(m[j][i])) continue;
            for (int k = m[j].size() - 1; k >= i; --k)
                m[j][k] = m[j][k] - m[i][k] * m[j][i];
        }
    }
}

int main() {
	
	int n;
	Matriz mat;
	bool sol, tmp;

	while (true) {
		cin >> n;
		if (n == 0) break;
		mat.assign(n, Vector(n + 1));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> mat[i][j];

		for (int i = 0; i < n; i++)
			cin >> mat[i][n];
		
		sol = true;
		EliminacionGaussiana(mat);
		for (int i = 0; i < n && sol; i++)
			if (EsCero(mat[i][i]))
				sol = false;
		
		if (sol) {
			for (int i = 0; i < n; i++)
				cout << mat[i][n] << " ";
		}
		else {
			tmp = true;
			for (int i = 0; i < n; i++) {
				if (EsCero(mat[i][0])) {
					bool cero = true;
					for (int j = 0; j < n + 1; j++) {
						if (!EsCero(mat[i][j])) {
							cero = false;
							break;
						}
					}
					if (cero) {
						cout << "multiple";
						tmp = false;
						break;
					}
				}
			}
			if (tmp) cout << "inconsistent";
		}
		cout << "\n";
		mat.clear();
	}
	return  0;
}
