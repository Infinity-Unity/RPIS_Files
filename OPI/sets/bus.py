list1 = set(input('Введите дома для первого листа\n').split())
list2 = set(input('Введите дома для второго листа\n').split())
list3 = set()
list4 = set()
for i in list1:
    for i1 in list2:
        if i == i1:
            list3.add(i)
if list3 == list4:
    print('Empty')
else:
    print(list3)


