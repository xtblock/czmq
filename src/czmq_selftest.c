/*  =========================================================================
    czmq_selftest.c - run selftests

    Runs all selftests.

    -------------------------------------------------------------------------
    Copyright (c) the Contributors as noted in the AUTHORS file.       
    This file is part of CZMQ, the high-level C binding for 0MQ:       
    http://czmq.zeromq.org.                                            
                                                                       
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.           

################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
    =========================================================================
*/

#include "czmq_classes.h"

typedef struct {
    const char *testname;
    void (*test) (bool);
} test_item_t;

static test_item_t
all_tests [] = {
// Tests for stable public classes:
    { "zactor", zactor_test },
    { "zarmour", zarmour_test },
    { "zcert", zcert_test },
    { "zcertstore", zcertstore_test },
    { "zchunk", zchunk_test },
    { "zclock", zclock_test },
    { "zconfig", zconfig_test },
    { "zdigest", zdigest_test },
    { "zdir", zdir_test },
    { "zdir_patch", zdir_patch_test },
    { "zfile", zfile_test },
    { "zframe", zframe_test },
    { "zhash", zhash_test },
    { "zhashx", zhashx_test },
    { "ziflist", ziflist_test },
    { "zlist", zlist_test },
    { "zlistx", zlistx_test },
    { "zloop", zloop_test },
    { "zmsg", zmsg_test },
    { "zpoller", zpoller_test },
    { "zsock", zsock_test },
    { "zstr", zstr_test },
    { "zuuid", zuuid_test },
    { "zauth", zauth_test },
    { "zbeacon", zbeacon_test },
    { "zgossip", zgossip_test },
    { "zmonitor", zmonitor_test },
    { "zproxy", zproxy_test },
    { "zrex", zrex_test },
    { "zsys", zsys_test },
#ifdef CZMQ_BUILD_DRAFT_API
// Tests for draft public classes:
    { "zproc", zproc_test },
    { "ztimerset", ztimerset_test },
    { "ztrie", ztrie_test },
#endif // CZMQ_BUILD_DRAFT_API
#ifdef CZMQ_BUILD_DRAFT_API
    { "private_classes", czmq_private_selftest },
#endif // CZMQ_BUILD_DRAFT_API
    {0, 0}          //  Sentinel
};

//  -------------------------------------------------------------------------
//  Test whether a test is available.
//  Return a pointer to a test_item_t if available, NULL otherwise.
//

test_item_t *
test_available (const char *testname)
{
    test_item_t *item;
    for (item = all_tests; item->test; item++) {
        if (streq (testname, item->testname))
            return item;
    }
    return NULL;
}

//  -------------------------------------------------------------------------
//  Run all tests.
//

static void
test_runall (bool verbose)
{
    test_item_t *item;
    printf ("Running czmq selftests...\n");
    for (item = all_tests; item->test; item++)
        item->test (verbose);

    printf ("Tests passed OK\n");
}

int
main (int argc, char **argv)
{
    bool verbose = false;
    test_item_t *test = 0;
    int argn;
    for (argn = 1; argn < argc; argn++) {
        if (streq (argv [argn], "--help")
        ||  streq (argv [argn], "-h")) {
            puts ("czmq_selftest.c [options] ...");
            puts ("  --verbose / -v         verbose test output");
            puts ("  --number / -n          report number of tests");
            puts ("  --list / -l            list all tests");
            puts ("  --test / -t [name]     run only test 'name'");
            puts ("  --continue / -c        continue on exception (on Windows)");
            return 0;
        }
        if (streq (argv [argn], "--verbose")
        ||  streq (argv [argn], "-v"))
            verbose = true;
        else
        if (streq (argv [argn], "--number")
        ||  streq (argv [argn], "-n")) {
            puts ("34");
            return 0;
        }
        else
        if (streq (argv [argn], "--list")
        ||  streq (argv [argn], "-l")) {
            puts ("Available tests:");
            puts ("    zactor\t\t- stable");
            puts ("    zarmour\t\t- stable");
            puts ("    zcert\t\t- stable");
            puts ("    zcertstore\t\t- stable");
            puts ("    zchunk\t\t- stable");
            puts ("    zclock\t\t- stable");
            puts ("    zconfig\t\t- stable");
            puts ("    zdigest\t\t- stable");
            puts ("    zdir\t\t- stable");
            puts ("    zdir_patch\t\t- stable");
            puts ("    zfile\t\t- stable");
            puts ("    zframe\t\t- stable");
            puts ("    zhash\t\t- stable");
            puts ("    zhashx\t\t- stable");
            puts ("    ziflist\t\t- stable");
            puts ("    zlist\t\t- stable");
            puts ("    zlistx\t\t- stable");
            puts ("    zloop\t\t- stable");
            puts ("    zmsg\t\t- stable");
            puts ("    zpoller\t\t- stable");
            puts ("    zproc\t\t- draft");
            puts ("    zsock\t\t- stable");
            puts ("    zstr\t\t- stable");
            puts ("    ztimerset\t\t- draft");
            puts ("    ztrie\t\t- draft");
            puts ("    zuuid\t\t- stable");
            puts ("    zauth\t\t- stable");
            puts ("    zbeacon\t\t- stable");
            puts ("    zgossip\t\t- stable");
            puts ("    zmonitor\t\t- stable");
            puts ("    zproxy\t\t- stable");
            puts ("    zrex\t\t- stable");
            puts ("    zsys\t\t- stable");
            puts ("    private_classes\t- draft");
            return 0;
        }
        else
        if (streq (argv [argn], "--test")
        ||  streq (argv [argn], "-t")) {
            argn++;
            if (argn >= argc) {
                fprintf (stderr, "--test needs an argument\n");
                return 1;
            }
            test = test_available (argv [argn]);
            if (!test) {
                fprintf (stderr, "%s not valid, use --list to show tests\n", argv [argn]);
                return 1;
            }
        }
        else
        if (streq (argv [argn], "--continue")
        ||  streq (argv [argn], "-c")) {
#ifdef _MSC_VER
            //  When receiving an abort signal, only print to stderr (no dialog)
            _set_abort_behavior (0, _WRITE_ABORT_MSG);
#endif
        }
        else {
            printf ("Unknown option: %s\n", argv [argn]);
            return 1;
        }
    }

    #ifdef NDEBUG
        printf(" !!! 'assert' macro is disabled, remove NDEBUG from your compilation definitions.\n");
        printf(" tests will be meaningless.\n");
    #endif //

    if (test) {
        printf ("Running czmq test '%s'...\n", test->testname);
        test->test (verbose);
    }
    else
        test_runall (verbose);

    return 0;
}
/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/
