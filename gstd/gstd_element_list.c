/*
 * Gstreamer Daemon - Gst Launch under steroids
 * Copyright (C) 2015 RidgeRun Engineering <support@ridgerun.com>
 *
 * This file is part of Gstd.
 *
 * Gstd is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Gstd is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Gstd.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "gstd_element_list.h"
#include "gstd_list.h"
#include "gstd_list_reader.h"

/* Gstd Core debugging category */
GST_DEBUG_CATEGORY_STATIC (gstd_element_list_debug);
#define GST_CAT_DEFAULT gstd_element_list_debug

#define GSTD_DEBUG_DEFAULT_LEVEL GST_LEVEL_INFO

/* VTable */

/**
 * GstdElementList:
 * A wrapper for the conventional element_list
 */
struct _GstdElementList
{
  GstdList parent;
};

struct _GstdElementListClass
{
  GstdListClass parent_class;
};

G_DEFINE_TYPE (GstdElementList, gstd_element_list, GSTD_TYPE_LIST);

static void
gstd_element_list_class_init (GstdElementListClass * klass)
{
  guint debug_color;

  /* Initialize debug category with nice colors */
  debug_color = GST_DEBUG_FG_BLACK | GST_DEBUG_BOLD | GST_DEBUG_BG_WHITE;
  GST_DEBUG_CATEGORY_INIT (gstd_element_list_debug, "gstd_element_list",
      debug_color, "Gstd Element List category");
}

static void
gstd_element_list_init (GstdElementList * self)
{
  gstd_object_set_reader (GSTD_OBJECT(self),
      g_object_new (GSTD_TYPE_LIST_READER, NULL));
}

GstdReturnCode
gstd_element_list_append (GstdElementList * self, GstdElement * element)
{
  GstdList *gstdlist;

  g_return_val_if_fail (GSTD_IS_ELEMENT_LIST (self), GSTD_NULL_ARGUMENT);
  g_return_val_if_fail (GSTD_IS_ELEMENT (element), GSTD_NULL_ARGUMENT);

  gstdlist = GSTD_LIST (self);

  gstdlist->list = g_list_append (gstdlist->list, element);
  gstdlist->count++;

  return GSTD_EOK;
}
