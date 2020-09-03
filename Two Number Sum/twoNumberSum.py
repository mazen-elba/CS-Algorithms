def twoNumberSum(array, targetSum):
    for i in range(len(array) - 1):
        for j in range(i + 1, len(array)):
            if targetSum == (array[i] + array[j]):
                return [array[i], array[j]]

    return []
