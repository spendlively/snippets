<?php

echo json_encode(debug_backtrace());
//or
echo debug_backtrace()[1]['function'];
//or
echo debug_backtrace(!DEBUG_BACKTRACE_PROVIDE_OBJECT|DEBUG_BACKTRACE_IGNORE_ARGS,2)[1]['function'];
