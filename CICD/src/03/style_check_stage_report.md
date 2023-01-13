# Report on completing the style check stage

[_.gitlab-ci.yml keyword reference_](https://docs.gitlab.com/ee/ci/yaml/index.html).\
[_Google Style_](https://google.github.io/styleguide/cppguide.html).

_Contents of the .gitlab-ci.yml file to complete the style check stage:_\
<img src="https://github.com/finchren/School21_main_education/blob/main/CICD/src/screenshots/06_style_check_stage_ci_file.png" alt="06_style_check_stage_ci_file.png"/>

If the style check didn't pass the pipeline fails. For this I use the ["allow_failure: false" parameter.](https://docs.gitlab.com/ee/ci/yaml/index.html#allow_failure)\
I display the output of the clang-format utility by saving the output to a text file. At the end of the script I cat the contents of the file to see the possible output.

_Code style stage passed:_\
<img src="https://github.com/finchren/School21_main_education/blob/main/CICD/src/screenshots/07_style_check_passed..png" alt="07_style_check_passed..png"/>

_Pipeline passed:_\
<img src="https://github.com/finchren/School21_main_education/blob/main/CICD/src/screenshots/08_pipiline_passed.png" alt="08_pipiline_passed.png"/>
