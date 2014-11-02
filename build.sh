#!/bin/bash

set -e

case $1 in
    '')
        echo '-- building...'
        make -j8
        echo '-- installing...'
        make uninstall 1>/dev/null
make install 1>/dev/null;;
    'clean')
        echo '-- cleaning...'
        make -j8 clean;;
    *)
        echo 'error: unknown action' 1>&2
        exit 1;;
esac
