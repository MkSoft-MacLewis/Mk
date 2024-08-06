/**
*
* @copyright Copyright (C) 2019 RENARD Mathieu. All rights reserved.
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
* @file mk_hid_pool_constants.h
* @brief Déclaration des constantes dédiées aux pools HID.
* @date 26 oct. 2019
*
*/

#ifndef MK_HID_POOL_CONSTANTS_H
#define MK_HID_POOL_CONSTANTS_H

/**
 * @def K_MK_HID_POOL_MAX_ITEM_NUMBER
 * @brief Définition du nombre de structures \ref T_mkHIDItem pouvant être allouées dynamiquement.
 */

#define K_MK_HID_POOL_MAX_ITEM_NUMBER 512

/**
 * @def K_MK_HID_POOL_MAX_REPORT_NUMBER
 * @brief Définition du nombre de structures \ref T_mkHIDReport pouvant être allouées dynamiquement.
 */

#define K_MK_HID_POOL_MAX_REPORT_NUMBER 32

/**
 * @def K_MK_HID_POOL_MAX_LOCAL_TABLE_NUMBER
 * @brief Définition du nombre de structures \ref T_mkHIDLocalTable pouvant être allouées dynamiquement.
 */

#define K_MK_HID_POOL_MAX_LOCAL_TABLE_NUMBER 5

/**
 * @def K_MK_HID_POOL_SIZE
 * @brief Définition de la taille de la pool dédiée à l'allocation dynamique des structures \ref T_mkHIDDevice,
 *        \ref T_mkHIDItem, \ref T_mkHIDReport et \ref T_mkHIDLocalTable.
 */

#define K_MK_HID_POOL_SIZE K_MK_HID_MAX_DEVICE_NUMBER * ( sizeof ( T_mkHIDDevice ) >> 2 ) + \
                           K_MK_HID_POOL_MAX_ITEM_NUMBER  * ( sizeof ( T_mkHIDItem ) >> 2 ) + \
                           K_MK_HID_POOL_MAX_REPORT_NUMBER * ( sizeof ( T_mkHIDReport ) >> 2 ) + \
                           K_MK_HID_POOL_MAX_LOCAL_TABLE_NUMBER * ( sizeof ( T_mkHIDLocalTable ) >> 2 )

/**
 *
 */

#endif


