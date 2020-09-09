function binarySearch(array, target) {
  return helper(array, target, 0, array.length - 1);
}

function helper(array, target, startIdx, endIdx) {
  if (startIdx > endIdx) {
    return -1;
  }

  var middleIdx = Math.floor((startIdx + endIdx) / 2);
  var potentialMatch = array[middleIdx];

  if (target === potentialMatch) {
    return middleIdx;
  } else if (target < potentialMatch) {
    return helper(array, target, startIdx, middleIdx - 1);
  } else {
    return helper(array, target, middleIdx + 1, endIdx);
  }
}

exports.binarySearch = binarySearch;
