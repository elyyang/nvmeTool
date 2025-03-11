#!/usr/bin/env bash

repoURL=https://github.com/axboe/fio
cloneDir="${PWD}/../submodule/fio"
cloneCmd="git clone $repoURL $cloneDir"
cloneCmdRun=$($cloneCmd 2>&1)

echo -e "running: $ $cloneCmd"
echo -e "${cloneCmdRun}\n"

cd $cloneDir
make