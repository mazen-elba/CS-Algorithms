function twoNumberSum(array, targetSum) {
  for (let i = 0; i < array.length; i++) {
    for (let j = i + 1; j < array.length; j++) {
      if (targetSum === array[i] + array[j]) {
        return [array[i], array[j]];
      }
    }
  }
  return [];
}

exports.twoNumberSum = twoNumberSum;
