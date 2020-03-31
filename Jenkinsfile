pipeline {
    agent any
    // agent {
    //     docker { image 'centos:build_env' }
    // }
    stage('check out code') {
        steps {
            echo 'checking out code...'
        }
        // git url: 'https://github.com/joe_user/simple-maven-project-with-tests.git'
    }
    // stage('build image') {
    //     app = docker.build("this/1.0")
    // }
    stage('build') {
        steps {
            echo 'building...'
        }
    }
    stage('test') {
        steps {
            echo 'running test suite...'
        }
    }
    stage('deploy') {
        steps {
            echo 'deploying...'
        }
    }
}