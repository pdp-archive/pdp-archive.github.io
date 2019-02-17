function run_test() {
    # arg 1 : testdata directory template input name
	# arg 2 : template output name
	# arg 3 : fixed input name
	# arg 4 : fixed output name
	# arg 5 : code location
	# arg 6 : time limit
	# arg 7 : compilation command
	# arg 8 : array of tests to execute
	#  sed -i 's/\r//' test.sh
	mkdir tmp/
	cd tmp/
	arr=("$@")
	$7 ../$5 -o executable
	for i in "${arr[@]:7}";
	do
	    norm1=${1/\#/$i}
		norm2=${2/\#/$i}
		cp ../${norm1} $3
		timeout $6 ./executable
		if [ "$?" = 124 ]; then
			echo Test $i: timeout
		else
			result=$(diff --strip-trailing-cr ../$norm2 $4)
			if [ "$result" != '' ]; then 
				echo Test $i: wrong 
				echo $result
			fi;
		fi;
	done;
	cd ../
	rm -r tmp/
}

# run_test 'testdata/pdp30/a/astrolavos.in#' 'testdata/pdp30/a/astrolavos.out#' 'astrolavos.in' 'astrolavos.out' 'code/pdp30/a/astrolavos.cc' 15 1 'g++'