# Add base alpine image
FROM alpine

# Upgrade packages
RUN apk upgrade

# Add build dependencies
RUN apk add g++
RUN apk add make
RUN apk add bash

# Add lcov for testing reports
RUN apk add lcov --repository=http://dl-cdn.alpinelinux.org/alpine/edge/testing
