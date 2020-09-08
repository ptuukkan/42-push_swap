#!/bin/sh

test()
{
	i=0
	FAILED=0
	TOTAL=0
	while [ $i -lt 100 ]
	do
		ARG=$(./nbgen.pl $1 2000)
		RES=$(./push_swap $ARG | ./checker $ARG)
		if [ "$RES" = "OK" ]
		then
			MOVES=$(./push_swap $ARG | wc | awk '{ print $1 }')
			if [ $i -eq 0 ]
			then
				BEST=$MOVES
				WORST=$MOVES
			else
				if [ $MOVES -lt $BEST ]
				then
					BEST=$MOVES
				fi
				if [ $MOVES -gt $WORST ]
				then
					WORST=$MOVES
				fi
			fi
			TOTAL=$(( $TOTAL + $MOVES ))
		else
			FAILED=$(( $FAILED + 1))
		fi
		i=$(( $i + 1 ))
	done
	TESTS=$(( 100 - $FAILED))
	AVG=$(( $TOTAL / $TESTS ))
	printf "%3d: %d of %d OK, average: %4d best: %4d worst: %4d\n" "$1" "$TESTS" "100" "$AVG" "$BEST" "$WORST"
}

test "1"
test "2"
test "3"
test "4"
test "5"
test "6"
test "7"
test "8"
test "9"
test "10"
test "11"
test "12"
test "13"
test "14"
test "15"
test "20"
test "50"
test "100"
test "500"
