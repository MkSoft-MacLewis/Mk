/**
*
* @copyright Copyright (C) 2023 RENARD Mathieu. All rights reserved.
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
* @file mk_console_clean.c
* @brief Définition de la fonction mk_console_clean.
* @date 7 avr. 2023
*
*/

#include "mk_engine_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

T_mkCode mk_console_clean ( T_mkConsole* p_console )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result = K_MK_ERROR_PARAM;

   /* Déclaration des variables de travail */
   uint32_t l_lowFileSize = 0, l_highFileSize = 0;

   /* Si les paramètres sont valides */
   if ( ( p_console != K_MK_NULL ) && ( p_console->semaphore != K_MK_NULL ) )
   {
      /* Entrée en section critique */
      l_result = mk_display_enterCritical ( );

      /* Si aucune erreur ne s'est produite */
      if ( l_result == K_MK_OK )
      {
         /* Initialisation des chaines de caractères */
         _writeBytes ( p_console->window.buf, 0, p_console->window.bufSize );

         /* Réinitialisation du buffer de la boite d'édition */
         mk_editField_setTextBuffer ( &p_console->foreground.window, p_console->window.buf, p_console->window.bufSize );

         /* Sortie de la section crique */
         l_result |= mk_display_exitCritical ( );
      }

      /* Sinon */
      else
      {
         /* Ne rien faire */
      }

      /* Si aucune erreur ne s'est produite */
      if ( l_result == K_MK_OK )
      {
         /* Prise du sémaphore */
         l_result = mk_semaphore_take ( p_console->semaphore, K_MK_TASK_WAIT_FOREVER );

         /* Si aucune erreur ne s'est produite */
         if ( l_result == K_MK_OK )
         {
            /* Si un fichier a été ouvert */
            if ( p_console->window.file != K_MK_NULL )
            {
               /* Récupération de la taille du fichier */
               l_result = mk_file_getSize ( p_console->window.file, &l_lowFileSize, &l_highFileSize, K_MK_NULL );

               /* Si aucune erreur ne s'est produite */
               if ( l_result == K_MK_OK )
               {
                  /* Enregistrement de l'adresse du pointeur de fichier */
                  p_console->window.filePointer = l_lowFileSize;

                  /* Reconfiguration du pointeur de fichier */
                  l_result = mk_file_seek ( p_console->window.file, ( uint32_t ) l_lowFileSize, K_MK_NULL );
               }

               /* Sinon */
               else
               {
                  /* Ne rien faire */
               }
            }

            /* Sinon */
            else
            {
               /* Ne rien faire */
            }

            /* Libération du sémaphore (sans condition) */
            l_result |= mk_semaphore_release ( p_console->semaphore );
         }

         /* Sinon */
         else
         {
            /* Ne rien faire */
         }
      }

      /* Si aucune erreur ne s'est produite */
      if ( l_result == K_MK_OK )
      {
         /* Déclenchement d'un rafraichissement graphique */
         mk_console_setRefresh ( p_console, K_MK_FIELD_REFRESH_ENABLED );
      }

      /* Sinon */
      else
      {
         /* Ne rien faire */
      }
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Retour */
   return ( l_result );
}


