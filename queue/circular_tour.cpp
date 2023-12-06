#include <iostream>
#include <queue>
using namespace std;

struct GasStation {
    int gas;
    int distance;
};

int canCompleteTour(queue<GasStation>& stations, int n) {
    int start = 0;
    int balance = 0;
    int deficit = 0;

    for (int i = 0; i < n; i++) {
        GasStation currentStation = stations.front();
        stations.pop();

        balance = balance + currentStation.gas - currentStation.distance;
        if (balance < 0) {
            deficit = deficit + balance;
            start = i + 1;
            balance = 0;
        }

        stations.push(currentStation);
    }

    if (deficit + balance >= 0) {
        return start;
    } else {
        return -1;
    }
}

int main() {
    queue<GasStation> stations;
    stations.push({4, 6});
    stations.push({6, 9});
    stations.push({7, 3});
    stations.push({4, 2});

    int n = stations.size(); // Incorrect way to get the number of gas stations
    cout << "Number of stations: " << n << endl;

    int result = canCompleteTour(stations, n);
    cout << "Starting station: " << result << endl;

    return 0;
}
