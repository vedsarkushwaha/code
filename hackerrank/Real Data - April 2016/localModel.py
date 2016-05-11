import base64
import cPickle as pickle
import zlib
import sys
from os.path import join, dirname, realpath

def writeToFile(fname):
	with open(fname) as f_in:
	    lines = [line.strip() for line in f_in]
	    serialized = base64.encodestring(zlib.compress(pickle.dumps(lines, -1), 9))
	    with open("serialized_"+fname.split('/')[-1][:-4]+".txt", "w") as f_out:
	        f_out.write(serialized)

basepath = join(dirname(realpath(__file__)), 'google-10000-english')
writeToFile(join(basepath, 'google-10000-english.txt'))