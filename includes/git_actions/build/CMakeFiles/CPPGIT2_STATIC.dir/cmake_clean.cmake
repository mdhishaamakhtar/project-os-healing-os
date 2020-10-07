file(REMOVE_RECURSE
  "lib/libcppgit2.a"
  "lib/libcppgit2.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/CPPGIT2_STATIC.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
