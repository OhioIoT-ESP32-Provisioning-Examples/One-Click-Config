#!/bin/bash

echo "connecting ..."

netsh wlan connect name="DEVICE PROVISIONING"

sleep 2

cd ~/workshops/firmware/One-Click-Config/app

node app.js

echo "finished ..."