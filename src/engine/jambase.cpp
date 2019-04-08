/* Generated by mkjambase from Jambase */
const char *jambase[] = {
/* Jambase */
"\n",
"\n",
"if $(NT)\n",
"{\n",
"SLASH ?= \\\\ ;\n",
"}\n",
"SLASH ?= / ;\n",
"\n",
"\n",
"rule find-to-root ( dir : patterns + )\n",
"{\n",
"local globs = [ GLOB $(dir) : $(patterns) ] ;\n",
"while ! $(globs) && $(dir:P) != $(dir)\n",
"{\n",
"dir = $(dir:P) ;\n",
"globs = [ GLOB $(dir) : $(patterns) ] ;\n",
"}\n",
"return $(globs) ;\n",
"}\n",
"\n",
"\n",
".boost-build-file = ;\n",
"\n",
".bootstrap-file = ;\n",
"\n",
"BOOST_BUILD_PATH.user-value = $(BOOST_BUILD_PATH) ;\n",
"\n",
"if ! $(BOOST_BUILD_PATH) && $(UNIX)\n",
"{\n",
"BOOST_BUILD_PATH = /usr/share/boost-build ;\n",
"}\n",
"\n",
"\n",
"rule _poke ( module-name ? : variables + : value * )\n",
"{\n",
"module $(<)\n",
"{\n",
"$(>) = $(3) ;\n",
"}\n",
"}\n",
"\n",
"\n",
"rule boost-build ( dir ? )\n",
"{\n",
"if $(.bootstrap-file)\n",
"{\n",
"ECHO \"Error: Illegal attempt to re-bootstrap the build system by invoking\" ;\n",
"ECHO ;\n",
"ECHO \"   'boost-build\" $(dir) \";'\" ;\n",
"ECHO ;\n",
"EXIT \"Please consult the documentation at 'http://www.boost.org'.\" ;\n",
"}\n",
"\n",
"BOOST_BUILD_PATH = $(dir:R=$(.boost-build-file:D)) $(BOOST_BUILD_PATH) ;\n",
"\n",
"_poke .ENVIRON : BOOST_BUILD_PATH : $(BOOST_BUILD_PATH) ;\n",
"\n",
"local bootstrap-file = [ GLOB $(BOOST_BUILD_PATH) : bootstrap.jam ] ;\n",
".bootstrap-file = $(bootstrap-file[1]) ;\n",
"\n",
"if ! $(.bootstrap-file)\n",
"{\n",
"ECHO \"Unable to load Boost.Build: could not find build system.\" ;\n",
"ECHO --------------------------------------------------------- ;\n",
"ECHO \"$(.boost-build-file) attempted to load the build system by invoking\" ;\n",
"ECHO ;\n",
"ECHO \"   'boost-build\" $(dir) \";'\" ;\n",
"ECHO ;\n",
"ECHO \"but we were unable to find \\\"bootstrap.jam\\\" in the specified directory\" ;\n",
"ECHO \"or in BOOST_BUILD_PATH (searching \"$(BOOST_BUILD_PATH:J=\", \")\").\" ;\n",
"ECHO ;\n",
"EXIT \"Please consult the documentation at 'http://www.boost.org'.\" ;\n",
"}\n",
"\n",
"if [ MATCH .*(--debug-configuration).* : $(ARGV) ]\n",
"{\n",
"ECHO \"notice: loading Boost.Build from\"\n",
"[ NORMALIZE_PATH $(.bootstrap-file:D) ] ;\n",
"}\n",
"\n",
"include $(.bootstrap-file) ;\n",
"}\n",
"\n",
"\n",
"{\n",
"\n",
"local search-path = $(BOOST_BUILD_PATH) $(BOOST_ROOT) ;\n",
"local self = [ SELF_PATH ] ;\n",
"local boost-build-relative = ../../share/boost-build ;\n",
"local self-based-path = [ NORMALIZE_PATH $(boost-build-relative:R=$(self)) ] ;\n",
"\n",
"local boost-build-files =\n",
"[ find-to-root [ PWD ] : boost-build.jam ]\n",
"[ GLOB $(self-based-path) : boost-build.jam ]\n",
"[ GLOB $(search-path) : boost-build.jam ] ;\n",
"\n",
".boost-build-file = $(boost-build-files[1]) ;\n",
"\n",
"if ! $(.boost-build-file)\n",
"{\n",
"ECHO \"Unable to load Boost.Build: could not find \\\"boost-build.jam\\\"\" ;\n",
"ECHO --------------------------------------------------------------- ;\n",
"\n",
"if ! [ MATCH .*(bjam).* : $(ARGV[1]:BL) ]\n",
"{\n",
"ECHO \"BOOST_ROOT must be set, either in the environment, or \" ;\n",
"ECHO \"on the command-line with -sBOOST_ROOT=..., to the root\" ;\n",
"ECHO \"of the boost installation.\" ;\n",
"ECHO ;\n",
"}\n",
"\n",
"ECHO \"Attempted search from\" [ PWD ] \"up to the root\" ;\n",
"ECHO \"at\" $(self-based-path) ;\n",
"ECHO \"and in these directories from BOOST_BUILD_PATH and BOOST_ROOT: \"$(search-path:J=\", \")\".\" ;\n",
"EXIT \"Please consult the documentation at 'http://www.boost.org'.\" ;\n",
"}\n",
"\n",
"if [ MATCH .*(--debug-configuration).* : $(ARGV) ]\n",
"{\n",
"ECHO \"notice: found boost-build.jam at\"\n",
"[ NORMALIZE_PATH $(.boost-build-file) ] ;\n",
"}\n",
"\n",
"include $(.boost-build-file) ;\n",
"\n",
"if ! $(.bootstrap-file)\n",
"{\n",
"ECHO \"Unable to load Boost.Build\" ;\n",
"ECHO -------------------------- ;\n",
"ECHO \"\\\"$(.boost-build-file)\\\" was found by searching from\" [ PWD ] \"up to the root\" ;\n",
"ECHO \"and in these directories from BOOST_BUILD_PATH and BOOST_ROOT: \"$(search-path:J=\", \")\".\" ;\n",
"ECHO ;\n",
"ECHO \"However, it failed to call the \\\"boost-build\\\" rule to indicate\" ;\n",
"ECHO \"the location of the build system.\" ;\n",
"ECHO ;\n",
"EXIT \"Please consult the documentation at 'http://www.boost.org'.\" ;\n",
"}\n",
"}\n",
0 };