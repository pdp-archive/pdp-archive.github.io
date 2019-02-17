source ./utils/test_functions.sh
echo "TASK : colors"
echo "   SOLUTION : colors_official"
array=(`seq 1 31`)
run_test 'testdata/29-PDP/colors/colors.in#' 'testdata/29-PDP/colors/colors.out#' 'colors.in' 'colors.out' './code/29-PDP/colors/colors_official.cpp' 1 'g++' "${array[@]}" 
echo "   SOLUTION : colors_efficient"
array=(`seq 1 31`)
run_test 'testdata/29-PDP/colors/colors.in#' 'testdata/29-PDP/colors/colors.out#' 'colors.in' 'colors.out' './code/29-PDP/colors/colors_efficient.cc' 1 'g++' "${array[@]}" 
echo "   SOLUTION : colors_brute_force"
array=(`seq 1 11`)
run_test 'testdata/29-PDP/colors/colors.in#' 'testdata/29-PDP/colors/colors.out#' 'colors.in' 'colors.out' './code/29-PDP/colors/colors_brute_force.cc' 1 'g++' "${array[@]}" 
echo "   SOLUTION : colors_n2"
array=(`seq 1 14`)
run_test 'testdata/29-PDP/colors/colors.in#' 'testdata/29-PDP/colors/colors.out#' 'colors.in' 'colors.out' './code/29-PDP/colors/colors_n2.cc' 1 'g++' "${array[@]}" 
echo "   SOLUTION : colors_nlogn"
array=(`seq 1 31`)
run_test 'testdata/29-PDP/colors/colors.in#' 'testdata/29-PDP/colors/colors.out#' 'colors.in' 'colors.out' './code/29-PDP/colors/colors_nlogn.cc' 1 'g++' "${array[@]}" 

