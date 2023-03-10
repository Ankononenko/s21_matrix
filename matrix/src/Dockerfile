FROM alpine:latest

RUN apk update && \
    apk add pkgconfig \
    valgrind \
    git \
    make \
    gcc \
    check-dev \
    dos2unix \
    gcovr \
    musl-dev \
    llvm-dev \
    bash \
    && apk add --no-cache --repository=http://dl-cdn.alpinelinux.org/alpine/edge/testing lcov

COPY . project/

WORKDIR /project/

RUN make gcov_report