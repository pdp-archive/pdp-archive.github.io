function run_test() {
   # arg 1 : testdata directory template input name
   # arg 2 : template output name
   # arg 3 : fixed input name
   # arg 4 : fixed output name
   # arg 5 : code location
   # arg 6 : time limit
   # arg 7 : compilation command
   # arg 8 : array of tests to execute
   #  sed -i 's/\r//' test_functions.sh
   mkdir tmp/
   cd tmp/
   arr=("$@")
   echo -e "      Compiling.."
   $7 ../$5 -o executable
   
   echo -e "      Running the testcases.."
   found_wrong_or_timeout="false"
   for i in "${arr[@]:7}";
   do
      norm1=${1/\#/$i}
      norm2=${2/\#/$i}
      cp ../${norm1} $3
      if [[ ! -x ./executable ]]; then
         #executable does not exist
         found_wrong_or_timeout="true"
      else
	 timeout $6 ./executable
	 if [ "$?" = 124 ]; then
            echo -e "         [\e[93mtimeout\e[0m] Test $i"
            found_wrong_or_timeout="true"
         else
            result=$(diff --strip-trailing-cr ../$norm2 $4 | head -c 200)
	    if [ "$result" != '' ]; then 
	       echo -e "         [\e[31mwrong\e[0m] Test $i:"
	       echo "           " $result
	       found_wrong_or_timeout="true"
	    fi;
         fi;
      fi;
   done;
   if [ "$found_wrong_or_timeout" = "false" ] ; then
      echo -e "      Done [\e[92mPASS\e[0m]\n"
   else
      echo -e "      Done [\e[31mFAIL\e[0m]\n"
   fi
   cd ../
   rm -r tmp/
}

# run_test 'testdata/pdp30/a/astrolavos.in#' 'testdata/pdp30/a/astrolavos.out#' 'astrolavos.in' 'astrolavos.out' 'code/pdp30/a/astrolavos.cc' 15 1 'g++'
