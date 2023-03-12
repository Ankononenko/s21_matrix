FROM nginx

USER root

RUN apt-get update && apt-get install -y \
    gcc \
    libfcgi-dev \
    spawn-fcgi

COPY ./miniserver.c ./school21/src/miniserver.c 
COPY ./nginx/nginx.conf etc/nginx/nginx.conf
COPY ./run_server.sh ./school21/src/run_server.sh

WORKDIR /school21/src/

RUN gcc -c miniserver.c -o miniserver.o \
    && gcc miniserver.o -lfcgi -o miniserver.out \
    && chmod +x run_server.sh

CMD ["/school21/src/run_server.sh"]
