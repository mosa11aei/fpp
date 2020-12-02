#!/bin/sh -e

# ----------------------------------------------------------------------
# Compile ref XML files, to check them for validity
# ----------------------------------------------------------------------

pwd=$PWD

fprime_codegen=$COMPILER/scripts/fprime-codegen
fprime_gcc=$COMPILER/scripts/fprime-gcc

files=`find . -name '*Ai.ref.xml'`

for file in $files
do
  dir=`dirname $file`
  base=`basename $file Ai.ref.xml`
  xml_file=$base'Ai.xml'
  cp $file $dir/$xml_file
  cd $dir
  echo "compiling $xml_file"
  $fprime_codegen $xml_file > /dev/null
  cd $pwd
done

for file in $files
do
  dir=`dirname $file`
  base=`basename $file Ai.ref.xml`
  cd $dir
  cpp_file=$base'Ac.cpp'
  echo "compiling $cpp_file"
  $fprime_gcc -c $cpp_file
  cd $pwd
done