#!/bin/sh
set -eu
TESTDIR=tests
./skandinav ${TESTDIR}/test.txt > ${TESTDIR}/result.txt
diff ${TESTDIR}/expected.txt ${TESTDIR}/result.txt
rm ${TESTDIR}/result.txt
echo Test passed
