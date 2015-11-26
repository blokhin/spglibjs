SpglibJS
======
[![DOI](https://zenodo.org/badge/18811/blokhin/spglibjs.svg)](https://zenodo.org/badge/latestdoi/18811/blokhin/spglibjs)

This is [Spglib](https://github.com/atztogo/spglib) library ported for the web with [LLVM](http://llvm.org) and [Emscripten](http://emscripten.org).
Follow the tutorial at the Emscripten website to learn details about [transpilation](https://en.wikipedia.org/wiki/Source-to-source_compiler) of C source code to JavaScript.

Now to determine crystalline symmetry you need only a browser (without any plugins). This is a pure experiment, and to foster any possible ideas and usecases I created an example web-app (```validator.html```), providing symmetry validation functionality for **CIF** or **POSCAR** files. An explicit symmetry information is absent in **POSCARs** and often omitted in **CIFs**, so this web-app provides a quick way of checking the symmetry for such cases. No server is used after page loading, so it is possible to drop a file there and check it without Internet connection (and without any concerns about privacy).

I thank Dr. Atsushi Togo-san for [Spglib](https://github.com/atztogo/spglib).

See [SpglibJS online](http://blokhin.github.io/spglibjs).
More info in the blog: https://blog.tilde.pro/handle-crystalline-symmetry-in-browser-using-pure-javascript-6bb01b99d170
