#include <iostream>
#include <queue>
using namespace std;

class RecentCounter {
private:
    queue<int> pings;

public:
    RecentCounter() {}

    int ping(int t) {
        pings.push(t);

        while (pings.front() < t - 3000) {
            pings.pop();
        }

        return pings.size();
    }
};

int main() {
    RecentCounter recentCounter;

    cout << recentCounter.ping(1) << endl;
    cout << recentCounter.ping(100) << endl;
    cout << recentCounter.ping(3001) << endl;
    cout << recentCounter.ping(3002) << endl;

    return 0;
}