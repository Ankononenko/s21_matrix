# Report on completing the testing stage

[_.gitlab-ci.yml keyword reference_](https://docs.gitlab.com/ee/ci/yaml/index.html).\
[_Tutorial: Create and run your first GitLab CI/CD pipeline._](https://docs.gitlab.com/ee/ci/quick_start/)

_Contents of the .gitlab-ci.yml file to complete the three stages - build, style check and the testing stage:_\
<img src="https://github.com/finchren/School21_main_education/blob/main/CICD/src/screenshots/09_gitlab_ci_contents.png" alt="09_gitlab_ci_contents.png"/>

_Contents of check_test_results.sh:_
```
#!/ bin / bash

if [ -f "../cat/log.txt" ];
then
	if [ -z "$(cat ../cat/log.txt)" ];
	then
		echo "Tests for cat utility have passed successfully"
	else
		echo "Tests for cat utility have failed"
		echo "List of failed tests:"
		cat ../cat/log.txt
		exit 1
	fi
else
	echo "Log file for cat tests doesn't exist"
	echo "Run the tests first - make test_cat"
	exit 1
fi


if [ -f "../grep/log.txt" ];
then
	if [ -z "$(cat ../grep/log.txt)" ];
	then
		echo "Tests for grep utility have passed successfully"
	else
		echo "Tests for grep utility have failed"
		echo "List of failed tests:"
		cat ../grep/log.txt
		exit 1
	fi
else
	echo "Log file for grep tests doesn't exist"
	echo "Run the tests first - make test_grep"
	exit 1
fi
```

_Testing stage passed:_\
<img src="https://github.com/finchren/School21_main_education/blob/main/CICD/src/screenshots/10_test_stage_passed.png" alt="10_test_stage_passed.png"/>

_Pipeline passed:_\
<img src="https://github.com/finchren/School21_main_education/blob/main/CICD/src/screenshots/11_pipeline_passed.png" alt="11_pipeline_passed.png"/>
