#!/usr/bin/env bash
INTERFACE=`netstat -i | grep eth | cut -d" "  -f1`;

if [ "$DELAY" != "" ]; then
    tc qdisc add dev $INTERFACE root netem delay $DELAY
fi
if [ "$BANDWIDTH" != "" ]; then
    tc qdisc add dev $INTERFACE root netem rate $BANDWIDTH
fi
