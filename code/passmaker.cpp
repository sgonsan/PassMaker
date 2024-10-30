#include "functions.h"

int main(int argc, char const *argv[]) {
  std::cout << "Welcome to PassMaker!" << std::endl;

  int length, numPasswords, numSpecialChars, groupSize;
  std::string groupDivider;

  getInputs(length, numPasswords, numSpecialChars, groupSize, groupDivider);

  std::cout << std::endl
            << "Generating " << numPasswords << " passwords of length "
            << length << " with " << numSpecialChars
            << " special characters and group "
            << "size " << groupSize << "." << std::endl
            << std::endl;

  for (int i = 0; i < numPasswords; i++) {
    srand(time(0) + i * 1000);
    generatePasswords(length, numSpecialChars, groupSize, groupDivider);
  }

  return 0;
}
