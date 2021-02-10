
//requests
sudo tcpdump -ni enx00e04c3648a8


//tcpdump ANCII format (-s 0 - whole packages)
sudo tcpdump -n -A -s 0 > tcpdump.txt

//only addresses
sudo tcpdump -n  > tcpdump.txt

//
sudo tcpdump -x -r tcpdump.pcap 2>/dev/null

awk '{ if (match($0, /^[0-9]/, _)) { printf (NR == 1 ? "%s " : "\n%s "), $0; fflush() } else { sub(/^\s+0x[0-9a-z]+:\s+/, " "); gsub(" ", ""); printf "%s", $0 } } END { print ""; fflush() }'
