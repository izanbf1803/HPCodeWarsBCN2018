import sys
import os
if len(sys.argv) == 1:
	sys.exit(0)
n = sys.argv[1]
os.system("g++ -static -std=gnu++11 -o {n}.exe {n}.cc".format(n=n))