school = {
    '1a':33,
    '1b':21,
    '2b':19,
    '6a':21,
    '7v':12
}
for i in school:
    print(f'{i}:{school.get(i)}')
print('\n\n\n\n')
school['7v'] = 30 #a
school.setdefault('8b')#b
school['8b'] = 35
school.pop('1b')
for f in school:
    print(f'{f}:{school.get(f)}')
child = 0
for u in school:
    child += school.get(u)
print(child)
