def verify_key(key):
  if(len(key) != 26): return False
  has_occured = [
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0
    ]
  for k in key:
    K = ord(k.upper())
    if(K < ord('A') or K > ord('Z')) : return False
    else:
      has_occured[K - ord('A')] = 1
  for h in has_occured:
    if(not h): return False
  return True
def get_ciphertext(plaintext, key):
  if (plaintext == ''): return 'plaintext is empty!'
  ciphertext = 'ciphertext: '
  for char in plaintext:
    CHAR = ord(char)
    ciphertext += key[CHAR - ord('A')].upper() if((CHAR >= ord('A')) and (CHAR <= ord('Z'))) else (key[ CHAR - ord('a')].lower() if((CHAR >= ord('a')) and (CHAR <= ord('z'))) else char)
  return ciphertext


def encrypt():
  key = input('key: ')
  if(verify_key(key)):
    plaintext = input('plaintext: ')
    print(get_ciphertext(plaintext, key))
  else:
    print('key must include ALL and ONLY the 26 LETTERS of the alphabet, NON-REPEATING!')
    encrypt()
    
encrypt()
  