//1. get text
#include <iostream>

int main(void)
{
  
  std::string text = "";
  std::cout << "text: ";
  std::getline(std::cin, text);
  std::string text_ = "";
  int N = 1;
  for(int t : text)
  {
    N += (t == ' ') ? 1 : 0;
    text_ += t;
  }
  int I = trunc(N/100);
  int sentences[I];
  int letters[I];
  
  for(int i = 0; i < N; i++)
  {
    char character = text_[i];
    int index = trunc(i/100);
    if(character == '.' || character == '?' || character == '!')
    {
      sentences[index] += 1;
    }
    if(character != ' ' && character >= 'a' && character <= 'z')
    {
      letters[index] += 1;
    }
  }
  int L = 0, S = 0, total_sentences_per = 0, total_letters_per = 0;
  for(int i = 0; i < I; i++)
  {
    total_sentences_per += sentences[i];
    total_letters_per += letters[i];
  }
  L = total_letters_per/I;
  S = total_sentences_per/I;
  int index = trunc(0.0588 * L - 0.296 * S - 15.8);
  std::string grade = (index < 1) ? "<1" : ((index > 16) ? "16+" : std::to_string(index));
  std::cout << "grade: " << grade << "\n";
}