<?php

test_figure_arg_types(NULL);
test_figure_arg_types(true);
test_figure_arg_types(false);
test_figure_arg_types(1);
test_figure_arg_types(1.0);
test_figure_arg_types("str");
test_figure_arg_types([123 => "qwe"]);
test_figure_arg_types(fopen(__FILE__, "r"));
test_figure_arg_types(new stdClass());
