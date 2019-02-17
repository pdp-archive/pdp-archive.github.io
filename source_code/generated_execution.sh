source ./utils/test_functions.sh
echo "TASK : villages"
echo "   SOLUTION : villages_official_cpp"
array=(`seq 1 52`)
run_test 'testdata/29-PDP/villages/villages.in#' 'testdata/29-PDP/villages/villages.out#' 'villages.in' 'villages.out' './code/29-PDP/villages/villages_official.cpp' 2 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : villages_efficient_recursive"
array=( 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 47 48 50 51)
run_test 'testdata/29-PDP/villages/villages.in#' 'testdata/29-PDP/villages/villages.out#' 'villages.in' 'villages.out' './code/29-PDP/villages/villages_efficient_recursive.cc' 2 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : villages_efficient_iterative"
array=(`seq 1 52`)
run_test 'testdata/29-PDP/villages/villages.in#' 'testdata/29-PDP/villages/villages.out#' 'villages.in' 'villages.out' './code/29-PDP/villages/villages_efficient_iterative.cc' 2 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : villages_slow"
array=(`seq 1 37`)
run_test 'testdata/29-PDP/villages/villages.in#' 'testdata/29-PDP/villages/villages.out#' 'villages.in' 'villages.out' './code/29-PDP/villages/villages_slow.cc' 2 'g++ -O2 -s -static -lm' "${array[@]}" 

