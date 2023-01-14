#!/ bin / bash

full_path="/home/finchren/school21/DO6_CICD-0/src/C3_SimpleBashUtils-0/src"
scp -P 2023 $full_path/cat/s21_cat $full_path/grep/s21_grep finchren@192.168.100.11:/home/finchren/school21/cat_grep/
