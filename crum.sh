#!/bin/bash
rm a.out
clear

if gcc $1; then
    echo ""
    ./a.out
else
    echo "CRum Says: Compilation Error, Forced Rum? [y/n]"
    read answer

    if "$answer" = "y"; then

        echo ""
        echo "====FORCED RUM by CRum===="
        echo ""

        if a.out; then
            echo ""
            gprof ./a.out gmon.out > report.txt
        else
            echo "CRum Says: Fatal error on compilation, a.out not found."
        fi
        
    fi
fi

rm a.out