(rule
 (target findlib.conf)
 (action (write-file %{target} "")))

(alias
 (name   runtest)
 (deps   (:x README.md)
         (:conf findlib.conf)
         (package mdx)
         (package base)
         (package base_quickcheck)
         (package core_kernel)
         (package ppx_jane)
         (:y9 examples/bigger_quickcheck_test/test.ml)
         (:y8 examples/broken_inline_test/test.ml)
         (:y7 examples/manual_property_test/test.ml)
         (:y6 examples/quickcheck_property_test/test.ml)
         (:y5 examples/simple_expect_test/test.ml)
         (:y4 examples/simple_inline_test/dune)
         (:y3 examples/simple_inline_test/test.ml)
         (:y2 examples/test_eq-inline_test/test.ml)
         (:y1 examples/trivial_expect_test/test.ml)
         (:y0 examples/trivial_expect_test_fixed/test.ml)
         (source_tree examples/broken_inline_test)
         (source_tree examples/manual_property_test)
         (source_tree examples/quickcheck_property_test)
         (source_tree examples/simple_inline_test)
         (source_tree examples/test_eq-inline_test)
         (source_tree examples/trivial_expect_test)
         (source_tree examples/trivial_expect_test_fixed)
         prelude.ml)
 (locks ../../global-lock)
 (action (progn
           (setenv OCAMLFIND_CONF %{conf} (run ocaml-mdx test --prelude=prelude.ml --direction=to-md %{x}))
           (diff? %{y9} %{y9}.corrected)
           (diff? %{y8} %{y8}.corrected)
           (diff? %{y7} %{y7}.corrected)
           (diff? %{y6} %{y6}.corrected)
           (diff? %{y5} %{y5}.corrected)
           (diff? %{y4} %{y4}.corrected)
           (diff? %{y3} %{y3}.corrected)
           (diff? %{y2} %{y2}.corrected)
           (diff? %{y1} %{y1}.corrected)
           (diff? %{y0} %{y0}.corrected)
           (diff? %{x} %{x}.corrected))))