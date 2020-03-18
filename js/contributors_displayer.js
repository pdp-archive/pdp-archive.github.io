function swap(arr, x, y) {
  var tmp = arr[x];
  arr[x] = arr[y];
  arr[y] = tmp;
}

/* Returns "A1, A2, .., Α(n-1) και An". */ 
function concatenateNames(arr) {
  return arr.slice(0, -1).join(', ') + ' και ' + arr.slice(-1);
}

// !!!If you are a contributor add your name to the arrays below
// respecting alphabetical order.
var contestant_contributor_names = [
  "Γ. Βενιζέλος", 
  "Γ. Βιδαλάκης", 
  "Γ. Γιαπιτζάκης", 
  "Ε. Κηπουρίδης", 
  "Δ. Λως",
];
var other_contributor_names = [
  "Κ. Μποκής", 
  "Ν. Παπασπύρου",
];

function shuffleNames(shuffled_names) {
  
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

/* Populates shuffled contestant contributor names in the given div. */
function populateShuffledContestantContributorNames(element_id) {
  var shuffled_names = shuffleNames(contestant_contributor_names);
  document.getElementById(element_id).innerHTML = concatenateNames(shuffled_names);
}

/* Populates shuffled other contributor names in the given div. */
function populateShuffledOtherContributorNames(element_id) {
  var shuffled_names = shuffleNames(other_contributor_names);
  document.getElementById(element_id).innerHTML = concatenateNames(shuffled_names);
}

