./isostuffer -R 5 -L 3 -M 7 -a 0.25 -b 0.42978 1.obj 1.tet
./extmat -f 1 -y 70e9 -p 0.23 -m -k -g
./modal_eigen -s 1.stiff.csc -m 1.mass.csc -o 1.ev -d 2400

