# Report on installing and running the Gitlab Runner

## Installation of Gitlab Runner:
[_Official Gitlab installation doc can be found here_](https://docs.gitlab.com/runner/install/linux-repository.html).
1. Add the official GitLab repository: `$ curl -L "https://packages.gitlab.com/install/repositories/runner/gitlab-runner/script.deb.sh" | sudo bash`.
<img src="https://github.com/finchren/School21_main_education/blob/main/CICD/src/screenshots/01_added_gitlab_repo.png" alt="01_added_gitlab_repo.png" width="800"/>

2. Install the latest version of GitLab Runner: `$ sudo apt-get install gitlab-runner`.
<img src="https://github.com/finchren/School21_main_education/blob/main/CICD/src/screenshots/02_installed_gitlab_runner.png" alt="02_installed_gitlab_runner.png" width="800"/>

## Registering the runner for the current project:
[_Official Gitlab doc for registration of a runner can be found here_](https://docs.gitlab.com/runner/register/).
1. Run the register command: `$ sudo gitlab-runner register`.
2. Enter your GitLab instance URL: `$ https://repos.21-school.ru`.
3. Enter the token: _the token can be found in the task description of the project on the School 21 platform_.
4. Enter a description for the runner.
5. Enter the tags associated with the runner, separated by commas. 
6. Enter any optional maintenance note for the runner.
7. Provide the runner executor.
<img src="https://github.com/finchren/School21_main_education/blob/main/CICD/src/screenshots/03_runner_registered.png" alt="03_runner_registered.png" width="800"/>
