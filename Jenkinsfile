pipeline {

    agent any

    environment {
        DOCKER_IMAGE_TAG = "deitel:alpine"
        BRANCH_FOLDER    = "${BRANCH_NAME.split('/')[-1]}"
        SOURCE_DIR       = "\"/var/jenkins_home/workspace/${JOB_NAME}/${BRANCH_FOLDER}\""
        COVERAGE_FILE    = "\${FILE, path=\"${BRANCH_FOLDER}/coverage.html\"}"
    }

    stages {
        stage('Build Docker Image') {
            steps {
                sh "make image"
            }
        }
        stage('Build Source') {
            steps {
                sh "docker run --volumes-from=jenkins-server -w ${env.SOURCE_DIR} ${env.DOCKER_IMAGE_TAG} make release"
            }
        }
        stage('Run Tests') {
            steps {
                sh "docker run --volumes-from=jenkins-server -w ${env.SOURCE_DIR} ${env.DOCKER_IMAGE_TAG} make release gcov-xml"
            }
            post {
                always {
                  step([$class: 'CoberturaPublisher', coberturaReportFile: "${BRANCH_FOLDER}/coverage.xml"])
                }
            }
        }
    }
    post {
        failure {
            emailext mimeType: 'text/html',
                body: '<!DOCTYPE html> \
                        <html> \
                        <body> \
                        <p style="width: 500px;"> \
                        <img alt="Jenkins Fire" src="https://www.jenkins.io/images/logos/fire/256.png" width="214" height="250" style="float: left;" /> \
                        <br> <br> &emsp; <strong> <font size="+3"> Build FAILURE! </font> </strong>\
                        <br> &emsp; ${BUILD_TIMESTAMP} <br> \
                        <br> &emsp; <a href="${BUILD_URL}/console"> Build Log </a> <br> \
                        <br> &emsp; Build: <a href="${BUILD_URL}"> ${BUILD_NUMBER} </a> <br> \
                        // <br> &emsp;   Job: <a href="${JOB_URL}"> ${JOB_NAME} </a> <br> \
                        <br> &emsp;   Job: <a href="${GIT_BRANCH}"> GitHub </a> <br> \
                        </body> \
                        </html> \
                        ',
                to: 'jenkinshudson@yahoo.com',
                recipientProviders: [[$class: 'RequesterRecipientProvider']],
                subject: "Jenkins Build ${currentBuild.currentResult}: ${env.JOB_NAME}:${env.BUILD_NUMBER}"
        }
        success {
            emailext mimeType: 'text/html',
                body: '<!DOCTYPE html> \
                        <html> \
                        <body> \
                        <p style="width: 500px;"> \
                        <img alt="Jenkins Logo" src="https://www.jenkins.io/images/logos/jenkins/256.png" width="180" height="250" style="float: left;" /> \
                        <br> <br> &emsp; <strong> <font size="+3"> Build SUCCESS! </font> </strong>\
                        <br> &emsp; ${BUILD_TIMESTAMP} <br> \
                        <br> &emsp; Build: <a href="${BUILD_URL}"> ${BUILD_NUMBER} </a> <br> \
                        <br> &emsp; <a href="${BUILD_URL}/console"> Build Log </a> <br> \
                        <br> &emsp; <a href="${BUILD_URL}/cobertura"> Code Coverage </a> <br> \
                        <br> &emsp; "${GIT_BRANCH}" <br> \
                        </body> \
                        </html> \
                        ',
                to: 'jenkinshudson@yahoo.com',
                recipientProviders: [[$class: 'RequesterRecipientProvider'], [$class: 'DevelopersRecipientProvider']],
                subject: "Jenkins Build ${currentBuild.currentResult}: ${env.JOB_NAME}:${env.BUILD_NUMBER}"
        }
    }
}