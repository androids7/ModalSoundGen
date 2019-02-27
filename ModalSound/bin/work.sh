./isostuffer -R 5 1.obj 1.tet
./extmat -f 1 -y 70e9 -p 0.23 -m -k -g
./modal_eigen -s 1.stiff.csc -m 1.mass.csc -o 1.ev -d 2400

