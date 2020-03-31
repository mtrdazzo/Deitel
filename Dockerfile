
# Start from base image with make and g++
FROM centos:build_env

# upgrade dependencies if necessary
# RUN yum -y upgrade

# Copy all contents to /src directory
COPY Chapter_2 /src/Chapter_2
COPY Chapter_9 /src/Chapter_9

