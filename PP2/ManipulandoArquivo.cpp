#include <iostream>
#include <cstdio>

using namespace std;

int main() {
  FILE *arquivo;
  arquivo = fopen("chaves.txt", "rt");
  char linha[100], *result;
  int i = 1;
  while(!feof(arquivo)) {
    result = fgets(linha, 100, arquivo);
    if(result) {
      cout << "Linha " << i << "-> " << linha << endl;
    }
    i++;
  }
  fclose(arquivo);
  return 0;
}
