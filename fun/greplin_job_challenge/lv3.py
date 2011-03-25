#!/usr/bin/env python

from itertools import combinations, chain
nums = tuple([int(v) for v in "3   4   9   14  15  19  28  37  47  50  54  56  59  61  70  73  78  81  92  95  97  99".split(' ') if v.strip()])

summ = [1 for v in chain(*[combinations(nums, r) for r in range(3, len(nums))]) if sum(v[0:-1]) == v[-1]]
print sum(summ)
