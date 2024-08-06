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
* @file mk_hid_routeMouse.c
* @brief Définition de la fonction mk_hid_routeMouse.
* @date 2 nov. 2019
*
*/

#include "mk_hid_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

static T_mkCode mk_hid_routeButtonMouse ( T_mkMouse* p_mouse, T_mkHIDReportTable* p_table, T_mkHIDUsage* p_usage, uint32_t p_buttonNumber )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result = K_MK_OK;

   /* Déclaration d'un pointeur de bouton */
   T_mkButton** l_button;

   /* Si l'usage est codé au maximum sur 32 bits */
   if ( p_table->global.reportSize <= K_MK_HID_MAX_USAGE_SIZE )
   {
      /* Création d'une table de boutons (la taille de destination est configurée dans cette fonction) */
      l_result = mk_hid_button_create ( p_table, p_usage, p_buttonNumber );

      /* Si aucune erreur ne s'est produite */
      if ( l_result == K_MK_OK )
      {
         /* Récupération de l'adresse du dernier bouton présent dans la chaine */
         l_button = mk_hid_button_getLast ( &p_mouse->button );

         /* Enregistrement de l'adresse mémoire de l'usage */
         ( *l_button ) = p_usage->first->addr;
      }

      /* Sinon */
      else
      {
         /* Ne rien faire */
         /* Une erreur grave s'est produite, il n'est pas nécessaire d'actualiser la variable d'état permettant de gérer */
         /* les usages alternatifs */
      }
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
      /* La taille de l'usage est incompatible avec le driver, il n'est pas nécessaire d'actualiser la variable d'état permettant de gérer */
      /* les usages alternatifs car ils possèdent tous la même taille. */
   }

   /* Retour */
   return ( l_result );
}

/**
 * @internal
 * @brief
 * @endinternal
 */

static T_mkCode mk_hid_routeGenericDesktopPageUsageToMouse ( T_mkMouse* p_mouse, T_mkHIDReportTable* p_table, T_mkHIDUsage* p_usage, uint32_t p_usageID, uint32_t* p_usageUsed )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result = K_MK_OK;

   /* Si l'usage est codé au maximum sur 32 bits */
   if ( p_table->global.reportSize <= K_MK_HID_MAX_USAGE_SIZE )
   {
      /* Si usage de type 'x' */
      if ( p_usageID == K_MK_HID_GENERIC_DESKTOP_PAGE_X )
      {
         /* Enregistrement de l'adresse mémoire de l'usage */
         l_result = mk_hid_setUsageAddr ( p_usage, &p_mouse->axis.dx, K_MK_HID_MAX_USAGE_SIZE );
      }

      /* Sinon si usage de type 'y' */
      else if ( p_usageID == K_MK_HID_GENERIC_DESKTOP_PAGE_Y )
      {
         /* Enregistrement de l'adresse mémoire de l'usage */
         l_result = mk_hid_setUsageAddr ( p_usage, &p_mouse->axis.dy, K_MK_HID_MAX_USAGE_SIZE );
      }

      /* Sinon si usage de type 'wheel' */
      else if ( p_usageID == K_MK_HID_GENERIC_DESKTOP_PAGE_WHEEL )
      {
         /* Enregistrement de l'adresse mémoire de l'usage */
         l_result = mk_hid_setUsageAddr ( p_usage, &p_mouse->wheel.delta, K_MK_HID_MAX_USAGE_SIZE );
      }

      /* Sinon si usage de type 'wheel' */
      else if ( p_usageID == K_MK_HID_GENERIC_DESKTOP_PAGE_POINTER )
      {
         /* Configuration de la valeur invalide, aucune donnée n'est associé à un pointeur */
         l_result = mk_hid_setUsageAddr ( p_usage, K_MK_INVALID_HANDLE, 0 );
      }

      /* Sinon */
      else
      {
         /* L'usage courant (alternatif ou principal) n'est pas utilisé */
         /* On bascule la variable pour continuer l'analyse des usages alternatifs */
         ( *p_usageUsed ) = 0;
      }
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
      /* La taille de l'usage est incompatible avec le driver, il n'est pas nécessaire d'actualiser la variable d'état permettant de gérer */
      /* les usages alternatifs car ils possèdent tous la même taille. */
   }

   /* Retour */
   return ( l_result );
}

/**
 * @internal
 * @brief
 * @endinternal
 */

static T_mkCode mk_hid_routeConsumerUsageToMouse ( T_mkMouse* p_mouse, T_mkHIDReportTable* p_table, T_mkHIDUsage* p_usage, uint32_t p_usageID, uint32_t* p_usageUsed )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result = K_MK_OK;

   /* Si l'usage est de type 'ACPan' */
   if ( p_usageID == K_MK_HID_CONSUMER_PAGE_AC_PAN )
   {
      /* Si l'usage est codé au maximum sur 32 bits */
      if ( p_table->global.reportSize <= K_MK_HID_MAX_USAGE_SIZE )
      {
         /* Enregistrement de l'adresse mémoire de l'usage */
         l_result = mk_hid_setUsageAddr ( p_usage, &p_mouse->acPan.delta, K_MK_HID_MAX_USAGE_SIZE );
      }

      /* Sinon */
      else
      {
         /* Ne rien faire */
         /* La taille de l'usage est incompatible avec le driver, il n'est pas nécessaire d'actualiser la variable d'état permettant de gérer */
         /* les usages alternatifs car ils possèdent tous la même taille. */
      }
   }

   /* Sinon */
   else
   {
      /* L'usage courant (alternatif ou principal) n'est pas utilisé */
      /* On bascule la variable pour continuer l'analyse des usages alternatifs */
      ( *p_usageUsed ) = 0;
   }

   /* Retour */
   return ( l_result );
}

/**
 * @internal
 * @brief
 * @endinternal
 */

T_mkCode mk_hid_routeMouse ( T_mkHIDReportTable* p_table, T_mkHIDReport* p_report, T_mkHIDUsage* p_usage, uint32_t p_page, uint32_t* p_usageUsed )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result = K_MK_OK;

   /* Déclaration d'une souris */
   T_mkMouse* l_mouse;

   /* Déclaration d'une variable stockant l'identifiant de l'usage */
   uint32_t l_usageId;

   /* Déclaration d'une variable de travail */
   uint32_t l_counter;

   /* Si les paramètres sont valides */
   if ( ( p_table != K_MK_NULL ) && ( p_report != K_MK_NULL ) && ( p_usage != K_MK_NULL ) && ( p_usageUsed != K_MK_NULL ) )
   {
      /* Récupération de l'adresse de la souris */
      l_mouse = p_report->addr;

      /* Actualisation de la variable d'état */
      /* Cette variable permet de savoir si l'intégralité des usages alternatifs doivent être analysés ou non */
      ( *p_usageUsed ) = 1;

      /* Si l'item courant est un item de type USAGE_MINIMUM */
      if ( p_usage->first->head.field.tag == K_MK_HID_ITEM_TAG_USAGE_MINIMUM )
      {
         /* Si la page courante est une page de type BUTTON */
         if ( p_page == K_MK_HID_BUTTON_PAGE )
         {
            /* Récupération du nombre de boutons */
            l_counter = ( p_table->local->usageMaximum - p_table->local->usageMinimum ) + 1;

            /* Allocation d'un ou plusieurs boutons supplémentaires dans la chaine */
            l_result = mk_hid_routeButtonMouse ( l_mouse, p_table, p_usage, l_counter );
         }

         /* Sinon */
         else
         {
            /* L'usage courant (alternatif ou principal) n'est pas utilisé */
            /* On bascule la variable pour continuer l'analyse des usages alternatifs */
            ( *p_usageUsed ) = 0;
         }
      }

      /* Sinon si l'item courant est un item de type USAGE */
      else if ( p_usage->first->head.field.tag == K_MK_HID_ITEM_TAG_USAGE )
      {
         /* Détermination de la valeur de l'usage */
         l_usageId = p_usage->first->value & 0x0000FFFF;

         /* Si la page courante est une page de type GENERIC_DESKTOP_PAGE */
         if ( p_page == K_MK_HID_GENERIC_DESKTOP_PAGE )
         {
            /* Routage des usage de type 'GenericDesktopPage' */
            l_result = mk_hid_routeGenericDesktopPageUsageToMouse ( l_mouse, p_table, p_usage, l_usageId, p_usageUsed );
         }

         /* Sinon si la page courante est une page de type BUTTON */
         else if ( p_page == K_MK_HID_BUTTON_PAGE )
         {
            /* Allocation d'un bouton supplémentaire dans la chaine */
            l_result = mk_hid_routeButtonMouse ( l_mouse, p_table, p_usage, 1 );
         }

         /* Sinon si la page courante est une page de type CONSUMMER */
         else if ( p_page == K_MK_HID_CONSUMER_PAGE )
         {
            /* Routage des usage de type 'Consumer' */
            mk_hid_routeConsumerUsageToMouse ( l_mouse, p_table, p_usage, l_usageId, p_usageUsed );
         }

         /* Sinon */
         else
         {
            /* La page courante n'est pas utilisée */
            /* On bascule la variable pour continuer l'analyse des usages alternatifs (les usages alternatifs peuvent possèder des numéros de page différent car elle */
            /* peut être concaténée dans les 32bits de poids fort. */
            ( *p_usageUsed ) = 0;
         }
      }

      /* Sinon */
      else
      {
         /* Ne rien faire */
         /* L'item courant n'est pas un usage */
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


