function isValidSubsequence(array, sequence) {
  var arrIdx = 0;
  var seqIdx = 0;
  while (arrIdx < array.length && seqIdx < array.length) {
    if (array[arrIdx] === sequence[seqIdx]) {
      seqIdx++;
    }
    arrIdx++;
  }

  return seqIdx === sequence.length;
}

exports.isValidSubsequence = isValidSubsequence;
