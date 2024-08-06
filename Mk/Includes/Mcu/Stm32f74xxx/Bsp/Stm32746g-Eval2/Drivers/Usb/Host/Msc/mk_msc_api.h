/**
*
* @copyright Copyright (C) 2024 RENARD Mathieu. All rights reserved.
*
* This file is part of Mk.
*
* Mk is free software. Redistribution and use in source and binary forms, with or
* without modification, are permitted provided that the following conditions are
* met:
*
*    1. Redistributions of source code must retain the above copyright notice,
*       this list of conditions and the following disclaimer.
*    2. Redistributions in binary form must reproduce the above copyright notice,
*       this list of conditions and the following disclaimer in the documentation
*       and/or other materials provided with the distribution.
*    3. Neither the name of the copyright holder nor the names of its contributors
*       may be used to endorse or promote products derived from this software
*       without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
* ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
* @file mk_msc_api.h
* @brief Ce fichier contient les directives 'include' utilisées.
* @date 23 mars 2024
*
*/

#ifndef MK_MSC_API_H
#define MK_MSC_API_H

/**
 *
 */

#include "mk_types.h"
#include "mk_binary.h"
#include "mk_peripheral_usb_constants.h"

/**
 *
 */

#include "mk_constants.h"
#include "mk_sync_types.h"
#include "mk_pool_constants.h"
#include "mk_pool_types.h"
#include "mk_task_constants.h"
#include "mk_task_types.h"
#include "mk_task.h"
#include "mk_pool.h"
#include "mk_list_types.h"
#include "mk_event_constants.h"
#include "mk_event_types.h"
#include "mk_event.h"
#include "mk_mutex_types.h"
#include "mk_semaphore_types.h"
#include "mk_semaphore.h"
#include "mk_mail_constants.h"
#include "mk_mail_types.h"
#include "mk_mail.h"
#include "mk_callback_constants.h"
#include "mk_callback_types.h"
#include "mk_callback_private.h"
#include "mk_memory_constants.h"
#include "mk_kernel.h"

/**
 *
 */

#include "mk_file_constants.h"
#include "mk_volume_constants.h"
#include "mk_volume_types.h"
#include "mk_disk_constants.h"
#include "mk_disk_types.h"
#include "mk_disk_request_constants.h"
#include "mk_disk_request_types.h"
#include "mk_disk_private.h"
#include "mk_disk_pool_constants.h"
#include "mk_disk_pool_types.h"
#include "mk_disk_data.h"
#include "mk_volume_private.h"

/**
 *
 */

#include "mk_usb_constants.h"
#include "mk_hcd_class_types.h"
#include "mk_hcd_constants.h"
#include "mk_hcd_hub_types.h"
#include "mk_hcd_device_types.h"
#include "mk_hcd_list_types.h"
#include "mk_hcd_list_private.h"
#include "mk_hcd_pipe_constants.h"
#include "mk_hcd_pipe_types.h"
#include "mk_hcd_request_types.h"
#include "mk_hcd_request_private.h"
#include "mk_hcd_types.h"
#include "mk_hcd_pipe_private.h"
#include "mk_hcd_device_private.h"
#include "mk_hcd_utils_private.h"

/**
 *
 */

#include "mk_display_events_types.h"
#include "mk_termio_constants.h"
#include "mk_termio_types.h"
#include "mk_termio_data.h"
#include "mk_termio_private.h"
#include "mk_termio.h"

/**
 *
 */

#include "mk_utils_string.h"
#include "mk_utils_utf.h"
#include "mk_utils.h"

/**
 *
 */

#include "mk_msc_constants.h"
#include "mk_msc_class_types.h"
#include "mk_msc_device_types.h"
#include "mk_msc_list_types.h"
#include "mk_msc_pool_constants.h"
#include "mk_msc_pool_types.h"
#include "mk_msc_types.h"
#include "mk_msc_request_types.h"
#include "mk_msc_wrapper_constants.h"
#include "mk_msc_wrapper_types.h"
#include "mk_msc_wrapper_private.h"
#include "mk_msc_scsi_types.h"
#include "mk_msc_scsi_private.h"
#include "mk_msc_device_private.h"
#include "mk_msc_utils_types.h"
#include "mk_msc_utils_private.h"
#include "mk_msc_data.h"
#include "mk_msc_request_private.h"
#include "mk_msc_list_private.h"
#include "mk_msc_disk_constants.h"
#include "mk_msc_disk_private.h"
#include "mk_msc_private.h"
#include "mk_msc.h"

/**
 *
 */

#endif

