# Parameter -c for whether cygwin is being used.

# Simple code to check if a parameter is present.
# Source: https://stackoverflow.com/questions/2875424/correct-way-to-check-for-a-command-line-flag-in-bash
has_param() {
   local term="$1"
   shift
   for arg; do
      if [[ $arg == "$term" ]]; then
        return 0
      fi
   done
   return 1
}

# Το chrome χρειάζεται το absolute path για να αποθηκεύσει 
# τα screenshots.
path_to_dir=`pwd`
if has_param '-c' "$@"; then
    path_to_dir=`cygpath -w $path_to_dir`
fi

# Τα URLs των αντιπροσωπευτικών σελίδων που θέλουμε να ελέγξουμε.
urls=(
"http://localhost:4000/"
"http://localhost:4000/27-PDP/c-supermarket-statement"
"http://localhost:4000/27-PDP/c-supermarket-solution"
"http://localhost:4000/27-PDP/"
"http://localhost:4000/categorised"
"http://localhost:4000/all"
"http://localhost:4000/relevant"
)

# Οι ονομασίες των εικόνων για κάθε σελίδα.
names=(
"main"
"statement"
"solution"
"summary"
"categorised"
"all"
"relevant"
)

# Run for computer screen.
for idx in "${!urls[@]}"; do
  url=${urls[$idx]}
  name=${names[$idx]}
  chrome --headless --disable-gpu --window-size=1000,600 --run-all-compositor-stages-before-draw --virtual-time-budget=10000 --screenshot="${path_to_dir}/srcns/${name}.png" "${url}"
done

# Run for mobile screen.
for idx in "${!urls[@]}"; do
  url=${urls[$idx]}
  name=${names[$idx]}
  chrome --headless --disable-gpu --window-size=375,667 --run-all-compositor-stages-before-draw --virtual-time-budget=10000 --screenshot="${path_to_dir}/srcns/${name}_mobile.png" "${url}"
done

