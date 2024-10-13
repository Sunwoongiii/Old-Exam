// #include <iostream>
// using namespace std;

// int p(){
//   cout<<"p\n";
//   return 1;
// }

// int q(){
//   cout<<"q\n";
//   return 0;
// }

// int main(){
//   cout<<p()&&q();
// }
#include <iostream>
using namespace std;

int p() {
  cout << "p\n";
  return 1;
}

int q() {
  cout << "q\n";
  return 0;
}

int main() {
  cout << (p() || q());
}
