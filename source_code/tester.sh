g++ --std=c++17 -fexceptions -o test_parser.out utils/test_parser.cc -lstdc++fs && ./test_parser.out $1
sed -i 's/\r//' generated_execution.sh
bash generated_execution.sh
