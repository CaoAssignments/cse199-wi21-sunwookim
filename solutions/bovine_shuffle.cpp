#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream fin ("shuffle.in");
  ofstream fout ("shuffle.out");

  int num;
  int shuffle_spots[100];
  int order[100];
  int original_order[100];

  fin >> num;

  for (int i = 0; i < num; i++) {
    fin >> shuffle_spots[i];
  }

  for (int i = 0; i < num; i++) {
    fin >> order[i];
  }

  for (int iter = 1; iter <= 3; iter++) {
    for (int i = 0; i < num; i++) {
      original_order[i] = order[shuffle_spots[i] - 1];
    }

    for (int i = 0; i < num; i++) {
      order[i] = original_order[i];
    }
  }

  for (int i = 0; i < num; i++) {
    fout << order[i] << "\n";
  }

  return 0;
}
