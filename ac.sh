#!/bin/bash

g++ run-test.cpp && ./a.out $1 $2

if [ "$3" == "-y" ]; then
	xdotool type 'uva' \
	&& xdotool key Return \
	&& xdotool type 'use uva canhnhtse03860' \
	&& xdotool key Return \
	&& xdotool type "send $1 $1.cpp" \
	&& xdotool key Return \
	&& xdotool type 'stat' \
	&& xdotool key Return
else
	echo 'Skip submitting'
fi