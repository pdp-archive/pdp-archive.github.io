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
echo "TASK : sch"
echo "   SOLUTION : sch_official_cpp"
array=(`seq 1 20`)
run_test 'testdata/29-PDP/sch/sch.in#' 'testdata/29-PDP/sch/sch.out#' 'sch.in' 'sch.out' './code/29-PDP/sch/sch_official.cpp' 1 'g++' "${array[@]}" 
echo "   SOLUTION : sch_official_c"
array=(`seq 1 20`)
run_test 'testdata/29-PDP/sch/sch.in#' 'testdata/29-PDP/sch/sch.out#' 'sch.in' 'sch.out' './code/29-PDP/sch/sch_official.c' 1 'gcc' "${array[@]}" 
echo "   SOLUTION : sch_official_pas"
echo "   SOLUTION : sch_efficient"
array=(`seq 1 20`)
run_test 'testdata/29-PDP/sch/sch.in#' 'testdata/29-PDP/sch/sch.out#' 'sch.in' 'sch.out' './code/29-PDP/sch/sch_efficient.cc' 1 'g++' "${array[@]}" 
echo "   SOLUTION : sch_set"
array=(`seq 1 20`)
run_test 'testdata/29-PDP/sch/sch.in#' 'testdata/29-PDP/sch/sch.out#' 'sch.in' 'sch.out' './code/29-PDP/sch/sch_set.cc' 1 'g++' "${array[@]}" 
echo "TASK : uflights"
echo "   SOLUTION : uflights_official_cpp"
array=(`seq 1 25`)
run_test 'testdata/29-PDP/uflights/uflights.in#' 'testdata/29-PDP/uflights/uflights.out#' 'uflights.in' 'uflights.out' './code/29-PDP/uflights/uflights_official.cpp' 3 'g++' "${array[@]}" 
echo "   SOLUTION : uflights_kruskal"
array=(`seq 1 25`)
run_test 'testdata/29-PDP/uflights/uflights.in#' 'testdata/29-PDP/uflights/uflights.out#' 'uflights.in' 'uflights.out' './code/29-PDP/uflights/uflights_kruskal.cc' 3 'g++' "${array[@]}" 
echo "   SOLUTION : uflights_prim"
array=(`seq 1 25`)
run_test 'testdata/29-PDP/uflights/uflights.in#' 'testdata/29-PDP/uflights/uflights.out#' 'uflights.in' 'uflights.out' './code/29-PDP/uflights/uflights_prim.cc' 3 'g++' "${array[@]}" 

