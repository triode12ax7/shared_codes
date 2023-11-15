#include <iostream>

using namespace std;

void hanoi(int number, int from, int to) {
    if (number == 0) {
        return;
    }

    hanoi(number - 1, from, 6 - from - to);
    cout << number << ' ' << from << " " << to << endl;
    hanoi(number - 1, 6 - from - to, to);
}
int main() {
    int n;
    cin >> n;

    hanoi(n, 1, 3);
}
