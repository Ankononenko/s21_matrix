FROM debian

RUN apt-get update && apt-get install -y nginx \
    && rm -rf /var/lib/apt/lists

COPY ./nginx/nginx.conf etc/nginx/nginx.conf

WORKDIR /school21/src/

RUN groupadd -g 999 appuser && \
    useradd -r -u 999 -g appuser appuser
USER appuser

ENTRYPOINT ["nginx", "-g", "daemon off;"]
