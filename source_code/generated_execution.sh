source ./utils/test_functions.sh
echo "TASK : karla"
echo "   SOLUTION : karla_official_cpp"
array=(`seq 1 12`)
run_test 'testdata/25-PDP/karla/karla.in#' 'testdata/25-PDP/karla/karla.out#' 'karla.in' 'karla.out' './code/25-PDP/karla/karla_official.cpp' 3 'g++' "${array[@]}" 
echo "   SOLUTION : karla_official_c"
array=(`seq 1 12`)
run_test 'testdata/25-PDP/karla/karla.in#' 'testdata/25-PDP/karla/karla.out#' 'karla.in' 'karla.out' './code/25-PDP/karla/karla_official.c' 3 'gcc' "${array[@]}" 
echo "   SOLUTION : karla_official_pas"
echo "   SOLUTION : karla_efficient_iterative"
array=(`seq 1 12`)
run_test 'testdata/25-PDP/karla/karla.in#' 'testdata/25-PDP/karla/karla.out#' 'karla.in' 'karla.out' './code/25-PDP/karla/karla_efficient_iterative.cc' 3 'g++' "${array[@]}" 
echo "   SOLUTION : karla_efficient_recursive"
array=(`seq 1 12`)
run_test 'testdata/25-PDP/karla/karla.in#' 'testdata/25-PDP/karla/karla.out#' 'karla.in' 'karla.out' './code/25-PDP/karla/karla_efficient_recursive.cc' 3 'g++' "${array[@]}" 
echo "   SOLUTION : karla_efficient_short"
array=(`seq 1 12`)
run_test 'testdata/25-PDP/karla/karla.in#' 'testdata/25-PDP/karla/karla.out#' 'karla.in' 'karla.out' './code/25-PDP/karla/karla_efficient_short.cc' 3 'g++' "${array[@]}" 
echo "TASK : seti"
echo "   SOLUTION : seti_official_cpp"
array=(`seq 1 10`)
run_test 'testdata/25-PDP/seti/seti.in#' 'testdata/25-PDP/seti/seti.out#' 'seti.in' 'seti.out' './code/25-PDP/seti/seti_official.cpp' 3 'g++' "${array[@]}" 
echo "   SOLUTION : seti_official_c"
array=(`seq 1 10`)
run_test 'testdata/25-PDP/seti/seti.in#' 'testdata/25-PDP/seti/seti.out#' 'seti.in' 'seti.out' './code/25-PDP/seti/seti_official.c' 3 'gcc' "${array[@]}" 
echo "   SOLUTION : seti_official_pas"
echo "   SOLUTION : seti_brute_force"
array=(`seq 1 10`)
run_test 'testdata/25-PDP/seti/seti.in#' 'testdata/25-PDP/seti/seti.out#' 'seti.in' 'seti.out' './code/25-PDP/seti/seti_brute_force.cc' 3 'g++' "${array[@]}" 
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

