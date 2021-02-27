make
./test_parser.out $1
sed -i 's/\r//' generated_execution.sh
bash generated_execution.sh
