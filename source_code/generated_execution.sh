source ./utils/test_functions.sh
echo "TASK : hydrocarbons"
echo "   SOLUTION : hydrocarbons_efficient_integers"
array=(`seq 1 18`)
run_test 'testdata/31-PDP/hydrocarbons/hydrocarbons.in#' 'testdata/31-PDP/hydrocarbons/hydrocarbons.out#' 'hydrocarbons.in' 'hydrocarbons.out' './code/31-PDP/hydrocarbons/hydrocarbons_efficient_integers.cc' 1 'g++ -O2 -DCONTEST -s -static -lm' "${array[@]}" 
echo "   SOLUTION : hydrocarbons_efficient_doubles"
array=(`seq 1 18`)
run_test 'testdata/31-PDP/hydrocarbons/hydrocarbons.in#' 'testdata/31-PDP/hydrocarbons/hydrocarbons.out#' 'hydrocarbons.in' 'hydrocarbons.out' './code/31-PDP/hydrocarbons/hydrocarbons_efficient_doubles.cc' 1 'g++ -O2 -DCONTEST -s -static -lm' "${array[@]}" 
echo "   SOLUTION : hydrocarbons_wrong"
array=(`seq 1 16`)
run_test 'testdata/31-PDP/hydrocarbons/hydrocarbons.in#' 'testdata/31-PDP/hydrocarbons/hydrocarbons.out#' 'hydrocarbons.in' 'hydrocarbons.out' './code/31-PDP/hydrocarbons/hydrocarbons_wrong.cc' 1 'g++ -O2 -DCONTEST -s -static -lm' "${array[@]}" 

