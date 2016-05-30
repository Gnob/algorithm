#include<iostream>

using namespace std;

int T, N;

int arr[100001];
int group[100001];
int DFS_Counter = 1;

int DFS(int v, int cnt) {
    group[v] = DFS_Counter;
    cout << v << "[" << DFS_Counter << "]" << "->" << arr[v];

    if (!group[arr[v]]) {
        cout << " going" << endl;
        return DFS(arr[v], cnt + 1);
    }
    else if (group[arr[v]] == DFS_Counter){
        cout << " true" << endl;
        return cnt;
    }
    else {
        cout << " false" << endl;
        return 0;
    }
}

int main() {
    int sum = 0, result = 0;
    cin >> T;

    while (T--) {
        sum = 0;
        DFS_Counter = 1;
        cin >> N;
        for (int i = 1; i <= N; ++i) {
            cin >> arr[i];

            if (arr[i] == i) {
                group[i] = DFS_Counter++;
                sum++;
            }
            else
                group[i] = 0;
        }

        for (int j = 1; j <= N; ++j) {
            if (!group[j]) {
                DFS_Counter++;
                result = DFS(j, 1);
                if(result > 0) {
                    sum += result;
                }
            }
        }

        cout << N - sum << "\n";
    }


    return 0;
}
