FROM jenkins/jenkins

# Prep Jenkins Directories
USER root

# Set permissions for /var to jenkins user
RUN mkdir /var/log/jenkins
RUN mkdir /var/cache/jenkins
RUN chown -R jenkins:jenkins /var/log/jenkins
RUN chown -R jenkins:jenkins /var/cache/jenkins

# Update packages
RUN apt --yes --force-yes update
RUN apt --yes --force-yes upgrade

# Install docker dependencies
RUN apt-get --yes --force-yes install apt-transport-https ca-certificates curl gnupg2 software-properties-common

# Add Docker's GPG key
RUN curl -fsSL https://download.docker.com/linux/debian/gpg | apt-key add -

# Add the Docker repository
RUN add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/debian $(lsb_release -cs) stable"

# Update and install docker
RUN apt-get --yes --force-yes update
RUN apt-get --yes --force-yes install docker-ce

# Add jenkins to docker and root user groups to use docker daemon
RUN usermod -aG docker jenkins
RUN usermod -aG root jenkins

# Run as jenkins user
USER jenkins

# Set Defaults
ENV JAVA_OPTS="-Xmx8192m"
ENV JENKINS_OPTS="--handlerCountMax=300 --logfile=/var/log/jenkins/jenkins.log  --webroot=/var/cache/jenkins/war"
