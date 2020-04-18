pipeline {

    agent any

    environment {
        DOCKER_IMAGE_TAG  = "deitel:alpine"
        GIT_PULL_RETRY_CNT = 3
        SOURCE_DIR         = "\"/var/jenkins_home/workspace/${JOB_NAME}/Chapter_9\""
        GIT_URL            = 'https://github.com/mtrdazzo/Deitel'
    }
    
    stages {
        stage('SCM Checkout') {
            steps {
                retry("${env.GIT_PULL_RETRY_CNT}") {
                checkout([$class: 'GitSCM',
                        branches: [[name: '*/feature/Chapter_9']],
                        doGenerateSubmoduleConfigurations: false,
                        extensions: [[$class: 'SubmoduleOption',
                                        disableSubmodules: false,
                                        parentCredentials: false,
                                        recursiveSubmodules: true,
                                        reference: '',
                                        trackingSubmodules: false]],
                        submoduleCfg: [],
                        userRemoteConfigs: [[url: "${env.GIT_URL}"]]])
                }
            }
        }
        stage('Build Docker Image') {
            steps {
                dir("Chapter_9") {
                    sh "make image"
                }
            }
        }
        stage('Build Source') {
            steps {
                sh "docker run --volumes-from=jenkins-master -w ${env.SOURCE_DIR} ${env.DOCKER_IMAGE_TAG} make release"
            }
        }
        stage('Run Tests') {
            steps {
                sh "docker run --volumes-from=jenkins-master -w ${env.SOURCE_DIR} ${env.DOCKER_IMAGE_TAG} make gcov"
            }
            post {
                always {
                  step([$class: 'CoberturaPublisher', coberturaReportFile: 'Chapter_9/coverage.xml'])
                }
            }
        }
    }
}