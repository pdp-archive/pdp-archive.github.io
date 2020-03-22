function fetch_testdata() {
   # Fetch testdata if directory is not present.

   # Arg 1 : PDP contest (e.g. 22)
   # Arg 2 : codename (e.g. 'fire')
   # sed -i 's/\r//' test.sh
   if [ ! -d testdata/$1-PDP/$2 ]; then
      echo 'Fetching testdata for : ' $2
      mkdir tmp
      wget https://gitlab.com/pdp-archive/pdp-archive/-/archive/master/pdp-archive-master.zip?path=testdata/$1-PDP/$2 -O tmp/download.zip
      cd tmp
      unzip -q download.zip
      cd ..
      cp -r tmp/pdp-archive-master-testdata-$1-PDP-$2/testdata .
      rm -r tmp
   fi;
}

# fetch_testdata '22' 'fire'
# fetch_testdata '22' 'matrix'
