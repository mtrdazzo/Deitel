# Add base alpine image
FROM alpine

# Upgrade packages
RUN apk upgrade

# Add build dependencies
RUN apk add g++
RUN apk add make

# Add gcovr for testing reports
RUN apk add gcovr

# All future commands should run as the user
USER appuser