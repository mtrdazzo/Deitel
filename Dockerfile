FROM alpine

RUN apk upgrade
RUN apk add --no-cache bash

# Add build dependencies
RUN apk add g++
RUN apk add make
