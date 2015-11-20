#!/usr/bin/python

import os, sys, string, time, struct

def encrypt_xor(data, key):
    buff = ""
    for i in range(0, len(data)):
        buff += chr(ord(data[i]) ^ ord(key[i % len(key)]))
    return buff

def encrypt_xor2(data, key):
    buff = []
    for i in range(0, len(data)):
        buff.append(chr(ord(data[i]) ^ ord(key[i % len(key)])))
    return ''.join(buff)

def encrypt_xor3(data, key):
    index = len(data) % 4
    size = (4, 1, 2, 1)[index]
    type = ('L', 'B', 'H', 'B')[index]
    key_len = len(key)/size
    data_len = len(data)/size
    key_fmt = "<" + str(key_len) + type;
    data_fmt = "<" + str(data_len) + type;

    key_list = struct.unpack(key_fmt, key)
    data_list = struct.unpack(data_fmt, data)

    result = []
    for i in range(data_len):
        result.append (key_list[i % key_len] ^ data_list[i])

    return struct.pack(data_fmt, *result)

def encrypt_xor4(data, key):
    import numpy, math

    # key multiplication in order to match the data length
    key = (key*int(math.ceil(float(len(data))/float(len(key)))))[:len(data)]

    # Select the type size in bytes       
    for i in (8,4,2,1):
        if not len(data) % i: break

    if i == 8: dt = numpy.dtype('<Q8');
    elif i == 4: dt = numpy.dtype('<L4');
    elif i == 2: dt = numpy.dtype('<H2');
    else: dt = numpy.dtype('B');

    return numpy.bitwise_xor(numpy.fromstring(key, dtype=dt), numpy.fromstring(data, dtype=dt)).tostring()


''' main '''

fname = sys.argv[1]
pw = sys.argv[2]

if fname.find('.') == -1:
    fname2 = fname
else:
    fname2 = fname[:fname.find('.')]
fname2 = fname2[::-1]

print time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time()))
infile  = open(fname, "rb")
outfile = open(fname2, "wb")

while 1:
    line = infile.read(256)
    if len(line) == 0:
        break;

    line2 = encrypt_xor3(line, pw)
    outfile.write(line2)

infile.close()
outfile.close()

#os.remove(fname)
print time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time()))
