from distutils.core import setup, Extension
#from libcpp.unordered_map cimport unordered_map


cgugletranslatemodule = Extension('CGT',
                           sources = ['cmod.c'])

setup(version = '1.0',
      description = 'implements gugle translate',
      ext_modules = [cgugletranslatemodule],
      author='Rex Sumsion')
