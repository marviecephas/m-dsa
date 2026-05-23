def verify_key(key):
  for k in key:
    K = ord(k)
    if(K < ord('0') or K > ord('9')) : return False
  return True
def get_ciphertext(plaintext, key):
  if (plaintext == ''): return 'plaintext is empty!'
  ciphertext = ''
  i, j, KEY= [1, 0.1, 0]
  for k in key:
    KEY += (ord(k) - ord('0')) * i
    i *= 0.1
    j *= 10
  KEY *= j
  for char in plaintext:
    CHAR = ord(char.upper())
    ciphertext += str(int(ord(char) + KEY%26)) if((CHAR >= ord('A')) and (CHAR <= ord('Z'))) else c
  return ciphertext


def encrypt():
  key = input('key: ')
  if(verify_key(key)):
    plaintext = input('plaintext: ')
    print(get_ciphertext(plaintext, key))
  else:
    print('key MUST be a POSITIVE INTEGER!')
    encrypt()
  
encrypt()
  
  