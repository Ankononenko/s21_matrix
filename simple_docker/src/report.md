# Simple Docker report
1. [Ready-made docker](#part-1-ready-made-docker)
2. [Operations with container](#part-2-operations-with-the-container)
3. [Mini web server](#part-3-mini-web-server)
4. [Your own docker](#part-4-your-own-docker)
5. [Dockle](#part-5-dockle)
6. [Basic Docker Compose](#part-6-basic-docker-compose)

## Part 1. Ready-made Docker

1. Download the official docker image from nginx using `$ docker pull`:
<img src="screenshots/01_Docker_nginx_pull.png" alt="01_Docker_nginx_pull.png" width="800"/>

2. Check for the docker image with `$ docker images`:\
`REPOSITORY   TAG       IMAGE ID       CREATED      SIZE`\
`nginx        latest    3964ce7b8458   6 days ago   142MB`

3. Run docker image `$ docker run -d 3964ce7b8458`:\
`c6a176f8dfb6ebd3d011bf22fdd9f53c00e6531461d18d5c75ff62e1b89e1c18`

4. Check that the image is running: `$ docker ps`:
<img src="screenshots/02_Image_is_running.png" alt="02_Image_is_running.png" width="800"/>

5. View container information `$ docker inspect c6a176f8dfb6`
<img src="screenshots/03_Docker_inspect.png" alt="03_Docker_inspect.png" width="800"/>

Container size: `"SizeRootFs": 141843741`\
List of mapped ports: `"Ports": {"80/tcp": null}`\
Container IP: `"IPAddress": "172.17.0.2"`

6. Stop docker image `$ docker stop`: \
`c6a176f8dfb6`

7. Check that the image has stopped `$ docker ps`:
<img src="screenshots/04_Docker_stop.png" alt="04_Docker_stop.png" width="800"/>

8. Run docker with mapped ports 80 and 443 on the local machine with run command: `$ docker run -d -p 80:80 -p 443:443 3964ce7b8458`:
<img src="screenshots/05_Docker_map_ports.png" alt="05_Docker_map_ports.png" width="800"/>

9. Check that the nginx start page is available in the browser at localhost:80:
<img src="screenshots/06_nginx_available_at_localhost.png" alt="06_nginx_available_at_localhost.png" width="800"/>

10. Restart docker container `$ docker restart c6a176f8dfb6` and check that the container is running:
<img src="screenshots/07_Restart_and_check_that_container_is_running.png" alt="07_Restart_and_check_that_container_is_running.png" width="800"/>

## Part 2. Operations with the container

1. Read the nginx.conf configuration file inside the docker container with the exec command `$ docker exec -it <container-id> bash`, `$ cat /etc/nginx/nginx.conf`:
<img src="screenshots/08_cat_nginx_config.png" alt="08_cat_nginx_config.png" width="800"/>

2. Create a nginx.conf file on a local machine: \
`$ touch nginx.conf`
<img src="screenshots/09_copied_nginx_conf_to_local_machine.png" alt="09_copied_nginx_conf_to_local_machine.png" width="800"/>

3. Configure it on the /status path to return the nginx server status page:\
_The ngx_http_stub_status_module module provides access to basic status information_
<img src="screenshots/10_configure_nginx.png" alt="10_configure_nginx.png" width="800"/>

_Line 30 is commented because nginx takes other files of configurations which don't let location '/status' work properly._

4. Copy the created nginx.conf file inside the docker image using the docker cp command `$ docker cp nginx.conf c6e561c366ea:etc/nginx/`:\
_Copied configuration file:_
<img src="screenshots/11_copied_the_file_on_the_container.png" alt="11_copied_the_file_on_the_container.png" width="800"/>

5. Restarted nginx inside the docker image:
<img src="screenshots/12_restarted_nginx_with_new_config.png" alt="12_restarted_nginx_with_new_config.png" width="800"/>

6. Check that localhost:80/status returns the nginx server status page:
<img src="screenshots/13_server_status_page.png" alt="13_server_status_page.png"/>

7. Exported the container to a container.tar file with the export command `$ docker export -o container.tar 3ca2d50b57d5`:
<img src="screenshots/12_exported_the_container.png" alt="12_exported_the_container.png" width="800"/>

8. Stoped the container `$ docker stop 3ca2d50b57d5`:
<img src="screenshots/14_stopped_the_container.png" alt="14_stopped_the_container.png"/>

9. Deleted the image with docker rmi [image_id|repository]without removing the container first:
<img src="screenshots/15_deleted_the_nginx_image.png" alt="15_deleted_the_nginx_image.png"/>

10. Deleted the stopped container:
<img src="screenshots/16_deleted_the_stopped_container.png" alt="16_deleted_the_stopped_container.png"/>

11. Imported the container back using the import command `$ docker import --change "CMD /docker-entrypoint.sh nginx -g 'daemon off;'" container.tar nginx2:latest2`:
<img src="screenshots/17_imported_the_container.png" alt="17_imported_the_container.png"/>

12. Run the imported container `$ docker run -d -p 80:80 fd3a40bba97a`:
<img src="screenshots/18_run_the_imported_container.png" alt="18_run_the_imported_container.png"/>

13. Localhost:80/status returns the nginx server status page:
<img src="screenshots/19_localhost_return_the_status_page.png" alt="19_localhost_return_the_status_page.png"/>

14. The contents of the created nginx.conf file:
<img src="screenshots/20_contents_of_nginx_config_fiile.png" alt="20_contents_of_nginx_config_fiile.png"/>

## Part 3. Mini web server:

1. Write a mini server in C and FastCgi that will return a simple page saying Hello World!:
<img src="screenshots/21_miniserver_in_c.png" alt="21_miniserver_in_c.png"/>

2. Run the written mini server via spawn-fcgi on port 8080: \
`$ apt install gcc` \
`$ apt install libfcgi-dev` \
`$ apt install spawn-fcgi` \
`$ gcc -c miniserver.c -o miniserver.o` \
`$ gcc -c miniserver.c -lfcgi -o miniserver.out` \
`$ spawn-fcgi -a 127.0.0.1 -p 8080 ./miniserver.out`
<img src="screenshots/22_spawned_successfully.png" alt="22_spawned_successfully.png"/>

3. Write your own nginx.conf that will proxy all requests from port 81 to 127.0.0.1:8080:

<img src="screenshots/23_cat_nginx_conf.png" alt="23_cat_nginx_conf.png"/>
<img src="screenshots/24_nginx_reload.png" alt="24_nginx_reload.png"/>

4. Check that browser on localhost:81 returns the page you wrote:
<img src="screenshots/25_localhost_81_output.png" alt="25_localhost_81_output.png"/>

## Part 4. Your own docker:

1. Write your own docker image that builds mini server sources on FastCgi from Part 3, runs it on port 8080, copies inside the image written ./nginx/nginx.conf, runs nginx.

Dockerfile: \
<img src="screenshots/26_dockerfile.png" alt="26_dockerfile.png"/>

Run_server.sh: \
<img src="screenshots/27_run_server_sh.png" alt="27_run_server_sh.png"/>

nginx.conf: \
<img src="screenshots/28_cat_nginx_conf.png" alt="28_cat_nginx_conf.png"/>

Docker build finished: \
<img src="screenshots/29_docker_build_finished.png" alt="29_docker_build_finished.png"/>

Image created: \
<img src="screenshots/30_image_created.png" alt="30_image_created.png"/>

Run the image: \
`$ docker run -d -p 80:81 -v "/d/Code/Docker/DO5_SimpleDocker-0/src/Part 04/nginx/:/etc/nginx/" --name real_part_04 my_server_part4:my_tag ` \
<img src="screenshots/31_docker_run.png" alt="31_docker_run.png"/>

The page of the written mini server is available on localhost:80: \
<img src="screenshots/32_localhost_80.png" alt="32_localhost_80.png"/>

Add proxying of /status page in ./nginx/nginx.conf to return the nginx server status: \
<img src="screenshots/33_server_status.png" alt="33_server_status.png"/>

After the restart: \
<img src="screenshots/34_after_restart.png" alt="34_after_restart.png"/>

## Part 5. Dockle:
