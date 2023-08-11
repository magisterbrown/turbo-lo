Add route with turbo lo:
`route add -host 111.111.1.1 dev turbo_lo`
Send one packet:
`echo "aa" | nc -u -w1 111.111.1.1 8000`
Start server:
`nc -l -s 111.111.1.1 -p 9999`
Connect to server:
`nc 111.111.1.1 9999`
