make
pout=`./test_parser.out $1`
if [[ $pout =~ "Error" ]] ; then
   echo $pout
   echo -e " Problem when reading the TASK file [\e[31mFAIL\e[0m]\n"
else
   sed -i 's/\r//' generated_execution.sh
   bash generated_execution.sh
fi

