# C-SPADE C++ implementation

This is a copy of Mohammed Zaki's original implementation of his C-SPADE algorithm. It's been cleaned up to be compiled
by modern C++ compiler. Utility programs (exttpose, getconf, makebin) are also included

# How to compile
`make`
Binary files are available bin `bin/`

# How to run test
The archived downloaded from Zaki's website includes `test.txt`. In R there's another smaller dataset `zaki.txt`.
To run cspade you need to:
 - Convert ascii data to binary with `makebin test.txt test.data`
 - Get a configuration file with `getconf -i test -o test`
 - Convert the database to vertical format with `exttpose -i test -o test -s 0 -l -x`
 - The you can run cspade e.g. `spade -e 1 -r -i test -s 0.2 -u 2 -o`

 See README for details of the arguments

 Run `make NAME="test" test` to run all of the above commands on the `test.txt` set
 Run `make NAME="zaki" test` to run all of the above commands on the `zaki.txt` set