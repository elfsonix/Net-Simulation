file(REMOVE_RECURSE
  "main.cpp.pdb"
  "main.cpp.exe"
  "main.cpp.exe.manifest"
  "libmain.cpp.dll.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/main.cpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
