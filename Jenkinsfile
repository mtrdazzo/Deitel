pipeline {
    agent {
        docker { image 'centos:build_env' }
    }
    stages {
        stage('check out code') {
            echo 'checking out code...'
        }
        // stage('build image') {
        //     app = docker.build("this/1.0")
        // }
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