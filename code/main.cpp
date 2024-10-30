#include <iostream>
#include <vector>

const std::string kSpecialChars = "!@#$%^&*()\\/~_+-=[]{}|;:,.<>?\"\'";
const std::string kUppercaseChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string kLowercaseChars = "abcdefghijklmnopqrstuvwxyz";
const std::string kNumberChars = "0123456789";

char getRandomChar(const std::string &chars) {
  return chars[rand() % chars.size()];
}

/**
 * @brief Generates a password of the given length. The password will be
 * composed of random lowercase and uppercase letters, numbers, and special
 * characters.
 *
 * @param length The length of the password to generate.
 * @param numPasswords The number of passwords to generate.
 * @param numSpecialChars The number of special characters to include.
 * @param numGroup The number of groups to divide the password into.
 */
void generatePasswords(int length, int numSpecialChars, int groupSize,
                       std::string groupDivider) {
  std::string password;
  std::vector<char> specialIndexes(numSpecialChars);
  for (int i = 0; i < numSpecialChars; i++) {
    specialIndexes[i] = rand() % length;
    for (int j = 0; j < i; j++) {
      if (specialIndexes[i] == specialIndexes[j]) {
        i--;
        break;
      }
    }
  }

  for (int j = 0; j < length; j++) {
    char c;
    if (j > 0 && j % groupSize == 0) {
      password += groupDivider;
    }

    bool isSpecial = false;

    for (int k = 0; k < numSpecialChars; k++) {
      if (j == specialIndexes[k]) {
        isSpecial = true;
        break;
      }
    }

    if (isSpecial) {  // Special character
      c = getRandomChar(kSpecialChars);
    } else {  // Letter or number
      int type = rand() % 3;
      switch (type) {
        case 0:
          c = getRandomChar(kUppercaseChars);
          break;
        case 1:
          c = getRandomChar(kLowercaseChars);
          break;
        case 2:
          c = getRandomChar(kNumberChars);
          break;
      }
    }
    password += c;
  }
  std::cout << password << std::endl;
}

void getInputs(int &length, int &numPasswords, int &numSpecialChars,
               int &groupSize, std::string &groupDivider) {
  std::cout << "Length of password to generate (default is 8): ";
  try {
    std::string input;
    std::getline(std::cin, input);
    if (input.empty()) {
      length = 8;
    } else {
      length = std::stoi(input);
    }

    if (length <= 0) {
      throw std::invalid_argument("Length must be greater than 0.");
    }
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
    exit(1);
  }

  std::cout << "Number of passwords to generate (default is 1): ";
  try {
    std::string input;
    std::getline(std::cin, input);
    if (input.empty()) {
      numPasswords = 1;
    } else {
      numPasswords = std::stoi(input);
    }

    if (numPasswords <= 0) {
      throw std::invalid_argument(
          "Number of passwords must be greater than 0.");
    }
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
    exit(1);
  }

  std::cout << "Number of special characters to include (default is 0): ";
  try {
    std::string input;
    std::getline(std::cin, input);
    if (input.empty()) {
      numSpecialChars = 0;
    } else {
      numSpecialChars = std::stoi(input);
    }

    if (numSpecialChars < 0) {
      throw std::invalid_argument(
          "Number of special characters must be greater than or equal to 0.");
    }
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
    exit(1);
  }

  std::cout << "Group size for passwords (default is " << length << "): ";
  try {
    std::string input;
    std::getline(std::cin, input);
    if (input.empty()) {
      groupSize = length;
    } else {
      groupSize = std::stoi(input);
    }

    if (groupSize <= 0 || groupSize > length) {
      throw std::invalid_argument("Group size must be greater than 0.");
    }
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
    exit(1);
  }

  if (groupSize < length) {
    std::cout << "Group divider (default is '-'): ";
    std::getline(std::cin, groupDivider);
    if (groupDivider.empty()) {
      groupDivider = "-";
    }
  }
}

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