from fractions import gcd
for cas in xrange(input()):
    a,b,x,y = map(int,raw_input().split())
    print "NO YES".split()[gcd(a,b) == gcd(x,y)]
