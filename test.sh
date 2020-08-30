#!/bin/sh

test()
{
	i=0
	FAILED=0
	TOTAL=0
	while [ $i -lt 1000 ]
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
}

test "1"
TESTS=$(( 1000 - $FAILED))
AVG=$(( $TOTAL / $TESTS ))
printf "1: %d of %d OK, average: %d best: %d worst: %d\n" "$TESTS" "1000" "$AVG" "$BEST" "$WORST"

test "2"
TESTS=$(( 1000 - $FAILED))
AVG=$(( $TOTAL / $TESTS ))
printf "2: %d of %d OK, average: %d best: %d worst: %d\n" "$TESTS" "1000" "$AVG" "$BEST" "$WORST"

test "3"
TESTS=$(( 1000 - $FAILED))
AVG=$(( $TOTAL / $TESTS ))
printf "3: %d of %d OK, average: %d best: %d worst: %d\n" "$TESTS" "1000" "$AVG" "$BEST" "$WORST"

test "4"
TESTS=$(( 1000 - $FAILED))
AVG=$(( $TOTAL / $TESTS ))
printf "4: %d of %d OK, average: %d best: %d worst: %d\n" "$TESTS" "1000" "$AVG" "$BEST" "$WORST"

test "5"
TESTS=$(( 1000 - $FAILED))
AVG=$(( $TOTAL / $TESTS ))
printf "5: %d of %d OK, average: %d best: %d worst: %d\n" "$TESTS" "1000" "$AVG" "$BEST" "$WORST"

test "6"
TESTS=$(( 1000 - $FAILED))
AVG=$(( $TOTAL / $TESTS ))
printf "6: %d of %d OK, average: %d best: %d worst: %d\n" "$TESTS" "1000" "$AVG" "$BEST" "$WORST"

test "10"
TESTS=$(( 1000 - $FAILED))
AVG=$(( $TOTAL / $TESTS ))
printf "10: %d of %d OK, average: %d best: %d worst: %d\n" "$TESTS" "1000" "$AVG" "$BEST" "$WORST"

test "20"
TESTS=$(( 1000 - $FAILED))
AVG=$(( $TOTAL / $TESTS ))
printf "20: %d of %d OK, average: %d best: %d worst: %d\n" "$TESTS" "1000" "$AVG" "$BEST" "$WORST"

test "50"
TESTS=$(( 1000 - $FAILED))
AVG=$(( $TOTAL / $TESTS ))
printf "50: %d of %d OK, average: %d best: %d worst: %d\n" "$TESTS" "1000" "$AVG" "$BEST" "$WORST"

test "100"
TESTS=$(( 1000 - $FAILED))
AVG=$(( $TOTAL / $TESTS ))
printf "100: %d of %d OK, average: %d best: %d worst: %d\n" "$TESTS" "1000" "$AVG" "$BEST" "$WORST"

test "500"
TESTS=$(( 1000 - $FAILED))
AVG=$(( $TOTAL / $TESTS ))
printf "500: %d of %d OK, average: %d best: %d worst: %d\n" "$TESTS" "1000" "$AVG" "$BEST" "$WORST"



