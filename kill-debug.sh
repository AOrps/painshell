#!/usr/bin/env bash
#
# Kills process being launched from ps
#


kill -9 $(ps aux | grep 'losh' | head -n 1 | awk '{print $2}')
