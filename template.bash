#!/bin/bash

cdir=${PWD##*/}
name=${cdir//-/_}.c

cat > $name <<- EOF
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int
main (int argc, char **argv)
{
  
}
EOF
