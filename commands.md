Add route with turbo lo:
`route add -host 111.111.1.1 dev turbo_lo`
Send one packet:
`echo "aa" | nc -u -w1 111.111.1.1 8000`
