#include <iostream>
 
using namespace std;
 
bool checker (int from, int to) {
    return (((from == 1) && (to == 2)) || ((from == 2) && (to == 3)) || ((from == 3) && (to == 1)));
}
 
void tower(int num, int from, int to)
{
    if (num != 0) {
        int buffer;
		 buffer  = 6 - from - to;
        if (checker(from, to)) {
            tower(num - 1, from, buffer);
            cout << num << " " << from << " " << to << endl;
            tower(num - 1, buffer, to);
        }
        else {
            tower(num - 1, from, to);
            cout << num << " " << from << " " << buffer << endl;
            tower(num - 1, to, from);
            cout << num << " " << buffer << " " << to << endl;
            tower(num - 1, from, to);
        }
    }
}
 
int main()
{
    int num;
    cin >> num;
    tower(num, 1, 3);
}
