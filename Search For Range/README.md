Search For Range

Write a function that takes in a sorted array of integers and a target integer. The function should use a variation of Binary Search algorithm to find a range of indices in between which the target number is contained in the array, and should return this range in the form of an array.

NOTE - first number in output array should represent the first index at which the target number is located, while the second number should represent the last index at which the target number is located.

NOTE - function should return [-1,-1] if the integer is not contained in the array.

INPUT
array = [0, 1, 21, 33, 45, 45, 45, 45, 45, 45, 61, 71, 73]
target = 45

OUTPUT
[4, 9]
