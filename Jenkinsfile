pipeline {
    agent {
        docker { image 'centos:build_env' }
    }
    stages {
        stage('build') {
            echo 'building...'
        }
        stage('test') {
            echo 'running test suite...'
        }
        stage('deploy') {
            echo 'deploying...'
        }
    }
}