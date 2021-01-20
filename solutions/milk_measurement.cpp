#include <iostream>
#include <fstream>
using namespace std;

int changes[3][101];
int rates[3][101];

bool is_highest(int c, int d) {
  int highest = max(max(rates[0][d], rates[1][d]), rates[2][d]);
  return rates[c][d] == highest;
}

int main() {
  ifstream fin ("measurement.in");
  ofstream fout ("measurement.out");

  int num;
  int day, cow_num, output;
  string cow_name;

  int num_changes = 0;

  fin >> num;

  for (int i = 0; i < num; i++) {
    fin >> day >> cow_name >> output;

    if (cow_name == "Bessie") cow_num = 0;
    if (cow_name == "Elsie") cow_num = 1;
    if (cow_name == "Mildred") cow_num = 2;

    changes[cow_num][day] = output;
  }

  for (int c = 0; c <= 2; c++) {
    rates[c][0] = 7;
  }

  for (int c = 0; c <= 2; c++) {
    for (int d = 1; d <= 100; d++) {
      rates[c][d] = rates[c][d - 1] + changes[c][d];
    }
  }

  for (int d = 1; d <= 100; d++) {
    if (is_highest(0, d - 1) != is_highest(0, d)
        || is_highest(1, d - 1) != is_highest(1, d)
        || is_highest(2, d - 1) != is_highest(2, d)) {
      num_changes++;
    }
  }

  fout << num_changes << "\n";

  return 0;
}
