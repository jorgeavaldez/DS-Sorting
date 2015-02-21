import random

f = open('biginput.txt', 'w')

letters = 'abcdefghijklmnopqrstuvwxyz'
capLetters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

ssize = random.randint(0, 90)
inputsize = 10000000 #random.randint(0, 1000)

sentenceCount = 0
iscap = False

for i in range(inputsize):
    word = ''

    if sentenceCount is 10:
        f.write('.\n')
        iscap = True

    for j in range(ssize):
        if iscap:
            word += random.choice(capLetters)
            iscap = False
            sentenceCount = 0

        else:
            word += random.choice(letters)


    f.write(' ' + word)
    ssize = random.randint(0, 50)
    sentenceCount += 1
