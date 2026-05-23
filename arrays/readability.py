text = input("text: ")
letters, words, sentences = [0, 0, 0]
in_word = False
for txt in text.lower():
  t = ord(txt)
  if(in_word and (txt == ' ' or txt == '\n' or txt == '\t')):
    words += 1
    in_word = False
  if(txt != ' ' and t >= ord('a') and t <= ord('z')):
    letters += 1
    in_word = True
  if(txt == '.' or txt == '!' or txt == '?'):
    sentences += 1

words += 1 if in_word else 0
if(words == 0):
  print('no text entered!')

else:
  L = 100 * letters / words
  S = 100 * sentences / words

  index = 0.0588 * L - 0.296 * S - 15.8;
  grade = '16+' if (index > 16) else ( '<1' if (index < 1) else str(int(round(index))))
  print(f'grade : {grade}')
