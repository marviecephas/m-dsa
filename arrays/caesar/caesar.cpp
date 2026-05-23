#include <iostream>
bool verifyKey(std::string key);
std::string ciphertext(std::string plaintext, std::string key);
int main(int argc, char* argv[])
{
  if(argc != 2 || !verifyKey(argv[1]))
  {
    std::cout << "usage: ./caesar key {key must be a positive integer}";
    return 1;
  }
  else
  {
    std::cout << "plaintext:  ";
    std::string plaintext = "";
    std::getline(std::cin, plaintext);
    std::cout << ciphertext(plaintext, argv[1]) << "\n";
    return 0;
  }
}

bool verifyKey(std::string key)
{
  for(char c : key)
  {
    if(c < '0' || c > '9')
    {
      return false;
    }
  }
  return true;
}

std::string ciphertext(std::string plaintext, std::string key){
  if(plaintext == "") return "plaintext is empty!";
  std::string ciphertext = "ciphertext: ";
  int Key = 0;
  float j = 1, i = 0.1, l = 0;
  for(char k : key)
  {
    l += (k - '0') * j;
    j *= 0.1;
    i *= 10;
  }
  l *= i;
  Key = static_cast<int>(l);
  for(char c : plaintext)
  {
    if(c >= 'A' && c <= 'Z') ciphertext += ('A' + (c - 'A' + Key)%26);
    else if(c >= 'a' && c <= 'z') ciphertext += ('a' + (c - 'a' + Key)%26);
    else ciphertext += c;
  }
  return ciphertext;
}