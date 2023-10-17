#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

int main() {
  ifstream infile("csv_file.csv");
  if (!infile.is_open()) {
    cout << "Error opening CSV file" << endl;
    return 1;
  }

  string header;
  getline(infile, header);

  while (infile.good()) {
    string line;
    getline(infile, line);

    char delimiter = ',';
    string field;
    istringstream iss(line);
    while (getline(iss, field, delimiter)) {
      cout << field << " ";
    }
    cout << endl;
  }

  infile.close();

  ofstream outfile("csv_file_out.csv");
  if (!outfile.is_open()) {
    cout << "Error opening CSV file" << endl;
    return 1;
  }

  outfile << header << endl;

  for (int i = 0; i < 10; i++) {
    int field1 = rand() % 100;
    int field2 = rand() % 100;

    outfile << field1 << "," << field2 << endl;
  }

  outfile.close();

  return 0;
}