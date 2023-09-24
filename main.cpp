#include <iostream>
#include <fstream>
#include <vector>

static const int max = 390624;

int main() {
    std::ifstream fin("in.txt");
    std::ofstream fout("out.txt");
    int n;
    fin >> n;
    std::vector<std::vector<int>> v(n, std::vector<int>(8));
    std::vector<int> corrects(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 8; ++j) {
            fin >> v[i][j];
            --v[i][j];
        }
        fin >> corrects[i];
    }

    for (int i = 0; i <= max; ++i) {
        bool flag = true;
        for (int num_v = 0; num_v < n; ++num_v) {
            int curr = 0;
            for (int j = 0, num = i; j < 8; ++j) {
                if (num % 5 == v[num_v][j]) ++curr;
                num /= 5;
            }
            if (curr < corrects[num_v]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            for (int j = 0, num = i; j < 8; ++j) {
                fout << num % 5 + 1 << '\n';
                num /= 5;
            }
            fout << '\n';
        }
    }

    return 0;
}
