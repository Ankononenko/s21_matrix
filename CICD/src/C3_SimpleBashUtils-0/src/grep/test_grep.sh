COUNTER_SUCCESS=0
COUNTER_FAIL=0
DIFF_RES=""
PATTERN1="Hello"
PATTERN2="World"
FILENAME2="../../texts/2.txt"
FILENAME4="../../texts/4.txt"
FILENAME5="../../texts/5.txt"
EFLAG="-e"
FFLAG="-f"
PATTERNFILE="../../texts/patterns.txt"

cat /dev/null > log.txt

for var in v c l n i o
do
                TEST2="$EFLAG $PATTERN1 -$var $FILENAME2"
                echo "$TEST2"
                ./s21_grep $TEST2 > s21_grep.txt
                grep $TEST2 > grep.txt
                DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
                if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
                  then
                    (( COUNTER_SUCCESS++ ))
                  else
                    echo "$TEST2" >> log.txt
                    (( COUNTER_FAIL++ ))
                fi
                rm s21_grep.txt grep.txt

                TEST4="$EFLAG $PATTERN1 -$var $FILENAME4"
                echo "$TEST4"
                ./s21_grep $TEST4 > s21_grep.txt
                grep $TEST4 > grep.txt
                DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
                if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
                  then
                    (( COUNTER_SUCCESS++ ))
                  else
                    echo "$TEST4" >> log.txt
                    (( COUNTER_FAIL++ ))
                fi
                rm s21_grep.txt grep.txt

                TEST5="$EFLAG $PATTERN1 -$var $FILENAME5"
                echo "$TEST5"
                ./s21_grep $TEST5 > s21_grep.txt
                grep $TEST5 > grep.txt
                DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
                if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
                  then
                    (( COUNTER_SUCCESS++ ))
                  else
                    echo "$TEST5" >> log.txt
                    (( COUNTER_FAIL++ ))
                fi
                rm s21_grep.txt grep.txt

            done    
echo "SUCCESS: $COUNTER_SUCCESS"
echo "FAIL: $COUNTER_FAIL"
