dict = {}
for i in range(int(input())):
    inputs =  input().split()
    if inputs[0]== 'find':
        if inputs[1] in dict:
            print(dict.get(inputs[1]))
        else:
            print('not found')
    elif inputs[0]== 'add':
        dict[inputs[1]]=inputs[2]
    else:
        if inputs[1] in dict:
            del dict[inputs[1]]
