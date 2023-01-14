# Report on completing the deployment stage

[_Job artifacts Gitlab doc._](https://docs.gitlab.com/ee/ci/pipelines/job_artifacts.html)\
[_How to Run SCP Without Password Prompt Interruption in Linux._](https://www.thegeekdiary.com/how-to-run-scp-without-password-prompt-interruption-in-linux/)

For the gitlab-runner user to be able to copy the file over scp without a password you need to do the following:

1. Log in as the gitlab-runner user;
2. Generate ssh key pair on the host (ws1);
3. Copy the public key on the deployment server (ws2);
4. Connect via ssh to the deployment server;
5. Create a .ssh directory if it doesn't exist already;
6. Copy the the public key to the created directory and name it "authorized_keys".

_Contents of copy_files_to_ws2.sh:_
```
#!/ bin / bash

full_path="/home/finchren/school21/DO6_CICD-0/src/C3_SimpleBashUtils-0/src"
scp -P 2023 $full_path/cat/s21_cat $full_path/grep/s21_grep finchren@192.168.100.11:/home/finchren/school21/cat_grep/
```

_Contents of the .gitlab-ci.yml file to complete the all of the stages:_
```
stages:
  - build
  - style-check
  - test
  - deploy

build:
  stage: build
  tags:
    - ws1_cicd
  script:
    - cd src/C3_SimpleBashUtils-0/src/cat/
    - make
    - cd ..
    - cd grep/
    - make
  artifacts:
    paths:
    - src/C3_SimpleBashUtils-0/src/cat/s21_cat
    - src/C3_SimpleBashUtils-0/src/grep/s21_grep
    expire_in: 30 days

style-check:
  stage: style-check
  tags:
    - ws1_cicd
  script:
    - cd src/C3_SimpleBashUtils-0/src/
    - clang-format -n cat/s21_cat.c &>> clang_output.txt
    - clang-format -n cat/s21_cat.h &>> clang_output.txt
    - clang-format -n cat/test_cat.sh &>> clang_output.txt
    - clang-format -n grep/s21_grep.c &>> clang_output.txt
    - clang-format -n grep/s21_grep.h &>> clang_output.txt
    - clang-format -n grep/test_grep.sh &>> clang_output.txt
    - clang-format -n grep/old_test_grep.sh &>> clang_output.txt
    # Line below is used for testing to fail the stage
    #- clang-format -n grep/Makefile &>> clang_output.txt
    - bash pipeline_scripts/check_clang_output.sh
    - cat clang_output.txt
  allow_failure: false

test:
  stage: test
  tags:
    - ws1_cicd
  script:
    - cd src/C3_SimpleBashUtils-0/src/cat/
    - make test_cat
    - cd ..
    - cd grep/
    - make test_grep
    - bash ../pipeline_scripts/check_test_results.sh
  allow_failure: false

deploy:
  stage: deploy
  when: manual
  tags:
    - ws1_cicd
  script:
    - bash src/C3_SimpleBashUtils-0/src/pipeline_scripts/copy_files_to_ws2.sh
  allow_failure: false
```

_Deployment stage passed:_\
<img src="https://github.com/finchren/School21_main_education/blob/main/CICD/src/screenshots/13_pipeline_passed.png" alt="13_pipeline_passed.png"/>

_Pipeline passed:_\
<img src="https://github.com/finchren/School21_main_education/blob/main/CICD/src/screenshots/12_deployment_stage_passed.png" alt="12_deployment_stage_passed.png"/>
