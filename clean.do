# ----------------------------------------------------------------------
# clean.do
# ----------------------------------------------------------------------

. ./defs.sh

find . -mindepth 2 -maxdepth 2 -name clean.do | sed 's/\.do$//' | xargs redo
rm_tmp