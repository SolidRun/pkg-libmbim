/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 * libmbim-glib -- GLib/GIO based library to control MBIM devices
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 * Copyright (C) 2013 Aleksander Morgado <aleksander@gnu.org>
 */

#ifndef _LIBMBIM_GLIB_MBIM_UUID_H_
#define _LIBMBIM_GLIB_MBIM_UUID_H_

#if !defined (__LIBMBIM_GLIB_H_INSIDE__) && !defined (LIBMBIM_GLIB_COMPILATION)
#error "Only <libmbim-glib.h> can be included directly."
#endif

#include <glib.h>

G_BEGIN_DECLS

/*****************************************************************************/

/**
 * MbimUuid:
 *
 * A UUID as defined in MBIM.
 */
typedef struct _MbimUuid MbimUuid;
#define MBIM_PACKED __attribute__((__packed__))
struct MBIM_PACKED _MbimUuid {
    guint8 a[4];
    guint8 b[2];
    guint8 c[2];
    guint8 d[2];
    guint8 e[6];
};
#undef MBIM_PACKED

gboolean  mbim_uuid_cmp            (const MbimUuid *a,
                                    const MbimUuid *b);
gchar    *mbim_uuid_get_printable  (const MbimUuid *uuid);
gboolean  mbim_uuid_from_printable (const gchar *str,
                                    MbimUuid    *uuid);

/*****************************************************************************/

/**
 * MbimService:
 * @MBIM_SERVICE_INVALID: Invalid service.
 * @MBIM_SERVICE_BASIC_CONNECT: Basic connectivity service.
 * @MBIM_SERVICE_SMS: SMS messaging service.
 * @MBIM_SERVICE_USSD: USSD service.
 * @MBIM_SERVICE_PHONEBOOK: Phonebook service.
 * @MBIM_SERVICE_STK: SIM toolkit service.
 * @MBIM_SERVICE_AUTH: Authentication service.
 * @MBIM_SERVICE_DSS: Device Service Stream service.
 * @MBIM_SERVICE_MS_FIRMWARE_ID: Microsoft Firmware ID service.
 * @MBIM_SERVICE_MS_HOST_SHUTDOWN: Microsoft Host Shutdown service.
 *
 * Enumeration of the generic MBIM services.
 */
typedef enum {
    MBIM_SERVICE_INVALID          = 0,
    MBIM_SERVICE_BASIC_CONNECT    = 1,
    MBIM_SERVICE_SMS              = 2,
    MBIM_SERVICE_USSD             = 3,
    MBIM_SERVICE_PHONEBOOK        = 4,
    MBIM_SERVICE_STK              = 5,
    MBIM_SERVICE_AUTH             = 6,
    MBIM_SERVICE_DSS              = 7,
    MBIM_SERVICE_MS_FIRMWARE_ID   = 8,
    MBIM_SERVICE_MS_HOST_SHUTDOWN = 9,
} MbimService;

/**
 * MBIM_UUID_INVALID:
 *
 * Get the UUID of the %MBIM_SERVICE_INVALID service.
 *
 * Returns: (transfer none): a #MbimUuid.
 */
#define MBIM_UUID_INVALID mbim_uuid_from_service (MBIM_SERVICE_INVALID)

/**
 * MBIM_UUID_BASIC_CONNECT:
 *
 * Get the UUID of the %MBIM_SERVICE_BASIC_CONNECT service.
 *
 * Returns: (transfer none): a #MbimUuid.
 */
#define MBIM_UUID_BASIC_CONNECT mbim_uuid_from_service (MBIM_SERVICE_BASIC_CONNECT)

/**
 * MBIM_UUID_SMS:
 *
 * Get the UUID of the %MBIM_SERVICE_SMS service.
 *
 * Returns: (transfer none): a #MbimUuid.
 */
#define MBIM_UUID_SMS mbim_uuid_from_service (MBIM_SERVICE_SMS)

/**
 * MBIM_UUID_USSD:
 *
 * Get the UUID of the %MBIM_SERVICE_USSD service.
 *
 * Returns: (transfer none): a #MbimUuid.
 */
#define MBIM_UUID_USSD mbim_uuid_from_service (MBIM_SERVICE_USSD)

/**
 * MBIM_UUID_PHONEBOOK:
 *
 * Get the UUID of the %MBIM_SERVICE_PHONEBOOK service.
 *
 * Returns: (transfer none): a #MbimUuid.
 */
#define MBIM_UUID_PHONEBOOK mbim_uuid_from_service (MBIM_SERVICE_PHONEBOOK)

/**
 * MBIM_UUID_STK:
 *
 * Get the UUID of the %MBIM_SERVICE_STK service.
 *
 * Returns: (transfer none): a #MbimUuid.
 */
#define MBIM_UUID_STK mbim_uuid_from_service (MBIM_SERVICE_STK)

/**
 * MBIM_UUID_AUTH:
 *
 * Get the UUID of the %MBIM_SERVICE_AUTH service.
 *
 * Returns: (transfer none): a #MbimUuid.
 */
#define MBIM_UUID_AUTH mbim_uuid_from_service (MBIM_SERVICE_AUTH)

/**
 * MBIM_UUID_DSS:
 *
 * Get the UUID of the %MBIM_SERVICE_DSS service.
 *
 * Returns: (transfer none): a #MbimUuid.
 */
#define MBIM_UUID_DSS mbim_uuid_from_service (MBIM_SERVICE_DSS)

/**
 * MBIM_UUID_MS_FIRMWARE_ID:
 *
 * Get the UUID of the %MBIM_SERVICE_MS_FIRMWARE_ID service.
 *
 * Returns: (transfer none): a #MbimUuid.
 */
#define MBIM_UUID_MS_FIRMWARE_ID mbim_uuid_from_service (MBIM_SERVICE_MS_FIRMWARE_ID)

/**
 * MBIM_UUID_MS_HOST_SHUTDOWN:
 *
 * Get the UUID of the %MBIM_SERVICE_MS_HOST_SHUTDOWN service.
 *
 * Returns: (transfer none): a #MbimUuid.
 */
#define MBIM_UUID_MS_HOST_SHUTDOWN mbim_uuid_from_service (MBIM_SERVICE_MS_HOST_SHUTDOWN)

/* To/From service */
const MbimUuid *mbim_uuid_from_service  (MbimService     service);
MbimService     mbim_uuid_to_service    (const MbimUuid *uuid);

/*****************************************************************************/

/**
 * MbimContextType:
 * @MBIM_CONTEXT_TYPE_INVALID: Invalid context type.
 * @MBIM_CONTEXT_TYPE_NONE: Context not yet provisioned.
 * @MBIM_CONTEXT_TYPE_INTERNET: Connection to the Internet.
 * @MBIM_CONTEXT_TYPE_VPN: Connection to a VPN.
 * @MBIM_CONTEXT_TYPE_VOICE: Connection to a VoIP service.
 * @MBIM_CONTEXT_TYPE_VIDEO_SHARE: Connection to a video sharing service.
 * @MBIM_CONTEXT_TYPE_PURCHASE: Connection to an over-the-air activation site.
 * @MBIM_CONTEXT_TYPE_IMS: Connection to IMS.
 * @MBIM_CONTEXT_TYPE_MMS: Connection to MMS.
 * @MBIM_CONTEXT_TYPE_LOCAL: A local.
 *
 * Enumeration of the generic MBIM context types.
 */
typedef enum {
    MBIM_CONTEXT_TYPE_INVALID     = 0,
    MBIM_CONTEXT_TYPE_NONE        = 1,
    MBIM_CONTEXT_TYPE_INTERNET    = 2,
    MBIM_CONTEXT_TYPE_VPN         = 3,
    MBIM_CONTEXT_TYPE_VOICE       = 4,
    MBIM_CONTEXT_TYPE_VIDEO_SHARE = 5,
    MBIM_CONTEXT_TYPE_PURCHASE    = 6,
    MBIM_CONTEXT_TYPE_IMS         = 7,
    MBIM_CONTEXT_TYPE_MMS         = 8,
    MBIM_CONTEXT_TYPE_LOCAL       = 9,
} MbimContextType;

/* To/From context type */
const MbimUuid  *mbim_uuid_from_context_type (MbimContextType  context_type);
MbimContextType  mbim_uuid_to_context_type   (const MbimUuid  *uuid);

G_END_DECLS

#endif /* _LIBMBIM_GLIB_MBIM_UUID_H_ */
