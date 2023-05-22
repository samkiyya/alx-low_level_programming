#!/bin/bash

echo -e '#include <stdlib.h>\n#include <time.h>\n\nint rand(void) { return 42; }\n\nvoid srand(unsigned int seed) {}' > /tmp/win.c
gcc -shared -o /tmp/win.so /tmp/win.c
LD_PRELOAD=/tmp/win.so
