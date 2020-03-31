pipeline {
    agent any
    // agent {
    //     docker { image 'centos:build_env' }
    // }
    stages {
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
}

pipeline {
   stages {
      stage('check out code') {
         steps {
            echo 'Checking out code...'
            checkout scm
         }
      }
      stage('check out base image') {
         steps {
            echo 'Checking out base image...'
         }
      }
      stage('build new image') {
         steps {
            echo 'Building new image...'
         }
      }
      stage('compilation') {
          steps {
              echo 'Compiling all files...'
          }
      }
      stage('testing') {
          steps {
              echo 'Running all tests...'
          }
      }
      stage('deploy') {
          steps {
              echo 'Deploying to application...'
          }
      }
   }
}
