#!/bin/bash
make -C ./
cd test/
for f in *
do 
	echo "************************************TESTING*************************************"
	../fillit $f > ../results/$f.out
	TIMING=$(( { time ../fillit $f 1>&2; } 2>&1 ) | grep "real" | cut -f 2)
	printf "%-25s %-25s %20s" "TEST: $f" "EXECUTION TIME: ($TIMING)" "RESULT: "
	cd ../results
	if ! diff $f.out ../answers/$f.out > /dev/null 2>&1;
	then
		printf "FAILED\n\n"
		printf "DIFF\n"
		diff $f.out ../answers/$f.out
		printf "\nYOUR OUTPUT\n"
		cat $f.out
		printf "\nSOLUTION\n"
		cat ../answers/$f.out
		printf "\n"
	else
		printf "PASSED\n"
	fi
	cd ../test
done
cd ..
