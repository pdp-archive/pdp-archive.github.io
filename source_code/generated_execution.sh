source ./utils/test_functions.sh
echo "TASK : karla"
echo "   SOLUTION : karla_official_cpp"
array=(`seq 1 12`)
run_test 'testdata/25-PDP/karla/karla.in#' 'testdata/25-PDP/karla/karla.out#' 'karla.in' 'karla.out' './code/25-PDP/karla/karla_official.cpp' 3 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : karla_official_c"
array=(`seq 1 12`)
run_test 'testdata/25-PDP/karla/karla.in#' 'testdata/25-PDP/karla/karla.out#' 'karla.in' 'karla.out' './code/25-PDP/karla/karla_official.c' 3 'gcc -std=c99 -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : karla_official_pas"
echo "   SOLUTION : karla_efficient_iterative"
array=(`seq 1 12`)
run_test 'testdata/25-PDP/karla/karla.in#' 'testdata/25-PDP/karla/karla.out#' 'karla.in' 'karla.out' './code/25-PDP/karla/karla_efficient_iterative.cc' 3 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : karla_efficient_recursive"
array=(`seq 1 12`)
run_test 'testdata/25-PDP/karla/karla.in#' 'testdata/25-PDP/karla/karla.out#' 'karla.in' 'karla.out' './code/25-PDP/karla/karla_efficient_recursive.cc' 3 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : karla_efficient_short"
array=(`seq 1 12`)
run_test 'testdata/25-PDP/karla/karla.in#' 'testdata/25-PDP/karla/karla.out#' 'karla.in' 'karla.out' './code/25-PDP/karla/karla_efficient_short.cc' 3 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "TASK : scidinner"
echo "   SOLUTION : scidinner_official_cpp"
array=(`seq 1 17`)
run_test 'testdata/25-PDP/scidinner/scidinner.in#' 'testdata/25-PDP/scidinner/scidinner.out#' 'scidinner.in' 'scidinner.out' './code/25-PDP/scidinner/scidinner_official.cpp' 1 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : scidinner_official_c"
array=(`seq 1 17`)
run_test 'testdata/25-PDP/scidinner/scidinner.in#' 'testdata/25-PDP/scidinner/scidinner.out#' 'scidinner.in' 'scidinner.out' './code/25-PDP/scidinner/scidinner_official.c' 1 'gcc -std=c99 -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : scidinner_official_pas"
echo "   SOLUTION : scidinner_complicated_iterative"
array=(`seq 1 15`)
run_test 'testdata/25-PDP/scidinner/scidinner.in#' 'testdata/25-PDP/scidinner/scidinner.out#' 'scidinner.in' 'scidinner.out' './code/25-PDP/scidinner/scidinner_complicated_iterative.cc' 1 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : scidinner_complicated_recursive"
array=( 1 2 3 4 5 6 7 8 9 10 11 12 14 17)
run_test 'testdata/25-PDP/scidinner/scidinner.in#' 'testdata/25-PDP/scidinner/scidinner.out#' 'scidinner.in' 'scidinner.out' './code/25-PDP/scidinner/scidinner_complicated_recursive.cc' 1 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "TASK : seti"
echo "   SOLUTION : seti_official_cpp"
array=(`seq 1 10`)
run_test 'testdata/25-PDP/seti/seti.in#' 'testdata/25-PDP/seti/seti.out#' 'seti.in' 'seti.out' './code/25-PDP/seti/seti_official.cpp' 3 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : seti_official_c"
array=(`seq 1 10`)
run_test 'testdata/25-PDP/seti/seti.in#' 'testdata/25-PDP/seti/seti.out#' 'seti.in' 'seti.out' './code/25-PDP/seti/seti_official.c' 3 'gcc -std=c99 -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : seti_official_pas"
echo "   SOLUTION : seti_brute_force"
array=(`seq 1 10`)
run_test 'testdata/25-PDP/seti/seti.in#' 'testdata/25-PDP/seti/seti.out#' 'seti.in' 'seti.out' './code/25-PDP/seti/seti_brute_force.cc' 3 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "TASK : sound"
echo "   SOLUTION : sound_official_cpp"
array=(`seq 1 14`)
run_test 'testdata/25-PDP/sound/sound.in#' 'testdata/25-PDP/sound/sound.out#' 'sound.in' 'sound.out' './code/25-PDP/sound/sound_official.cpp' 1 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : sound_efficient"
array=(`seq 1 14`)
run_test 'testdata/25-PDP/sound/sound.in#' 'testdata/25-PDP/sound/sound.out#' 'sound.in' 'sound.out' './code/25-PDP/sound/sound_efficient.cc' 1 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : sound_brute_force"
array=( 1 2 3 4 7)
run_test 'testdata/25-PDP/sound/sound.in#' 'testdata/25-PDP/sound/sound.out#' 'sound.in' 'sound.out' './code/25-PDP/sound/sound_brute_force.cc' 1 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : sound_semi_fast"
array=(`seq 1 8`)
run_test 'testdata/25-PDP/sound/sound.in#' 'testdata/25-PDP/sound/sound.out#' 'sound.in' 'sound.out' './code/25-PDP/sound/sound_semi_fast.cc' 1 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "TASK : telecom"
echo "   SOLUTION : telecom_official_cpp"
array=(`seq 1 31`)
run_test 'testdata/25-PDP/telecom/telecom.in#' 'testdata/25-PDP/telecom/telecom.out#' 'telecom.in' 'telecom.out' './code/25-PDP/telecom/telecom_official.cpp' 1 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : telecom_efficient"
array=(`seq 1 32`)
run_test 'testdata/25-PDP/telecom/telecom.in#' 'testdata/25-PDP/telecom/telecom.out#' 'telecom.in' 'telecom.out' './code/25-PDP/telecom/telecom_efficient.cc' 1 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : telecom_n2"
array=(`seq 1 21`)
run_test 'testdata/25-PDP/telecom/telecom.in#' 'testdata/25-PDP/telecom/telecom.out#' 'telecom.in' 'telecom.out' './code/25-PDP/telecom/telecom_n2.cc' 1 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : telecom_n3"
array=(`seq 1 13`)
run_test 'testdata/25-PDP/telecom/telecom.in#' 'testdata/25-PDP/telecom/telecom.out#' 'telecom.in' 'telecom.out' './code/25-PDP/telecom/telecom_n3.cc' 1 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "TASK : triangle"
echo "   SOLUTION : triangle_official_cpp"
array=(`seq 1 16`)
run_test 'testdata/25-PDP/triangle/triangle.in#' 'testdata/25-PDP/triangle/triangle.out#' 'triangle.in' 'triangle.out' './code/25-PDP/triangle/triangle_official.cpp' 1 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : triangle_efficient"
array=(`seq 1 16`)
run_test 'testdata/25-PDP/triangle/triangle.in#' 'testdata/25-PDP/triangle/triangle.out#' 'triangle.in' 'triangle.out' './code/25-PDP/triangle/triangle_efficient.cc' 1 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : triangle_mem_efficient"
array=(`seq 1 16`)
run_test 'testdata/25-PDP/triangle/triangle.in#' 'testdata/25-PDP/triangle/triangle.out#' 'triangle.in' 'triangle.out' './code/25-PDP/triangle/triangle_mem_efficient.cc' 1 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : triangle_brute_force"
array=(`seq 1 4`)
run_test 'testdata/25-PDP/triangle/triangle.in#' 'testdata/25-PDP/triangle/triangle.out#' 'triangle.in' 'triangle.out' './code/25-PDP/triangle/triangle_brute_force.cc' 1 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "TASK : colors"
echo "   SOLUTION : colors_official"
array=(`seq 1 31`)
run_test 'testdata/29-PDP/colors/colors.in#' 'testdata/29-PDP/colors/colors.out#' 'colors.in' 'colors.out' './code/29-PDP/colors/colors_official.cpp' 1 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : colors_efficient"
array=(`seq 1 31`)
run_test 'testdata/29-PDP/colors/colors.in#' 'testdata/29-PDP/colors/colors.out#' 'colors.in' 'colors.out' './code/29-PDP/colors/colors_efficient.cc' 1 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : colors_brute_force"
array=(`seq 1 11`)
run_test 'testdata/29-PDP/colors/colors.in#' 'testdata/29-PDP/colors/colors.out#' 'colors.in' 'colors.out' './code/29-PDP/colors/colors_brute_force.cc' 1 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : colors_n2"
array=(`seq 1 14`)
run_test 'testdata/29-PDP/colors/colors.in#' 'testdata/29-PDP/colors/colors.out#' 'colors.in' 'colors.out' './code/29-PDP/colors/colors_n2.cc' 1 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : colors_nlogn"
array=(`seq 1 31`)
run_test 'testdata/29-PDP/colors/colors.in#' 'testdata/29-PDP/colors/colors.out#' 'colors.in' 'colors.out' './code/29-PDP/colors/colors_nlogn.cc' 1 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "TASK : dnaseq"
echo "   SOLUTION : dnaseq_official_cpp"
array=(`seq 1 41`)
run_test 'testdata/29-PDP/dnaseq/dnaseq.in#' 'testdata/29-PDP/dnaseq/dnaseq.out#' 'dnaseq.in' 'dnaseq.out' './code/29-PDP/dnaseq/dnaseq_official.cpp' 1 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : dnaseq_efficient"
array=(`seq 1 41`)
run_test 'testdata/29-PDP/dnaseq/dnaseq.in#' 'testdata/29-PDP/dnaseq/dnaseq.out#' 'dnaseq.in' 'dnaseq.out' './code/29-PDP/dnaseq/dnaseq_efficient.cc' 1 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : dnaseq_brute_force"
array=(`seq 1 20`)
run_test 'testdata/29-PDP/dnaseq/dnaseq.in#' 'testdata/29-PDP/dnaseq/dnaseq.out#' 'dnaseq.in' 'dnaseq.out' './code/29-PDP/dnaseq/dnaseq_brute_force.cc' 1 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : dnaseq_rolling_hash"
array=(`seq 1 25`)
run_test 'testdata/29-PDP/dnaseq/dnaseq.in#' 'testdata/29-PDP/dnaseq/dnaseq.out#' 'dnaseq.in' 'dnaseq.out' './code/29-PDP/dnaseq/dnaseq_rolling_hash.cc' 1 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "TASK : maketime"
echo "   SOLUTION : maketime_official_cpp"
array=(`seq 1 23`)
run_test 'testdata/29-PDP/maketime/maketime.in#' 'testdata/29-PDP/maketime/maketime.out#' 'maketime.in' 'maketime.out' './code/29-PDP/maketime/maketime_official.cpp' 1 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : maketime_brute_force"
array=(`seq 1 11`)
run_test 'testdata/29-PDP/maketime/maketime.in#' 'testdata/29-PDP/maketime/maketime.out#' 'maketime.in' 'maketime.out' './code/29-PDP/maketime/maketime_brute_force.cc' 1 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : maketime_bsearch_answer"
array=(`seq 1 23`)
run_test 'testdata/29-PDP/maketime/maketime.in#' 'testdata/29-PDP/maketime/maketime.out#' 'maketime.in' 'maketime.out' './code/29-PDP/maketime/maketime_bsearch_answer.cc' 1 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : maketime_prefix_sums"
array=(`seq 1 15`)
run_test 'testdata/29-PDP/maketime/maketime.in#' 'testdata/29-PDP/maketime/maketime.out#' 'maketime.in' 'maketime.out' './code/29-PDP/maketime/maketime_prefix_sums.cc' 1 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : maketime_sort"
array=(`seq 1 23`)
run_test 'testdata/29-PDP/maketime/maketime.in#' 'testdata/29-PDP/maketime/maketime.out#' 'maketime.in' 'maketime.out' './code/29-PDP/maketime/maketime_sort.cc' 1 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : maketime_two_pointers"
array=(`seq 1 23`)
run_test 'testdata/29-PDP/maketime/maketime.in#' 'testdata/29-PDP/maketime/maketime.out#' 'maketime.in' 'maketime.out' './code/29-PDP/maketime/maketime_two_pointers.cc' 1 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "TASK : sch"
echo "   SOLUTION : sch_official_cpp"
array=(`seq 1 20`)
run_test 'testdata/29-PDP/sch/sch.in#' 'testdata/29-PDP/sch/sch.out#' 'sch.in' 'sch.out' './code/29-PDP/sch/sch_official.cpp' 1 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : sch_official_c"
array=(`seq 1 20`)
run_test 'testdata/29-PDP/sch/sch.in#' 'testdata/29-PDP/sch/sch.out#' 'sch.in' 'sch.out' './code/29-PDP/sch/sch_official.c' 1 'gcc -std=c99 -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : sch_official_pas"
echo "   SOLUTION : sch_efficient"
array=(`seq 1 20`)
run_test 'testdata/29-PDP/sch/sch.in#' 'testdata/29-PDP/sch/sch.out#' 'sch.in' 'sch.out' './code/29-PDP/sch/sch_efficient.cc' 1 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : sch_set"
array=(`seq 1 20`)
run_test 'testdata/29-PDP/sch/sch.in#' 'testdata/29-PDP/sch/sch.out#' 'sch.in' 'sch.out' './code/29-PDP/sch/sch_set.cc' 1 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "TASK : uflights"
echo "   SOLUTION : uflights_official_cpp"
array=(`seq 1 25`)
run_test 'testdata/29-PDP/uflights/uflights.in#' 'testdata/29-PDP/uflights/uflights.out#' 'uflights.in' 'uflights.out' './code/29-PDP/uflights/uflights_official.cpp' 3 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : uflights_kruskal"
array=(`seq 1 25`)
run_test 'testdata/29-PDP/uflights/uflights.in#' 'testdata/29-PDP/uflights/uflights.out#' 'uflights.in' 'uflights.out' './code/29-PDP/uflights/uflights_kruskal.cc' 3 'g++ -O2 -s -static -lm' "${array[@]}" 
echo "   SOLUTION : uflights_prim"
array=(`seq 1 25`)
run_test 'testdata/29-PDP/uflights/uflights.in#' 'testdata/29-PDP/uflights/uflights.out#' 'uflights.in' 'uflights.out' './code/29-PDP/uflights/uflights_prim.cc' 3 'g++ -O2 -s -static -lm' "${array[@]}" 
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

