/*
 * This file is part of GStreamer Daemon
 * Copyright 2015-2022 Ridgerun, LLC (http://www.ridgerun.com)
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * 1. Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#include <gst/check/gstcheck.h>

#include "gstd_session.h"

const gchar *target_node[] = {
  "/pipelines/p0",
  "/pipelines/p0/elements",
  "/pipelines/p0/elements/fakesrc0",
  "/pipelines/p0/elements/fakesrc0/properties",
  "/pipelines/p0/elements/fakesrc0/properties/format",
  "/pipelines/p0/bus",
  "/pipelines/p0/bus/timeout",
  "/pipelines/p0/bus/types",
  "/pipelines/p0/name",
  "/pipelines/p0/description",
  "/pipelines/p0/state",
  "/pipelines/count",
  "/debug",
  "/debug/name",
  "/debug/enable",
  "/debug/color",
  "/debug/threshold",
  "/debug/flags"
};

GST_START_TEST (test_no_create)
{
  GstdObject *node;
  GstdReturnCode ret;
  GstdSession *test_session = gstd_session_new ("Test_session");
  gint i;

  /* Create pipeline to test no create cases */
  ret = gstd_get_by_uri (test_session, "/pipelines", &node);
  fail_if (ret);
  fail_if (NULL == node);

  ret = gstd_object_create (node, "p0", "fakesrc ! fakesink");
  fail_if (ret);
  gst_object_unref (node);

  /* Tests */
  for (i = 0; i < sizeof (target_node) / sizeof (target_node[0]); i++) {
    ret = gstd_get_by_uri (test_session, target_node[i], &node);
    fail_if (ret);
    fail_if (NULL == node);

    ret = gstd_object_create (node, NULL, NULL);
    fail_if (GSTD_NO_CREATE != ret);
    gst_object_unref (node);
  }

  gst_object_unref (test_session);
}

GST_END_TEST;

static Suite *
gstd_no_create_suite (void)
{
  Suite *suite = suite_create ("gstd_no_create");
  TCase *tc = tcase_create ("general");

  suite_add_tcase (suite, tc);
  tcase_add_test (tc, test_no_create);

  return suite;
}

GST_CHECK_MAIN (gstd_no_create);
