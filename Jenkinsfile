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
                sh "docker run --volumes-from=jenkins-server -w ${env.SOURCE_DIR} ${env.DOCKER_IMAGE_TAG} make release gcov-xml && make release gcov"
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
            emailext body: " Job: ${env.JOB_NAME}\n Result: ${currentBuild.currentResult}\n Build #:${env.BUILD_NUMBER}\n More info at: ${env.BUILD_URL}",
                recipientProviders: [[$class: 'DevelopersRecipientProvider'], [$class: 'RequesterRecipientProvider']],
                subject: "Jenkins Build ${currentBuild.currentResult}: ${env.JOB_NAME}",
                attachLog: true
        }
        success {
            emailext mimeType: 'text/html',
                body: "${env.COVERAGE_FILE}",
                recipientProviders: [[$class: 'DevelopersRecipientProvider'], [$class: 'RequesterRecipientProvider']],
                subject: "Jenkins Build ${currentBuild.currentResult}: ${env.JOB_NAME}"
        }
    }
}