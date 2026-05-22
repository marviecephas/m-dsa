//1. get text
#include <iostream>

int main(void)
{
  
  std::string text = "";
  std::cout << "text: ";
  std::getline(std::cin, text);
  int sentences = 0, letters = 0, words = 0;
  bool in_word = false;
  for(char t : text)
  {
    char i = tolower(t);
    if(in_word && (i == ' ' || i == '\n' || i == '\t'))
    {
      words++;
      in_word = false;
    }
    else if(i == '.' || i == '?' || i == '!')
    {
        sentences++;
    }
    else if(i != ' ' && i >= 'a' && i <= 'z')
    {
      letters++;
      in_word = true;
    }
  }
  if(in_word) words++;
  if(words == 0)
  {
    std::cout << "no text entered!\n";
    return 0;
  }
  std::cout << letters << "\n" << sentences << "\n";
  double L = 100 * letters / words;
  double S = 100 * sentences / words;
  double index = 0.0588 * L - 0.296 * S - 15.8;
  std::string grade = (index < 1) ? "<1" : ((index > 16) ? "16+" : std::to_string(int(round(index))));
  std::cout << index << "\ngrade: " << grade << "\n";
}