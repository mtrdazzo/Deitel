pipeline {

    dockerfile {
        filename 'Dockerfile'
        dir '.'
        label 'app'
        additionalBuildArgs  '--build-arg version=1.0.2'
    }
    stages {
        stage('build') {
            steps {
                echo 'build'
            }
        }
    }
}