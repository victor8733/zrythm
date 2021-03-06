/*
 * Copyright (C) 2019 Alexandros Theodotou <alex at zrythm dot org>
 *
 * This file is part of Zrythm
 *
 * Zrythm is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Zrythm is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef __GUI_WIDGETS_PORT_CONNECTIONS_POPOVER_H__
#define __GUI_WIDGETS_PORT_CONNECTIONS_POPOVER_H__


#include <gtk/gtk.h>

#define PORT_CONNECTIONS_POPOVER_WIDGET_TYPE \
  (port_connections_popover_widget_get_type ())
G_DECLARE_FINAL_TYPE (
  PortConnectionsPopoverWidget,
  port_connections_popover_widget,
  Z, PORT_CONNECTIONS_POPOVER_WIDGET,
  GtkPopover)

typedef struct _InspectorPortWidget
  InspectorPortWidget;

typedef struct _PortConnectionsPopoverWidget
{
  GtkPopover              parent_instance;

  /** The owner button. */
  InspectorPortWidget * owner;

  /** The main vertical box containing everything. */
  GtkBox *         main_box;

  /** Title to show at the top, e.g. "INPUTS". */
  GtkLabel *       title;

  /** Box containing the ports. */
  GtkBox *         ports_box;

  /** Button to add connection. */
  GtkButton *      add;
} PortConnectionsPopoverWidget;

/**
 * Creates the popover.
 */
PortConnectionsPopoverWidget *
port_connections_popover_widget_new (
  InspectorPortWidget * owner);

/**
 * Refreshes the popover.
 *
 * Removes all children of ports_box and readds them
 * based on the current connections.
 */
void
port_connections_popover_widget_refresh (
  PortConnectionsPopoverWidget * self);

#endif
