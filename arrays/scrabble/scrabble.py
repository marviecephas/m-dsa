p1_word = input("player 1: ")
p2_word = input("player 3: ")
points = [1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10];
p1_score = 0
p2_score = 0
a = ord('a')
z = ord('z')

for letter in p1_word:
  letter_ = ord(letter.lower())
  p1_score += points[letter_ - a] if (letter_ <= z and letter_ >= a) else 0
for letter in p2_word:
  letter_ = ord(letter.lower())
  p2_score += points[letter_ - a] if (letter_ <= z and letter_ >= a) else 0

result = "player 1 wins" if (p1_score > p2_score) else ("player 2 wins" if (p2_score > p1_score) else "tie!")
print(result)
  