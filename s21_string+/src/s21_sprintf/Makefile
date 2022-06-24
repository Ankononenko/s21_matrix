CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11 -c $(shell pkg-config --cflags check) -g -fsanitize=address
# CFLAGS=-Wall -Werror -Wextra -std=c11 -c -g
CFLAGS_GCOV=-fprofile-arcs -ftest-coverage
LIBS=-lcheck -lgcov $(shell pkg-config --libs check) -g -fsanitize=address
# LIBS=-lcheck -lgcov -g

SOURCE_DIRECTORIES=../s21_strlen ../s21_memcpy ../s21_common/s21_memcpy_forward_backward ../s21_memset ../s21_memmove
OBJECT_DIRECTORIES_TO_CLEAN=$(subst ../,,$(filter ../%, $(SOURCE_DIRECTORIES)))

BUILD_DIRECTORY=build
DEPENDENCY_DIRECTORY=$(BUILD_DIRECTORY)/dependencies



# TEST_FILE=$(wildcard *.check)
# TEST_FILE_GENERATED=$(patsubst %.check,%.c,$(TEST_FILE))

ALL_TESTS_IN_ONE_FILE=s21_sprintf_test.check
ALL_TESTS_IN_ONE_FILE_GENERATED=s21_sprintf_test.c
TEST_FILE_GENERATED=$(ALL_TESTS_IN_ONE_FILE_GENERATED)

OBJECT_TEST_FILE_GENERATED=$(BUILD_DIRECTORY)/$(notdir $(patsubst %.c,%.o,$(TEST_FILE_GENERATED)))
TARGET_TEST=$(BUILD_DIRECTORY)/$(notdir $(patsubst %.o,%.out,$(OBJECT_TEST_FILE_GENERATED)))

TEST_DIRECTORIES=.
TEST_FILES=$(foreach directory_as_variable, $(TEST_DIRECTORIES),$(wildcard $(directory_as_variable)/*.check))

SOURCE_FILES_ALL=$(wildcard *.c)
SOURCE_FILES_ALL+=$(foreach directory_as_variable, $(SOURCE_DIRECTORIES),$(wildcard $(directory_as_variable)/*.c))
SOURCE_FILES=$(filter-out %_test.c, $(SOURCE_FILES_ALL))

OBJECT_FILES_IN_SOURCE_DIRECTORIES=$(patsubst %.c,%.o,$(SOURCE_FILES))
OBJECT_FILES_IN_BUILD_DIRECTORIES=$(addprefix $(BUILD_DIRECTORY)/,$(OBJECT_FILES_IN_SOURCE_DIRECTORIES))

DEPENDENCY_FILES_ALL_IN_SOURCE_DIRECTORIES=$(patsubst %.c,%.d,$(SOURCE_FILES))
DEPENDENCY_FILES_ALL_IN_DEPENDENCY_DIRECTORIES=$(addprefix $(DEPENDENCY_DIRECTORY)/,$(DEPENDENCY_FILES_ALL_IN_SOURCE_DIRECTORIES))

DEPENDENCY_FILE_TEST_FILE_GENERATED_IN_DEPENDENCY_DIRECTORY=$(DEPENDENCY_DIRECTORY)/$(subst .c,.d,$(notdir $(TEST_FILE_GENERATED)))
DEPENDENCY_FILES_ALL_IN_DEPENDENCY_DIRECTORIES+=$(DEPENDENCY_FILE_TEST_FILE_GENERATED_IN_DEPENDENCY_DIRECTORY)
DEPENDENCY_DIRECTORIES=$(dir $(DEPENDENCY_FILES_ALL_IN_DEPENDENCY_DIRECTORIES))

DEPFLAGS=-MT $@ -MMD -MP -MF $(DEPENDENCY_DIRECTORY)/$*.d


run_test: test
		-$(TARGET_TEST)


test: $(TARGET_TEST)


rerun_test: clean run_test


gcov_report: run_test
		$(foreach directory,$(SOURCE_DIRECTORIES),gcovr $(subst ../,,$(directory)) -r $(directory) --html-details -o coverage_report.html ;)
		gcovr -r . --html --html-details -o coverage_report.html

leaks: run_test
		leaks -atExit -- $(TARGET_TEST)

leaks_short: run_test
		leaks -atExit -- $(TARGET_TEST) | grep LEAK

valgrind: test
		valgrind --trace-children=yes --leak-check=full --show-leak-kinds=all --track-origins=yes $(TARGET_TEST)

insert_line_to_make_leaks_work_fast:
		sed -i.bak -r 's/srunner_run_all\(sr, CK_ENV\);/srunner_set_fork_status\(sr, CK_NOFORK\); srunner_run_all\(sr, CK_ENV\);/g' $(TEST_FILE_GENERATED)


$(ALL_TESTS_IN_ONE_FILE): $(TEST_FILES)
		mkdir -p $(dir $@)
		rm -f $(ALL_TESTS_IN_ONE_FILE)
		touch $(ALL_TESTS_IN_ONE_FILE)
		cat $^ >> $@
		echo "\n" >> $@



# $(TEST_FILE_GENERATED): $(TEST_FILE)
# checkmk $< > $@

$(TEST_FILE_GENERATED): $(ALL_TESTS_IN_ONE_FILE)
		checkmk $< > $@

unite_tests: $(ALL_TESTS_IN_ONE_FILE)


$(TARGET_TEST): $(OBJECT_FILES_IN_BUILD_DIRECTORIES) $(OBJECT_TEST_FILE_GENERATED)
		$(CC) -o $@ $^ $(LIBS) -g


$(OBJECT_TEST_FILE_GENERATED): $(TEST_FILE_GENERATED) insert_line_to_make_leaks_work_fast $(DEPENDENCY_FILE_TEST_FILE_GENERATED_IN_DEPENDENCY_DIRECTORY) | $(DEPENDENCY_DIRECTORY)
		mkdir -p $(dir $@)
		mkdir -p $(DEPENDENCY_DIRECTORY)/$(dir $*)
		$(CC) $(CFLAGS) $< -o $@ $(DEPFLAGS) -g


$(OBJECT_FILES_IN_BUILD_DIRECTORIES): $(BUILD_DIRECTORY)/%.o: %.c $(DEPENDENCY_DIRECTORY)/%.d | $(DEPENDENCY_DIRECTORY)
		mkdir -p $(dir $@)
		mkdir -p $(DEPENDENCY_DIRECTORY)/$(dir $*)
		$(CC) $(CFLAGS) $(CFLAGS_GCOV) $< -o $@ $(DEPFLAGS) -g


$(DEPENDENCY_DIRECTORY):
		mkdir -p $(DEPENDENCY_DIRECTORY)


$(DEPENDENCY_FILES_ALL_IN_DEPENDENCY_DIRECTORIES):


clean: 
		rm -rf $(BUILD_DIRECTORY) $(DEPENDENCY_DIRECTORY) $(OBJECT_DIRECTORIES_TO_CLEAN) $(TEST_FILE_GENERATED) *.gcov *.html *.css *.bak


print:
		#echo $(TEST_FILES)
		

include $(wildcard $(DEPENDENCY_FILES_ALL_IN_DEPENDENCY_DIRECTORIES))	