#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using MatrixOfDoubles = vector<vector<double>>;

void solution(MatrixOfDoubles& in, MatrixOfDoubles& out) {
    static constexpr int TILE_SIZE = 16;
    int size = in.size();
    for (int ii = 0; ii < size; ii += TILE_SIZE) {
        for (int jj = 0; jj < size; jj += TILE_SIZE) {
            for (int i = ii; i < min(ii + TILE_SIZE, size); i++) {
                for (int j = jj; j < min(jj + TILE_SIZE, size); j++) {
                    out[i][j] = in[j][i];
                }
            }
        }
    }
}

int main() {
    MatrixOfDoubles in = {
        {1.0, 2.0, 3.0, 4.0, 5.0},
        {6.0, 7.0, 8.0, 9.0, 10.0},
        {11.0, 12.0, 13.0, 14.0, 15.0},
        {16.0, 17.0, 18.0, 19.0, 20.0},
        {21.0, 22.0, 23.0, 24.0, 25.0}
    };

    MatrixOfDoubles out(5, vector<double>(5, 0.0));

    solution(in, out);

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << out[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
