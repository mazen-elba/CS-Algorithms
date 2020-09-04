function productSum(array, multiplier = 1) {
  let total = 0;
  for (let i = 0; i < array.length; i++) {
    if (Array.isArray(array[i])) {
      total += productSum(array[i], multiplier + 1);
    } else {
      total += array[i];
    }
  }
  return total * multiplier;
}

exports.productSum = productSum;
