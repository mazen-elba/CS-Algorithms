def productSum(array, multiplier=1):
    total = 0
    for i in range(len(array)):
        if type(array[i]) == list:
            total += productSum(array[i], multiplier + 1)
        else:
            total += array[i]
    return total * multiplier
