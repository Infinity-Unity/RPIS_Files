data = {
    1:'Alex1',
    2:'Alex2',
    3:'Alex3',
    4:'Alex4',
    5:'Alex5',
    6:'Alex6'

}
a = data.items()

def reverse_dict(dict_items):
    return {value: key for key, value in dict_items}

print(reverse_dict(a))

