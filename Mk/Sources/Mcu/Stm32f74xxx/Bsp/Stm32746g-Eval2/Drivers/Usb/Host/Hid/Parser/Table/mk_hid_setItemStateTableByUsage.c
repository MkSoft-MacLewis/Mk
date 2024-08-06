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
* @file mk_hid_setItemStateTableByUsage.c
* @brief Définition de la fonction mk_hid_setItemStateTableByUsage.
* @date 2 nov. 2019
*
*/

#include "mk_hid_api.h"


/**
 * @internal
 * @brief
 * @endinternal
 */

T_mkCode mk_hid_setItemStateTableByUsage ( T_mkHIDReportStack* p_stack, T_mkHIDReportTable* p_table, T_mkHIDUsage* p_usage )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result = K_MK_OK;

   /* Déclaration d'un pointeur d'item */
   T_mkHIDItem* l_item;

   /* Si les paramètres sont valides */
   if ( ( p_stack != K_MK_NULL ) && ( p_table != K_MK_NULL ) && ( p_usage != K_MK_NULL ) )
   {
      /* Configuration de la valeur initiale de l'item */
      l_item = p_usage->first;

      /* Tant que des items relatifs aux collections sont rencontrés */
      while ( ( ( l_item->head.field.tag == K_MK_HID_ITEM_TAG_COLLECTION ) || ( l_item->head.field.tag == K_MK_HID_ITEM_TAG_END_COLLECTION ) ) &&
              ( l_item != p_usage->last->nextItem ) )
      {
         /* Bypass du premier item */
         l_item = l_item->nextItem;
      }

      /* Tant qu'un item de type 'Main' n'est pas rencontré (Collection, Endcollection ou Input, Output et Feature) */
      /* Le dernier Item est forcément un item de type de type 'Main'. */
      while ( ( l_result == K_MK_OK ) &&
              ( l_item->head.field.tag != K_MK_HID_ITEM_TAG_COLLECTION ) && ( l_item->head.field.tag != K_MK_HID_ITEM_TAG_END_COLLECTION ) &&
              ( l_item != p_usage->last->nextItem ) )
      {
         /* Actualisation de la table d'item */
         l_result = mk_hid_setItemStateTable ( p_stack, p_table, l_item );

         /* Actualisation de l'item courant */
         l_item = l_item->nextItem;
      }
   }

   /* Sinon */
   else
   {
      /* Actualisation de la variable de retour */
      l_result = K_MK_ERROR_PARAM;
   }

   /* Retour */
   return ( l_result );
}



