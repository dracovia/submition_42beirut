#!/bin/bash

service ssh start
service nginx start
service tor start

echo "=============================="
echo "ONION ADDRESS:"
cat /var/lib/tor/ft_onion/hostname
echo "=============================="

tail -f /dev/null
