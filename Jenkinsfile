pipeline {

    agent any

    environment {
        DOCKER_IMAGE_TAG  = "deitel:alpine"
        // GIT_PULL_RETRY_CNT = 3
        BRANCH_FOLDER     = ${env.BRANCH_NAME}.split('/')[-1]
        SOURCE_DIR         = "\"/var/jenkins_home/workspace/${JOB_NAME}/${BRANCH_FOLDER}\""
        // GIT_URL            = 'https://github.com/mtrdazzo/Deitel'
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
            // post {
            //     always {
            //       step([$class: 'CoberturaPublisher', coberturaReportFile: '${env.BRANCH_NAME}.split('/')[-1]/coverage.xml'])
            //     }
            // }
        }
    }
}