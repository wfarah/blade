deps = [
  dependency('JlCxx', modules: ['JlCxx::cxxwrap_julia', 'JlCxx::cxxwrap_julia_stl'], required: false),
]

has_julia = true
foreach x_dep : deps
  has_julia = has_julia and x_dep.found()
endforeach

if has_julia
  lib_bladejl = library(
    'bladejl',
    files('bindings.cc'),
    include_directories: inc_lst + '@0@/include/julia'.format(get_option('prefix')),
    dependencies: dep_lst,
    install: true,
  )
  julia_path = meson.current_build_dir()
endif
