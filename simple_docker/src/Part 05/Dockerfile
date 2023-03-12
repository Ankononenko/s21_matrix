FROM debian

RUN apt-get update && apt-get install -y \
    nginx \
    gcc \
    libfcgi-dev \
    spawn-fcgi \
    && rm -rf /var/lib/apt/lists

COPY ./miniserver.c ./school21/src/miniserver.c 
COPY ./nginx/nginx.conf etc/nginx/nginx.conf
COPY ./run_server.sh ./school21/src/run_server.sh

WORKDIR /school21/src/

RUN gcc -c miniserver.c -o miniserver.o \
    && gcc miniserver.o -lfcgi -o miniserver.out \
    && chmod +x run_server.sh

RUN groupadd -g 999 appuser && \
    useradd -r -u 999 -g appuser appuser
USER appuser

ENTRYPOINT ["/school21/src/run_server.sh"]
