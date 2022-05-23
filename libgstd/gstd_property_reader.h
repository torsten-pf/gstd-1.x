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

#ifndef __GSTD_PROPERTY_READER_H__
#define __GSTD_PROPERTY_READER_H__

#include <gst/gst.h>

#include "gstd_ireader.h"

G_BEGIN_DECLS
/*
 * Type declaration.
 */
#define GSTD_TYPE_PROPERTY_READER \
  (gstd_property_reader_get_type())
#define GSTD_PROPERTY_READER(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj),GSTD_TYPE_PROPERTY_READER,GstdPropertyReader))
#define GSTD_PROPERTY_READER_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST((klass),GSTD_TYPE_PROPERTY_READER,GstdPropertyReaderClass))
#define GSTD_IS_PROPERTY_READER(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj),GSTD_TYPE_PROPERTY_READER))
#define GSTD_IS_PROPERTY_READER_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE((klass),GSTD_TYPE_PROPERTY_READER))
#define GSTD_PROPERTY_READER_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_CLASS ((obj), GSTD_TYPE_PROPERTY_READER, GstdPropertyReaderClass))
typedef struct _GstdPropertyReader GstdPropertyReader;

GType gstd_property_reader_get_type (void);

typedef struct _GstdPropertyReaderClass GstdPropertyReaderClass;

/**
 * GstdPropertyReader:
 * A wrapper for the conventional property_reader
 */
struct _GstdPropertyReader
{
  GObject parent;
};

struct _GstdPropertyReaderClass
{
  GObjectClass parent_class;
};

G_END_DECLS
#endif // __GSTD_PROPERTY_READER_H__
