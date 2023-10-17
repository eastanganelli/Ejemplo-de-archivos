#include <fstream>
#include <iostream>

using namespace std;

int main() {
  ifstream infile("binary_file.bin", ios::binary);
  if (!infile.is_open()) {
    cout << "Error opening binary file" << endl;
    return 1;
  }

  char buffer[1024];
  while (infile.good()) {
    infile.read(buffer, sizeof(buffer));
  }

  infile.close();

  ofstream outfile("binary_file_out.bin", ios::binary);
  if (!outfile.is_open()) {
    cout << "Error opening binary file" << endl;
    return 1;
  }

  char data[] = "This is the binary data.";
  outfile.write(data, sizeof(data));

  outfile.close();

  return 0;
}