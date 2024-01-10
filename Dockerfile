FROM alpine:latest

# Metadata of Container
LABEL name="alpine-testing"
LABEL maintainer="AOrps"

# Setting WORKDIR
WORKDIR /usr/src/app

# Adding files to container
ADD *.c /usr/src/app
ADD *.h /usr/src/app
ADD Makefile /usr/src/app
ADD kill-debug.sh /usr/src/app
ADD LICENSE /usr/src/app

# Installing Dependencies
# APK add make

# Running Commands


# It's a BINGO!
ENTRYPOINT ["/bin/sh"]
