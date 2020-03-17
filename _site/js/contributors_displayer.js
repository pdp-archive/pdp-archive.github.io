function swap(arr, x, y) {
  var tmp = arr[x];
  arr[x] = arr[y];
  arr[y] = tmp;
}

/* Returns "A1, A2, .., Α(n-1) και An". */ 
function concatenateNames(arr) {
  return arr.slice(0, -1).join(', ') + ' και ' + arr.slice(-1);
}

function shuffleNames() {
  // !!!If you are a contributor add your name to the array below
  // respecting alphabetical order.
  var shuffled_names = [
      "Γ. Βενιζέλος", 
      "Γ. Βιδαλάκης", 
      "Γ. Γιαπιτζάκης", 
      "Ε. Κηπουρίδης", 
      "Δ. Λως",
      "Κ. Μποκής",
  ];
  
  // Generate a permutation uniformly at random.
  // Choose a random name from the remaining ones and 
  // place at shuffled_names[i].
  // Note: the last iteration is not needed.
  for (i = 0; i + 1 < shuffled_names.length; i++) {
    var remaining_elements = shuffled_names.length - i;
    var idx = Math.floor(Math.random() * remaining_elements);
	swap(shuffled_names, i, i + idx);
  }
  
  return shuffled_names;
}

/* Populates shuffled names in the given div. */
function populateShuffledNames(element_id) {
  var shuffled_names = shuffleNames()
  document.getElementById(element_id).innerHTML = concatenateNames(shuffled_names);
}

