file(REMOVE_RECURSE
  "lib/libcppgit2.pdb"
  "lib/libcppgit2.so"
  "lib/libcppgit2.so.0.1.0"
  "lib/libcppgit2.so.1"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/CPPGIT2_SHARED.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
