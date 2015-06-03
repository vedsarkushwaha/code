from fractions import Fraction
t=int(raw_input())
for i in range(t):
	m=float(raw_input())
	print Fraction(m).limit_denominator(10000).denominator
