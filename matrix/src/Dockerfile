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
    llvm-dev

COPY . project/

WORKDIR /project/

RUN make
