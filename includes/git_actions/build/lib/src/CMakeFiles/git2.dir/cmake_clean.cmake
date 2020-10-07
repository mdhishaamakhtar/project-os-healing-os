file(REMOVE_RECURSE
  "../git2.pdb"
  "../git2.so"
  "../git2.so.1.0"
  "../git2.so.1.0.0"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/git2.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
