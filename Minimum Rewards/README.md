Minimum Rewards

Write a function that takes a list of scores and returns the minimum number of rewards that you must give out to students to satisfy these two rules:

1. All students must receive at least one reward.
2. Any given student must receive strictly more rewards that an adjacent student (a student immediately to the left or the right) with a lower score and must receive strictly fewer rewards than an adjacent student with a higher score.

Assume that all students have different scores (ie; scores are all unique).

INPUT
scores = [8, 4, 2, 1, 3, 6, 7, 9, 5]

OUTPUT
25 // gives out the following rewards: [4, 3, 2, 1, 2, 3, 4, 5, 1]
