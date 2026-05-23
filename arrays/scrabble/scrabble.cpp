#include <iostream>

int main(void)
{
  std::string p1_word = "";
  std::string p2_word = "";
  std::cout << "player 1: ";
  std::getline(std::cin, p1_word);
  std::cout << "player 2: ";
  std::getline(std::cin, p2_word);
  int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
  int p1_score = 0;
  for(char letter : p1_word)
  {
    char letter_ = tolower(letter);
    if(letter_ >= 'a' && letter_ <= 'z')
    {
      p1_score += points[(letter_ - 'a')];
    }
  }
  int p2_score = 0;
  for(char letter : p2_word)
  {
    char letter_ = tolower(letter);
    if(letter_ >= 'a' && letter_ <= 'z')
    {
      p2_score += points[(letter_ - 'a')];
    }
  }
  std::string result = (p1_score > p2_score) ? "player 1 wins!" : (p1_score < p2_score) ? "player 2 wins" : "tie!";
  std::cout << result << "\n";
  return 0;
}