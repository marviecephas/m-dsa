#include <iostream>
bool verifyKey(std::string key);
std::string ciphertext(std::string plaintext, std::string key);
int main(int argc, char* argv[])
{
  if(argc != 2 || !verifyKey(argv[1]))
  {
    std::cout << "usage: ./caesar key {key must include all and only the 26 alphabets}";
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
  int keylen = 0;
  bool has_occurred[26] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
  for(char c : key)
  {
    char C = toupper(c);
    if(C < 'A' || C > 'Z')
    {
      return false;
    }
    has_occurred[C - 'A'] = 1;
    keylen++;
  }
  if (keylen != 26) 
  {
    return false;
  }
  else
  {
    for(bool b : has_occurred)
    {
      if(!b)
      {
        return false;
      }
    }
  }
  return true;
}

std::string ciphertext(std::string plaintext, std::string key)
{
  if(plaintext == "") return "plaintext is empty!";
  std::string ciphertext = "ciphertext: ";
  for(char c : plaintext)
  {
    char C = toupper(c);
    ciphertext += (C >= 'A' && C <= 'Z') ? key[C - 'A'] : c;
  }
  return ciphertext;
}