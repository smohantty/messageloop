project('messageloop', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++17'])

# These arguments are only used to build the shared library
# not the executables that use the library.
lib_args = ['-DBUILDING_MESSAGELOOP']

subdir('flutter/fml')

shlib = shared_library('messageloop', 'messageloop.cpp',
  install : true,
  cpp_args : lib_args,
  dependencies: [flutter_fml_dep, dependency('threads')],
  gnu_symbol_visibility : 'hidden',
)

test_exe = executable('messageloop', 'messageloop_test.cpp',
  link_with : shlib)
test('messageloop', test_exe)

# Make this library usable as a Meson subproject.
messageloop_dep = declare_dependency(
  include_directories: include_directories('.'),
  link_with : shlib)

# Make this library usable from the system's
# package manager.
install_headers('messageloop.hpp', subdir : 'messageloop')

pkg_mod = import('pkgconfig')
pkg_mod.generate(
  name : 'messageloop',
  filebase : 'messageloop',
  description : 'Meson sample project.',
  subdirs : 'messageloop',
  libraries : shlib,
  version : '0.1',
)
