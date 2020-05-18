pipeline {

    agent any

    environment {
        DOCKER_IMAGE_TAG  = "deitel:alpine"
        BRANCH_FOLDER     = "${BRANCH_NAME.split('/')[-1]}"
        SOURCE_DIR         = "\"/var/jenkins_home/workspace/${JOB_NAME}/${BRANCH_FOLDER}\""
    }

    stages {
        // stage('Build Docker Image') {
        //     steps {
        //         sh "make image"
        //     }
        // }
        stage('Build Source') {
            steps {
                sh "docker run --volumes-from=jenkins-server -w ${env.SOURCE_DIR} ${env.DOCKER_IMAGE_TAG} make release"
            }
        }
        stage('Run Tests') {
            steps {
                sh "docker run --volumes-from=jenkins-server -w ${env.SOURCE_DIR} ${env.DOCKER_IMAGE_TAG} make release gcov"
            }
            post {
                always {
                  step([$class: 'CoberturaPublisher', coberturaReportFile: '${BRANCH_FOLDER}/coverage.html'])
                }
            }
        }
    }
}