#include <iostream>
#include <vector>

using namespace std;
using LL = long long;

const int DIV = 1e5;
inline LL ceil(LL x, LL y) {
    return (x + y - 1) / y;
}

int main() {
    int T, M; cin >> T >> M;

    vector<bool> is_seen(M + 1, false);
    is_seen[0] = true;
    vector<int> answer(M + 1, -1);
    answer[0] = 0;

    for (int timestep = 1; timestep <= T; timestep++) {
        auto new_is_seen = is_seen;

        int t, y; LL x;
        cin >> t >> x >> y;

        auto operation = [&] (long long &curr) {
            if (t == 1) {
                curr = curr + ceil(x, DIV);
            } else {
                curr = ceil(curr * x, DIV);
            }
        };

        for (int k = 0; k <= M; k++) {
            if (is_seen[k]) {
                long long curr = k;
                operation(curr);

                for (int a = 1; a <= y;) {
                    if (curr > M) break;
                    if (is_seen[curr]) break;
                    
                    new_is_seen[curr] = true;
                    answer[curr] = timestep;

                    a++;
                    operation(curr);
                }
            }
        }

        is_seen = new_is_seen;
    }

    for (int i = 1; i <= M; i++)
        cout << answer[i] << " ";

    cout << endl;
}