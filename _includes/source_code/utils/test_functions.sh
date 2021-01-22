export CYGWIN="winsymlinks:native"

function run_test() {
   testcase_inp_template_name=$1
   testcase_out_template_name=$2
   fixed_inp_name=$3
   fixed_out_name=$4
   code_dir=$5
   code_filename=$6
   time_limit=$7
   compilation_command=$8
   #  sed -i 's/\r//' test_functions.sh
   # Step 1: Clear the tmp/ directory.
   if [[ -x tmp/ ]]; then
      rm -r tmp/
   fi;
   mkdir tmp/
   cd tmp/
   # Check if the compiler exists otherwise skip the test.
   compiler="${compilation_command%% *}"
   if [[! command -v "$compiler" &> /dev/null]];
   then
       echo -e "      Done [\e[33mSKIP\e[0m - compiler "$compiler" not found]\n"
       return 0
   fi;
   
   # Step 2: Compile the executable.
   echo -e "      Compiling.."
   comp_result=$($8 ../$5$6 -oexecutable)
   
   if [[ ! -x ./executable ]]; then
      # Check if executable is present in source dir (pascal)
      if [[ ! -x ../$code_dir/executable ]]; then
         echo -e "      \e[31mExecutable not produced\e[0m"
         echo -e "      Compiler exited with:"
         echo "${comp_result}"
         cd ../
         rm -r tmp/
         return 0
      else
         # Object files need to be moved for Pascal.
         mv ../$code_dir/executable .
         mv ../$code_dir/${code_filename%.*}.o .
      fi;
   fi
   
   # Step 3: Run the test cases.
   echo -e "      Running the testcases.."
   did_fail="false"
   all_arguments_arr=("$@")
   for i in "${all_arguments_arr[@]:8}";
   do
      # Decode the input/output filenames.
      norm1=${testcase_inp_template_name/\#/$i}
      norm2=${testcase_out_template_name/\#/$i}
      # Link the input with the canonical name.
      ln -sf ../${norm1} $fixed_inp_name
      # Run the code.
      timeout $time_limit ./executable
      # Check that no timeout occurred.
      if [ "$?" = 124 ]; then
         echo -e "         [\e[93mtimeout\e[0m] Test $i"
         did_fail="true"
      else
         result=$(diff --strip-trailing-cr ../$norm2 $fixed_out_name | head -c 200)
         # Check that output file was produced and was correct.
         if [[ "$result" != '' || ! -f $fixed_out_name ]]; then 
            echo -e "         [\e[31mwrong\e[0m] Test $i:"
            echo "           " $result
            did_fail="true"
         fi;
      fi;
   done;
   if [ "$did_fail" = "false" ] ; then
      echo -e "      Done [\e[92mPASS\e[0m]\n"
   else
      echo -e "      Done [\e[31mFAIL\e[0m]\n"
   fi
   cd ../
   rm -r tmp/
}

# run_test 'testdata/pdp30/a/astrolavos.in#' 'testdata/pdp30/a/astrolavos.out#' 'astrolavos.in' 'astrolavos.out' 'code/pdp30/a/astrolavos.cc' 15 1 'g++'
