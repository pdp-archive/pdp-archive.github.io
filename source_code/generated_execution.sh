source ./utils/test_functions.sh
source ./utils/fetch_testdata.sh
fetch_testdata '22' 'hydrogen'
echo "TASK : hydrogen"
echo "   SOLUTION : hydrogen_official_cpp"
array=(`seq 1 10`)
run_test 'testdata/22-PDP/hydrogen/hydrogen.in#' 'testdata/22-PDP/hydrogen/hydrogen.out#' 'hydrogen.in' 'hydrogen.out' './code/22-PDP/hydrogen/hydrogen_official.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : hydrogen_official_c"
array=(`seq 1 10`)
run_test 'testdata/22-PDP/hydrogen/hydrogen.in#' 'testdata/22-PDP/hydrogen/hydrogen.out#' 'hydrogen.in' 'hydrogen.out' './code/22-PDP/hydrogen/hydrogen_official.c' 1 'gcc -std=c99 -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : hydrogen_official_pas"
echo "   SOLUTION : hydrogen_bubble_sort"
array=(`seq 1 10`)
run_test 'testdata/22-PDP/hydrogen/hydrogen.in#' 'testdata/22-PDP/hydrogen/hydrogen.out#' 'hydrogen.in' 'hydrogen.out' './code/22-PDP/hydrogen/hydrogen_bubble_sort.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : hydrogen_quicksort"
array=(`seq 1 10`)
run_test 'testdata/22-PDP/hydrogen/hydrogen.in#' 'testdata/22-PDP/hydrogen/hydrogen.out#' 'hydrogen.in' 'hydrogen.out' './code/22-PDP/hydrogen/hydrogen_quicksort.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '23' 'company'
echo "TASK : company"
echo "   SOLUTION : company_official_cpp"
array=( 1 2 3 4 5 7)
run_test 'testdata/23-PDP/company/company.in#' 'testdata/23-PDP/company/company.out#' 'company.in' 'company.out' './code/23-PDP/company/company_official.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : company_official_c"
array=(`seq 1 9`)
run_test 'testdata/23-PDP/company/company.in#' 'testdata/23-PDP/company/company.out#' 'company.in' 'company.out' './code/23-PDP/company/company_official.c' 1 'gcc -std=c99 -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : company_official_pas"
echo "   SOLUTION : company_brute_force"
array=(`seq 1 5`)
run_test 'testdata/23-PDP/company/company.in#' 'testdata/23-PDP/company/company.out#' 'company.in' 'company.out' './code/23-PDP/company/company_brute_force.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : company_efficient"
array=(`seq 1 10`)
run_test 'testdata/23-PDP/company/company.in#' 'testdata/23-PDP/company/company.out#' 'company.in' 'company.out' './code/23-PDP/company/company_efficient.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '23' 'profit'
echo "TASK : profit"
echo "   SOLUTION : profit_official_cpp"
array=(`seq 1 12`)
run_test 'testdata/23-PDP/profit/profit.in#' 'testdata/23-PDP/profit/profit.out#' 'profit.in' 'profit.out' './code/23-PDP/profit/profit_official.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : profit_official_c"
array=(`seq 1 12`)
run_test 'testdata/23-PDP/profit/profit.in#' 'testdata/23-PDP/profit/profit.out#' 'profit.in' 'profit.out' './code/23-PDP/profit/profit_official.c' 1 'gcc -std=c99 -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : profit_official_pas"
echo "   SOLUTION : profit_brute_force"
array=(`seq 1 9`)
run_test 'testdata/23-PDP/profit/profit.in#' 'testdata/23-PDP/profit/profit.out#' 'profit.in' 'profit.out' './code/23-PDP/profit/profit_brute_force.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : profit_efficient"
array=(`seq 1 12`)
run_test 'testdata/23-PDP/profit/profit.in#' 'testdata/23-PDP/profit/profit.out#' 'profit.in' 'profit.out' './code/23-PDP/profit/profit_efficient.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '23' 'snow_run'
echo "TASK : snow_run"
echo "   SOLUTION : snow_run_official_cpp"
array=(`seq 1 12`)
run_test 'testdata/23-PDP/snow_run/snow_run.in#' 'testdata/23-PDP/snow_run/snow_run.out#' 'snow_run.in' 'snow_run.out' './code/23-PDP/snow_run/snow_run_official.cpp' 5 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : snow_run_official_c"
array=(`seq 1 12`)
run_test 'testdata/23-PDP/snow_run/snow_run.in#' 'testdata/23-PDP/snow_run/snow_run.out#' 'snow_run.in' 'snow_run.out' './code/23-PDP/snow_run/snow_run_official.c' 5 'gcc -std=c99 -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : snow_run_official_pas"
echo "   SOLUTION : snow_run_brute_force_1"
array=(`seq 1 12`)
run_test 'testdata/23-PDP/snow_run/snow_run.in#' 'testdata/23-PDP/snow_run/snow_run.out#' 'snow_run.in' 'snow_run.out' './code/23-PDP/snow_run/snow_run_brute_force_1.cpp' 5 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : snow_run_brute_force_2"
array=(`seq 1 12`)
run_test 'testdata/23-PDP/snow_run/snow_run.in#' 'testdata/23-PDP/snow_run/snow_run.out#' 'snow_run.in' 'snow_run.out' './code/23-PDP/snow_run/snow_run_brute_force_2.cpp' 5 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : snow_run_seg_tree"
array=(`seq 1 12`)
run_test 'testdata/23-PDP/snow_run/snow_run.in#' 'testdata/23-PDP/snow_run/snow_run.out#' 'snow_run.in' 'snow_run.out' './code/23-PDP/snow_run/snow_run_seg_tree.cpp' 5 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '24' 'function'
echo "TASK : function"
echo "   SOLUTION : function_official_cpp"
array=(`seq 1 10`)
run_test 'testdata/24-PDP/function/function.in#' 'testdata/24-PDP/function/function.out#' 'function.in' 'function.out' './code/24-PDP/function/function_official.cpp' 3 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : function_official_c"
array=(`seq 1 10`)
run_test 'testdata/24-PDP/function/function.in#' 'testdata/24-PDP/function/function.out#' 'function.in' 'function.out' './code/24-PDP/function/function_official.c' 3 'gcc -std=c99 -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : function_official_pas"
echo "   SOLUTION : function_eratosthenes_sieve"
array=(`seq 1 10`)
run_test 'testdata/24-PDP/function/function.in#' 'testdata/24-PDP/function/function.out#' 'function.in' 'function.out' './code/24-PDP/function/function_eratosthenes_sieve.cpp' 3 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : function_l_root_l"
array=(`seq 1 10`)
run_test 'testdata/24-PDP/function/function.in#' 'testdata/24-PDP/function/function.out#' 'function.in' 'function.out' './code/24-PDP/function/function_l_root_l.cpp' 3 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : function_l_2"
array=(`seq 1 10`)
run_test 'testdata/24-PDP/function/function.in#' 'testdata/24-PDP/function/function.out#' 'function.in' 'function.out' './code/24-PDP/function/function_l_2.cpp' 3 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : function_precomputation"
array=(`seq 1 10`)
run_test 'testdata/24-PDP/function/function.in#' 'testdata/24-PDP/function/function.out#' 'function.in' 'function.out' './code/24-PDP/function/function_precomputation.cpp' 3 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '24' 'loutraki'
echo "TASK : loutraki"
echo "   SOLUTION : loutraki_n2"
array=( 1 2 3 4 5 6 7 11 12 13)
run_test 'testdata/24-PDP/loutraki/loutraki.in#' 'testdata/24-PDP/loutraki/loutraki.out#' 'loutraki.in' 'loutraki.out' './code/24-PDP/loutraki/loutraki_n2.cc' 2 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : loutraki_nlogn"
array=(`seq 1 15`)
run_test 'testdata/24-PDP/loutraki/loutraki.in#' 'testdata/24-PDP/loutraki/loutraki.out#' 'loutraki.in' 'loutraki.out' './code/24-PDP/loutraki/loutraki_nlogn.cc' 2 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : loutraki_nlogn_2"
array=(`seq 1 15`)
run_test 'testdata/24-PDP/loutraki/loutraki.in#' 'testdata/24-PDP/loutraki/loutraki.out#' 'loutraki.in' 'loutraki.out' './code/24-PDP/loutraki/loutraki_nlogn_2.cc' 2 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : loutraki_nlogn_sweep"
array=(`seq 1 15`)
run_test 'testdata/24-PDP/loutraki/loutraki.in#' 'testdata/24-PDP/loutraki/loutraki.out#' 'loutraki.in' 'loutraki.out' './code/24-PDP/loutraki/loutraki_nlogn_sweep.cc' 2 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : loutraki_n"
array=(`seq 1 15`)
run_test 'testdata/24-PDP/loutraki/loutraki.in#' 'testdata/24-PDP/loutraki/loutraki.out#' 'loutraki.in' 'loutraki.out' './code/24-PDP/loutraki/loutraki_n.cc' 2 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : loutraki_official"
array=(`seq 1 15`)
run_test 'testdata/24-PDP/loutraki/loutraki.in#' 'testdata/24-PDP/loutraki/loutraki.out#' 'loutraki.in' 'loutraki.out' './code/24-PDP/loutraki/loutraki_official.cc' 2 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '24' 'operators'
echo "TASK : operators"
echo "   SOLUTION : operators_official_cpp"
array=( 1 2 3 4 8)
run_test 'testdata/24-PDP/operators/operators.in#' 'testdata/24-PDP/operators/operators.out#' 'operators.in' 'operators.out' './code/24-PDP/operators/operators_official.cpp' 3 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : operators_official_c"
array=(`seq 1 10`)
run_test 'testdata/24-PDP/operators/operators.in#' 'testdata/24-PDP/operators/operators.out#' 'operators.in' 'operators.out' './code/24-PDP/operators/operators_official.c' 3 'gcc -std=c99 -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : operators_official_pas"
echo "   SOLUTION : operators_brute_force"
array=(`seq 1 7`)
run_test 'testdata/24-PDP/operators/operators.in#' 'testdata/24-PDP/operators/operators.out#' 'operators.in' 'operators.out' './code/24-PDP/operators/operators_brute_force.cpp' 3 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : operators_binary_search"
array=(`seq 1 10`)
run_test 'testdata/24-PDP/operators/operators.in#' 'testdata/24-PDP/operators/operators.out#' 'operators.in' 'operators.out' './code/24-PDP/operators/operators_binary_search.cpp' 3 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : operators_two_pointers"
array=(`seq 1 10`)
run_test 'testdata/24-PDP/operators/operators.in#' 'testdata/24-PDP/operators/operators.out#' 'operators.in' 'operators.out' './code/24-PDP/operators/operators_two_pointers.cpp' 3 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '25' 'karla'
echo "TASK : karla"
echo "   SOLUTION : karla_official_cpp"
array=(`seq 1 12`)
run_test 'testdata/25-PDP/karla/karla.in#' 'testdata/25-PDP/karla/karla.out#' 'karla.in' 'karla.out' './code/25-PDP/karla/karla_official.cpp' 3 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : karla_official_c"
array=(`seq 1 12`)
run_test 'testdata/25-PDP/karla/karla.in#' 'testdata/25-PDP/karla/karla.out#' 'karla.in' 'karla.out' './code/25-PDP/karla/karla_official.c' 3 'gcc -std=c99 -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : karla_official_pas"
echo "   SOLUTION : karla_efficient_iterative"
array=(`seq 1 12`)
run_test 'testdata/25-PDP/karla/karla.in#' 'testdata/25-PDP/karla/karla.out#' 'karla.in' 'karla.out' './code/25-PDP/karla/karla_efficient_iterative.cc' 3 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : karla_efficient_recursive"
array=(`seq 1 12`)
run_test 'testdata/25-PDP/karla/karla.in#' 'testdata/25-PDP/karla/karla.out#' 'karla.in' 'karla.out' './code/25-PDP/karla/karla_efficient_recursive.cc' 3 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : karla_efficient_short"
array=(`seq 1 12`)
run_test 'testdata/25-PDP/karla/karla.in#' 'testdata/25-PDP/karla/karla.out#' 'karla.in' 'karla.out' './code/25-PDP/karla/karla_efficient_short.cc' 3 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '25' 'scidinner'
echo "TASK : scidinner"
echo "   SOLUTION : scidinner_official_cpp"
array=(`seq 1 17`)
run_test 'testdata/25-PDP/scidinner/scidinner.in#' 'testdata/25-PDP/scidinner/scidinner.out#' 'scidinner.in' 'scidinner.out' './code/25-PDP/scidinner/scidinner_official.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : scidinner_official_c"
array=(`seq 1 17`)
run_test 'testdata/25-PDP/scidinner/scidinner.in#' 'testdata/25-PDP/scidinner/scidinner.out#' 'scidinner.in' 'scidinner.out' './code/25-PDP/scidinner/scidinner_official.c' 1 'gcc -std=c99 -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : scidinner_official_pas"
echo "   SOLUTION : scidinner_complicated_iterative"
array=(`seq 1 15`)
run_test 'testdata/25-PDP/scidinner/scidinner.in#' 'testdata/25-PDP/scidinner/scidinner.out#' 'scidinner.in' 'scidinner.out' './code/25-PDP/scidinner/scidinner_complicated_iterative.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : scidinner_complicated_recursive"
array=( 1 2 3 4 5 6 7 8 9 10 11 12 14 17)
run_test 'testdata/25-PDP/scidinner/scidinner.in#' 'testdata/25-PDP/scidinner/scidinner.out#' 'scidinner.in' 'scidinner.out' './code/25-PDP/scidinner/scidinner_complicated_recursive.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '25' 'seti'
echo "TASK : seti"
echo "   SOLUTION : seti_official_cpp"
array=(`seq 1 10`)
run_test 'testdata/25-PDP/seti/seti.in#' 'testdata/25-PDP/seti/seti.out#' 'seti.in' 'seti.out' './code/25-PDP/seti/seti_official.cpp' 3 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : seti_official_c"
array=(`seq 1 10`)
run_test 'testdata/25-PDP/seti/seti.in#' 'testdata/25-PDP/seti/seti.out#' 'seti.in' 'seti.out' './code/25-PDP/seti/seti_official.c' 3 'gcc -std=c99 -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : seti_official_pas"
echo "   SOLUTION : seti_brute_force"
array=(`seq 1 10`)
run_test 'testdata/25-PDP/seti/seti.in#' 'testdata/25-PDP/seti/seti.out#' 'seti.in' 'seti.out' './code/25-PDP/seti/seti_brute_force.cc' 3 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '25' 'sound'
echo "TASK : sound"
echo "   SOLUTION : sound_official_cpp"
array=(`seq 1 14`)
run_test 'testdata/25-PDP/sound/sound.in#' 'testdata/25-PDP/sound/sound.out#' 'sound.in' 'sound.out' './code/25-PDP/sound/sound_official.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : sound_efficient"
array=(`seq 1 14`)
run_test 'testdata/25-PDP/sound/sound.in#' 'testdata/25-PDP/sound/sound.out#' 'sound.in' 'sound.out' './code/25-PDP/sound/sound_efficient.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : sound_brute_force"
array=( 1 2 3 4 7)
run_test 'testdata/25-PDP/sound/sound.in#' 'testdata/25-PDP/sound/sound.out#' 'sound.in' 'sound.out' './code/25-PDP/sound/sound_brute_force.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : sound_semi_fast"
array=(`seq 1 8`)
run_test 'testdata/25-PDP/sound/sound.in#' 'testdata/25-PDP/sound/sound.out#' 'sound.in' 'sound.out' './code/25-PDP/sound/sound_semi_fast.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '25' 'telecom'
echo "TASK : telecom"
echo "   SOLUTION : telecom_official_cpp"
array=(`seq 1 31`)
run_test 'testdata/25-PDP/telecom/telecom.in#' 'testdata/25-PDP/telecom/telecom.out#' 'telecom.in' 'telecom.out' './code/25-PDP/telecom/telecom_official.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : telecom_efficient"
array=(`seq 1 32`)
run_test 'testdata/25-PDP/telecom/telecom.in#' 'testdata/25-PDP/telecom/telecom.out#' 'telecom.in' 'telecom.out' './code/25-PDP/telecom/telecom_efficient.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : telecom_n2"
array=(`seq 1 21`)
run_test 'testdata/25-PDP/telecom/telecom.in#' 'testdata/25-PDP/telecom/telecom.out#' 'telecom.in' 'telecom.out' './code/25-PDP/telecom/telecom_n2.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : telecom_n3"
array=(`seq 1 13`)
run_test 'testdata/25-PDP/telecom/telecom.in#' 'testdata/25-PDP/telecom/telecom.out#' 'telecom.in' 'telecom.out' './code/25-PDP/telecom/telecom_n3.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '25' 'triangle'
echo "TASK : triangle"
echo "   SOLUTION : triangle_official_cpp"
array=(`seq 1 16`)
run_test 'testdata/25-PDP/triangle/triangle.in#' 'testdata/25-PDP/triangle/triangle.out#' 'triangle.in' 'triangle.out' './code/25-PDP/triangle/triangle_official.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : triangle_efficient"
array=(`seq 1 16`)
run_test 'testdata/25-PDP/triangle/triangle.in#' 'testdata/25-PDP/triangle/triangle.out#' 'triangle.in' 'triangle.out' './code/25-PDP/triangle/triangle_efficient.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : triangle_mem_efficient"
array=(`seq 1 16`)
run_test 'testdata/25-PDP/triangle/triangle.in#' 'testdata/25-PDP/triangle/triangle.out#' 'triangle.in' 'triangle.out' './code/25-PDP/triangle/triangle_mem_efficient.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : triangle_brute_force"
array=(`seq 1 4`)
run_test 'testdata/25-PDP/triangle/triangle.in#' 'testdata/25-PDP/triangle/triangle.out#' 'triangle.in' 'triangle.out' './code/25-PDP/triangle/triangle_brute_force.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '26' 'domes'
echo "TASK : domes"
echo "   SOLUTION : domes_official_cpp"
array=(`seq 1 10`)
run_test 'testdata/26-PDP/domes/domes.in#' 'testdata/26-PDP/domes/domes.out#' 'domes.in' 'domes.out' './code/26-PDP/domes/domes_official.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : domes_official_c"
array=(`seq 1 10`)
run_test 'testdata/26-PDP/domes/domes.in#' 'testdata/26-PDP/domes/domes.out#' 'domes.in' 'domes.out' './code/26-PDP/domes/domes_official.c' 1 'gcc -std=c99 -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : domes_official_pas"
echo "   SOLUTION : domes_efficient"
array=(`seq 1 10`)
run_test 'testdata/26-PDP/domes/domes.in#' 'testdata/26-PDP/domes/domes.out#' 'domes.in' 'domes.out' './code/26-PDP/domes/domes_efficient.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '26' 'ensemble'
echo "TASK : ensemble"
echo "   SOLUTION : ensemble_official_cpp"
array=(`seq 1 12`)
run_test 'testdata/26-PDP/ensemble/ensemble.in#' 'testdata/26-PDP/ensemble/ensemble.out#' 'ensemble.in' 'ensemble.out' './code/26-PDP/ensemble/ensemble_official.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : ensemble_official_c"
array=(`seq 1 12`)
run_test 'testdata/26-PDP/ensemble/ensemble.in#' 'testdata/26-PDP/ensemble/ensemble.out#' 'ensemble.in' 'ensemble.out' './code/26-PDP/ensemble/ensemble_official.c' 1 'gcc -std=c99 -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : ensemble_official_pas"
echo "   SOLUTION : ensemble_efficient"
array=(`seq 1 12`)
run_test 'testdata/26-PDP/ensemble/ensemble.in#' 'testdata/26-PDP/ensemble/ensemble.out#' 'ensemble.in' 'ensemble.out' './code/26-PDP/ensemble/ensemble_efficient.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : ensemble_perfect_accuracy"
array=(`seq 1 12`)
run_test 'testdata/26-PDP/ensemble/ensemble.in#' 'testdata/26-PDP/ensemble/ensemble.out#' 'ensemble.in' 'ensemble.out' './code/26-PDP/ensemble/ensemble_perfect_accuracy.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '26' 'numbase'
echo "TASK : numbase"
echo "   SOLUTION : numbase_official_cpp"
array=(`seq 1 41`)
run_test 'testdata/26-PDP/numbase/numbase.in#' 'testdata/26-PDP/numbase/numbase.out#' 'numbase.in' 'numbase.out' './code/26-PDP/numbase/numbase_official.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : numbase_brute_force"
array=(`seq 1 13`)
run_test 'testdata/26-PDP/numbase/numbase.in#' 'testdata/26-PDP/numbase/numbase.out#' 'numbase.in' 'numbase.out' './code/26-PDP/numbase/numbase_brute_force.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : numbase_correct"
array=(`seq 1 31`)
run_test 'testdata/26-PDP/numbase/numbase.in#' 'testdata/26-PDP/numbase/numbase.out#' 'numbase.in' 'numbase.out' './code/26-PDP/numbase/numbase_correct.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : numbase_50_first"
array=(`seq 1 21`)
run_test 'testdata/26-PDP/numbase/numbase.in#' 'testdata/26-PDP/numbase/numbase.out#' 'numbase.in' 'numbase.out' './code/26-PDP/numbase/numbase_50_first.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : numbase_50_second"
array=(`seq 1 14`)
run_test 'testdata/26-PDP/numbase/numbase.in#' 'testdata/26-PDP/numbase/numbase.out#' 'numbase.in' 'numbase.out' './code/26-PDP/numbase/numbase_50_second.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '26' 'roadwork'
echo "TASK : roadwork"
echo "   SOLUTION : roadwork_official_cpp"
array=( 1 2 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 60 61 62 63 64 65 67 68 69 70 71 72)
run_test 'testdata/26-PDP/roadwork/roadwork.in#' 'testdata/26-PDP/roadwork/roadwork.out#' 'roadwork.in' 'roadwork.out' './code/26-PDP/roadwork/roadwork_official.cpp' 2 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : roadwork_slow"
array=(`seq 1 22`)
run_test 'testdata/26-PDP/roadwork/roadwork.in#' 'testdata/26-PDP/roadwork/roadwork.out#' 'roadwork.in' 'roadwork.out' './code/26-PDP/roadwork/roadwork_slow.cc' 2 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : roadwork_semifast"
array=(`seq 1 49`)
run_test 'testdata/26-PDP/roadwork/roadwork.in#' 'testdata/26-PDP/roadwork/roadwork.out#' 'roadwork.in' 'roadwork.out' './code/26-PDP/roadwork/roadwork_semifast.cc' 2 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : roadwork_efficient"
array=(`seq 1 72`)
run_test 'testdata/26-PDP/roadwork/roadwork.in#' 'testdata/26-PDP/roadwork/roadwork.out#' 'roadwork.in' 'roadwork.out' './code/26-PDP/roadwork/roadwork_efficient.cc' 2 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '26' 'solar'
echo "TASK : solar"
echo "   SOLUTION : solar_official_cpp"
array=(`seq 1 28`)
run_test 'testdata/26-PDP/solar/solar.in#' 'testdata/26-PDP/solar/solar.out#' 'solar.in' 'solar.out' './code/26-PDP/solar/solar_official.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : solar_official_c"
array=(`seq 1 28`)
run_test 'testdata/26-PDP/solar/solar.in#' 'testdata/26-PDP/solar/solar.out#' 'solar.in' 'solar.out' './code/26-PDP/solar/solar_official.c' 1 'gcc -std=c99 -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : solar_official_pas"
echo "   SOLUTION : solar_efficient"
array=(`seq 1 28`)
run_test 'testdata/26-PDP/solar/solar.in#' 'testdata/26-PDP/solar/solar.out#' 'solar.in' 'solar.out' './code/26-PDP/solar/solar_efficient.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : solar_slow"
array=( 1 2 3 4 5 6 7 8 9 10 11 13 14 15 16)
run_test 'testdata/26-PDP/solar/solar.in#' 'testdata/26-PDP/solar/solar.out#' 'solar.in' 'solar.out' './code/26-PDP/solar/solar_slow.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '26' 'sumpair'
echo "TASK : sumpair"
echo "   SOLUTION : sumpair_official_cpp"
array=(`seq 1 11`)
run_test 'testdata/26-PDP/sumpair/sumpair.in#' 'testdata/26-PDP/sumpair/sumpair.out#' 'sumpair.in' 'sumpair.out' './code/26-PDP/sumpair/sumpair_official.cpp' 2 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : sumpair_brute_force"
array=(`seq 1 5`)
run_test 'testdata/26-PDP/sumpair/sumpair.in#' 'testdata/26-PDP/sumpair/sumpair.out#' 'sumpair.in' 'sumpair.out' './code/26-PDP/sumpair/sumpair_brute_force.cc' 2 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : sumpair_set"
array=(`seq 1 7`)
run_test 'testdata/26-PDP/sumpair/sumpair.in#' 'testdata/26-PDP/sumpair/sumpair.out#' 'sumpair.in' 'sumpair.out' './code/26-PDP/sumpair/sumpair_set.cc' 2 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : sumpair_linear_query"
array=(`seq 1 11`)
run_test 'testdata/26-PDP/sumpair/sumpair.in#' 'testdata/26-PDP/sumpair/sumpair.out#' 'sumpair.in' 'sumpair.out' './code/26-PDP/sumpair/sumpair_linear_query.cc' 2 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '27' 'share'
echo "TASK : share"
echo "   SOLUTION : share_official_c"
array=(`seq 1 14`)
run_test 'testdata/27-PDP/share/share.in#' 'testdata/27-PDP/share/share.out#' 'share.in' 'share.out' './code/27-PDP/share/share_official.c' 1 'gcc -std=c99 -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : share_official_cpp"
array=(`seq 1 14`)
run_test 'testdata/27-PDP/share/share.in#' 'testdata/27-PDP/share/share.out#' 'share.in' 'share.out' './code/27-PDP/share/share_official.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : share_official_pas"
echo "   SOLUTION : share_brute_force"
array=(`seq 1 6`)
run_test 'testdata/27-PDP/share/share.in#' 'testdata/27-PDP/share/share.out#' 'share.in' 'share.out' './code/27-PDP/share/share_brute_force.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : share_brute_force_prefix_sums"
array=(`seq 1 7`)
run_test 'testdata/27-PDP/share/share.in#' 'testdata/27-PDP/share/share.out#' 'share.in' 'share.out' './code/27-PDP/share/share_brute_force_prefix_sums.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : share_binary_search"
array=(`seq 1 14`)
run_test 'testdata/27-PDP/share/share.in#' 'testdata/27-PDP/share/share.out#' 'share.in' 'share.out' './code/27-PDP/share/share_binary_search.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : share_two_binary_searches"
array=(`seq 1 14`)
run_test 'testdata/27-PDP/share/share.in#' 'testdata/27-PDP/share/share.out#' 'share.in' 'share.out' './code/27-PDP/share/share_two_binary_searches.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : share_two_pointers"
array=(`seq 1 14`)
run_test 'testdata/27-PDP/share/share.in#' 'testdata/27-PDP/share/share.out#' 'share.in' 'share.out' './code/27-PDP/share/share_two_pointers.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '27' 'twosqr'
echo "TASK : twosqr"
echo "   SOLUTION : twosqr_official_cpp"
array=(`seq 1 13`)
run_test 'testdata/27-PDP/twosqr/twosqr.in#' 'testdata/27-PDP/twosqr/twosqr.out#' 'twosqr.in' 'twosqr.out' './code/27-PDP/twosqr/twosqr_official.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : twosqr_official_c"
array=( 1 2 3 4 6 7 8 10 12)
run_test 'testdata/27-PDP/twosqr/twosqr.in#' 'testdata/27-PDP/twosqr/twosqr.out#' 'twosqr.in' 'twosqr.out' './code/27-PDP/twosqr/twosqr_official.c' 1 'gcc -std=c99 -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : twosqr_official_pas"
echo "   SOLUTION : twosqr_brute_force"
array=( 1 2 3 4 6 7 8 10 12)
run_test 'testdata/27-PDP/twosqr/twosqr.in#' 'testdata/27-PDP/twosqr/twosqr.out#' 'twosqr.in' 'twosqr.out' './code/27-PDP/twosqr/twosqr_brute_force.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : twosqr_binary_search"
array=(`seq 1 12`)
run_test 'testdata/27-PDP/twosqr/twosqr.in#' 'testdata/27-PDP/twosqr/twosqr.out#' 'twosqr.in' 'twosqr.out' './code/27-PDP/twosqr/twosqr_binary_search.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : twosqr_efficient"
array=(`seq 1 13`)
run_test 'testdata/27-PDP/twosqr/twosqr.in#' 'testdata/27-PDP/twosqr/twosqr.out#' 'twosqr.in' 'twosqr.out' './code/27-PDP/twosqr/twosqr_efficient.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '27' 'xxx'
echo "TASK : xxx"
echo "   SOLUTION : xxx_official_cpp"
array=(`seq 1 12`)
run_test 'testdata/27-PDP/xxx/xxx.in#' 'testdata/27-PDP/xxx/xxx.out#' 'xxx.in' 'xxx.out' './code/27-PDP/xxx/xxx_official.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : xxx_official_c"
array=(`seq 1 12`)
run_test 'testdata/27-PDP/xxx/xxx.in#' 'testdata/27-PDP/xxx/xxx.out#' 'xxx.in' 'xxx.out' './code/27-PDP/xxx/xxx_official.c' 1 'gcc -std=c99 -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : xxx_official_pas"
echo "   SOLUTION : xxx_brute_force"
array=(`seq 1 8`)
run_test 'testdata/27-PDP/xxx/xxx.in#' 'testdata/27-PDP/xxx/xxx.out#' 'xxx.in' 'xxx.out' './code/27-PDP/xxx/xxx_brute_force.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : xxx_efficient"
array=(`seq 1 12`)
run_test 'testdata/27-PDP/xxx/xxx.in#' 'testdata/27-PDP/xxx/xxx.out#' 'xxx.in' 'xxx.out' './code/27-PDP/xxx/xxx_efficient.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '28' 'aris'
echo "TASK : aris"
echo "   SOLUTION : aris_brute_force_cpp"
array=(`seq 1 10`)
run_test 'testdata/28-PDP/aris/aris.in#' 'testdata/28-PDP/aris/aris.out#' 'aris.in' 'aris.out' './code/28-PDP/aris/aris_brute_force.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : aris_efficient_cpp"
array=(`seq 1 14`)
run_test 'testdata/28-PDP/aris/aris.in#' 'testdata/28-PDP/aris/aris.out#' 'aris.in' 'aris.out' './code/28-PDP/aris/aris_efficient.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '28' 'kite'
echo "TASK : kite"
echo "   SOLUTION : kite_n3_cpp"
array=(`seq 1 9`)
run_test 'testdata/28-PDP/kite/kite.in#' 'testdata/28-PDP/kite/kite.out#' 'kite.in' 'kite.out' './code/28-PDP/kite/kite_n3.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : kite_n2_cpp"
array=(`seq 1 14`)
run_test 'testdata/28-PDP/kite/kite.in#' 'testdata/28-PDP/kite/kite.out#' 'kite.in' 'kite.out' './code/28-PDP/kite/kite_n2.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : kite_nlogn_cpp"
array=(`seq 1 22`)
run_test 'testdata/28-PDP/kite/kite.in#' 'testdata/28-PDP/kite/kite.out#' 'kite.in' 'kite.out' './code/28-PDP/kite/kite_nlogn.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : kite_n_cpp"
array=(`seq 1 22`)
run_test 'testdata/28-PDP/kite/kite.in#' 'testdata/28-PDP/kite/kite.out#' 'kite.in' 'kite.out' './code/28-PDP/kite/kite_n.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '28' 'schoolnet'
echo "TASK : schoolnet"
echo "   SOLUTION : schoolnet"
array=(`seq 1 22`)
run_test 'testdata/28-PDP/schoolnet/schoolnet.in#' 'testdata/28-PDP/schoolnet/schoolnet.out#' 'schoolnet.in' 'schoolnet.out' './code/28-PDP/schoolnet/schoolnet_official.cc' 2 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : schoolnet"
array=(`seq 1 22`)
run_test 'testdata/28-PDP/schoolnet/schoolnet.in#' 'testdata/28-PDP/schoolnet/schoolnet.out#' 'schoolnet.in' 'schoolnet.out' './code/28-PDP/schoolnet/schoolnet.cc' 2 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '28' 'scrabble1d'
echo "TASK : scrabble1d"
echo "   SOLUTION : scrabble1d_n2k_cpp"
array=(`seq 1 18`)
run_test 'testdata/28-PDP/scrabble1d/scrabble1d.in#' 'testdata/28-PDP/scrabble1d/scrabble1d.out#' 'scrabble1d.in' 'scrabble1d.out' './code/28-PDP/scrabble1d/scrabble1d_n2k.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : scrabble1d_n2_cpp"
array=(`seq 1 22`)
run_test 'testdata/28-PDP/scrabble1d/scrabble1d.in#' 'testdata/28-PDP/scrabble1d/scrabble1d.out#' 'scrabble1d.in' 'scrabble1d.out' './code/28-PDP/scrabble1d/scrabble1d_n2.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : scrabble1d_n_cpp"
array=(`seq 1 14`)
run_test 'testdata/28-PDP/scrabble1d/scrabble1d.in#' 'testdata/28-PDP/scrabble1d/scrabble1d.out#' 'scrabble1d.in' 'scrabble1d.out' './code/28-PDP/scrabble1d/scrabble1d_n.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '28' 'skitrip'
echo "TASK : skitrip"
echo "   SOLUTION : skitrip_official_cpp"
array=(`seq 1 42`)
run_test 'testdata/28-PDP/skitrip/skitrip.in#' 'testdata/28-PDP/skitrip/skitrip.out#' 'skitrip.in' 'skitrip.out' './code/28-PDP/skitrip/skitrip_official.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : skitrip_brute_force_cpp"
array=(`seq 1 17`)
run_test 'testdata/28-PDP/skitrip/skitrip.in#' 'testdata/28-PDP/skitrip/skitrip.out#' 'skitrip.in' 'skitrip.out' './code/28-PDP/skitrip/skitrip_brute_force.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : skitrip_sorting_cpp"
array=(`seq 1 26`)
run_test 'testdata/28-PDP/skitrip/skitrip.in#' 'testdata/28-PDP/skitrip/skitrip.out#' 'skitrip.in' 'skitrip.out' './code/28-PDP/skitrip/skitrip_sorting.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : skitrip_efficient_cpp"
array=(`seq 1 42`)
run_test 'testdata/28-PDP/skitrip/skitrip.in#' 'testdata/28-PDP/skitrip/skitrip.out#' 'skitrip.in' 'skitrip.out' './code/28-PDP/skitrip/skitrip_efficient.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '28' 'starwars'
echo "TASK : starwars"
echo "   SOLUTION : starwars_official"
array=(`seq 1 13`)
run_test 'testdata/28-PDP/starwars/starwars.in#' 'testdata/28-PDP/starwars/starwars.out#' 'starwars.in' 'starwars.out' './code/28-PDP/starwars/starwars_official.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : starwars_brute_force_cpp"
array=(`seq 1 5`)
run_test 'testdata/28-PDP/starwars/starwars.in#' 'testdata/28-PDP/starwars/starwars.out#' 'starwars.in' 'starwars.out' './code/28-PDP/starwars/starwars_brute_force.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : starwars_sqrt_decomposition_cpp"
array=(`seq 1 8`)
run_test 'testdata/28-PDP/starwars/starwars.in#' 'testdata/28-PDP/starwars/starwars.out#' 'starwars.in' 'starwars.out' './code/28-PDP/starwars/starwars_sqrt_decomposition.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : starwars_seg_tree"
array=(`seq 1 13`)
run_test 'testdata/28-PDP/starwars/starwars.in#' 'testdata/28-PDP/starwars/starwars.out#' 'starwars.in' 'starwars.out' './code/28-PDP/starwars/starwars_seg_tree.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '29' 'colors'
echo "TASK : colors"
echo "   SOLUTION : colors_official"
array=(`seq 1 31`)
run_test 'testdata/29-PDP/colors/colors.in#' 'testdata/29-PDP/colors/colors.out#' 'colors.in' 'colors.out' './code/29-PDP/colors/colors_official.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : colors_efficient"
array=(`seq 1 31`)
run_test 'testdata/29-PDP/colors/colors.in#' 'testdata/29-PDP/colors/colors.out#' 'colors.in' 'colors.out' './code/29-PDP/colors/colors_efficient.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : colors_brute_force"
array=(`seq 1 11`)
run_test 'testdata/29-PDP/colors/colors.in#' 'testdata/29-PDP/colors/colors.out#' 'colors.in' 'colors.out' './code/29-PDP/colors/colors_brute_force.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : colors_n2"
array=(`seq 1 14`)
run_test 'testdata/29-PDP/colors/colors.in#' 'testdata/29-PDP/colors/colors.out#' 'colors.in' 'colors.out' './code/29-PDP/colors/colors_n2.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : colors_nlogn"
array=(`seq 1 31`)
run_test 'testdata/29-PDP/colors/colors.in#' 'testdata/29-PDP/colors/colors.out#' 'colors.in' 'colors.out' './code/29-PDP/colors/colors_nlogn.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '29' 'dnaseq'
echo "TASK : dnaseq"
echo "   SOLUTION : dnaseq_official_cpp"
array=(`seq 1 41`)
run_test 'testdata/29-PDP/dnaseq/dnaseq.in#' 'testdata/29-PDP/dnaseq/dnaseq.out#' 'dnaseq.in' 'dnaseq.out' './code/29-PDP/dnaseq/dnaseq_official.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : dnaseq_efficient"
array=(`seq 1 41`)
run_test 'testdata/29-PDP/dnaseq/dnaseq.in#' 'testdata/29-PDP/dnaseq/dnaseq.out#' 'dnaseq.in' 'dnaseq.out' './code/29-PDP/dnaseq/dnaseq_efficient.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : dnaseq_brute_force"
array=(`seq 1 20`)
run_test 'testdata/29-PDP/dnaseq/dnaseq.in#' 'testdata/29-PDP/dnaseq/dnaseq.out#' 'dnaseq.in' 'dnaseq.out' './code/29-PDP/dnaseq/dnaseq_brute_force.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : dnaseq_rolling_hash"
array=(`seq 1 25`)
run_test 'testdata/29-PDP/dnaseq/dnaseq.in#' 'testdata/29-PDP/dnaseq/dnaseq.out#' 'dnaseq.in' 'dnaseq.out' './code/29-PDP/dnaseq/dnaseq_rolling_hash.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '29' 'maketime'
echo "TASK : maketime"
echo "   SOLUTION : maketime_official_cpp"
array=(`seq 1 23`)
run_test 'testdata/29-PDP/maketime/maketime.in#' 'testdata/29-PDP/maketime/maketime.out#' 'maketime.in' 'maketime.out' './code/29-PDP/maketime/maketime_official.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : maketime_brute_force"
array=(`seq 1 11`)
run_test 'testdata/29-PDP/maketime/maketime.in#' 'testdata/29-PDP/maketime/maketime.out#' 'maketime.in' 'maketime.out' './code/29-PDP/maketime/maketime_brute_force.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : maketime_bsearch_answer"
array=(`seq 1 23`)
run_test 'testdata/29-PDP/maketime/maketime.in#' 'testdata/29-PDP/maketime/maketime.out#' 'maketime.in' 'maketime.out' './code/29-PDP/maketime/maketime_bsearch_answer.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : maketime_prefix_sums"
array=(`seq 1 15`)
run_test 'testdata/29-PDP/maketime/maketime.in#' 'testdata/29-PDP/maketime/maketime.out#' 'maketime.in' 'maketime.out' './code/29-PDP/maketime/maketime_prefix_sums.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : maketime_sort"
array=(`seq 1 23`)
run_test 'testdata/29-PDP/maketime/maketime.in#' 'testdata/29-PDP/maketime/maketime.out#' 'maketime.in' 'maketime.out' './code/29-PDP/maketime/maketime_sort.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : maketime_two_pointers"
array=(`seq 1 23`)
run_test 'testdata/29-PDP/maketime/maketime.in#' 'testdata/29-PDP/maketime/maketime.out#' 'maketime.in' 'maketime.out' './code/29-PDP/maketime/maketime_two_pointers.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '29' 'sch'
echo "TASK : sch"
echo "   SOLUTION : sch_official_cpp"
array=(`seq 1 20`)
run_test 'testdata/29-PDP/sch/sch.in#' 'testdata/29-PDP/sch/sch.out#' 'sch.in' 'sch.out' './code/29-PDP/sch/sch_official.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : sch_official_c"
array=(`seq 1 20`)
run_test 'testdata/29-PDP/sch/sch.in#' 'testdata/29-PDP/sch/sch.out#' 'sch.in' 'sch.out' './code/29-PDP/sch/sch_official.c' 1 'gcc -std=c99 -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : sch_official_pas"
echo "   SOLUTION : sch_efficient"
array=(`seq 1 20`)
run_test 'testdata/29-PDP/sch/sch.in#' 'testdata/29-PDP/sch/sch.out#' 'sch.in' 'sch.out' './code/29-PDP/sch/sch_efficient.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : sch_set"
array=(`seq 1 20`)
run_test 'testdata/29-PDP/sch/sch.in#' 'testdata/29-PDP/sch/sch.out#' 'sch.in' 'sch.out' './code/29-PDP/sch/sch_set.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '29' 'uflights'
echo "TASK : uflights"
echo "   SOLUTION : uflights_official_cpp"
array=(`seq 1 25`)
run_test 'testdata/29-PDP/uflights/uflights.in#' 'testdata/29-PDP/uflights/uflights.out#' 'uflights.in' 'uflights.out' './code/29-PDP/uflights/uflights_official.cpp' 3 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : uflights_kruskal"
array=(`seq 1 25`)
run_test 'testdata/29-PDP/uflights/uflights.in#' 'testdata/29-PDP/uflights/uflights.out#' 'uflights.in' 'uflights.out' './code/29-PDP/uflights/uflights_kruskal.cc' 3 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : uflights_prim"
array=(`seq 1 25`)
run_test 'testdata/29-PDP/uflights/uflights.in#' 'testdata/29-PDP/uflights/uflights.out#' 'uflights.in' 'uflights.out' './code/29-PDP/uflights/uflights_prim.cc' 3 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '29' 'villages'
echo "TASK : villages"
echo "   SOLUTION : villages_official_cpp"
array=(`seq 1 52`)
run_test 'testdata/29-PDP/villages/villages.in#' 'testdata/29-PDP/villages/villages.out#' 'villages.in' 'villages.out' './code/29-PDP/villages/villages_official.cpp' 2 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : villages_efficient_recursive"
array=( 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 47 48 50 51)
run_test 'testdata/29-PDP/villages/villages.in#' 'testdata/29-PDP/villages/villages.out#' 'villages.in' 'villages.out' './code/29-PDP/villages/villages_efficient_recursive.cc' 2 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : villages_efficient_iterative"
array=(`seq 1 52`)
run_test 'testdata/29-PDP/villages/villages.in#' 'testdata/29-PDP/villages/villages.out#' 'villages.in' 'villages.out' './code/29-PDP/villages/villages_efficient_iterative.cc' 2 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : villages_slow"
array=(`seq 1 37`)
run_test 'testdata/29-PDP/villages/villages.in#' 'testdata/29-PDP/villages/villages.out#' 'villages.in' 'villages.out' './code/29-PDP/villages/villages_slow.cc' 2 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '30' 'agora'
echo "TASK : agora"
echo "   SOLUTION : agora_official"
array=(`seq 1 20`)
run_test 'testdata/30-PDP/agora/agora.in#' 'testdata/30-PDP/agora/agora.out#' 'agora.in' 'agora.out' './code/30-PDP/agora/agora_official.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : agora_brute_force"
array=(`seq 1 10`)
run_test 'testdata/30-PDP/agora/agora.in#' 'testdata/30-PDP/agora/agora.out#' 'agora.in' 'agora.out' './code/30-PDP/agora/agora_brute_force.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : agora_efficient"
array=(`seq 1 20`)
run_test 'testdata/30-PDP/agora/agora.in#' 'testdata/30-PDP/agora/agora.out#' 'agora.in' 'agora.out' './code/30-PDP/agora/agora_efficient.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '30' 'astrolavos'
echo "TASK : astrolavos"
echo "   SOLUTION : astrolavos_efficient"
array=(`seq 1 15`)
run_test 'testdata/30-PDP/astrolavos/astrolavos.in#' 'testdata/30-PDP/astrolavos/astrolavos.out#' 'astrolavos.in' 'astrolavos.out' './code/30-PDP/astrolavos/astrolavos_efficient.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '30' 'brickbreaker'
echo "TASK : brickbreaker"
echo "   SOLUTION : brickbreaker_official"
array=(`seq 1 43`)
run_test 'testdata/30-PDP/brickbreaker/brickbreaker.in#' 'testdata/30-PDP/brickbreaker/brickbreaker.out#' 'brickbreaker.in' 'brickbreaker.out' './code/30-PDP/brickbreaker/brickbreaker_official.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : brickbreaker_efficient"
array=(`seq 1 43`)
run_test 'testdata/30-PDP/brickbreaker/brickbreaker.in#' 'testdata/30-PDP/brickbreaker/brickbreaker.out#' 'brickbreaker.in' 'brickbreaker.out' './code/30-PDP/brickbreaker/brickbreaker_efficient.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : brickbreaker_slow"
array=(`seq 1 23`)
run_test 'testdata/30-PDP/brickbreaker/brickbreaker.in#' 'testdata/30-PDP/brickbreaker/brickbreaker.out#' 'brickbreaker.in' 'brickbreaker.out' './code/30-PDP/brickbreaker/brickbreaker_slow.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '30' 'kalanta'
echo "TASK : kalanta"
echo "   SOLUTION : kalanta_official"
array=(`seq 1 19`)
run_test 'testdata/30-PDP/kalanta/kalanta.in#' 'testdata/30-PDP/kalanta/kalanta.out#' 'kalanta.in' 'kalanta.out' './code/30-PDP/kalanta/kalanta_official.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : kalanta_n3"
array=(`seq 1 8`)
run_test 'testdata/30-PDP/kalanta/kalanta.in#' 'testdata/30-PDP/kalanta/kalanta.out#' 'kalanta.in' 'kalanta.out' './code/30-PDP/kalanta/kalanta_n3.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : kalanta_n2"
array=(`seq 1 10`)
run_test 'testdata/30-PDP/kalanta/kalanta.in#' 'testdata/30-PDP/kalanta/kalanta.out#' 'kalanta.in' 'kalanta.out' './code/30-PDP/kalanta/kalanta_n2.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : kalanta_bsearch_answer"
array=(`seq 1 19`)
run_test 'testdata/30-PDP/kalanta/kalanta.in#' 'testdata/30-PDP/kalanta/kalanta.out#' 'kalanta.in' 'kalanta.out' './code/30-PDP/kalanta/kalanta_bsearch_answer.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : kalanta_linear"
array=(`seq 1 19`)
run_test 'testdata/30-PDP/kalanta/kalanta.in#' 'testdata/30-PDP/kalanta/kalanta.out#' 'kalanta.in' 'kalanta.out' './code/30-PDP/kalanta/kalanta_linear.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '30' 'listgame'
echo "TASK : listgame"
echo "   SOLUTION : listgame_official"
array=(`seq 1 18`)
run_test 'testdata/30-PDP/listgame/listgame.in#' 'testdata/30-PDP/listgame/listgame.out#' 'listgame.in' 'listgame.out' './code/30-PDP/listgame/listgame_official.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : listgame_brute_force"
array=(`seq 1 8`)
run_test 'testdata/30-PDP/listgame/listgame.in#' 'testdata/30-PDP/listgame/listgame.out#' 'listgame.in' 'listgame.out' './code/30-PDP/listgame/listgame_brute_force.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : listgame_dp_recursive"
array=(`seq 1 13`)
run_test 'testdata/30-PDP/listgame/listgame.in#' 'testdata/30-PDP/listgame/listgame.out#' 'listgame.in' 'listgame.out' './code/30-PDP/listgame/listgame_dp_recursive.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : listgame_dp"
array=(`seq 1 18`)
run_test 'testdata/30-PDP/listgame/listgame.in#' 'testdata/30-PDP/listgame/listgame.out#' 'listgame.in' 'listgame.out' './code/30-PDP/listgame/listgame_dp.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : listgame_dp_memoisation"
array=(`seq 1 18`)
run_test 'testdata/30-PDP/listgame/listgame.in#' 'testdata/30-PDP/listgame/listgame.out#' 'listgame.in' 'listgame.out' './code/30-PDP/listgame/listgame_dp_memoisation.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '30' 'rafting'
echo "TASK : rafting"
echo "   SOLUTION : rafting_official"
array=(`seq 1 17`)
run_test 'testdata/30-PDP/rafting/rafting.in#' 'testdata/30-PDP/rafting/rafting.out#' 'rafting.in' 'rafting.out' './code/30-PDP/rafting/rafting_official.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : rafting_brute_force"
array=(`seq 1 12`)
run_test 'testdata/30-PDP/rafting/rafting.in#' 'testdata/30-PDP/rafting/rafting.out#' 'rafting.in' 'rafting.out' './code/30-PDP/rafting/rafting_brute_force.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : rafting_brute_force_list"
array=(`seq 1 12`)
run_test 'testdata/30-PDP/rafting/rafting.in#' 'testdata/30-PDP/rafting/rafting.out#' 'rafting.in' 'rafting.out' './code/30-PDP/rafting/rafting_brute_force_list.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : rafting_efficient_seg_tree"
array=(`seq 1 17`)
run_test 'testdata/30-PDP/rafting/rafting.in#' 'testdata/30-PDP/rafting/rafting.out#' 'rafting.in' 'rafting.out' './code/30-PDP/rafting/rafting_efficient_seg_tree.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '31' 'cntbal'
echo "TASK : cntbal"
echo "   SOLUTION : cntbal_official"
array=(`seq 1 38`)
run_test 'testdata/31-PDP/cntbal/cntbal.in#' 'testdata/31-PDP/cntbal/cntbal.out#' 'cntbal.in' 'cntbal.out' './code/31-PDP/cntbal/cntbal_official.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : cntbal_N^3"
array=(`seq 1 15`)
run_test 'testdata/31-PDP/cntbal/cntbal.in#' 'testdata/31-PDP/cntbal/cntbal.out#' 'cntbal.in' 'cntbal.out' './code/31-PDP/cntbal/cntbal_N^3.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : cntbal_N^2"
array=(`seq 1 24`)
run_test 'testdata/31-PDP/cntbal/cntbal.in#' 'testdata/31-PDP/cntbal/cntbal.out#' 'cntbal.in' 'cntbal.out' './code/31-PDP/cntbal/cntbal_N^2.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : cntbal_optimal"
array=(`seq 1 38`)
run_test 'testdata/31-PDP/cntbal/cntbal.in#' 'testdata/31-PDP/cntbal/cntbal.out#' 'cntbal.in' 'cntbal.out' './code/31-PDP/cntbal/cntbal_optimal.cpp' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '31' 'hydrocarbons'
echo "TASK : hydrocarbons"
echo "   SOLUTION : hydrocarbons_official"
array=(`seq 1 18`)
run_test 'testdata/31-PDP/hydrocarbons/hydrocarbons.in#' 'testdata/31-PDP/hydrocarbons/hydrocarbons.out#' 'hydrocarbons.in' 'hydrocarbons.out' './code/31-PDP/hydrocarbons/hydrocarbons_official.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : hydrocarbons_efficient_integers"
array=(`seq 1 18`)
run_test 'testdata/31-PDP/hydrocarbons/hydrocarbons.in#' 'testdata/31-PDP/hydrocarbons/hydrocarbons.out#' 'hydrocarbons.in' 'hydrocarbons.out' './code/31-PDP/hydrocarbons/hydrocarbons_efficient_integers.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : hydrocarbons_efficient_doubles"
array=(`seq 1 18`)
run_test 'testdata/31-PDP/hydrocarbons/hydrocarbons.in#' 'testdata/31-PDP/hydrocarbons/hydrocarbons.out#' 'hydrocarbons.in' 'hydrocarbons.out' './code/31-PDP/hydrocarbons/hydrocarbons_efficient_doubles.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : hydrocarbons_wrong"
array=(`seq 1 16`)
run_test 'testdata/31-PDP/hydrocarbons/hydrocarbons.in#' 'testdata/31-PDP/hydrocarbons/hydrocarbons.out#' 'hydrocarbons.in' 'hydrocarbons.out' './code/31-PDP/hydrocarbons/hydrocarbons_wrong.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '31' 'lottery'
echo "TASK : lottery"
echo "   SOLUTION : lottery_brute"
array=(`seq 1 12`)
run_test 'testdata/31-PDP/lottery/lottery.in#' 'testdata/31-PDP/lottery/lottery.out#' 'lottery.in' 'lottery.out' './code/31-PDP/lottery/lottery_brute.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : lottery_bsearch"
array=( 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 18 21)
run_test 'testdata/31-PDP/lottery/lottery.in#' 'testdata/31-PDP/lottery/lottery.out#' 'lottery.in' 'lottery.out' './code/31-PDP/lottery/lottery_bsearch.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : lottery_trie"
array=(`seq 1 27`)
run_test 'testdata/31-PDP/lottery/lottery.in#' 'testdata/31-PDP/lottery/lottery.out#' 'lottery.in' 'lottery.out' './code/31-PDP/lottery/lottery_trie.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '31' 'mntsea'
echo "TASK : mntsea"
echo "   SOLUTION : mntsea_official"
array=(`seq 1 20`)
run_test 'testdata/31-PDP/mntsea/mntsea.in#' 'testdata/31-PDP/mntsea/mntsea.out#' 'mntsea.in' 'mntsea.out' './code/31-PDP/mntsea/mntsea_official.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : mntsea_n3"
array=(`seq 1 8`)
run_test 'testdata/31-PDP/mntsea/mntsea.in#' 'testdata/31-PDP/mntsea/mntsea.out#' 'mntsea.in' 'mntsea.out' './code/31-PDP/mntsea/mntsea_n3.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : mntsea_n2"
array=(`seq 1 11`)
run_test 'testdata/31-PDP/mntsea/mntsea.in#' 'testdata/31-PDP/mntsea/mntsea.out#' 'mntsea.in' 'mntsea.out' './code/31-PDP/mntsea/mntsea_n2.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : mntsea_n2_cumulative_sums"
array=(`seq 1 13`)
run_test 'testdata/31-PDP/mntsea/mntsea.in#' 'testdata/31-PDP/mntsea/mntsea.out#' 'mntsea.in' 'mntsea.out' './code/31-PDP/mntsea/mntsea_n2_cumulative_sums.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : mntsea_nlogn"
array=(`seq 1 20`)
run_test 'testdata/31-PDP/mntsea/mntsea.in#' 'testdata/31-PDP/mntsea/mntsea.out#' 'mntsea.in' 'mntsea.out' './code/31-PDP/mntsea/mntsea_nlogn.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : mntsea_n"
array=(`seq 1 20`)
run_test 'testdata/31-PDP/mntsea/mntsea.in#' 'testdata/31-PDP/mntsea/mntsea.out#' 'mntsea.in' 'mntsea.out' './code/31-PDP/mntsea/mntsea_n.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '31' 'symstr'
echo "TASK : symstr"
echo "   SOLUTION : symstr"
array=(`seq 1 23`)
run_test 'testdata/31-PDP/symstr/symstr.in#' 'testdata/31-PDP/symstr/symstr.out#' 'symstr.in' 'symstr.out' './code/31-PDP/symstr/symstr.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '32' 'erasmus'
echo "TASK : erasmus"
echo "   SOLUTION : erasmus1"
array=(`seq 1 13`)
run_test 'testdata/32-PDP/erasmus/erasmus.in#' 'testdata/32-PDP/erasmus/erasmus.out#' 'erasmus.in' 'erasmus.out' './code/32-PDP/erasmus/erasmus1.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : erasmus2"
array=(`seq 1 13`)
run_test 'testdata/32-PDP/erasmus/erasmus.in#' 'testdata/32-PDP/erasmus/erasmus.out#' 'erasmus.in' 'erasmus.out' './code/32-PDP/erasmus/erasmus2.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '32' 'longsumk'
echo "TASK : longsumk"
echo "   SOLUTION : longsumk_n3"
array=(`seq 1 10`)
run_test 'testdata/32-PDP/longsumk/longsumk.in#' 'testdata/32-PDP/longsumk/longsumk.out#' 'longsumk.in' 'longsumk.out' './code/32-PDP/longsumk/longsumk_n3.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : longsumk_n2"
array=(`seq 1 12`)
run_test 'testdata/32-PDP/longsumk/longsumk.in#' 'testdata/32-PDP/longsumk/longsumk.out#' 'longsumk.in' 'longsumk.out' './code/32-PDP/longsumk/longsumk_n2.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : longsumk_n"
array=(`seq 1 19`)
run_test 'testdata/32-PDP/longsumk/longsumk.in#' 'testdata/32-PDP/longsumk/longsumk.out#' 'longsumk.in' 'longsumk.out' './code/32-PDP/longsumk/longsumk_n.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : longsumk_n_2pointers"
array=(`seq 1 19`)
run_test 'testdata/32-PDP/longsumk/longsumk.in#' 'testdata/32-PDP/longsumk/longsumk.out#' 'longsumk.in' 'longsumk.out' './code/32-PDP/longsumk/longsumk_n_2pointers.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
fetch_testdata '32' 'shops'
echo "TASK : shops"
echo "   SOLUTION : shops_n2k"
array=( 1 2 3 4 5 6 7 8 22 23 24 25 26 27 28 29 30 31)
run_test 'testdata/32-PDP/shops/shops.in#' 'testdata/32-PDP/shops/shops.out#' 'shops.in' 'shops.out' './code/32-PDP/shops/shops_n2k.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : shops_n2"
array=( 1 2 3 4 5 6 7 8 9 10 11 22 23 24 25 26 27 28 29 30 31)
run_test 'testdata/32-PDP/shops/shops.in#' 'testdata/32-PDP/shops/shops.out#' 'shops.in' 'shops.out' './code/32-PDP/shops/shops_n2.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : shops_n"
array=(`seq 1 31`)
run_test 'testdata/32-PDP/shops/shops.in#' 'testdata/32-PDP/shops/shops.out#' 'shops.in' 'shops.out' './code/32-PDP/shops/shops_n.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : shops_n_lessmem"
array=(`seq 1 31`)
run_test 'testdata/32-PDP/shops/shops.in#' 'testdata/32-PDP/shops/shops.out#' 'shops.in' 'shops.out' './code/32-PDP/shops/shops_n_lessmem.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 
echo "   SOLUTION : shops_n_slide"
array=(`seq 1 31`)
run_test 'testdata/32-PDP/shops/shops.in#' 'testdata/32-PDP/shops/shops.out#' 'shops.in' 'shops.out' './code/32-PDP/shops/shops_n_slide.cc' 1 'g++ -O2 -DCONTEST -s -static -lm -w' "${array[@]}" 

