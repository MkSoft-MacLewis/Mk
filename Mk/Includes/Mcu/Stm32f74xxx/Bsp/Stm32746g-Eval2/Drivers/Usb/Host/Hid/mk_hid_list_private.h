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
* @file mk_hid_list_private.h
* @brief Déclaration des fonctions dédiées aux listes HID.
* @date 20 oct. 2019
*
*/

#ifndef MK_HID_LIST_PRIVATE_H
#define MK_HID_LIST_PRIVATE_H

/**
 * @fn T_mkCode mk_hid_add ( T_mkHIDList* p_list, T_mkHIDDevice* p_device );
 * @brief Cette fonction ajoute un périphérique de type \ref T_mkHIDDevice dans une liste de périphérique MSC. Le périphérique est ajouté en
 *        tête de liste.
 *
 * @param[in, out] p_list   Ce paramètre contient l'adresse d'une liste de type \ref T_mkHIDList.
 * @param[in]      p_device Ce paramètre contient l'adresse d'un périphérique de type \ref T_mkHIDDevice.
 *
 * @return Cette fonction retourne une des valeurs suivantes :
 *         \li \ref K_MK_OK          : le périphérique a été ajouté dans la liste chainée.
 *         \li \ref K_MK_ERROR_PARAM : le périphérique n'a pas été ajouté dans la liste chainée car au moins un paramètre est invalide.
 */

T_mkCode mk_hid_add ( T_mkHIDList* p_list, T_mkHIDDevice* p_device );

/**
 * @fn T_mkCode mk_hid_remove ( T_mkHIDList* p_list, T_mkHIDDevice* p_device );
 * @brief Cette fonction supprime un périphérique de la liste des périphériques HID.
 *
 * @param[in, out] p_list   Ce paramètre contient l'adresse d'une liste de type \ref T_mkHIDList.
 * @param[in]      p_device Ce paramètre contient l'adresse d'un périphérique de type \ref T_mkHIDDevice. Le périphérique doit être présent dans
 *                          la liste.
 *
 * @return Cette fonction retourne une des valeurs suivantes :
 *         \li \ref K_MK_OK          : le périphérique a été supprimé de la liste chainée.
 *         \li \ref K_MK_ERROR_PARAM : le périphérique n'a pas été supprimé de la liste chainée car au moins un paramètre est invalide.
 */

T_mkCode mk_hid_remove ( T_mkHIDList* p_list, T_mkHIDDevice* p_device );

/**
 *
 */

#endif

