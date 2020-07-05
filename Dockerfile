# Add base alpine image
FROM alpine

USER root

ARG username=deitel-user
ARG group=devs
ARG uid
ARG gid

# Upgrade packages
RUN apk upgrade && apk update
RUN apk add make \
    gcovr \
    g++ \
    git

# Create user and group
RUN addgroup -S -g ${gid} ${group}
RUN adduser -S -u ${uid} -g ${group} -D ${username}

# All future commands should run as the user
USER ${username}
