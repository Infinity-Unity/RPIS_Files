numbers = ((5, 4, 5, 4), (3, 3, 4, 6), (8, 9, 5, 4), (12, 4, 5, 1), (9, 3, 5, 1))
number_to_list = list(numbers)
for i in range(len(number_to_list)):
    print(sum(number_to_list[i])/4,end = ' ')