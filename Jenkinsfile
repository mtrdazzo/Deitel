pipeline {

    agent any

    // environment {
        // DOCKER_IMAGE_TAG  = "deitel:alpine"
        // GIT_PULL_RETRY_CNT = 3
        // SOURCE_DIR         = "\"/var/jenkins_home/workspace/${JOB_NAME}/Chapter_9\""
        // GIT_URL            = 'https://github.com/mtrdazzo/Deitel'
    // }

    stages {
        stage('Build Docker Image') {
            steps {
        //         sh "make image"
                echo "making docker image"
            }
        }
        stage('Build Source') {
            steps {
                // sh "docker run --volumes-from=jenkins-server -w ${env.SOURCE_DIR} ${env.DOCKER_IMAGE_TAG} make release"
                echo "building source..."
            }
        }
        stage('Run Tests') {
            steps {
                // sh "docker run --volumes-from=jenkins-server -w ${env.SOURCE_DIR} ${env.DOCKER_IMAGE_TAG} make release gcov"
                echo "running tests"
            }
            // post {
            //     always {
            //       step([$class: 'CoberturaPublisher', coberturaReportFile: 'Chapter_9/coverage.xml'])
            //     }
            // }
        }
    }
}