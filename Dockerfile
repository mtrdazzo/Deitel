# Add base alpine image
FROM alpine

USER root

ARG username=deitel-user

# Upgrade packages
RUN apk upgrade

# Add build dependencies
RUN apk add g++
RUN apk add make

# Add gcovr for testing reports
RUN apk add gcovr

RUN adduser -D -u 1000 $username 

RUN mkdir -p /opt/source
RUN chown -R $username:$username /opt/source/

# All future commands should run as the user
USER $username
WORKDIR /opt/source