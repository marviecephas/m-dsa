//1. get text
#include <iostream>

int main(void)
{
  
  std::string text = "";
  std::cout << "text: ";
  std::getline(std::cin, text);
  std::string text_ = "";
  int N = 1;
  for(char t : text)
  {
    N += (t == ' ') ? 1 : 0;
    text_ += tolower(t);
  }
  int I = N/100 + 1;
  std::cout << I << "\n" << N << "\n";
  int sentences[I];
  int letters[I];
  for(int i = 0; i< I; i++)
  {
    sentences[i] = 0;
    letters[i] = 0;
  }
  int pos = 0;
  int n = 1;
  for(char i : text_)
  {
    if(i == ' ')
    {
      n++;
      pos = n/100;
    }
    else if(i == '.' || i == '?' || i == '!')
    {
        sentences[pos] += 1;
    }
    else if(i != ' ' && i >= 'a' && i <= 'z')
    {
      letters[pos] += 1;
    }
  }
  std::cout << letters[0] << "\n" << sentences[0] << "\n";
  int L = 0, S = 0, total_sentences_percent = 0, total_letters_percent = 0;
  for(int i = 0; i < I; i++)
  {
    total_sentences_percent += sentences[i];
    total_letters_percent += letters[i];
  }
  L = total_letters_percent / N * 100;
  S = total_sentences_percent / N * 100;
  float index = 0.0588 * L - 0.296 * S - 15.8;
  std::string grade = (index < 1) ? "<1" : ((index > 16) ? "16+" : std::to_string(index));
  std::cout << index << "\ngrade: " << grade << "\n";
}