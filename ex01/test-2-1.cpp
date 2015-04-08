#include <iostream>
using namespace std;

int main() {
  int a, b;
  while ( cin >> a >> b ) {
    int c = 15 - a - b;
    cout << "c => " << c << endl;
  }
  return 0;
}
