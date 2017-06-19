#include <iostream>
#include <fstream>

using namespace std;

int main() {
  string linha;
  ifstream myfile ("chaves.txt");
  int i = 1;
  if(myfile.is_open()) {
    while(getline(myfile,linha)) {
      cout << i << " - " << linha << endl;
      i ++;
    }
    myfile.close();
  }else {
    cout << "\nImpossível abrir arquivo\n";
  }
  return 0;
}
