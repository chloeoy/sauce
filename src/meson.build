subdir('core')
subdir('utils')

# Define the executable using variables from subdirs
executable('saucebin', 'main.cpp',
  core_files + utils_files, 
  include_directories : inc
)