#include <fstream>
#include <iostream>

using namespace std;

int main() {
  ifstream infile("text_file.txt");
  if (!infile.is_open()) {
    cout << "Error opening text file" << endl;
    return 1;
  }

  string line;
  while (infile.good()) {
    getline(infile, line);
    cout << line << endl;
  }

  infile.close();

  ofstream outfile("text_file_out.txt");
  if (!outfile.is_open()) {
    cout << "Error opening text file" << endl;
    return 1;
  }

  outfile << "This is the first line of the text file." << endl;
  outfile << "This is the second line of the text file." << endl;

  outfile.close();

  return 0;
}