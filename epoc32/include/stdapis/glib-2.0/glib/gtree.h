/* GLIB - Library of useful routines for C programming
 * Copyright (C) 1995-1997  Peter Mattis, Spencer Kimball and Josh MacDonald
 * Portions copyright (c) 2006 Nokia Corporation.  All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

/*
 * Modified by the GLib Team and others 1997-2000.  See the AUTHORS
 * file for a list of people on the GLib Team.  See the ChangeLog
 * files for a list of changes.  These files are distributed with
 * GLib at ftp://ftp.gtk.org/pub/gtk/. 
 */

#ifndef __G_TREE_H__
#define __G_TREE_H__

#include <_ansi.h>
#include <glib/gnode.h>

G_BEGIN_DECLS

typedef struct _GTree  GTree;

typedef gboolean (*GTraverseFunc) (gpointer  key,
                                   gpointer  value,
                                   gpointer  data);

/* Balanced binary trees
 */
IMPORT_C GTree*   g_tree_new             (GCompareFunc      key_compare_func);
IMPORT_C GTree*   g_tree_new_with_data   (GCompareDataFunc  key_compare_func,
                                 gpointer          key_compare_data);
IMPORT_C GTree*   g_tree_new_full        (GCompareDataFunc  key_compare_func,
                                 gpointer          key_compare_data,
                                 GDestroyNotify    key_destroy_func,
                                 GDestroyNotify    value_destroy_func);
IMPORT_C void     g_tree_destroy         (GTree            *tree);
IMPORT_C void     g_tree_insert          (GTree            *tree,
                                 gpointer          key,
                                 gpointer          value);
IMPORT_C void     g_tree_replace         (GTree            *tree,
                                 gpointer          key,
                                 gpointer          value);
IMPORT_C gboolean g_tree_remove          (GTree            *tree,
                                 gconstpointer     key);
IMPORT_C gboolean g_tree_steal           (GTree            *tree,
                                 gconstpointer     key);
IMPORT_C gpointer g_tree_lookup          (GTree            *tree,
                                 gconstpointer     key);
IMPORT_C gboolean g_tree_lookup_extended (GTree            *tree,
                                 gconstpointer     lookup_key,
                                 gpointer         *orig_key,
                                 gpointer         *value);
IMPORT_C void     g_tree_foreach         (GTree            *tree,
                                 GTraverseFunc	   func,
                                 gpointer	   user_data);

#ifndef G_DISABLE_DEPRECATED
IMPORT_C void     g_tree_traverse        (GTree            *tree,
                                 GTraverseFunc     traverse_func,
                                 GTraverseType     traverse_type,
                                 gpointer          user_data);
#endif /* G_DISABLE_DEPRECATED */

IMPORT_C gpointer g_tree_search          (GTree            *tree,
                                 GCompareFunc      search_func,
                                 gconstpointer     user_data);
IMPORT_C gint     g_tree_height          (GTree            *tree);
IMPORT_C gint     g_tree_nnodes          (GTree            *tree);



G_END_DECLS

#endif /* __G_TREE_H__ */

